// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaDemo_Functions.generated.h"

UCLASS()
class OMEGADEMO_API UOmegaDemoFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION() static  TArray<FName> GetAssetKeys_Attributes();
	UFUNCTION() static  TArray<FName> GetAssetKeys_EquipSlots();
};

