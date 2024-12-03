// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaFunctions_Camera.generated.h"

UCLASS()
class UOmegaCameraFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|Camera",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Player"))
	static FVector2D ProjectWorldToScreen_FromCamera(UObject* WorldContextObject, UCameraComponent* Camera, FVector Location,APlayerController* Player=nullptr);
	
};
