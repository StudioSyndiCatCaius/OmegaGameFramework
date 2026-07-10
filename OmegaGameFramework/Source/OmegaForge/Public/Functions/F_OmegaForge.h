// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Structs/Struct_LevelData.h"
#include "F_OmegaForge.generated.h"

/**
 * 
 */
UCLASS()
class OMEGAFORGE_API UOmegaFunctions_Forge : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	//These first to load and save custom level data from a json formated file with the extention .OGFLVL
	
	UFUNCTION(BlueprintCallable, Category = "OmegaForge")
	static bool CustomLevelData_SaveToFile(FOmegaForge_LevelData Data, FString FilePath);
	UFUNCTION(BlueprintCallable, Category = "OmegaForge")
	static bool CustomLevelData_LoadFromFile(FOmegaForge_LevelData& Data, FString FilePath);
	
	UFUNCTION(BlueprintCallable, Category = "OmegaForge")
	static FOmegaForge_LevelData CustomLevelData_Create(TArray<AActor*> ActorSaveList);
};
