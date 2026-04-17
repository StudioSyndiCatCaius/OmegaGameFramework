// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_LinearChoice.h"

#include "FlowAsset.h"
#include "FlowTypes.h"
#include "OmegaLinearEventSubsystem.h"
#include "OmegaSettings.h"
#include "OmegaGameplayConfig.h"
#include "Engine/World.h"
#include "LinearEvents/LinearChoice_SimpleChoice.h"
#include "Subsystems/Subsystem_Save.h"


UFlowNode_LinkedChoice* UFlowNode_LinearChoice::GetLinkedChoice_ByID(FName ID)
{
	for (auto* n : cached_linkNodes)
	{
		if (n && n->LinkID==ID)
		{
			return n;
		}
	}
	return nullptr;
}

UFlowNode_LinearChoice::UFlowNode_LinearChoice()
{
	InputPins.Empty();
	InputPins.Add(FFlowPin(TEXT("Begin")));
	OutputPins.Empty();
	//NodeStyle = EFlowNodeStyle::Latent;
	//InstanceClass = LoadObject<UClass>(nullptr, TEXT("/OmegaGameFramework/DEMO/Choice/OmegaDemo_Choice_Instance.OmegaDemo_Choice_Instance"));

	for (int i = 0; i < 3; ++i)
	{
		FName OriginalName = FName("choice_");
		FName NewName = FName(*(OriginalName.ToString() + FString::FromInt(i)));
		Choices.Choices.Add(nullptr);
	}
	
#if WITH_EDITOR
	
	Category = TEXT("GameFlow");
	SubscribeToAssetChanges();
#endif
}

TArray<FName> UFlowNode_LinearChoice::L_LinkedNodes()
{
	TArray<FName> out;
	for (auto* n : GetFlowAsset()->GetAllNodes())
	{
		if (UFlowNode_LinkedChoice* _link=Cast<UFlowNode_LinkedChoice>(n))
		{
			out.Add(_link->LinkID);
		}
	}
	return out;
}

void UFlowNode_LinearChoice::LocalChoiceSelect(UOmegaLinearChoice* Choice, int32 Index)
{
	if(SaveParamToSet.IsValid())
	{
		GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->ActiveSaveData->TagVars_int.Add(SaveParamToSet,Index);
	}
	if(LocalParamToSet.IsValid())
	{
		GetFlowAsset()->SetLocalParam_Int(LocalParamToSet,Index);
	}
	FString OutputLocalName = FString::FromInt(Index);
	
	int32 inner_choice_len=OutputLocalName.Len();
	if (Index<=inner_choice_len)
	{
		TriggerOutput(FName(OutputLocalName));	
	}
	else
	{
		int32 linked_index=Index-inner_choice_len-1;
		FName link_id=LinkedChoiceNodes[linked_index];
		UFlowNode_LinkedChoice* c=GetLinkedChoice_ByID(link_id);
		c->TriggerFirstOutput(true);
		Finish();
	}
}


 
void UFlowNode_LinearChoice::ExecuteInput(const FName&PinName)
{
	cached_linkNodes.Empty();
	for (auto* n : GetFlowAsset()->GetAllNodes())
	{
		if (UFlowNode_LinkedChoice* _link=Cast<UFlowNode_LinkedChoice>(n))
		{
			cached_linkNodes.AddUnique(_link);
		}
	}
	
	TSubclassOf<AOmegaLinearChoiceInstance> class_in=InstanceClass;
	if(!class_in)
	{
		if (TSubclassOf<AOmegaLinearChoiceInstance> newClass=GetMutableDefault<UOmegaSettings>()->DefaultChoiceInstance.LoadSynchronous())
		{
			class_in=newClass;
		}
	}
	FOmegaLinearChoices c=Choices;
	
	TArray<UOmegaLinearChoice*> LinkedChoices;
	for (FName link_id : LinkedChoiceNodes)
	{
		for (auto* n : cached_linkNodes)
		{
			if (n->LinkID == link_id)
			{
				LinkedChoices.Add(n->Choice);
			}
		}
	}
	
	c.Choices.Append(LinkedChoices);
	c.flags=Flags;
	c.NamedLists=NamedLists;
	ChoiceInst = GetWorld()->GetSubsystem<UOmegaLinearEventSubsystem>()->PlayLinearChoice(c, class_in);
	ChoiceInst->OnChoiceSelected.AddDynamic(this, &UFlowNode_LinearChoice::LocalChoiceSelect);
	
	Super::ExecuteInput(PinName);
}

#if WITH_EDITOR
TArray<FName> UFlowNode_LinearChoice::GetContextOutputs()
{
	TArray<FName> out;
	int32 last_ind=-1;
	for (auto* a : Choices.Choices)
	{
		last_ind+=1;
		out.Add(*FString::FromInt(last_ind));
	}
	
	return out;
}

void UFlowNode_LinearChoice::PostLoad()
{
	Super::PostLoad();
	SubscribeToAssetChanges();
}

void UFlowNode_LinearChoice::PreEditChange(FProperty* PropertyAboutToChange)
{
	Super::PreEditChange(PropertyAboutToChange);
	//SubscribeToAssetChanges();
}

void UFlowNode_LinearChoice::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	SubscribeToAssetChanges();
}

void UFlowNode_LinearChoice::SubscribeToAssetChanges()
{
	TWeakObjectPtr<UFlowNode_LinearChoice> SelfWeakPtr(this);
	if (SelfWeakPtr.IsValid())
	{
		SelfWeakPtr->OnReconstructionRequested.ExecuteIfBound();
	}
}

UFlowNode_LinkedChoice::UFlowNode_LinkedChoice()
{
	InputPins.Empty();
}

#endif

void UFlowNode_LinkedChoice::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	TriggerFirstOutput(true);
}

#if WITH_EDITOR
FString UFlowNode_LinkedChoice::GetNodeDescription() const
{
	return "Linked Choice : "+LinkID.ToString()+"";
}
#endif
