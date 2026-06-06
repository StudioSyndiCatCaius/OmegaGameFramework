#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Sound/SoundWave.h"
#include "F_Import.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_Import : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Import|Audio")
	static USoundWave* MP3(const FString& FilePath);
};