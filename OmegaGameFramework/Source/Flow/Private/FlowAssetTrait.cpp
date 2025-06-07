// Fill out your copyright notice in the Description page of Project Settings.

#include "FlowAssetTrait.h"
#include "Engine/GameInstance.h"



void UFlowAssetTrait::Native_FlowBegin(UFlowAsset* FlowInstance) const
{
	FlowBegin(FlowInstance);
}

void UFlowAssetTrait::Native_FlowEnd(UFlowAsset* FlowInstance, FName Output, const FString& Flag) const
{
	FlowEnd(FlowInstance,Output,Flag);
}


