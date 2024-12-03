// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Dom/JsonObject.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaFunctions_Graphics.generated.h"

UENUM(BlueprintType)
enum class EGraphicsRHI : uint8
{
	RHI_DX11	UMETA(DisplayName="DirectX 11"),
	RHI_DX12	UMETA(DisplayName="DirectX 12"),
	RHI_VULKAN	UMETA(DisplayName="Vulkan")
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGraphicsFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "RHIManager sample test testing"), Category = "RHIManagerTesting")
	static float RHIManagerSampleFunction(float Param);
	
	UFUNCTION(BlueprintCallable, Category = "GraphicsRHIManager")
	static void SetGraphicsRHI(EGraphicsRHI GraphicsRHI);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "GraphicsRHIManager")
	static EGraphicsRHI GetCurrentGraphicsRHI();
	
};
