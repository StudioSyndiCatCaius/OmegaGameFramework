// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once
#include "Actor_EventVolume.h"
#include "Functions/F_Component.h"

#include "script_EventTrigger.generated.h"


class UFlowAsset;
// ====================================================================================================
// 
// ====================================================================================================
UCLASS(DisplayName="(🕹️Trigger) Actor Overlap")
class OMEGADEMO_API UEventTrigger_ActorOverlap : public UOmegaEventVolumeTriggerScript
{
	GENERATED_BODY()
public:

	
	UFUNCTION()
	void Local_OnOverlap(AActor* OverlappedActor, AActor* OtherActor);
	virtual void OnBeginPlay_Implementation(AOmega_EventVolume* Owner) override;
	virtual FLinearColor GetVolumeColor_Implementation() const override { return FLinearColor(0,0.7,1,1); };
	
	UPROPERTY(EditAnywhere,Category="Trigger") TArray<TSubclassOf<AActor>> Allowed_Classes;
	UPROPERTY(EditAnywhere,Category="Trigger") TArray<TSubclassOf<AController>> Allowed_Controllers;
	
};

UCLASS(DisplayName="(🕹️Trigger) Timer")
class OMEGADEMO_API UEventTrigger_Timer : public UOmegaEventVolumeTriggerScript
{
	GENERATED_BODY()
public:
	
	FTimerHandle TimerHandle;

	void Local_TimerFinish();
	virtual void OnBeginPlay_Implementation(AOmega_EventVolume* Owner) override;
	virtual FLinearColor GetVolumeColor_Implementation() const override { return FLinearColor(0,1,0.2,1); };
	UPROPERTY(EditAnywhere,Category="Trigger") float Time=1.0;
};



// ====================================================================================================
// 
// ====================================================================================================
UCLASS(DisplayName="(🚀Event) Modify Actor")
class OMEGADEMO_API UEventScript_ActorModify : public UOmegaEventVolumeSequenceScript
{
	GENERATED_BODY()
public:
	
	virtual void OnEventTriggered_Implementation(AActor* Owner) const override;
	
	UPROPERTY(EditAnywhere,Category="Trigger") FActorModifiers Modifiers;
};

UCLASS(DisplayName="(🚀Event) Play Flow")
class OMEGADEMO_API UEventScript_PlayFlow : public UOmegaEventVolumeSequenceScript
{
	GENERATED_BODY()
public:
	
	virtual void OnEventTriggered_Implementation(AActor* Owner) const override;
	
	UPROPERTY(EditAnywhere,Category="Trigger") UFlowAsset* FlowAsset;
	UPROPERTY(EditAnywhere,Category="Trigger") bool UseFlowSystem=true;
};

UCLASS(DisplayName="(🚀Event) Set Lifetime")
class OMEGADEMO_API UEventScript_SetLifetime : public UOmegaEventVolumeSequenceScript
{
	GENERATED_BODY()
public:
	
	virtual void OnEventTriggered_Implementation(AActor* Owner) const override;
	
	UPROPERTY(EditAnywhere,Category="Trigger") float NewLifetime=0.1;
};