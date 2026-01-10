// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Subsystems/WorldSubsystem.h"
#include "Subsystem_Actors.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnActorInteraction, AActor*, InteractInstigator, AActor*, Target, FGameplayTag, Tag,FOmegaCommonMeta, Context);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnActorTaggedTargetChange, AActor*, Instigator, FGameplayTag, Tag, AActor*, Target, bool, regsitered);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnActorGroupChange, AActor*, Actor, FGameplayTag, Tag, bool, regsitered);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorTagEvent, AActor*, Actor, FGameplayTag, Tag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FActorIdentityDelegateRegister, AActor*, Actor, UActorIdentityComponent*, Component, bool, Registered);

USTRUCT()
struct FOmegaActorGroupData
{
	GENERATED_BODY()
	UPROPERTY() TArray<AActor*> Actors;
};

UINTERFACE() class UActorInterface_Interactable : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IActorInterface_Interactable
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interaction")
	void OnInteraction(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interaction")
	bool IsInteractionBlocked(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interaction")
	int32 GetInteraction_BitFlags();
};



// =======================================================================================================================
// SUBSYSTEM
// =======================================================================================================================


UCLASS(DisplayName="Omega Subsystem: Actor")
class OMEGAGAMEFRAMEWORK_API UOmegaActorSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	
	UPROPERTY() TArray<UActorIdentityComponent*> REF_ActorIdComps;
	UPROPERTY() TMap<FGameplayTag, FOmegaActorGroupData> actorGroups;
	UPROPERTY() TMap<AActor*, FOmegaActorMeta> actors_meta;
public:
	TMap<FName,FString>& GetA_PMap(AActor* a);
	FString GetAParam_string(AActor* a, FName key, FString def);
	float GetAParam_float(AActor* a, FName key, float def);
	int32 GetAParam_int(AActor* a, FName key, int32 def);
	bool GetAParam_bool(AActor* a, FName key, bool def);
	void SetAParam_string(AActor* a, FName key, FString def);
	void SetAParam_float(AActor* a, FName key, float def);
	void SetAParam_int(AActor* a, FName key, int32 def);
	void SetAParam_bool(AActor* a, FName key, bool def);
	
	UPROPERTY(BlueprintAssignable) FOnActorInteraction OnActorInteraction;
	UPROPERTY(BlueprintAssignable) FOnActorTaggedTargetChange OnActorTaggedTargetChange;
	UPROPERTY(BlueprintAssignable) FOnActorTagEvent OnActorTagEvent;
	UPROPERTY(BlueprintAssignable) FOnActorGroupChange OnActorGroupChange;
	
	UPROPERTY(BlueprintAssignable) FActorIdentityDelegateRegister OnActorIdentityRegistered;
	
	void local_RegisterActorIdComp(UActorIdentityComponent* Component, bool bIsRegister);

	UFUNCTION(BlueprintCallable,Category="Actor Identity Subsystem")
	TArray<UActorIdentityComponent*> GetAllActorIdentityComponents();

	UFUNCTION(BlueprintCallable,Category="Actor Identity Subsystem")
	AActor* GetFirstActorIfIdentity(UPrimaryDataAsset* Identity,TSubclassOf<AActor> FilterClass=nullptr);

	// ---------------------------------------------------------------------------------
	// Interaction
	// ---------------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable,Category="ActorSubsystem|Interaction")
	bool CanInteract(AActor* Instigator, AActor* TargetActor, FGameplayTag Tag, FOmegaCommonMeta Context);
	
	UFUNCTION(BlueprintCallable,Category="ActorSubsystem|Interaction")
	void PerformInteraction(AActor* Instigator, AActor* TargetActor, FGameplayTag Tag, FOmegaCommonMeta Context);

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

	// ---------------------------------------------------------------------------------
	// Actor Meta
	// ---------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable,Category="ActorSubsystem|Groups")
	void SetActorTaggedTarget(AActor* Instigator, FGameplayTag Tag, AActor* Target=nullptr);
	UFUNCTION(BlueprintPure,Category="ActorSubsystem|Groups")
	AActor* GetActorTaggedTarget(AActor* Instigator, FGameplayTag Tag);

};