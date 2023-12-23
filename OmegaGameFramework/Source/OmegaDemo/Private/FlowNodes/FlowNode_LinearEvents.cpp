// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_LinearEvents.h"

#include "Event/OmegaLinearEventInstance.h"
#include "Save/OmegaSaveSubsystem.h"


UFlowNode_LinearEvents::UFlowNode_LinearEvents()
{
	InputPins.Empty();
	InputPins.Add(FFlowPin(TEXT("Begin")));
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("Finish")));
#if WITH_EDITOR
	Category = TEXT("GameFlow");
#endif
}

void UFlowNode_LinearEvents::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	LocalInst = GetWorld()->GetSubsystem<UOmegaLinearEventSubsystem>()->PlayLinearEvent(Events, 0);
	LocalInst->OnEventSequenceFinish.AddDynamic(this, &UFlowNode_LinearEvents::LocalFinish);
}

#if WITH_EDITOR
FString UFlowNode_LinearEvents::GetNodeDescription() const
{
	FString OutString;
	int32 Index = 0; // Start an index at 0 to number the list items

	for (const auto* TempEvent : Events.Events)
	{
		if (TempEvent)
		{
			const FString LocalString = TempEvent->GetLogString();
			OutString += FString::Printf(TEXT("[%d] %s\n"), Index, *LocalString); // Append the indexed string with a newline
			Index++; // Increment the index for the next list item
		}
	}

	// If you want to remove the last newline from the string, you can do so before returning.
	if (!OutString.IsEmpty())
	{
		OutString.RemoveAt(OutString.Len() - 1); // Remove the last character (newline)
	}

	return OutString;
}
#endif

void UFlowNode_LinearEvents::LocalFinish(const FString& Flag,UOmegaLinearEventInstance* Instance)
{
	TriggerFirstOutput(true);
}



//-----------------------------------------
// Edit Save Tags
//-----------------------------------------

UFlowNode_EditSaveTags::UFlowNode_EditSaveTags()
{
#if WITH_EDITOR
	Category = TEXT("GameFlow");
#endif
}

void UFlowNode_EditSaveTags::ExecuteInput(const FName& PinName)
{
	UOmegaSaveSubsystem* SubsysRef = GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>();
	
	switch (Action)
	{
	case EAddRemove::Add:
		SubsysRef->AddStoryTags(Tags, GlobalSave);
		break;
	case EAddRemove::Remove:
		SubsysRef->RemoveStoryTags(Tags, GlobalSave);
		break;
	default: ;
	}
	TriggerFirstOutput(true);
}
