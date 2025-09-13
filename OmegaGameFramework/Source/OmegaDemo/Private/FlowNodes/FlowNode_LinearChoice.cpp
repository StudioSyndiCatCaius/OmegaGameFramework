// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_LinearChoice.h"

#include "FlowAsset.h"
#include "FlowTypes.h"
#include "OmegaLinearEventSubsystem.h"
#include "OmegaSettings_Gameplay.h"
#include "Engine/World.h"
#include "LinearEvents/LinearChoice_SimpleChoice.h"
#include "Subsystems/OmegaSubsystem_Save.h"

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

#if WITH_EDITOR
bool UFlowNode_LinearChoice::CanUserAddOutput() const
{
	return true;
}
#endif

void UFlowNode_LinearChoice::ExecuteInput(const FName& PinName)
{
	TSubclassOf<AOmegaLinearChoiceInstance> class_in=InstanceClass;
	if(UOmegaSettings_Gameplay* set=UOmegaGameplayStyleFunctions::GetCurrentGameplayStyle())
	{
		if(set)
		{
			if(Cast<AOmegaLinearChoiceInstance>(set->DefaultChoiceInstance))
			{
				class_in=set->DefaultChoiceInstance;
			}
		}
	}
	ChoiceInst = GetWorld()->GetSubsystem<UOmegaLinearEventSubsystem>()->PlayLinearChoice(Choices, class_in);
	ChoiceInst->OnChoiceSelected.AddDynamic(this, &UFlowNode_LinearChoice::LocalChoiceSelect);
	
	Super::ExecuteInput(PinName);
}
