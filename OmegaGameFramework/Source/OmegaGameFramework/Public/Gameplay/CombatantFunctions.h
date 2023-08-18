// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatantComponent.h"
#include "OmegaGameplayEffect.h"
#include "OmegaGeneralEnums.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CombatantFunctions.generated.h"

/**
 * 
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API UCombatantFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintPure, Category="Combat")
	static TArray<UCombatantComponent*> FilterCombatantsByTags(TArray<UCombatantComponent*> Combatants, FGameplayTagContainer Tags, bool bExact, bool bExclude);

	UFUNCTION(BlueprintPure, Category="Combat")
	static TArray<UCombatantComponent*> FilterCombatantsByFaction(TArray<UCombatantComponent*> Combatants, FGameplayTag Faction, bool bExclude);

	UFUNCTION(BlueprintPure, Category="Combat")
	static UCombatantComponent* GetCombatantWithHighestAttributeValue(TArray<UCombatantComponent*> Combatants, UOmegaAttribute* Attribute, bool bUseCurrentValue);
	
	//-----------------------------------------------------------------------------------
	// Effects
	//-----------------------------------------------------------------------------------
	
	// Applies an Effect From a Container struct
	UFUNCTION(BlueprintCallable, Category="Combat", meta=(AdvancedDisplay = "Context"))
	static void ApplyEffectFromContainer(UCombatantComponent* Combatant, UCombatantComponent* Instigator, FOmegaEffectContainer Effect, UObject* Context);

	//NOTE: Asset must implement "DataInterface_OmegaEffect".
	UFUNCTION(BlueprintCallable, Category="Combat")
	static void ApplyEffectFromAsset(UCombatantComponent* Combatant, UCombatantComponent* Instigator, UObject* Asset);

	UFUNCTION(BlueprintPure, Category="Combat", meta = (WorldContext = "WorldContextObject")) 
	static UCombatantComponent* GetPlayerCombatant(const UObject* WorldContextObject, int32 Index);

	UFUNCTION(BlueprintCallable, Category="Combat", meta = (WorldContext = "WorldContextObject")) 
	static void NotifyCombatantFaction(const UObject* WorldContextObject, FGameplayTag Faction, FName Notify);

	//Will attempt to get a combatant component, casting the object as a combatant, and actor, or a sibling component.
	

	//-----------------------------------------------------------------------------------
	// ATTRIBUTES
	//-----------------------------------------------------------------------------------
	UFUNCTION(BlueprintPure, Category="Attributes", meta=(CompactNodeTitle="Attribute ID"))
	static UOmegaAttribute* GetAttributeByUniqueID(const FString& ID);

	/*
	UFUNCTION(BlueprintPure, Category="Attributes")
	static TMap<UOmegaAttribute*, float> CompareAttributeModifiers(UCombatantComponent* Combatant, UObject* ComparedModifier, UObject* UncomparedModifer);

	UFUNCTION(BlueprintPure, Category="Attributes")
	static float CompareSingleAttributeModifiers(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, UObject* ComparedModifier, UObject* UncomparedModifer);
	*/
	//-----------------------------------------------------------------------------------
	// Targets
	//-----------------------------------------------------------------------------------

	UFUNCTION(BlueprintPure, Category="Omega|Combat|Targeting")
	static float GetCombatantDistantToActiveTarget(UCombatantComponent* Combatant);

	UFUNCTION(BlueprintPure, Category="Omega|Combat|Targeting")
	static bool IsCombatantActiveTargetInRange(UCombatantComponent* Combatant, float Range);

	//-----------------------------------------------------------------------------------
	// Branches
	//-----------------------------------------------------------------------------------
/*
	//Checks if the Current Attribute Value is at given value
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandEnumAsExecs = "Outcome"))
	static void IsAttributeAtValue(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, float Value, EComparisonMethod Method, TEnumAsByte<EOmegaBranch>& Outcome);

	//Checks if the Current Attribute Value is at a given percentage
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandEnumAsExecs = "Outcome"))
	static void IsAttributeAtPercentage(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, float Percentage, EComparisonMethod Method, TEnumAsByte<EOmegaBranch>& Outcome);
*/
	//Checks if the Attribute is at 100%.
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandEnumAsExecs = "Outcome"))
	static void DoesCombatantHaveTag(UCombatantComponent* Combatant, FGameplayTag Tag, TEnumAsByte<EOmegaBranch>& Outcome);
	
	//Checks if the Attribute is at 100%.
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandEnumAsExecs = "Outcome"))
	static void DoesCombatantHaveEffectWithTag(UCombatantComponent* Combatant, FGameplayTagContainer Tags, TEnumAsByte<EOmegaBranch>& Outcome);
};
