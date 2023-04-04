// Copyright Incanta Games 2021. All Rights Reserved.

#pragma once

#include "FileSDKLineReader.generated.h"

UCLASS(Blueprintable)
class FILESDK_API UFileSDKLineReader : public UObject {
  GENERATED_BODY()

public:
  /**
   * An overridable function that dictates whether or not a line in a file
   * is filtered. Should return true if the line should be provided, false
   * if the line should be filtered out (not included).
   *
   * @param Line The contents of the current line, excluding line endings.
   *
   * @return Should return true if the line should be provided, false
   * if the line should be filtered out (not included).
   */
  UFUNCTION(BlueprintNativeEvent, Category = "FileSDK")
  bool FilterLine(const FString & Line);

  virtual bool FilterLine_Implementation(const FString & line) {
    return true;
  }
};
