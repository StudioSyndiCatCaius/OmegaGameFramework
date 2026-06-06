// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Draw.generated.h"

UCLASS()
class UOmegaFunctions_Draw3D : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
};


UCLASS()
class UOmegaFunctions_Draw2D : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Draw2D", meta = (WorldContext = "WorldContextObject"))
	static void DrawObjectTree(
		const UObject* WorldContextObject,
		FVector2D Position,
		FVector2D Size,
		UObject* Object,
		APlayerController* PC = nullptr
	);
};
