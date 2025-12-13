// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Actor_AdvancedVolume.h"
#include "GameFramework/Actor.h"
#include "OmegaLinearEventSubsystem.h"
#include "Actors/Actor_GameplayCue.h"
#include "Functions/OmegaFunctions_ScriptedTrace.h"
#include "Subsystems/OmegaSubsystem_Save.h"
#include "Actor_EventVolume.generated.h"

class UCombatantComponent;

UCLASS(EditInlineNew,Abstract,BlueprintType,Blueprintable,CollapseCategories,meta=(ShowWorldContextPin))
class OMEGADEMO_API UOmegaEventVolumeTriggerScript : public UObject
{
	GENERATED_BODY()
	
	virtual UWorld* GetWorld() const override
	{
		if(WorldPrivate) { return  WorldPrivate; }
		if(GetGameInstance()) { return GetGameInstance()->GetWorld(); } return nullptr;
	};
	UFUNCTION() virtual UGameInstance* GetGameInstance() const
	{
		if(WorldPrivate) { return WorldPrivate->GetGameInstance();}
		return Cast<UGameInstance>(GetOuter());
	};
	UOmegaEventVolumeTriggerScript(const FObjectInitializer& ObjectInitializer)
	{
		if (const UObject* Owner = GetOuter()) { WorldPrivate = Owner->GetWorld(); }
	};
	UPROPERTY(Transient) UWorld* WorldPrivate = nullptr;
	
public:
	
	UPROPERTY() AOmega_EventVolume* REF_Owner=nullptr;
	UFUNCTION(BlueprintPure,Category="TriggerScript")
	AOmega_EventVolume* GetOwningActor() const { return REF_Owner; };
	
	UFUNCTION(BlueprintCallable,Category="TriggerScript")
	void TriggerEvent() const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="TriggerScript")
	void OnBeginPlay(AOmega_EventVolume* Owner);

	UFUNCTION(BlueprintImplementableEvent,Category="TriggerScript")
	FLinearColor GetVolumeColor() const;
};

UCLASS(EditInlineNew,Abstract,BlueprintType,Blueprintable,CollapseCategories,Const,meta=(ShowWorldContextPin))
class OMEGADEMO_API UOmegaEventVolumeSequenceScript : public UObject
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintPure,Category="SequenceScript")
	AOmega_EventVolume* GetOwningActor() const;

	UFUNCTION(BlueprintImplementableEvent,Category="SequenceScript")
	void OnEventTriggered(const AActor* Owner) const;
	
};


UCLASS(DisplayName="Ω Event Trigger")
class OMEGADEMO_API AOmega_EventVolume : public AAdvancedVolume
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AOmega_EventVolume();
	
	UFUNCTION()
	void Local_TryPlay() const;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Volume")
	UCombatantComponent* Combatant;
	
	// Called every frame
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="EventVolume")
	UOmegaEventVolumeTriggerScript* TriggerScript;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="EventVolume")
	TArray<UOmegaEventVolumeSequenceScript*> Events;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="EventVolume")
	FOmegaSaveConditions Conditions;
	
};


