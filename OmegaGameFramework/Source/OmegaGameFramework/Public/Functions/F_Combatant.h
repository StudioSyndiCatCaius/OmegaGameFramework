// Fill out your copyright notice in the Description page of Project Settings.

// Functions that may commonly be used in relation to the combatant component.

#pragma once

#include "CoreMinimal.h"
#include "F_ScriptedEffects.h"
#include "Misc/GeneralDataObject.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Combatant.generated.h"

class UOmegaAttribute;
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

	UFUNCTION(BlueprintCallable,Category="Omega|Combatant",DisplayName="🤜Combatant - Set Combatant (From Source)")
	static bool CheckCombatantConditions(UCombatantComponent* Combatant, FOmegaConditions_Combatant Conditions);
	//-----------------------------------------------------------------------------------
	// Get
	//-----------------------------------------------------------------------------------
	
	//Checks if the combatant has sufficient attributes to use skill
	UFUNCTION(BlueprintPure, Category="Omega|Attributes",DisplayName="🤜Combatant - Can Combatant Use Skill?")
	static bool CanCombatantUseSkill(UCombatantComponent* Combatant, UObject* SkillObject);
	
	UFUNCTION(BlueprintPure, Category="Omega|Combatant", DisplayName="🤜Combatant - Select Combatant (Highest Attribute Value)")
	static UCombatantComponent* GetCombatantWithHighestAttributeValue(TArray<UCombatantComponent*> Combatants, UOmegaAttribute* Attribute, bool bUseCurrentValue);

	UFUNCTION(BlueprintPure, Category="Omega|Combatant", DisplayName="🤜Combatant - Get Combatants (From Target Selection)")
	static TArray<UCombatantComponent*> GetCombatantFromTargetSelection(UCombatantComponent* Instigator, EOmegaCombatTarget Selection);
	
	//Trys Getting First Combatant With a DataAsset
	UFUNCTION(BlueprintCallable, Category="Omega|Combatant",meta=(WorldContext="WorldContextObject"))
	static TArray<UCombatantComponent*> GetAllCombatantsWithDataAsset(UObject* WorldContextObject, UPrimaryDataAsset* Asset);

	UFUNCTION(BlueprintCallable, Category="Omega|Combatant")
	static TArray<UPrimaryDataAsset*> GetDataAssetsFromCombatants(TArray<UCombatantComponent*> Combatants);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Combatant", meta=(WorldContext="WorldContextObject",ExpandBoolAsExecs = "Outcome"),DisplayName="🤜Combatant - 🔴 Get First Combatant /w Data Asset")
	static UCombatantComponent* GetFirstCombatantWithDataAsset(UObject* WorldContextObject,UPrimaryDataAsset* Asset,  bool& Outcome);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Combatant",meta=(WorldContext="WorldContextObject"))
	static TArray<UCombatantComponent*> GetAllCombatants_OfFaction(UObject* WorldContextObject, UOmegaFaction* Faction);
	
	//-----------------------------------------------------------------------------------
	// Filter
	//-----------------------------------------------------------------------------------
	UFUNCTION(BlueprintPure, Category="Omega|Combatant|Filter",DisplayName="🤜Combatant - Filter (By Tags)")
	static TArray<UCombatantComponent*> FilterCombatantsByTags(TArray<UCombatantComponent*> Combatants, FGameplayTagContainer Tags, bool bExact, bool bExclude);

	UFUNCTION(BlueprintPure, Category="Omega|Combatant|Filter",DisplayName="🤜Combatant - Filter (By Faction)")
	static TArray<UCombatantComponent*> FilterCombatantsByFaction(TArray<UCombatantComponent*> Combatants, UPARAM(meta=(Categories="FACTION")) FGameplayTag Faction, bool bExclude);

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
	UFUNCTION(BlueprintCallable, Category="Combat", meta=(AdvancedDisplay = "Context"),DisplayName="🤜Combatant - Apply Gameplay Effects (from Container)")
	static void ApplyEffectFromContainer(UCombatantComponent* Combatant, UCombatantComponent* Instigator, FOmegaEffectContainer Effect, UObject* Context);

	UFUNCTION(BlueprintPure, Category="Combat", meta = (WorldContext = "WorldContextObject")) 
	static UCombatantComponent* GetPlayerCombatant(const UObject* WorldContextObject, int32 Index);

	//-----------------------------------------------------------------------------------
	// Notify
	//-----------------------------------------------------------------------------------
	
	UFUNCTION(BlueprintCallable, Category="Combat", meta = (WorldContext = "WorldContextObject"),DisplayName="🤜Combatant - Notify All (Of Faction Tag)")
	static void NotifyCombatantFaction(const UObject* WorldContextObject, FGameplayTag Faction, FName Notify);

	UFUNCTION(BlueprintCallable, Category="Combat", meta = (WorldContext = "WorldContextObject"),DisplayName="🤜Combatant - Notify All (Of Faction)")
	static void NotifyCombatant_FactionOfTag(const UObject* WorldContextObject, FGameplayTag Tag, FName Notify);

	//-----------------------------------------------------------------------------------
	// ATTRIBUTES
	//-----------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable, Category="Omega|Attributes",DisplayName="❤️Attribute Mods - Make (From Flat Values)")
	static TArray<FOmegaAttributeModifier> MakeAttributeMods_FromFlatValues(TMap<UOmegaAttribute*, float> FlatAttributes,bool AsMultiplier=false);
	UFUNCTION(BlueprintCallable, Category="Omega|Attributes",DisplayName="❤️Attribute Mods - Make (From Flat Int Values)")
	static TArray<FOmegaAttributeModifier> MakeAttributeMods_FromFlatIntValues(TMap<UOmegaAttribute*, int32> FlatAttributes,bool AsMultiplier=false);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Attributes",DisplayName="❤️Attribute Mods - Scale")
	static TArray<FOmegaAttributeModifier> AttributeMods_Scale(TArray<FOmegaAttributeModifier> In,float Scale=1.0f,bool bIncrements=true,bool bMultipliers=true);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Attributes",DisplayName="❤️Attribute Mods - Flatten")
	static TArray<FOmegaAttributeModifier> AttributeMods_Flatten(TArray<FOmegaAttributeModifier> In);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Attributes",DisplayName="❤️Attributes Mods - Combine")
	static TArray<FOmegaAttributeModifier> AttributeMods_Combine(TArray<FOmegaAttributeModifier> A,TArray<FOmegaAttributeModifier> B,bool Flatten=true);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Attributes",DisplayName="❤️Attributes Mods - Compare Single Modifiers")
	static void CompareSingleAttributeModifiers(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, UObject* ComparedSource, UObject* UncomparedSource, float& NewValue, float& OldValue);

	

	//Consume the amount of attributes required for this skill. Returns FALSE of insufficient.
	UFUNCTION(BlueprintCallable, Category="Omega|Attributes",DisplayName="🤜Combatant - Consume Skill Attirbute Cost")
	static bool ConsumeSkillAttributes(UCombatantComponent* Combatant, UObject* SkillObject);
	
	//-----------------------------------------------------------------------------------
	// Targets
	//-----------------------------------------------------------------------------------

	UFUNCTION(BlueprintPure, Category="Omega|Combat|Targeting",DisplayName="🤜Combatant - Get Distance (Combatant to Active Target)")
	static float GetCombatantDistantToActiveTarget(UCombatantComponent* Combatant);

	UFUNCTION(BlueprintPure, Category="Omega|Combat|Targeting", DisplayName="🤜Combatant - Is Active Target in Range?")
	static bool IsCombatantActiveTargetInRange(UCombatantComponent* Combatant, float Range);

	//-----------------------------------------------------------------------------------
	// Branches
	//-----------------------------------------------------------------------------------
	
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome"),DisplayName="🤜Combatant - 🔴 Is Combatant Of Faction")
	static void IsCombatantOfFaction(UCombatantComponent* Combatant, UOmegaFaction* Faction, bool& Outcome);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(ExpandBoolAsExecs = "Outcome"),DisplayName="🤜Combatant - 🔴 Select First Combatant (/w Data Asset)")
	static UCombatantComponent* SelectFirstCombatantWithDataAsset(TArray<UCombatantComponent*> Combatants,UPrimaryDataAsset* Asset,  bool& Outcome);

	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(ExpandBoolAsExecs = "Outcome"),DisplayName="🤜Combatant - 🔴 Select First Combatant (/w Tag)")
	static UCombatantComponent* SelectFirstCombatant_WithTag(TArray<UCombatantComponent*> Combatants, FGameplayTag Tag, bool& Outcome);
	
	//Checks if the Attribute is at 100%.
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome"),DisplayName="🤜Combatant - 🔴 Does Combatant Have Tag")
	static void DoesCombatantHaveTag(UCombatantComponent* Combatant, FGameplayTag Tag, bool& Outcome);
	
	//Checks if the Attribute is at 100%.
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome"),DisplayName="🤜Combatant - 🔴 Does Combatant Have Effect With Tag")
	static void DoesCombatantHaveEffectWithTag(UCombatantComponent* Combatant, UPARAM(meta=(Categories="EFFECT")) FGameplayTagContainer Tags, bool& Outcome);


};


