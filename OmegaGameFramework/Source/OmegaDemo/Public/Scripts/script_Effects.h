// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "Functions/OmegaFunctions_ScriptedEffects.h"
#include "script_Effects.generated.h"


class AOmegaGameplayEffect;
class UOmegaDamageType;
class UOmegaAttribute;

// Applies effects to the intial instigator with the initial target as the new instigator
UCLASS(DisplayName="(Effect) Flip Targets")
class OMEGADEMO_API UEffectScript_FlipTargets : public UOmegaScriptedEffect
{
	GENERATED_BODY()
public:
	virtual bool OnEffectApplied_Implementation(UCombatantComponent* Target, UCombatantComponent* Instigator) override;

	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="Effects")
	TArray<UOmegaScriptedEffect*> Effects;
};

UCLASS(DisplayName="(Effect) Effect Actor - Add")
class OMEGADEMO_API UEffectScript_EffectActorAdd : public UOmegaScriptedEffect
{
	GENERATED_BODY()
public:
	virtual bool OnEffectApplied_Implementation(UCombatantComponent* Target, UCombatantComponent* Instigator) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effects")
	TSubclassOf<AOmegaGameplayEffect> Class;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effects")
	UObject* Context=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effects")
	float Power=1.0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effects")
	FGameplayTagContainer Tags;
	
};

UCLASS(DisplayName="(Effect) Effect Actor - Remove")
class OMEGADEMO_API UEffectScript_EffectActorRemove : public UOmegaScriptedEffect
{
	GENERATED_BODY()
public:
	virtual bool OnEffectApplied_Implementation(UCombatantComponent* Target, UCombatantComponent* Instigator) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effects")
	TArray<TSubclassOf<AOmegaGameplayEffect>> Classes_Removed;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effects")
	FGameplayTagContainer Tags_Removed;
	
};



UCLASS(DisplayName="(Effect) Damage - Flat")
class OMEGADEMO_API UEffectScript_DamageFlat : public UOmegaScriptedEffect
{
	GENERATED_BODY()
public:
	virtual bool OnEffectApplied_Implementation(UCombatantComponent* Target, UCombatantComponent* Instigator) override;
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effect")
	UOmegaAttribute* DamagedAttribute;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effect")
	float Amount;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effect")
	bool bIsPercentage;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effect")
	UOmegaDamageType* DamageType;
};


UCLASS(Abstract)
class OMEGADEMO_API UEffectScriptBASE_DamagePercent : public UOmegaScriptedEffect
{
	GENERATED_BODY()

	virtual bool OnEffectApplied_Implementation(UCombatantComponent* Target, UCombatantComponent* Instigator) override;
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	
public:

	UFUNCTION(BlueprintNativeEvent,Category="Effect")
	void GetEffectParameters(UOmegaAttribute*& _DamagedAttribute,UOmegaDamageType*& _DamageType,float& _Variance,float& _MinDamage,float& _MaxDamage,
		UOmegaAttribute*& _Instigator_Attribute, float& _Instigator_Power, UOmegaAttribute*& _Target_Attribute, float& _Target_Power);
};
	
UCLASS(DisplayName="(Effect) Damage - Attribute Subtraction")
class OMEGADEMO_API UEffectScript_DamagePercent : public UEffectScriptBASE_DamagePercent
{
	GENERATED_BODY()
public:
	virtual void GetEffectParameters_Implementation(UOmegaAttribute*& _DamagedAttribute, UOmegaDamageType*& _DamageType, float& _Variance, float& _MinDamage, float& _MaxDamage, UOmegaAttribute*& _Instigator_Attribute, float& Instigator_Power, UOmegaAttribute*& _Target_Attribute, float& _Target_Power) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effect")
	UOmegaAttribute* DamagedAttribute;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effect")
	UOmegaDamageType* DamageType;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effect")
	float Variance=0.05;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effect")
	float MinDamage=0.0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effect")
	float MaxDamage=99999.0;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effect")
	UOmegaAttribute* Instigator_Attribute;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effect")
	float Instigator_Power=1.0;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effect")
	UOmegaAttribute* Target_Attribute;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effect")
	float Target_Power=0.5;
};

