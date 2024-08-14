// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_Subscript.h"


void USubscript::OnBeginPlay_Implementation() const
{
}

void USubscript::OnEndPlay_Implementation() const
{
}

void USubscript::Tick_Implementation(float Delta) const
{
}

void USubscriptComponent::BeginPlay()
{
	Super::BeginPlay();
	for(const auto* TempScript : Subscripts)
	{
		if(TempScript)
		{
			//TempScript->OwnerComp = this;
			TempScript->OnBeginPlay();
		}
	}
}

void USubscriptComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	for(const auto* TempScript : Subscripts)
	{
		if(TempScript)
		{
			TempScript->OnEndPlay();
		}
	}
}

void USubscriptComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	for(const auto* TempScript : Subscripts)
	{
		if(TempScript)
		{
			TempScript->Tick(DeltaTime);
		}
	}
}

USubscript::USubscript()
{
	if(Cast<USubscriptComponent>(this->GetOuter()))
	{
		OwnerComp = Cast<USubscriptComponent>(this->GetOuter());
	}
}

AActor* USubscript::GetOwningActor() const
{
	if(GetOwningComponent()->GetOwner())
	{
		return GetOwningComponent()->GetOwner();
	}
	return nullptr;
}

USubscriptComponent* USubscript::GetOwningComponent() const
{
	return OwnerComp;
}
