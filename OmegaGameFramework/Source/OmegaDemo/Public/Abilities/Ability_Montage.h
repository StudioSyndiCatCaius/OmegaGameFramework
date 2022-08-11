// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaAbility.h"
#include "GameFramework/Actor.h"
#include "Ability_Montage.generated.h"

UCLASS(Abstract)
class OMEGADEMO_API AAbility_Montage : public AOmegaAbility
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAbility_Montage();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Native_AbilityActivated(UObject* Context) override;

	UFUNCTION(BlueprintImplementableEvent, Category="Montage")
	UAnimMontage* GetMontage();

	UPROPERTY()
	UAnimInstance* LocalAnimInst;
	
	UFUNCTION()
	void Local_OnMontageEnd(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNotifyBegin(FName Notify);
	UFUNCTION(BlueprintImplementableEvent)
	void OnNotifyEnd(FName Notify);

	UFUNCTION()
	void OnNotifyBeginReceived(FName Notify, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload);
	
	UFUNCTION()
	void OnNotifyEndReceived(FName Notify, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload);
};

