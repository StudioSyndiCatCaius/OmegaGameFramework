// Fill out your copyright notice in the Description page of Project Settings.

// Functions that may commonly be used in relation to the combatant component.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/GeneralDataObject.h"
#include "OmegaFunctions_CombatantFilter.generated.h"

class UCombatantComponent;

// ================================================================================================================
// COMBATANT FILTER
// ================================================================================================================

UCLASS(Blueprintable,BlueprintType,EditInlineNew,Abstract,Const,meta=(ShowWorldContextPin),CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UCombatantFilterScript : public UObject
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintNativeEvent, Category="CombatantFilter")
	const TArray<UCombatantComponent*> FilterCombatants(UCombatantComponent* Instigator, const TArray<UCombatantComponent*>& CombatantsIn) const;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UCombatantFilterCollection : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable,Category="Combatant|Filter") 
	TArray<UCombatantComponent*> FilterCombatants(UCombatantComponent* Instigator, TArray<UCombatantComponent*> In);

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced, Category="Filter")
	TArray<UCombatantFilterScript*> FilterScripts;

};

USTRUCT(Blueprintable,BlueprintType)
struct FCombatantFilterData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Filter",DisplayName="🎯Filter (Presets)")
	TArray<UCombatantFilterCollection*> FilterCollections;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced, Category="Filter",DisplayName="🎯Filter (Inline)")
	TArray<UCombatantFilterScript*> FilterScripts;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UCombatantFilterFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable,Category="Omega|Combatant|Filter")
	static TArray<UCombatantComponent*> FilterCombatants_ByScript(UCombatantComponent* Instigator, TArray<UCombatantComponent*> CombatantsIn, FCombatantFilterData Filter);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Combatant|Filter",meta=(ExpandBoolAsExecs="Outcome"))
	static UPrimaryDataAsset* SelectFirstSkillThatCanTarget(UCombatantComponent* Instigator, TArray<UPrimaryDataAsset*> Skills, UCombatantComponent* Target, bool& Outcome);

	
};