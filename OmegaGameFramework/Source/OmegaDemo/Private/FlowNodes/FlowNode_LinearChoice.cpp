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
	TriggerOutput(FName(OutputLocalName));
}



void UFlowNode_LinearChoice::ExecuteInput(const FName& PinName)
{
	TSubclassOf<AOmegaLinearChoiceInstance> class_in=InstanceClass;
	if(!class_in)
	{
		if (TSubclassOf<AOmegaLinearChoiceInstance> newClass=GetMutableDefault<UOmegaSettings>()->DefaultChoiceInstance.LoadSynchronous())
		{
			class_in=newClass;
		}
	}
	FOmegaLinearChoices c=Choices;
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


#endif
