// Copyright Incanta Games 2020. All Rights Reserved.

#include "FileSDKFileReader.h"
#include "FileSDKBPLibrary.h"

UFileSDKFileReader::UFileSDKFileReader(
  const FObjectInitializer& ObjectInitializer
) : Super(ObjectInitializer) {
  //
}

void UFileSDKFileReader::OpenFile(
  FString fileName
) {
  this->FileName = fileName;
  this->fileReader = IFileManager::Get().CreateFileReader(*fileName);
}

bool UFileSDKFileReader::IsGood() {
  return
    this->fileReader &&
    !this->fileReader->IsError() &&
    !this->fileReader->IsCriticalError() &&
    !this->fileReader->AtEnd();
}

int64 UFileSDKFileReader::GetFilePosition() {
  if (this->fileReader) {
    return this->fileReader->Tell();
  } else {
    return 0;
  }
}

bool UFileSDKFileReader::SeekFilePosition(
  EFileSDKFileAnchor Anchor,
  int64 Offset
) {
  if (this->IsGood() && Offset >= 0) {
    switch (Anchor) {
      case EFileSDKFileAnchor::Beginning: {
        if (Offset > this->fileReader->TotalSize()) {
          this->fileReader->Seek(this->fileReader->TotalSize());
        } else {
          this->fileReader->Seek(Offset);
        }
        break;
      }
      case EFileSDKFileAnchor::Current: {
        if (this->fileReader->Tell() + Offset > this->fileReader->TotalSize()) {
          this->fileReader->Seek(this->fileReader->TotalSize());
        } else {
          this->fileReader->Seek(this->fileReader->Tell() + Offset);
        }
        break;
      }
      case EFileSDKFileAnchor::End: {
        if (Offset > this->fileReader->TotalSize()) {
          this->fileReader->Seek(0);
        } else {
          this->fileReader->Seek(this->fileReader->TotalSize() - Offset);
        }
        break;
      }
    }
    return true;
  } else {
    return false;
  }
}

int64 UFileSDKFileReader::ReadBytes(int64 Num, TArray<uint8> & Content) {
  if (this->IsGood()) {
    uint8 * Buffer = new uint8[Num];
    Content.Reserve(Num);
    memset(Buffer, 0, Num);
    int64 PosBefore = this->fileReader->Tell();
    this->fileReader->Serialize(Buffer, Num);
    int64 PosAfter = this->fileReader->Tell();
    int64 NumRead = PosAfter - PosBefore;
    Content.Append(Buffer, NumRead);
    return NumRead;
  } else {
    return 0;
  }
}

int64 UFileSDKFileReader::ReadBytesToEnd(TArray<uint8> & Content) {
  if (this->IsGood()) {
    int64 CurrentPosition = this->fileReader->Tell();
    int64 EndPosition = this->fileReader->TotalSize();

    return this->ReadBytes(EndPosition - CurrentPosition, Content);
  } else {
    return 0;
  }
}

int64 UFileSDKFileReader::ReadString(int64 Num, FString & Content) {
  if (this->IsGood()) {
    uint8 * Buffer = new uint8[Num];
    Content.Reserve(Num);
    memset(Buffer, 0, Num);
    int64 PosBefore = this->fileReader->Tell();
    this->fileReader->Serialize(Buffer, Num);
    int64 PosAfter = this->fileReader->Tell();
    int64 NumRead = PosAfter - PosBefore;

    int64 Count = NumRead;
    uint8 * BufferIterator = Buffer;
    Content.Empty(Count);
    while (Count)
    {
      int16 Value = *BufferIterator;

      Content += TCHAR(Value);

      ++BufferIterator;
      Count--;
    }

    return NumRead;
  } else {
    return 0;
  }
}

int64 UFileSDKFileReader::ReadStringToEnd(FString & Content) {
  if (this->IsGood()) {
    int64 CurrentPosition = this->fileReader->Tell();
    int64 EndPosition = this->fileReader->TotalSize();

    return this->ReadString(EndPosition - CurrentPosition, Content);
  } else {
    return 0;
  }
}

void UFileSDKFileReader::Close() {
  if (this->fileReader) {
    this->fileReader->Close();
  }
}
