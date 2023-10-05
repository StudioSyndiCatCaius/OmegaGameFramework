// Fill out your copyright notice in the Description page of Project Settings.


#include "OFunctions_GameFeatures.h"
#include "GameFeaturesSubsystem.h"
#include "Engine/Engine.h"


void UOFunctions_GameFeatures::SetGameFeatureActive(const FString& Name, bool bNewActive)
{
	FString PluginURL;
	//UGameFeaturesSubsystem::Get().GetPluginURLForBuiltInPluginByName(Name, PluginURL);
	UGameFeaturesSubsystem::Get().GetPluginURLByName(Name, PluginURL);
	if(bNewActive)
	{
		UGameFeaturesSubsystem::Get().LoadAndActivateGameFeaturePlugin(PluginURL, FGameFeaturePluginLoadComplete());
	}
	else
	{
		UGameFeaturesSubsystem::Get().UnloadGameFeaturePlugin(PluginURL, true);
	}
	
}

void UOmegaGameFeatureActionBase::OnGameFeatureActivating(FGameFeatureActivatingContext& Context)
{
	Super::OnGameFeatureActivating(Context);
	FeatureActivated();
}

void UOmegaGameFeatureActionBase::OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context)
{
	Super::OnGameFeatureDeactivating(Context);
	FeatureDeactivated();
}
