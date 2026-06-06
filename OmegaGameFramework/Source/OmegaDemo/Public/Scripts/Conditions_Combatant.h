// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Component_Combatant.h"
#include "Condition/Condition_Combatant.h"
#include "Conditions_Combatant.generated.h"

class UEquipmentSlot;

UCLASS(DisplayName="(🤜?) Equipment - Check Slots")
class OMEGADEMO_API UOCon_Combatant_EquipSlot : public UOmegaCondition_Combatant
{
	GENERATED_BODY()
public:
	virtual bool CheckCombatantCondition_Implementation(UCombatantComponent* Combatant) const override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") TArray<UEquipmentSlot* > SlotsToCheck;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") TArray<UPrimaryDataAsset*> Accepted_Items;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") TArray<UPrimaryDataAsset*> Rejected_Items;
};

UCLASS(DisplayName="(🤜?) Inventory - Has Items")
class OMEGADEMO_API UOCon_Combatant_InventoryAmount : public UOmegaCondition_Combatant
{
	GENERATED_BODY()
public:
	virtual bool CheckCombatantCondition_Implementation(UCombatantComponent* Combatant) const override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") TMap<UPrimaryDataAsset*, int32> MinimumItems;
};

UCLASS(DisplayName="(🤜?) XP - Level Check")
class OMEGADEMO_API UOCon_Combatant_LevelCheck : public UOmegaCondition_Combatant
{
	GENERATED_BODY()
public:
	virtual bool CheckCombatantCondition_Implementation(UCombatantComponent* Combatant) const override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") UOmegaLevelingAsset* LevelingAsset;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") TEnumAsByte<EOmegaComparisonMethod> Method;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") int32 CheckLevel;
};

UCLASS(DisplayName="(🤜?) Attriubute %")
class OMEGADEMO_API UOCon_Combatant_AttributePercent : public UOmegaCondition_Combatant
{
	GENERATED_BODY()
public:
	virtual bool CheckCombatantCondition_Implementation(UCombatantComponent* Combatant) const override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") UOmegaAttribute* Attribute;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") float Percent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") TEnumAsByte<EOmegaComparisonMethod> Method;
};

UCLASS(DisplayName="(🤜?) Check Tags")
class OMEGADEMO_API UOCon_Combatant_CheckTags : public UOmegaCondition_Combatant
{
	GENERATED_BODY()
public:
	virtual bool CheckCombatantCondition_Implementation(UCombatantComponent* Combatant) const override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") FGameplayTagQuery Combatant_Query;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") FGameplayTagQuery Entity_Query;
};