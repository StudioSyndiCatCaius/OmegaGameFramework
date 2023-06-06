// Fill out your copyright notice in the Description page of Project Settings.


// Sets default values

#include "Gameplay/ActorTagEvent/ActorTagEvent.h"
#include "Components/BillboardComponent.h"

void UActorTagEventFunctions::FireActorTagEvents(TMap<AActor*, FGameplayTag> Events)
{
	TArray<AActor*> TempActorList;
	Events.GetKeys(TempActorList);
	for(AActor* TempActor : TempActorList)
	{
		const FGameplayTag IncomingEvent = Events[TempActor];
		FireTagEventOnActor(TempActor,IncomingEvent);
	}
}

void UActorTagEventFunctions::FireTagEventOnActors(TArray<AActor*> Actors, FGameplayTag Event)
{
	for(auto* TempActor : Actors)
	{
		if(TempActor)
		{
			if(TempActor->GetClass()->ImplementsInterface(UActorTagEventInterface::StaticClass()))
			{
				IActorTagEventInterface::Execute_OnTagEvent(TempActor, Event);
			}
			
			for(UActorComponent* TempComp : TempActor->GetComponents())
			{
				if(TempComp && TempComp->GetClass()->ImplementsInterface(UActorTagEventInterface::StaticClass()))
				{
					IActorTagEventInterface::Execute_OnTagEvent(TempComp, Event);
				}
			}
			
			TArray<AActor*> ChildActorsList;
			TempActor->GetAllChildActors(ChildActorsList);
			for(auto* TempChildActor : ChildActorsList)
			{
				FireTagEventOnActor(TempChildActor,Event);
			}
		}
	}
}

void UActorTagEventFunctions::FireTagEventOnActor(AActor* Actor, FGameplayTag Event)
{
	if(Actor)
	{
		TArray<AActor*> LocalActors;
		LocalActors.Add(Actor);
		FireTagEventOnActors(LocalActors,Event);
	}
}

void UActorTagEventFunctions::FireTagEventsOnActors(TArray<AActor*> Actors, FGameplayTagContainer Events)
{
	TArray<FGameplayTag> TempTagList;
	Events.GetGameplayTagArray(TempTagList);
	
	for(const FGameplayTag TempTag : TempTagList)
	{
		FireTagEventOnActors(Actors,TempTag);
	}
}

void UActorTagEventFunctions::FireTagEventsOnActor(AActor* Actor, FGameplayTagContainer Events)
{
	TArray<FGameplayTag> TempTagList;
	Events.GetGameplayTagArray(TempTagList);
	
	for(const FGameplayTag TempTag : TempTagList)
	{
		FireTagEventOnActor(Actor,TempTag);
	}
}

ATagEventDisperser::ATagEventDisperser()
{
	UBillboardComponent* RootRef = CreateDefaultSubobject<UBillboardComponent>("Root");
}


void ATagEventDisperser::OnTagEvent_Implementation(FGameplayTag Event)
{
	UActorTagEventFunctions::FireTagEventOnActors(TargetActors,Event);
}

void UAnimNotify_TagEvent::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	UActorTagEventFunctions::FireTagEventsOnActor(MeshComp->GetOwner(),Events);
}
