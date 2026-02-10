// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Condition/Condition_Actor.h"
#include "Functions/F_Component.h"
#include "Types/Struct_RandomRange.h"
#include "Component_ActorConfig.generated.h"

// =======================================================================================================================
// COMPONENT
// =======================================================================================================================


UCLASS(Blueprintable,BlueprintType,Const,EditInlineNew,Abstract,meta=(ShowWorldContextPin),HideCategories="Navigation, Cooking, Activation, AssetUserData, Asset User Data")
class OMEGAGAMEFRAMEWORK_API UOmegaActorConfigScript : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent,Category="ActorConfig")
	void OnActorConfigured(AActor* Actor) const;
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaActorConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actors")
	TArray<FGameplayTag> AutoregisterToGroups;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Actors")
	TArray<UOmegaActorConfigScript*> Scripts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actors")
	FOmegaRandomRangeFloat BeginPlayMod_Delay;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Actors")
	TArray<UActorModifierScript*> BeginPlay_Modifiers;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable")
	FOmegaConditions_Actor CanInteract_Target;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable")
	FOmegaConditions_Actor CanInteract_Instigator;
};

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UActorConfigComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY() FTimerHandle timer_modDelay;
	UFUNCTION() void L_TimerEnd();
	virtual UOmegaActorConfig* L_GetConfig();
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere,Category="Config")
	UOmegaActorConfig* DefaultConfig;

	UFUNCTION(BlueprintCallable,Category="Config")
	void SetConfig(UOmegaActorConfig* Config);
};
