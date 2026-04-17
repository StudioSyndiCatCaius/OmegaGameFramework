// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/I_Skill.h"
#include "Misc/GeneralDataObject.h"
#include "Misc/OmegaUtils_Structs.h"

#include "DA_EntityPreset.generated.h"


class UEquipmentSlot;
class UOmegaLevelingAsset;

UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOmegaEntityPreset : public UOmegaDemoDataAsset, public IDataInterface_SkillSource
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintPure,Category="Omega|Entity")
	FOmegaEntity GetEntityData() const;
	
	UFUNCTION(BlueprintCallable,Category="Omega|Entity")
	void ApplyToCombatant(UCombatantComponent* combatant,bool bEvenIfSaveEntity ) const;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Entity") TMap<UOmegaLevelingAsset*,int32> XpLevels;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Entity") TMap<UEquipmentSlot*,UPrimaryDataAsset*> Equipment;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Entity") TMap<UPrimaryDataAsset*,int32> Inventory;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Entity") TArray<UPrimaryDataAsset*> Skills;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Param") FGameplayTagContainer EntityTags;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Param") TMap<FName,int32> params_int;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Param") TMap<FName,FString> params_string;
	
	//virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;
	//virtual float ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) override;
	//virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation(UCombatantComponent* Combatant) override { return Skills; }; 

};
