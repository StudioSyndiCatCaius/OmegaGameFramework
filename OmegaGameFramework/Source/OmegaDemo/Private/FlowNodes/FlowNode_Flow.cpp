// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_Flow.h"

#include "FlowAsset.h"
#include "FlowSubsystem.h"

void UFlowNode_SubflowTagged::L_End(UFlowAsset* FlowAsset, FName Output, const FString& Flag)
{
	if(FlowAsset==l_subflowinst)
	{
		TriggerOutput(TEXT("Finished"),true);
	}
}

UFlowNode_SubflowTagged::UFlowNode_SubflowTagged()
{
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("Finished")));
	OutputPins.Add(FFlowPin(TEXT("Failed")));
}

void UFlowNode_SubflowTagged::ExecuteInput(const FName& PinName)
{
	if(SourceObject)
	{
		if(UObject* src=SourceObject->GetSelected_Obj(this))
		{
			if(src->GetClass()->ImplementsInterface(UDataInterface_FlowAsset::StaticClass()))
			{
				if(UFlowAsset* flw=IDataInterface_FlowAsset::Execute_GetFlowAsset(src,Tag))
				{
					if(UFlowSubsystem* _sub=GetWorld()->GetGameInstance()->GetSubsystem<UFlowSubsystem>())
					{
						l_subflowinst=_sub->StartRootFlow(this,flw,FFlowAssetOverrideData());
						if(l_subflowinst)
						{
							_sub->OnFlowEventFinish.AddDynamic(this,&UFlowNode_SubflowTagged::L_End);
							return;
						}
					}
				}
			}
		}
	}
	TriggerOutput(TEXT("Failed"),true);
}

void UFlowNode_SubflowTagged::FlowNotified_Implementation(FName Notify, UObject* Context)
{
	if(ReplicateNotifies && l_subflowinst) 
	{
		l_subflowinst->FireFlowSignal(Notify,Context);
	}
}
