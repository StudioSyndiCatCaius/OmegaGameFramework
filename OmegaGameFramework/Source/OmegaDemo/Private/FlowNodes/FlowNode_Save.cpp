// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_Save.h"

#include "Engine/GameInstance.h"
#include "Functions/F_GlobalParam.h"
#include "Kismet/KismetStringLibrary.h"
#include "Subsystems/Subsystem_Save.h"
#include "Engine/World.h"



UFlowNode_SaveOnce::UFlowNode_SaveOnce()
{
	InputPins.Empty();
	InputPins.Add(FFlowPin(TEXT("In")));
	InputPins.Add(FFlowPin(TEXT("Reset")));
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("First")));
	OutputPins.Add(FFlowPin(TEXT("Then")));
}

void UFlowNode_SaveOnce::ExecuteInput(const FName& PinName)
{
	FString SaveParam=NodeGuid.ToString();
	
	if (PinName.ToString()=="Reset")
	{
		UOmegaFunctions_GlobalVars::SetGlobalVariable_Bool(this,Target,*SaveParam,false);
	}
	else
	{
		if (UOmegaFunctions_GlobalVars::GetGlobalVariable_Bool(this,Target,*SaveParam))
		{
			TriggerOutput(TEXT("Then"),true);
		}
		else
		{
			UOmegaFunctions_GlobalVars::SetGlobalVariable_Bool(this,Target,*SaveParam,true);
			TriggerOutput(TEXT("First"),true);
		}
	}
	
}


UFlowNode_TagsEdit::UFlowNode_TagsEdit()
{
	InputPins.Empty();
	InputPins.Add(FFlowPin(TEXT("In")));
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("Out")));
}

void UFlowNode_TagsEdit::ExecuteInput(const FName& PinName)
{
	if(UOmegaSaveSubsystem* sub=GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>())
	{
		sub->AddStoryTags(TagsAdded, bGlobal);
		sub->RemoveStoryTags(TagsRemoved, bGlobal);
	}
	TriggerOutput(TEXT("Out"), true);
}

#if WITH_EDITOR
FString UFlowNode_TagsEdit::GetNodeDescription() const
{
	return FString::Printf(TEXT("Add: %s\nRemove: %s"),
		*UKismetStringLibrary::Replace(TagsAdded.ToString(),",","\n  "),
		*UKismetStringLibrary::Replace(TagsRemoved.ToString(),",","\n  "));
}
#endif


UFlowNode_TagsCheck::UFlowNode_TagsCheck()
{
	InputPins.Empty();
	InputPins.Add(FFlowPin(TEXT("In")));
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("True")));
	OutputPins.Add(FFlowPin(TEXT("False")));
}

void UFlowNode_TagsCheck::ExecuteInput(const FName& PinName)
{
	bool bResult = false;
	if(UOmegaSaveSubsystem* sub=GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>())
	{
		const FGameplayTagContainer SaveTags = sub->GetStoryTags(bGlobal);
		bResult = bExact ? SaveTags.HasAllExact(HasTags) : SaveTags.HasAll(HasTags);
	}
	TriggerOutput(bResult ? TEXT("True") : TEXT("False"), true);
}

#if WITH_EDITOR
FString UFlowNode_TagsCheck::GetNodeDescription() const
{
	return FString::Printf(TEXT("Has: %s\nExact: %s"), *HasTags.ToString(), bExact ? TEXT("true") : TEXT("false"));
}
#endif
