// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_StartFlowAsset.h"

#include "OmegaGameManager.h"
#include "Flow/Public/FlowSubsystem.h"




void UAsyncAction_StartFlowAsset::Native_OnFinishFlow(UFlowAsset* FlowAsset, FName Output, const FString& Flag)
{
	UFlowSubsystem* SubsystemRef = LocalWorldContext->GetWorld()->GetGameInstance()->GetSubsystem<UFlowSubsystem>();
	
	if(SubsystemRef->GetRootFlow(this) == FlowAsset)
	{
		OnFinish.Broadcast(Output, Flag);
		SetReadyToDestroy();
	}
}


void UAsyncAction_StartFlowAsset::Activate()
{
	UFlowSubsystem* SubsystemRef = LocalWorldContext->GetWorld()->GetGameInstance()->GetSubsystem<UFlowSubsystem>();
	
	if(SubsystemRef)
	{
		SubsystemRef->OnFlowEventFinish.AddDynamic(this, &UAsyncAction_StartFlowAsset::Native_OnFinishFlow);
		SubsystemRef->StartRootFlow(this, Local_FlowAsset, Local_OverrideStart, Local_StartNode, Local_Input, Local_MultiInst);
	}
}

UAsyncAction_StartFlowAsset* UAsyncAction_StartFlowAsset::StartFlowAsset(UObject* WorldContextObject, UFlowAsset* Asset, bool bOverrideStartingNode, FGuid NewStartingNode, FName Input, bool AllowMultipleInstances)
{
	UAsyncAction_StartFlowAsset* NewNode = NewObject<UAsyncAction_StartFlowAsset>();
	NewNode->Local_FlowAsset = Asset;
	NewNode->Local_OverrideStart = bOverrideStartingNode;
	NewNode->Local_StartNode = NewStartingNode;
	NewNode->Local_Input = Input;
	NewNode->Local_MultiInst = AllowMultipleInstances;
	NewNode->LocalWorldContext = WorldContextObject;
	return NewNode;
}


