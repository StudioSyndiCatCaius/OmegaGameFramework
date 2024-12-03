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
	for(const auto* TempScript : GetAllSubscripts())
	{
		if(TempScript)
		{
			//TempScript->OwnerComp = this;
			TempScript->OnBeginPlay(this);
		}
	}
	GetOwner()->OnActorBeginOverlap.AddDynamic(this, &USubscriptComponent::OnActorBeginOverlap);
	GetOwner()->OnActorEndOverlap.AddDynamic(this, &USubscriptComponent::OnActorEndOverlap);
	GetOwner()->OnActorHit.AddDynamic(this, &USubscriptComponent::OnActorHit);
	Super::BeginPlay();
}

void USubscriptComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	for(const auto* TempScript : GetAllSubscripts())
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
	for(const auto* TempScript : GetAllSubscripts())
	{
		if(TempScript && TempScript->bCanTick)
		{
			TempScript->Tick(DeltaTime,this);
		}
	}
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USubscriptComponent::OnTagEvent_Implementation(FGameplayTag Event)
{
	for(const auto* TempScript : GetAllSubscripts())
	{
		if(TempScript)
		{
			TempScript->OnTagEvent(this,Event);
		}
	}
}

TArray<USubscript*> USubscriptComponent::GetAllSubscripts()
{
	TArray<USubscript*> out;
	for (auto* temp_script : Subscripts)
	{
		if(temp_script) { out.Add(temp_script); }
	}
	for (auto* temp_coll : SubscriptCollections)
	{
		if(temp_coll)
		{
			for (auto* temp_script : temp_coll->Subscripts)
			{
				if(temp_script) { out.Add(temp_script); }
			}
		}
	}
	return out;
}

void USubscriptComponent::OnActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	for(const auto* TempScript : GetAllSubscripts())
	{
		if(TempScript && TempScript->bCanTick)
		{
			TempScript->ActorBeginOverlap(this,OverlappedActor,OtherActor);
		}
	}
}

void USubscriptComponent::OnActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	for(const auto* TempScript : GetAllSubscripts())
	{
		if(TempScript && TempScript->bCanTick)
		{
			TempScript->ActorEndOverlap(this,OverlappedActor,OtherActor);
		}
	}
}

void USubscriptComponent::OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector Vector, const FHitResult& hit)
{
	for(const auto* TempScript : GetAllSubscripts())
	{
		if(TempScript && TempScript->bCanTick)
		{
			TempScript->ActorHit(this,SelfActor,OtherActor,Vector,hit);
		}
	}
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

void USubscriptComponent::SetSubscriptParam_Vector(FName Param, FVector value)
{
	param_data.Add(Param,value);
}

FVector USubscriptComponent::GetSubscriptParam_Vector(FName Param)
{
	if(param_data.Contains(Param)) { return param_data[Param]; }
	return FVector();
}

USubscript::USubscript()
{

}

void USubscript::ActorHit_Implementation(USubscriptComponent* OwningComponent, AActor* SelfActor, AActor* OtherActor, FVector Vector, const FHitResult& hit) const
{
}

void USubscript::ActorEndOverlap_Implementation(USubscriptComponent* OwningComponent, AActor* OverlappedActor, AActor* OtherActor) const
{
}

void USubscript::ActorBeginOverlap_Implementation(USubscriptComponent* OwningComponent, AActor* OverlappedActor, AActor* OtherActor) const
{
}

void USubscript::OnTagEvent_Implementation(USubscriptComponent* OwningComponent, FGameplayTag Event) const
{
	
}

