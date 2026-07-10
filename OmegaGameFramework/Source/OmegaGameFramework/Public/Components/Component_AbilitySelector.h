// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component_CombatantExtension.h"
#include "Component_AbilitySelector.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UAbilitySelectorComponent : public UCombatantExtensionComponent
{
	GENERATED_BODY()
	virtual void BeginPlay() override;

	UPROPERTY() float SelectorAccumulator = 0.f;
	UPROPERTY() bool bSelectorAbilityActive = false;
	UPROPERTY() TSubclassOf<AOmegaAbility> SelectorActiveAbilityClass;

public:
	UAbilitySelectorComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Utility")
	TArray<TSubclassOf<AOmegaAbility>> Abilities;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Utility")
	bool bForceGrantAbilities;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Utility")
	bool bSelectorActive;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Utility")
	float SelectFrequency=0.3;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Utility")
	bool bCancelAbilityOnSelectorChange = true;
};
