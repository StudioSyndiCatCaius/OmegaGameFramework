// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/OmegaSubsystem_Midi.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"



int32 UOmegaMidiSubsystem::ReadVariableLength(const TArray<uint8>& Data, int32& Position)
{
    int32 Value = 0;
    uint8 Byte;
    do
    {
        Byte = Data[Position++];
        Value = (Value << 7) | (Byte & 0x7F);
    } while (Byte & 0x80);
    return Value;
}

void UOmegaMidiSubsystem::HandleNoteOff(FMidiTrack& Track, TMap<uint8, FMidiKey>& ActiveNotes, uint8 Note,
    float CurrentTime)
{
    if (FMidiKey* Key = ActiveNotes.Find(Note))
    {
        Key->Duration = CurrentTime - Key->StartTime;
        Track.Keys.Add(*Key);
        ActiveNotes.Remove(Note);
    }
}

bool UOmegaMidiSubsystem::ParseMidiFile(const FString& FilePath, FMidiData& OutMidiData)
{
	 // Read file into buffer
        TArray<uint8> FileData;
        if (!FFileHelper::LoadFileToArray(FileData, *FilePath))
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to load MIDI file: %s"), *FilePath);
            return false;
        }

        // Parse MIDI header
        if (FileData.Num() < 14)
        {
            UE_LOG(LogTemp, Error, TEXT("Invalid MIDI file: too small"));
            return false;
        }

        // Verify MIDI header chunk
        if (FileData[0] != 'M' || FileData[1] != 'T' || FileData[2] != 'h' || FileData[3] != 'd')
        {
            UE_LOG(LogTemp, Error, TEXT("Invalid MIDI file: wrong header signature"));
            return false;
        }

        // Parse header length (should be 6)
        int32 HeaderLength = (FileData[4] << 24) | (FileData[5] << 16) | (FileData[6] << 8) | FileData[7];
        if (HeaderLength != 6)
        {
            UE_LOG(LogTemp, Error, TEXT("Invalid MIDI header length"));
            return false;
        }

        // Parse format type
        OutMidiData.Format = (FileData[8] << 8) | FileData[9];
        
        // Parse number of tracks
        uint16 NumTracks = (FileData[10] << 8) | FileData[11];
        
        // Parse time division
        OutMidiData.TimeDivision = (FileData[12] << 8) | FileData[13];
        float MicrosecondsPerQuarterNote = 500000.0f;  // Default tempo (120 BPM)
        OutMidiData.InitialBPM = 120.0f;

        int32 CurrentPosition = 14;  // Start after header
        float MaxTime = 0.0f;

        // Process each track
        for (uint16 TrackIndex = 0; TrackIndex < NumTracks; ++TrackIndex)
        {
            FMidiTrack Track;
            Track.TrackNumber = TrackIndex;

            // Verify track header
            if (CurrentPosition + 8 > FileData.Num())
            {
                UE_LOG(LogTemp, Error, TEXT("Unexpected end of file"));
                return false;
            }

            if (FileData[CurrentPosition] != 'M' || FileData[CurrentPosition + 1] != 'T' ||
                FileData[CurrentPosition + 2] != 'r' || FileData[CurrentPosition + 3] != 'k')
            {
                UE_LOG(LogTemp, Error, TEXT("Invalid track header"));
                return false;
            }

            // Get track length
            int32 TrackLength = (FileData[CurrentPosition + 4] << 24) | 
                              (FileData[CurrentPosition + 5] << 16) |
                              (FileData[CurrentPosition + 6] << 8) | 
                               FileData[CurrentPosition + 7];

            CurrentPosition += 8;

            float CurrentTime = 0.0f;
            TMap<uint8, FMidiKey> ActiveNotes;

            // Process track events
            while (CurrentPosition < FileData.Num())
            {
                // Read variable-length delta time
                int32 DeltaTime = 0;
                uint8 Byte;
                do
                {
                    Byte = FileData[CurrentPosition++];
                    DeltaTime = (DeltaTime << 7) | (Byte & 0x7F);
                } while (Byte & 0x80);

                float DeltaSeconds = (DeltaTime * MicrosecondsPerQuarterNote) / 
                                   (OutMidiData.TimeDivision * 1000000.0f);
                CurrentTime += DeltaSeconds;
                MaxTime = FMath::Max(MaxTime, CurrentTime);

                // Read event type
                uint8 StatusByte = FileData[CurrentPosition++];
                
                // Handle Note On event
                if ((StatusByte & 0xF0) == 0x90)
                {
                    uint8 Note = FileData[CurrentPosition++];
                    uint8 Velocity = FileData[CurrentPosition++];

                    if (Velocity > 0)
                    {
                        FMidiKey NewKey;
                        NewKey.NoteNumber = Note;
                        NewKey.StartTime = CurrentTime;
                        NewKey.Velocity = Velocity;
                        ActiveNotes.Add(Note, NewKey);
                    }
                    else
                    {
                        HandleNoteOff(Track, ActiveNotes, Note, CurrentTime);
                    }
                }
                // Handle Note Off event
                else if ((StatusByte & 0xF0) == 0x80)
                {
                    uint8 Note = FileData[CurrentPosition++];
                    uint8 Velocity = FileData[CurrentPosition++];
                    HandleNoteOff(Track, ActiveNotes, Note, CurrentTime);
                }
                // Handle Program Change
                else if ((StatusByte & 0xF0) == 0xC0)
                {
                    Track.InstrumentNumber = FileData[CurrentPosition++];
                }
                // Handle Meta Event
                else if (StatusByte == 0xFF)
                {
                    uint8 MetaType = FileData[CurrentPosition++];
                    int32 Length = ReadVariableLength(FileData, CurrentPosition);

                    // Handle track name meta event
                    if (MetaType == 0x03)
                    {
                        Track.TrackName = FString(Length, (char*)&FileData[CurrentPosition]);
                    }
                    // Handle tempo meta event
                    else if (MetaType == 0x51)
                    {
                        MicrosecondsPerQuarterNote = (FileData[CurrentPosition] << 16) |
                                                    (FileData[CurrentPosition + 1] << 8) |
                                                    FileData[CurrentPosition + 2];
                        
                        float BPM = 60000000.0f / MicrosecondsPerQuarterNote;
                        
                        FTempoEvent TempoChange;
                        TempoChange.TimeInSeconds = CurrentTime;
                        TempoChange.BPM = BPM;
                        
                        if (CurrentTime == 0.0f)
                        {
                            OutMidiData.InitialBPM = BPM;
                        }
                        
                        OutMidiData.TempoChanges.Add(TempoChange);
                    }
                    
                    CurrentPosition += Length;

                    // End of track meta event
                    if (MetaType == 0x2F)
                    {
                        break;
                    }
                }
                // Skip other events
                else if ((StatusByte & 0x80) == 0x80)
                {
                    // Read event data (simplified)
                    CurrentPosition += 2;
                }
            }

            OutMidiData.Tracks.Add(Track);
        }

        OutMidiData.DurationInSeconds = MaxTime;
        return true;
}
