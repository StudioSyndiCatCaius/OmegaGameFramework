// Copyright Studio Syndicat 2021. All Rights Reserved.

// Common Use Gameplay Functions

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Spline.generated.h"

UCLASS()
class UOmegaFunctions_Spline : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category="Omega|Spline",DisplayName="Spline - Get Vector2D Points") 
	static TArray<FVector2D> Get2DVectorPoints(USplineComponent* Spline);

	UFUNCTION(BlueprintCallable, Category="Omega|Spline",DisplayName="Spline - Clamp Tangents") 
	static void ClampTangents(USplineComponent* Spline, float Min, float Max);
};

