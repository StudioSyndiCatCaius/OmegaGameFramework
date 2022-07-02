// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/InstanceActor/InstanceActorComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UInstanceActorComponent::UInstanceActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	InstancedActorClass = AOmegaInstanceActor::StaticClass();
	// ...
}


// Called when the game starts
void UInstanceActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInstanceActorComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

AOmegaInstanceActor* UInstanceActorComponent::CreateInstance(UObject* Context, const FString& Flag, FTransform LocalTransform)
{
	UObject* LocalContext;
	if(!Context)
	{
		LocalContext = nullptr;
	}
	else
	{
		LocalContext = Context;
	}

	AOmegaInstanceActor* LocalActor = GetWorld()->SpawnActorDeferred<AOmegaInstanceActor>(InstancedActorClass, LocalTransform, nullptr);
	LocalActor->ContextObject = LocalContext;
	LocalActor->OwningComponent = this;
	UGameplayStatics::FinishSpawningActor(LocalActor, LocalTransform);
	LocalActor->AttachToActor(GetOwner(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));
	LocalActor->SetActorRelativeTransform(LocalTransform);
	LocalActor->OnInstanceCreated(LocalContext, Flag);

	PrivateInstances.AddUnique(LocalActor);
	
	return LocalActor;
}

AOmegaInstanceActor* UInstanceActorComponent::GetInstanceByIndex(int32 Index)
{
	if(GetInstances().IsValidIndex(Index))
	{
		return GetInstances()[Index];
	}
	else
	{
		return nullptr;
	}
}

AOmegaInstanceActor* UInstanceActorComponent::GetInstanceByContext(UObject* Context)
{
	for(auto* TempInst : GetInstances())
	{
		if(TempInst->ContextObject == Context)
		{
			return TempInst;
		}
	}
	return nullptr;
}

TArray<AOmegaInstanceActor*> UInstanceActorComponent::GetInstances()
{
	TArray<AOmegaInstanceActor*> OutInstances;
	for(auto* TempInst : PrivateInstances)
	{
		if(TempInst)
		{
			OutInstances.Add(TempInst);
		}
	}
	return OutInstances;
}

TArray<AOmegaInstanceActor*> UInstanceActorComponent::GetInstancesOfCategory(FGameplayTag CategoryTag, bool bExclude, bool bExact)
{
	TArray<AOmegaInstanceActor*> OutInstances;
	for(auto* TempInst : GetInstances())
	{
		bool LocalIsValid = false;
		if(bExact)
		{
			LocalIsValid = IGameplayTagsInterface::Execute_GetObjectGameplayCategory(TempInst).MatchesTagExact(CategoryTag); 
		}
		else
		{
			LocalIsValid = IGameplayTagsInterface::Execute_GetObjectGameplayCategory(TempInst).MatchesTag(CategoryTag);
		}

		if(LocalIsValid != bExclude)
		{
			OutInstances.Add(TempInst);
		}
	}
	return OutInstances;
}

TArray<AOmegaInstanceActor*> UInstanceActorComponent::GetInstancesWithGameplayTags(FGameplayTagContainer Tags, bool bExclude,
	bool bExact)
{
	TArray<AOmegaInstanceActor*> OutInstances;
	for(auto* TempInst : GetInstances())
	{
		bool LocalIsValid = false;
		if(bExact)
		{
			LocalIsValid = IGameplayTagsInterface::Execute_GetObjectGameplayTags(TempInst).HasAnyExact(Tags); 
		}
		else
		{
			LocalIsValid = IGameplayTagsInterface::Execute_GetObjectGameplayTags(TempInst).HasAny(Tags);
		}

		if(LocalIsValid != bExclude)
		{
			OutInstances.Add(TempInst);
		}
	}
	return OutInstances;
}

bool UInstanceActorComponent::SwapInstanceIndecies(int32 A, int32 B)
{
	if(GetInstances().IsValidIndex(A) &&GetInstances().IsValidIndex(B))
	{
		PrivateInstances.Swap(A, B);
		return true;
	}
	return false;
}

