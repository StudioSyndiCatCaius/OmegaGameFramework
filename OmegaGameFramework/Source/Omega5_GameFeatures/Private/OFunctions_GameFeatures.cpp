// Fill out your copyright notice in the Description page of Project Settings.


#include "OFunctions_GameFeatures.h"
#include "GameFeaturesSubsystem.h"
#include "Engine/Engine.h"


void UOFunctions_GameFeatures::SetGameFeatureActive(const FString& Name, bool bNewActive)
{
	FString PluginURL;
	UGameFeaturesSubsystem::Get().GetPluginURLForBuiltInPluginByName(Name, PluginURL);
	if(bNewActive)
	{
		UGameFeaturesSubsystem::Get().LoadAndActivateGameFeaturePlugin(PluginURL, FGameFeaturePluginLoadComplete());
	}
	else
	{
		UGameFeaturesSubsystem::Get().UnloadGameFeaturePlugin(PluginURL, true);
	}
	
}
