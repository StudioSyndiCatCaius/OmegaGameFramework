// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "OmegaFunctions_Player.generated.h"

UCLASS()
class UOmegaPlayerFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="Omega|Player")
	static FVector OffsetScreenPositionToWorld(APlayerController* Player, FVector2D ScreenPosition,FVector Offset);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Player",meta=(AdvancedDisplay="Start_Offset, End_Offset"))
	static FRotator GetRotationFrom2DDirection(APlayerController* Player, FVector2D Start,FVector2D Target, FVector Start_Offset,FVector End_Offset);

	
};
