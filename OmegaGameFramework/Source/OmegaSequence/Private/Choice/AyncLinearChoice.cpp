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

void UOmegaLinearChoice::OnChoiceSelected_Implementation() const
{
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

UAyncLinearChoice* UAyncLinearChoice::PlayLinearChoice(UObject* WorldContextObject, FOmegaLinearChoices Choices, TSubclassOf<AOmegaLinearChoiceInstance> InstanceClass)
{
	if(WorldContextObject)
	{
		UAyncLinearChoice* NewChoice = NewObject<UAyncLinearChoice>();
		NewChoice->SubsystemRef = WorldContextObject->GetWorld()->GetSubsystem<UOmegaLinearEventSubsystem>();
		NewChoice->ChoiceData = Choices;
		NewChoice->InstanceClassRef = InstanceClass;
		return  NewChoice;
	}
	return nullptr;
}
