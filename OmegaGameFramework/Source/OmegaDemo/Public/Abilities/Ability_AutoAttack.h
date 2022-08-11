// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaAbility.h"

#include "GameFramework/Actor.h"
#include "Gameplay/DataInterface_OmegaEffect.h"
#include "Ability_AutoAttack.generated.h"

UCLASS(Abstract)
class OMEGADEMO_API AAbility_AutoAttack : public AOmegaAbility, public IDataInterface_OmegaEffect
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAbility_AutoAttack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Native_AbilityActivated(UObject* Context) override;
	virtual void Native_AbilityFinished(bool Cancelled) override;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, Category="AutoAttack")
	TArray<UAnimMontage*> GetAttackMontages();

	UFUNCTION(BlueprintImplementableEvent, Category="AutoAttack")
	float GetAttackRange();
	
	UFUNCTION(BlueprintImplementableEvent, Category="AutoAttack")
	float GetAttackCooldownTime();

	UPROPERTY(EditDefaultsOnly, Category="AutoAttack")
	FName ImpactNotifyName = "Impact";

	UPROPERTY()
	UAnimInstance* LocalAnimInst;
	UPROPERTY()
	int32 CurrentAttackIndex = -1;
	
	UPROPERTY()
	float AttackChargeAmount;
	UFUNCTION()
	void Local_OnNotify(FName Notify, const FBranchingPointNotifyPayload& DumPayload);
	UFUNCTION()
	void Local_OnAttackEnd(UAnimMontage* Montage, bool bInterrupted);
	UFUNCTION()
	UAnimMontage* GetNextAttackMontage();
};
