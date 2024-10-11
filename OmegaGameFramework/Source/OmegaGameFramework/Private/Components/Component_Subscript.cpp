// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_Subscript.h"


void USubscript::OnBeginPlay_Implementation(USubscriptComponent* OwningComponent) const
{
}

void USubscript::OnEndPlay_Implementation(USubscriptComponent* OwningComponent) const
{
}

void USubscript::Tick_Implementation(float Delta,USubscriptComponent* OwningComponent) const
{
}

USubscriptComponent::USubscriptComponent()
{
	PrimaryComponentTick.bCanEverTick=true;
	UActorComponent::SetComponentTickEnabled(true);
	UActorComponent::SetAutoActivate(true);
}

void USubscriptComponent::BeginPlay()
{
	PrimaryComponentTick.bCanEverTick=true;
	SetComponentTickEnabled(true);
	RegisterComponent();
	for(const auto* TempScript : Subscripts)
	{
		if(TempScript)
		{
			//TempScript->OwnerComp = this;
			TempScript->OnBeginPlay(this);
		}
	}
	Super::BeginPlay();
}

void USubscriptComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	for(const auto* TempScript : Subscripts)
	{
		if(TempScript)
		{
			TempScript->OnEndPlay(this);
		}
	}
	Super::EndPlay(EndPlayReason);
}



void USubscriptComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction)
{
	for(const auto* TempScript : Subscripts)
	{
		if(TempScript)
		{
			TempScript->Tick(DeltaTime,this);
		}
	}
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USubscriptComponent::SetSubscriptParam_Float(FName Param, float value)
{
	param_data.Add(Param,FVector(value,0,0));
}

float USubscriptComponent::GetSubscriptParam_Float(FName Param)
{
	if(param_data.Contains(Param)) { return param_data.Find(Param)->X; }
	return 0.0;
}

void USubscriptComponent::SetSubscriptParam_Int32(FName Param, int32 value)
{
	param_data.Add(Param,FVector(value,0,0));
}

int32 USubscriptComponent::GetSubscriptParam_Int32(FName Param)
{
	if(param_data.Contains(Param)) { return param_data.Find(Param)->X; }
	return 0;
}

void USubscriptComponent::SetSubscriptParam_Bool(FName Param, bool value)
{
	param_data.Add(Param,FVector(value,0,0));
}

bool USubscriptComponent::GetSubscriptParam_Bool(FName Param)
{
	if(param_data.Contains(Param)) { return static_cast<bool>(param_data.Find(Param)->X); }
	return false;
}

USubscript::USubscript()
{

}

