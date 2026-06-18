// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DataAssets/DA_Attribute.h"
#include "Types/Struct_Combatant.h"
#include "I_Combatant.generated.h"

class UOmegaDamageType;
class UCombatantComponent;
class UCombatantFilter;


USTRUCT(BlueprintType)
struct FOmegaCombatantSourceConfig
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Combatant") bool bUseDamageModifier;
};

USTRUCT(BlueprintType)
struct FOmegaScripted_CombatantModifiers
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="Combatant")
	TArray<UOmegaScripted_CombatantModifier*> Modifiers;

	TArray<FOmegaAttributeModifier> GatherAttributeModifiers(UCombatantComponent* CombatantComponent) const;
	float ApplyDamageMod(UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context);
};




UINTERFACE(DisplayName="♎Data🔴 - Combatant") class UDataInterface_Combatant : public UInterface
{
	GENERATED_BODY()
public:
	static TArray<FOmegaAttributeModifier> GetObjectModifiers(UCombatantComponent* Combatant, UObject* object);
};
class OMEGAGAMEFRAMEWORK_API IDataInterface_Combatant
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="♎I|💪Combatant",DisplayName="💪Combatant - Get Config")
	FOmegaCombatantSourceConfig Combatant_GetConfig();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="♎I|💪Combatant",DisplayName="💪Combatant - Scripted Modifiers")
	FOmegaScripted_CombatantModifiers Combatant_GetScriptedModifiers();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="♎I|💪Combatant",DisplayName="💪Combatant - Modify Attirbutes")
	TArray<FOmegaAttributeModifier> GetModifierValues(UCombatantComponent* CombatantComponent);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="♎I|💪Combatant",DisplayName="💪Combatant - Modify Damage")
	float ModifyDamage(UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, 
		UObject* Context);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="♎I|💪Combatant",DisplayName="💪Combatant - Get Skills")
	TArray<UPrimaryDataAsset*> GetSkills(UCombatantComponent* Combatant);
	
	UFUNCTION(BlueprintNativeEvent, Category="♎I|💪Combatant",DisplayName="💪Combatant - On Event")
	int32 Combatant_OnEvent(UCombatantComponent* Combatant, FGameplayTag Event, FOmegaCombatantEventMeta meta);
	
	UFUNCTION(BlueprintNativeEvent, Category="♎I|💪Combatant",DisplayName="💪Combatant - Damage Type Weight")
    UPrimaryDataAsset* GetDamageType_Weight(UCombatantComponent* Combatant, UOmegaDamageType* DamageType, float& weight, int32& priority);

	UFUNCTION(BlueprintNativeEvent, Category="♎I|💪Combatant",DisplayName="💪Combatant - Modify Dynamic (Scalar)")
	float Combatant_ModDynamicScalar(UCombatantComponent* Combatant, FGameplayTag Tag, UObject* Context, int32& priority,bool bValidConsider);
	
	UFUNCTION(BlueprintNativeEvent, Category="♎I|💪Combatant",DisplayName="💪Combatant - Modify Dynamic (Asset)")
	UPrimaryDataAsset* Combatant_ModDynamicAsset(UCombatantComponent* Combatant, FGameplayTag Tag, UObject* Context, int32& priority,bool bValidConsider);
};


UCLASS(Blueprintable,BlueprintType,EditInlineNew,CollapseCategories,Const,Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaScripted_CombatantModifier : public UObject, public IDataInterface_Combatant
{
	GENERATED_BODY()

public:

	
};




UCLASS(EditInlineNew, Blueprintable, BlueprintType, CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UAttributeModifierContainer : public UObject, public IDataInterface_Combatant
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attribute") UOmegaAttribute* Attribute = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attribute") float IncValue = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attribute") float MultiValue = 0.f;
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;
};




