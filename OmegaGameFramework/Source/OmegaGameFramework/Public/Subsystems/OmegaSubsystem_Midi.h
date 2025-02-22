// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Subsystems/WorldSubsystem.h"
#include "OmegaSubsystem_Midi.generated.h"


USTRUCT(BlueprintType)
struct FMidiKey
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MIDI")
    int32 NoteNumber;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MIDI")
    float StartTime;  // In seconds

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MIDI")
    float Duration;   // In seconds

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MIDI")
    uint8 Velocity;

    FMidiKey() : NoteNumber(0), StartTime(0.0f), Duration(0.0f), Velocity(0) {}
};

USTRUCT(BlueprintType)
struct FMidiTrack
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MIDI")
    TArray<FMidiKey> Keys;

    UPROPERTY(BlueprintReadWrite, Category = "MIDI")
    FString TrackName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MIDI")
    int32 TrackNumber;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MIDI")
    int32 InstrumentNumber;

    FMidiTrack() : TrackNumber(0), InstrumentNumber(0) {}
};

USTRUCT(BlueprintType)
struct FTempoEvent
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MIDI")
    float TimeInSeconds;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MIDI")
    float BPM;

    FTempoEvent() : TimeInSeconds(0.0f), BPM(120.0f) {}
};

USTRUCT(BlueprintType)
struct FMidiData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MIDI")
    TArray<FMidiTrack> Tracks;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MIDI")
    TArray<FTempoEvent> TempoChanges;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MIDI")
    float InitialBPM;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MIDI")
    int32 TimeDivision;  // Ticks per quarter note

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MIDI")
    int32 Format;       // MIDI format (0, 1, or 2)

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MIDI")
    float DurationInSeconds;

    FMidiData() : InitialBPM(120.0f), TimeDivision(480), Format(1), DurationInSeconds(0.0f) {}
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaMidiSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

    static int32 ReadVariableLength(const TArray<uint8>& Data, int32& Position);
    static void HandleNoteOff(FMidiTrack& Track, TMap<uint8, FMidiKey>& ActiveNotes, uint8 Note, float CurrentTime);
    
public:
    UFUNCTION(BlueprintCallable,Category="Omega|Midi")
    bool ParseMidiFile(const FString& FilePath, FMidiData& OutMidiData);
};

