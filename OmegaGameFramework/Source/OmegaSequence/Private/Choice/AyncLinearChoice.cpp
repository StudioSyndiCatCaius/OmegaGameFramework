// Fill out your copyright notice in the Description page of Project Settings.


#include "Choice/AyncLinearChoice.h"
#include "Engine/GameInstance.h"
#include "OmegaLinearEventSubsystem.h"

UOmegaLinearChoice::UOmegaLinearChoice(const FObjectInitializer& ObjectInitializer)
{
	if (const UObject* Owner = GetOuter())
	{
		WorldPrivate = Owner->GetWorld();
	}
}

UWorld* UOmegaLinearChoice::GetWorld() const
{
	if(GetGameInstance())
	{
		return GetGameInstance()->GetWorld();
	}
	if(WorldPrivate)
	{
		return WorldPrivate;
	}
	return nullptr;
}

UGameInstance* UOmegaLinearChoice::GetGameInstance() const
{
	return GameInstanceRef;
}


void UAyncLinearChoice::LocalChoiceSelected(UOmegaLinearChoice* Choice, int32 ChoiceIndex)
{
	OnSelected.Broadcast(Choice, ChoiceIndex);
	SetReadyToDestroy();
}

void UAyncLinearChoice::Activate()
{
	AOmegaLinearChoiceInstance* LocalInst;
	LocalInst = SubsystemRef->PlayLinearChoice(ChoiceData, InstanceClassRef);
	LocalInst->OnChoiceSelected.AddDynamic(this, &UAyncLinearChoice::UAyncLinearChoice::LocalChoiceSelected);

	Super::Activate();
}

UAyncLinearChoice* UAyncLinearChoice::PlayLinearChoice(UOmegaLinearEventSubsystem* Subsystem, FOmegaLinearChoices Choices, TSubclassOf<AOmegaLinearChoiceInstance> InstanceClass)
{
	UAyncLinearChoice* NewChoice = NewObject<UAyncLinearChoice>();
	NewChoice->SubsystemRef = Subsystem;
	NewChoice->ChoiceData = Choices;
	NewChoice->InstanceClassRef = InstanceClass;
	
	return  NewChoice;
}
