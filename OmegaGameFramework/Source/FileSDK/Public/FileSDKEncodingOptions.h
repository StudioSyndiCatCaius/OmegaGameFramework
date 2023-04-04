// Copyright Incanta Games 2021. All Rights Reserved.

#pragma once

#include "Misc/FileHelper.h"

UENUM( BlueprintType )
enum class EFileSDKEncodingOptions : uint8 {
  AutoDetect,
  ForceAnsi,
  ForceUnicode,
  ForceUTF8,
  ForceUTF8WithoutBOM
};
