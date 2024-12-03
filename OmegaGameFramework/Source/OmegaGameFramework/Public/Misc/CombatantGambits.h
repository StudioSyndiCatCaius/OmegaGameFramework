// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Components/Component_Combatant.h"
#include "CombatantGambits.generated.h"

USTRUCT(BlueprintType)
struct FCombatantGambit
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gambit")
	float TriggerChance = 1.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gambit", Instanced, DisplayName="TARGET")
	UCombatantGambitTarget* Gambit_TARGET = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gambit", Instanced, DisplayName="IF")
	TArray<UCombatantGambitCondition*> Gambit_IF;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gambit", Instanced, DisplayName="THEN")
	UCombatantGambitAction* Gambit_THEN = nullptr;
	
};

UCLASS(Blueprintable, BlueprintType, EditInlineNew, Const, CollapseCategories,Abstract)
class OMEGAGAMEFRAMEWORK_API UCombatantGambitTarget : public UObject
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintImplementableEvent, Category="Combat|Gambit")
	TArray<UCombatantComponent*> GetTargetList(const UCombatantComponent* Instigator) const;

};


UCLASS(Blueprintable, BlueprintType, EditInlineNew, Const, CollapseCategories,Abstract)
class OMEGAGAMEFRAMEWORK_API UCombatantGambitCondition : public UObject
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintImplementableEvent, Category="Combat|Gambit")
	bool RunGambitCheck(const UCombatantComponent* Combatant) const;

};

UCLASS(Blueprintable, BlueprintType, EditInlineNew, Const, CollapseCategories,Abstract)
class OMEGAGAMEFRAMEWORK_API UCombatantGambitAction : public UObject
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintImplementableEvent, Category="Combat|Gambit")
	void RunGambitAction(const UCombatantComponent* Combatant, TSubclassOf<AOmegaAbility>& AbilityClass, UObject*& AbilityContext) const;

};


UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UCombatantGambitAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UFUNCTION()
	TArray<FCombatantGambit> GetAllGambitActions();
	
	//Gambits played BEFORE gambit actions
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Gambits")
	TArray<UCombatantGambitAsset*> PrecedingGambits;
		
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Gambits")
	TArray<FCombatantGambit> GambitActions;

	//Gambits played AFTER gambit actions
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Gambits")
	TArray<UCombatantGambitAsset*> FollowingGambits;
};

