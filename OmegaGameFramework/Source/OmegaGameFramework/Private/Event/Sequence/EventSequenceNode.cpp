// Fill out your copyright notice in the Description page of Project Settings.


#include "Event/Sequence/EventSequenceNode.h"
#include "OmegaGameplaySubsystem.h"

UEventSequenceNode::UEventSequenceNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	if (const UObject* Owner = GetOuter())
	{
		WorldPrivate = Owner->GetWorld();
	}
}

UWorld* UEventSequenceNode::GetWorld() const
{
	if(GetOuter()->GetClass()==UOmegaGameplaySubsystem::StaticClass())
	{
		return Cast<UOmegaGameplaySubsystem>(GetOuter())->GetWorld();
	}
	return nullptr;
}

void UEventSequenceNode::FinishEvent()
{
	
}
