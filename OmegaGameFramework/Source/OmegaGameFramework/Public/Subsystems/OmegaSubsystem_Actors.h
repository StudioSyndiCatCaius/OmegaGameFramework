// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "Materials/MaterialExpression.h"
#include "MaterialCompiler.h"
#include "Actors/Actor_ActorProcessor.h"
#include "Subsystems/WorldSubsystem.h"
#include "OmegaSubsystem_Actors.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnActorInteraction, AActor*, Instigator, AActor*, Target, FGameplayTag, Tag,UObject*, Context);

USTRUCT()
struct FOmegaActorGroupData
{
	GENERATED_BODY()
	UPROPERTY() TArray<AActor*> Actors;
};

UINTERFACE(MinimalAPI) class UActorInterface_Interactable : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IActorInterface_Interactable
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interaction")
	void OnInteraction(AActor* Instigator, FGameplayTag Tag, UObject* Context);
};


// =======================================================================================================================
// SUBSYSTEM
// =======================================================================================================================


UCLASS(DisplayName="Omega Subsystem: Actor")
class OMEGAGAMEFRAMEWORK_API UOmegaActorSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	
	UPROPERTY() TArray<AOmegaActorProcessor*> active_processors;
	UPROPERTY() TArray<UActorIdentityComponent*> REF_ActorIdComps;
	UPROPERTY() TMap<FGameplayTag, FOmegaActorGroupData> actorGroups;
public:

	void local_RegisterActorIdComp(UActorIdentityComponent* Component, bool bIsRegister);

	UFUNCTION(BlueprintCallable,Category="Actor Identity Subsystem")
	TArray<UActorIdentityComponent*> GetAllActorIdentityComponents();

	UFUNCTION(BlueprintCallable,Category="ActorSubsystem|Processor")
	void RegisterActorToProcessor(AActor* Actor, TSubclassOf<AOmegaActorProcessor> Processor);

	// ---------------------------------------------------------------------------------
	// Interaction
	// ---------------------------------------------------------------------------------
	UPROPERTY(BlueprintAssignable) FOnActorInteraction OnActorInteraction;
	
	UFUNCTION(BlueprintCallable,Category="ActorSubsystem|Interaction")
	void PerformInteraction(AActor* Instigator, AActor* TargetActor, FGameplayTag Tag, UObject* Context);

	// ---------------------------------------------------------------------------------
	// Groups
	// ---------------------------------------------------------------------------------
	UFUNCTION(BlueprintPure,Category="ActorSubsystem|Groups")
	bool IsActorInGroup(FGameplayTag GroupTag, AActor* Actor) const;
	
	UFUNCTION(BlueprintCallable,Category="ActorSubsystem|Groups")
	void SetActorRegisteredToGroup(FGameplayTag GroupTag, AActor* Actor, bool registered);

	UFUNCTION(BlueprintCallable,Category="ActorSubsystem|Groups")
	void SetActorsRegisteredToGroup(FGameplayTag GroupTag, TArray<AActor*> Actors, bool registered);
	
	UFUNCTION(BlueprintCallable,Category="ActorSubsystem|Groups")
	void ClearActorGroup(FGameplayTag GroupTag);
	
	UFUNCTION(BlueprintCallable,Category="ActorSubsystem|Groups")
	TArray<AActor*> GetActorsInGroup(FGameplayTag GroupTag) const;
};