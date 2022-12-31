// Fill out your copyright notice in the Description page of Project Settings.

#include "FlowAssetTrait.h"

UFlowAssetTrait::UFlowAssetTrait(const FObjectInitializer& ObjectInitializer)
{
	if (const UObject* Owner = GetOuter())
	{
		WorldPrivate = Owner->GetWorld();
	}
}



UWorld* UFlowAssetTrait::GetWorld() const
{
	if(GameInstanceRef)
	{
		return GetGameInstance()->GetWorld();
	}
	return WorldPrivate;
}

UGameInstance* UFlowAssetTrait::GetGameInstance() const
{
	return GameInstanceRef;
}