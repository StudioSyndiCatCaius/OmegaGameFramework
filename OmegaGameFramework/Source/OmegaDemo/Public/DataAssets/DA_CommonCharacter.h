// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DA_CommonRace.h"
#include "FlowAsset.h"
#include "Components/Component_ActorIdentity.h"
#include "Components/Component_Equipment.h"
#include "Components/Component_Inventory.h"
#include "DataAssets/DA_ActorIdentity.h"
#include "DataAssets/DA_Appearance.h"
#include "DataAssets/DA_AssetLib.h"
#include "DataAssets/DA_CombatSource.h"
#include "Functions/OmegaFunctions_ComponentMod.h"
#include "Interfaces/OmegaInterface_Combatant.h"
#include "DA_CommonCharacter.generated.h"

class AOmegaSkin;
class UOmegaFaction;
class UEquipmentSlot;
class UCombatantGambitAsset;
class UOmegaDamageType;
class UOmegaDamageTypeReactionAsset;

UCLASS(DisplayName="Ω Common - Character")
class OMEGADEMO_API UOAsset_CommonCharacter : public UOAsset_CombatantIdentity, public IDataInterface_FlowAsset, public IDataInterface_ContextSlate,
												public IDataInterface_InventorySource, public IDataInterface_EquipmentSource, public IDataInterface_AppearanceSource
																		
{
	GENERATED_BODY()

	void L_Init(AActor* a,bool init);

	UFUNCTION() TArray<FName> opts_attributes() const;
	UFUNCTION() TArray<FName> opts_equipSlot() const;
	
public:
	// Function
	virtual UFlowAsset* GetFlowAsset_Implementation(FGameplayTag Tag) override {return FlowAsset;};
	virtual bool OnIdentityInit_Implementation(AActor* Actor, UActorIdentityComponent* Component) override;
	virtual bool OnIdentityUninit_Implementation(AActor* Actor, UActorIdentityComponent* Component) override;
	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation(UCombatantComponent* Combatant) override;
	virtual TMap<UPrimaryDataAsset*,int32> GetInventory_Implementation() override { return Inventory;};
	//virtual TMap<UEquipmentSlot*,UPrimaryDataAsset*> GetEquipment_Implementation() override { return Equipment;};
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags") bool Autoset_Level=true;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags") bool AutoSet_Combatant=true;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags") bool AutoSet_Equipment=true;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags") bool Autoset_Inventory=true;
	//True=Set inventory as a SourceObject | False=Set 'Inventory' to Component's TMap
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags",AdvancedDisplay) bool Inventory_AsSource=true;
	//True=Set Equipment as a SourceObject | False=Set 'Equipment' to Component's TMap
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags",AdvancedDisplay) bool Equipment_AsSource=true;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character")
	int32 Seed=-1;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Character",meta=(EditCondition="!Appearance_Preset"))
	UOAsset_Appearance* Appearance_Custom;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character")
	UOAsset_Appearance* Appearance_Preset;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Actor")
	UFlowAsset* FlowAsset;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character")
	UOAsset_CommonRace* Race=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character")
	EOmegaGender Gender;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character")
	int32 Level=1;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat",Meta=(GetKeyOptions="opts_attributes"))
	TMap<FName,float> Attribute_Overrides;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat",Meta=(GetKeyOptions="opts_equipSlot"))
	TMap<FName,UPrimaryDataAsset*> Equipment;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat")
	TMap<UPrimaryDataAsset*,int32> Inventory;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat")
	TArray<UPrimaryDataAsset*> Skills;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat")
	UCombatantGambitAsset* Gambit;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat")
	TMap<UOmegaDamageType*,UOmegaDamageTypeReactionAsset*> DamageReactions;
	

	
	UFUNCTION(BlueprintPure,Category="CommonCharacter") UOAsset_Appearance* GetAppearance() const
	{
		if(Appearance_Preset) {return Appearance_Preset;} if(Appearance_Custom) {return Appearance_Custom;} return nullptr;
	};
	UFUNCTION(BlueprintPure,Category="CommonCharacter") UOAsset_CommonRace* GetRace() const;

	virtual UOAsset_Appearance* GetAppearanceAsset_Implementation() override;
};
