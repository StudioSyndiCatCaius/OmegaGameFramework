// Fill out your copyright notice in the Description page of Project Settings.

// Functions that may commonly be used in relation to the combatant component.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/Component_Combatant.h"
#include "Misc/GeneralDataObject.h"
#include "OmegaFunctions_CombatantFilter.generated.h"

// ================================================================================================================
// COMBATANT FILTER
// ================================================================================================================

UCLASS(Blueprintable,BlueprintType,EditInlineNew,Abstract,Const,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UCombatantFilterScript : public UObject
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintImplementableEvent, Category="CombatantFilter")
	const TArray<UCombatantComponent*> FilterCombatants(UCombatantComponent* Instigator, const TArray<UCombatantComponent*>& CombatantsIn) const;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UCombatantFilterCollection : public UOmegaDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced, Category="Filter")
	TArray<UCombatantFilterScript*> FilterScripts;

};

USTRUCT(Blueprintable,BlueprintType)
struct FCombatantFilterData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Filter")
	TArray<UCombatantFilterCollection*> FilterCollections;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced, Category="Filter")
	TArray<UCombatantFilterScript*> FilterScripts;
};

UINTERFACE(MinimalAPI) class UDataInterface_CombatantFilter : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_CombatantFilter
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Combatant")
	FCombatantFilterData GetSkillTargetFilterData();
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UCombatantFilterFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable,Category="Omega|Combatant|Filter")
	static TArray<UCombatantComponent*> FilterCombatants_ByScript(UCombatantComponent* Instigator, TArray<UCombatantComponent*> CombatantsIn, FCombatantFilterData Filter);

	UFUNCTION(BlueprintCallable,Category="Omega|Combatant|Filter")
	static TArray<UCombatantComponent*> FilterCombatants_ByAsset(UCombatantComponent* Instigator, TArray<UCombatantComponent*> CombatantsIn, UObject* FilterAsset);
	
};