#pragma once
#include "Functions/F_ScriptedEffects.h"
#include "Interfaces/I_Combatant.h"
#include "script_CombatantMods.generated.h"

class IDataInterface_Skill;
class UOmegaDamageType;

// ####################################################################################################
// ATTRIBUTE MODS
// ####################################################################################################

UCLASS(DisplayName="♎ C Mod (Attribute) - Increment + Scale")
class OMEGADEMO_API UAttributeMod_AddedMultiplier : public UOmegaScripted_CombatantModifier
{
	GENERATED_BODY()
	
public:
	
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;
	
	// Flat values added to each attribute's modifier (Incrementer).
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Attribute") TMap<UOmegaAttribute*,float> Increment;

	// Multiplier values applied to each attribute's modifier (Multiplier/Scale).
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Attribute") TMap<UOmegaAttribute*,float> Scale;
	
};

// ####################################################################################################
// DAMAGE MODS
// ####################################################################################################

UCLASS(DisplayName="♎ C Mod (Damage) - Scale by Attribute")
class OMEGADEMO_API UDamageMod_ByAttributeScale : public UOmegaScripted_CombatantModifier
{
	GENERATED_BODY()
	
public:
	
	virtual float ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="Mod") TMap<UOmegaAttribute*,float> AttributeScales;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="Mod") bool bIfPositiveDamage=true;
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="Mod") bool bIfNegativeDamage=false;
};


UCLASS(DisplayName="♎ C Mod (Damage) - By Attribute Percent")
class OMEGADEMO_API UDamageMod_ByAttributePercent : public UOmegaScripted_CombatantModifier
{
	GENERATED_BODY()
	
public:
	
	virtual float ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) override;
	
	// The attribute being damaged that this modifier targets.
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="Mod") UOmegaAttribute* DamagedAttribute;

	// The attribute on the target whose current percentage (0–1) is used to scale the incoming damage.
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="Mod") UOmegaAttribute* ModifierAttribute;

	// Controls how strongly the modifier attribute's percentage influences the final damage.
	// 0 = no change (full base damage), 1 = damage fully scaled by the modifier attribute's percentage.
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="Mod") float ModifierScale;
	
};

UCLASS(DisplayName="♎ C Mod (Damage) - Scale by Damage Type")
class OMEGADEMO_API UDamageMod_ScaleByDamageType : public UOmegaScripted_CombatantModifier
{
	GENERATED_BODY()
	
public:
	
	virtual float ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context);
	
	// The attribute being damaged that this modifier targets.
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="Mod") TArray<UOmegaAttribute*> DamagedAttributes;

	// The attribute on the target whose current percentage (0–1) is used to scale the incoming damage.
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="Mod") UOmegaDamageType* Damage_Type;

	// Controls how strongly the modifier attribute's percentage influences the final damage.
	// 0 = no change (full base damage), 1 = damage fully scaled by the modifier attribute's percentage.
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="Mod") float ModifierScale;
	
};

// ####################################################################################################
// SKILL SOURCE
// ####################################################################################################

UCLASS(DisplayName="♎ C Mod (Skills) -  Common")
class OMEGADEMO_API USkillSource_Common : public UOmegaScripted_CombatantModifier
{
	GENERATED_BODY()
	
public:
	
	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation(UCombatantComponent* Combatant) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Skill Source") TArray<TScriptInterface<IDataInterface_Skill>> Skills;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Skill Source") TMap<UPrimaryDataAsset*,int32> SkillsByLevel;
	
};


// ####################################################################################################
// SKILL SOURCE
// ####################################################################################################

UCLASS(DisplayName="♎ C Mod (On Event) - ApplyEffects")
class OMEGADEMO_API UCombMod_EffectsOnEvent : public UOmegaScripted_CombatantModifier
{
	GENERATED_BODY()
	
public:
	
	virtual int32 Combatant_OnEvent_Implementation(UCombatantComponent* Combatant, FGameplayTag Event, FOmegaCombatantEventMeta meta) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effects",meta=(Categories="EVENT.Combat"))
	FGameplayTag event;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effects",meta=(ShowOnlyInnerProperties))
	FOmegaCustomScriptedEffects Effects;
};
