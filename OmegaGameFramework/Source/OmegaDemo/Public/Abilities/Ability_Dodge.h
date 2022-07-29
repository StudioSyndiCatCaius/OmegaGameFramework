// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaAbility.h"
#include "OmegaGameplayEffect.h"
#include "GameFramework/Actor.h"
#include "Gameplay/DataInterface_OmegaEffect.h"
#include "Ability_Dodge.generated.h"

UCLASS(Abstract)
class OMEGADEMO_API AAbility_Dodge : public AOmegaAbility
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AAbility_Dodge();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Native_AbilityActivated(UObject* Context) override;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintImplementableEvent, Category="Dodge")
	UAnimMontage* GetDodgeMontage();

	UFUNCTION(BlueprintImplementableEvent, Category="Dodge")
	FVector2D GetDodgeInputAxis(bool& SnapRotationToInput);

	//EFFECTS
	UPROPERTY()
	TArray<AOmegaGameplayEffect*> EffectList;
	UPROPERTY(EditDefaultsOnly, Category="Dodge")
	FName DodgeEffectNotify = "DodgeWindow";
	UPROPERTY(EditDefaultsOnly, Category="Dodge")
	TArray<FOmegaEffectContainer> DodgeEffects;
	UPROPERTY(EditDefaultsOnly, Category="Dodge")
	FGameplayTag DodgeEffectCategory;
	UPROPERTY()
	bool bDodgeEffectsActive;
	UFUNCTION(BlueprintCallable, Category="Dodge")
	void SetDodgeEffectsActive(bool EffectsActive);
	
};
