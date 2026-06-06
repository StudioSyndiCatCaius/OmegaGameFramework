// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Debug.generated.h"

UCLASS()
class UOmegaFunctions_Debug : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	// DRAW
	UFUNCTION(BlueprintCallable, Category = "Omega|Debug")
	static void Draw_DebugComponent(
		USceneComponent* Component,
		FLinearColor Color = FLinearColor::White,
		bool bAsSphere = false,
		float Duration = 0.0f,
		float Thickness = 2.0f,
		float AxisLength = 50.0f,
		bool bDrawAxes = true,
		bool bDrawBounds = false,
		float BoundsScale=1.0f
	);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Debug")
	static void Draw_DebugLineBetweenComponents(
		USceneComponent* ComponentA,
		USceneComponent* ComponentB,
		FLinearColor Color = FLinearColor::White,
		float Duration = 0.0f,
		float Thickness = 2.0f
	);
};
