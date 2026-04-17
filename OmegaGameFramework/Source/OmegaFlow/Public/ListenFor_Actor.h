// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Types/Struct_Message.h"
#include "ListenFor_Actor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnListenActor_Interact, AActor*, InteractInstigator, AActor*, Target, FGameplayTag, Tag, FOmegaCommonMeta, Context);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnListenActor_TagTarget, AActor*, Instigator, FGameplayTag, Tag, AActor*, Target, bool, bRegsitered);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListenActor_TagEvent, AActor*, Actor, FGameplayTag, Tag);
// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
// INTERACTION
// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────

UCLASS()
class OMEGAFLOW_API UListenFor_ActorInteraction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable) FOnListenActor_Interact OnInteraction;
	
	UPROPERTY() const UObject* LocalWorldContext;

	UFUNCTION()
	void L_OnEvent(AActor* InteractInstigator, AActor* Target, FGameplayTag Tag, FOmegaCommonMeta Context);
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|ListenFor", meta = (WorldContext = "WorldContextObject"),DisplayName="👂Listen For - Actor Interaction") 
	static UListenFor_ActorInteraction* ListenFor_ActorInteraction(const UObject* WorldContextObject);
	
};

// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
// Tag Target Change
// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
UCLASS()
class OMEGAFLOW_API UListenFor_ActorTagTarget : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable) FOnListenActor_TagTarget OnTargetChange;
	
	UPROPERTY() const UObject* LocalWorldContext;

	UFUNCTION()
	void L_OnEvent(AActor* Instigator, FGameplayTag Tag, AActor* Target, bool bRegsitered);
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|ListenFor", meta = (WorldContext = "WorldContextObject"),DisplayName="👂Listen For - Actor Tag Target Change") 
	static UListenFor_ActorTagTarget* ListenFor_ActorTagTarget(const UObject* WorldContextObject);
	
};

// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
// Tag Event
// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
UCLASS()
class OMEGAFLOW_API UListenFor_ActorTagEvent : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable) FOnListenActor_TagEvent OnTagEvent;
	
	UPROPERTY() const UObject* LocalWorldContext;

	UFUNCTION()
	void L_OnEvent(AActor* Actor, FGameplayTag Tag);
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|ListenFor", meta = (WorldContext = "WorldContextObject"),DisplayName="👂Listen For - Actor Tag Event") 
	static UListenFor_ActorTagEvent* ListenFor_ActorTagEvent(const UObject* WorldContextObject);
};