// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_OmegaForge.h"

bool UOmegaFunctions_Forge::CustomLevelData_SaveToFile(FOmegaForge_LevelData Data, FString FilePath)
{
	return false;
}

bool UOmegaFunctions_Forge::CustomLevelData_LoadFromFile(FOmegaForge_LevelData& Data, FString FilePath)
{
	return false;
}

FOmegaForge_LevelData UOmegaFunctions_Forge::CustomLevelData_Create(TArray<AActor*> ActorSaveList)
{
	return FOmegaForge_LevelData();
}
