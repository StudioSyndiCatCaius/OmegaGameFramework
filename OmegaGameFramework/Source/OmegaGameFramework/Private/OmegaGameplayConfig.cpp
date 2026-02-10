// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaGameplayConfig.h"

#include "MaterialKeyGeneratorContext.h"
#include "OmegaGameCore.h"
#include "Subsystems/Subsystem_Gameplay.h"
#include "OmegaSettings.h"



UOmegaGameplayConfig::UOmegaGameplayConfig()
{
	//DefaultInteractionType=FGameplayTag::RequestGameplayTag("Event.Actor.Interact");
}

TArray<UOmegaGameplayModule*> UOmegaGameplayConfig::GetModules()
{
	TArray<UOmegaGameplayModule*> out;
	for(auto* a : ModuleSets)
	{
		if(a)
		{
			out.Append(a->GetModules());
		}
	}
	out.Append(ScriptedModules);
	return out;
}

FOmegaSortedClassPathData UOmegaGameplayConfig::GetAssetDataFromClass(TSubclassOf<UObject> Class) const
{
	TMap<TSubclassOf<UObject>, FOmegaSortedClassPathData> temp=ClassPaths;
	return temp.FindOrAdd(Class);
}


TArray<FString> UOmegaGameplayConfig::GetPathsFromAssetName(const FString& AssetName, TSubclassOf<UObject> Class) const
{
	return UOmegaGameCore::GetPathsFromAssetName(ClassPaths,AssetName,Class);
}





