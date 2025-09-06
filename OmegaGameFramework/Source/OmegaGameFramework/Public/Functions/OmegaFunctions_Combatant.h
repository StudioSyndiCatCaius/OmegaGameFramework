// Fill out your copyright notice in the Description page of Project Settings.

// Functions that may commonly be used in relation to the combatant component.

#pragma once

#include "CoreMinimal.h"
#include "OmegaFunctions_ScriptedEffects.h"
#include "Misc/GeneralDataObject.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaFunctions_Combatant.generated.h"

class UOmegaFaction;
class UOmegaScripted_DamageModifier;
class UCombatantComponent;
class AOmegaGameplayEffect;

UENUM(Blueprintable, BlueprintType)
enum EOmegaCombatTarget
{
	Target_Self					UMETA(DisplayName = "Self"),
	Target_ActiveTarget			UMETA(DisplayName = "Active Target"),
	Target_AllTargets			UMETA(DisplayName = "All Targets"),
};

class UCombatantComponent;

UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UCombatantFilter : public UObject
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintImplementableEvent, Category="CombatantFilter")
	const TArray<UCombatantComponent*> FilterCombatants(UCombatantComponent* Instigator, const TArray<UCombatantComponent*>& Combatants);

};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UCombatantFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="Omega|Combatant",DisplayName="Ω Set Combatant (From Source)")
	static void SetCombatantFromSource(UCombatantComponent* Combatant, UObject* Source);

	UFUNCTION(BlueprintCallable,Category="Omega|Combatant",DisplayName="Ω Set Combatant (From Source)")
	static bool CheckCombatantConditions(UCombatantComponent* Combatant, FOmegaConditions_Combatant Conditions);
	//-----------------------------------------------------------------------------------
	// Get
	//-----------------------------------------------------------------------------------
	
	UFUNCTION(BlueprintPure, Category="Omega|Combatant", DisplayName="Ω Select Combatant (Highest Attribute Value)")
	static UCombatantComponent* GetCombatantWithHighestAttributeValue(TArray<UCombatantComponent*> Combatants, UOmegaAttribute* Attribute, bool bUseCurrentValue);

	UFUNCTION(BlueprintPure, Category="Omega|Combatant", DisplayName="Ω Get Combatants (From Target Selection)")
	static TArray<UCombatantComponent*> GetCombatantFromTargetSelection(UCombatantComponent* Instigator, EOmegaCombatTarget Selection);
	
	//Trys Getting First Combatant With a DataAsset
	UFUNCTION(BlueprintCallable, Category="Omega|Combatant",meta=(WorldContext="WorldContextObject"))
	static TArray<UCombatantComponent*> GetAllCombatantsWithDataAsset(UObject* WorldContextObject, UPrimaryDataAsset* Asset);

	UFUNCTION(BlueprintCallable, Category="Omega|Combatant")
	static TArray<UPrimaryDataAsset*> GetDataAssetsFromCombatants(TArray<UCombatantComponent*> Combatants);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Combatant", meta=(WorldContext="WorldContextObject",ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Get First Combatant /w Data Asset")
	static UCombatantComponent* GetFirstCombatantWithDataAsset(UObject* WorldContextObject,UPrimaryDataAsset* Asset,  bool& Outcome);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Combatant",meta=(WorldContext="WorldContextObject"))
	static TArray<UCombatantComponent*> GetAllCombatants_OfFaction(UObject* WorldContextObject, UOmegaFaction* Faction);
	
	//-----------------------------------------------------------------------------------
	// Filter
	//-----------------------------------------------------------------------------------
	UFUNCTION(BlueprintPure, Category="Omega|Combatant|Filter",DisplayName="Ω Filter Combatant (By Tags)")
	static TArray<UCombatantComponent*> FilterCombatantsByTags(TArray<UCombatantComponent*> Combatants, FGameplayTagContainer Tags, bool bExact, bool bExclude);

	UFUNCTION(BlueprintPure, Category="Omega|Combatant|Filter",DisplayName="Ω Filter Combatant (By Faction)")
	static TArray<UCombatantComponent*> FilterCombatantsByFaction(TArray<UCombatantComponent*> Combatants, FGameplayTag Faction, bool bExclude);

	//-----------------------------------------------------------------------------------
	// Effects
	//-----------------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable, Category="Combat",meta=(DeterminesOutputType="EffectClass", ExpandBoolAsExecs="Result"))
	static AOmegaGameplayEffect* SelectFirstEffectWithContext(TArray<AOmegaGameplayEffect*> Effects, UObject* Context, bool& Result);

	UFUNCTION(BlueprintCallable, Category="Combat")
	static void RemoveGameplayEffects_WithContext(UCombatantComponent* Combatant, UObject* Context);
	
	UFUNCTION(BlueprintCallable, Category="Combat")
	static void RemoveGameplayEffects_OfClass(UCombatantComponent* Combatant, TSubclassOf<AOmegaGameplayEffect> EffectClass, bool bIncludeChildTypes);
	
	// Applies an Effect From a Container struct
	UFUNCTION(BlueprintCallable, Category="Combat", meta=(AdvancedDisplay = "Context"),DisplayName="Ω Apply Gameplay Effects (from Container)")
	static void ApplyEffectFromContainer(UCombatantComponent* Combatant, UCombatantComponent* Instigator, FOmegaEffectContainer Effect, UObject* Context);

	UFUNCTION(BlueprintPure, Category="Combat", meta = (WorldContext = "WorldContextObject")) 
	static UCombatantComponent* GetPlayerCombatant(const UObject* WorldContextObject, int32 Index);

	//-----------------------------------------------------------------------------------
	// Notify
	//-----------------------------------------------------------------------------------
	
	UFUNCTION(BlueprintCallable, Category="Combat", meta = (WorldContext = "WorldContextObject"),DisplayName="Ω Notify All Combatants (Of Faction Tag)")
	static void NotifyCombatantFaction(const UObject* WorldContextObject, FGameplayTag Faction, FName Notify);

	UFUNCTION(BlueprintCallable, Category="Combat", meta = (WorldContext = "WorldContextObject"),DisplayName="Ω Notify All Combatants (Of Faction)")
	static void NotifyCombatant_FactionOfTag(const UObject* WorldContextObject, FGameplayTag Tag, FName Notify);

	//-----------------------------------------------------------------------------------
	// ATTRIBUTES
	//-----------------------------------------------------------------------------------
	UFUNCTION(BlueprintPure, Category="Omega|Attributes", meta=(CompactNodeTitle="Attribute ID"))
	static UOmegaAttribute* GetAttributeByUniqueID(const FString& ID);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Attributes")
	static TArray<FOmegaAttributeModifier> MakeAttributeMods_FromFlatValues(TMap<UOmegaAttribute*, float> FlatAttributes,bool AsMultiplier=false);
	UFUNCTION(BlueprintCallable, Category="Omega|Attributes")
	static TArray<FOmegaAttributeModifier> MakeAttributeMods_FromFlatIntValues(TMap<UOmegaAttribute*, int32> FlatAttributes,bool AsMultiplier=false);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Attributes",DisplayName="Ω Compare Attribute Modifiers (Single)")
	static void CompareSingleAttributeModifiers(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, UObject* ComparedSource, UObject* UncomparedSource, float& NewValue, float& OldValue);

	//Checks if the combatant has sufficient attributes to use skill
	UFUNCTION(BlueprintPure, Category="Omega|Attributes",DisplayName="Ω Can Combatant Use Skill?")
	static bool CanCombatantUseSkill(UCombatantComponent* Combatant, UObject* SkillObject);
	//Consume the amount of attributes required for this skill. Returns FALSE of insufficient.
	UFUNCTION(BlueprintCallable, Category="Omega|Attributes",DisplayName="Ω Consume Skill Attirbute Cost")
	static bool ConsumeSkillAttributes(UCombatantComponent* Combatant, UObject* SkillObject);


	
	//-----------------------------------------------------------------------------------
	// Targets
	//-----------------------------------------------------------------------------------

	UFUNCTION(BlueprintPure, Category="Omega|Combat|Targeting",DisplayName="Ω Get Distance (Combatant to Active Target)")
	static float GetCombatantDistantToActiveTarget(UCombatantComponent* Combatant);

	UFUNCTION(BlueprintPure, Category="Omega|Combat|Targeting", DisplayName="Ω Is Active Target in Range?")
	static bool IsCombatantActiveTargetInRange(UCombatantComponent* Combatant, float Range);

	//-----------------------------------------------------------------------------------
	// Branches
	//-----------------------------------------------------------------------------------
	
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Is Combatant Of Faction")
	static void IsCombatantOfFaction(UCombatantComponent* Combatant, UOmegaFaction* Faction, bool& Outcome);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Select First Combatant (/w Data Asset)")
	static UCombatantComponent* SelectFirstCombatantWithDataAsset(TArray<UCombatantComponent*> Combatants,UPrimaryDataAsset* Asset,  bool& Outcome);

	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Select First Combatant (/w Tag)")
	static UCombatantComponent* SelectFirstCombatant_WithTag(TArray<UCombatantComponent*> Combatants, FGameplayTag Tag, bool& Outcome);
	
	//Checks if the Attribute is at 100%.
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Does Combatant Have Tag")
	static void DoesCombatantHaveTag(UCombatantComponent* Combatant, FGameplayTag Tag, bool& Outcome);
	
	//Checks if the Attribute is at 100%.
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Does Combatant Have Effect With Tag")
	static void DoesCombatantHaveEffectWithTag(UCombatantComponent* Combatant, FGameplayTagContainer Tags, bool& Outcome);


};


