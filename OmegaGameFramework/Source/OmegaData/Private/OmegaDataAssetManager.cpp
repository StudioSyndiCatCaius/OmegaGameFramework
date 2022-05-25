// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaDataAssetManager.h"

void UOmegaDataAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
}

UOmegaDataAssetManager& UOmegaDataAssetManager::Get()
{
	UOmegaDataAssetManager* This = Cast<UOmegaDataAssetManager>(GEngine->AssetManager);

	if(This)
	{
		return *This;
	}
	else
	{
		return *NewObject<UOmegaDataAssetManager>();
	}
}
