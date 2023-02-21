// Fill out your copyright notice in the Description page of Project Settings.


#include "Save/OmegaSaveCondition.h"

bool UOmegaSaveCondition::CheckSaveCondition_Implementation(UOmegaSaveSubsystem* SaveSubsystem) const
{
	return true;
}

UOmegaSaveCondition::UOmegaSaveCondition(const FObjectInitializer& ObjectInitializer)
{
	if (const UObject* Owner = GetOuter())
	{
		WorldPrivate = Owner->GetWorld();
	}
}

UWorld* UOmegaSaveCondition::GetWorld() const
{
	if(GetGameInstance())
	{
		return GetGameInstance()->GetWorld();
	}
	return nullptr;
}

UGameInstance* UOmegaSaveCondition::GetGameInstance() const
{
	if(WorldPrivate)
	{
		return WorldPrivate->GetWorld()->GetGameInstance();
	}
	return Cast<UGameInstance>(GetOuter());
}
