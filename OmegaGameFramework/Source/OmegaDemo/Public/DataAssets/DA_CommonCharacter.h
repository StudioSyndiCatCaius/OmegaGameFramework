// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DA_CommonRace.h"
#include "FlowAsset.h"
#include "Actors/Actor_Character.h"
#include "Components/Component_GameplayActor.h"
#include "Functions/F_Equipment.h"
#include "Components/Component_Inventory.h"
#include "DataAssets/DA_ActorIdentity.h"
#include "DataAssets/DA_Appearance.h"
#include "DataAssets/DA_AssetLib.h"
#include "Functions/F_Assets.h"
#include "Functions/F_Component.h"
#include "Interfaces/I_Combatant.h"
#include "DA_CommonCharacter.generated.h"

class IDataInterface_Skill;
class AOmegaSkin;
class UOmegaFaction;
class UEquipmentSlot;
class UOmegaGambit_Asset;
class UOmegaDamageType;
class UOmegaDamageTypeReactionAsset;

UCLASS(DisplayName="♎Demo - Character (Common)")
class OMEGADEMO_API UOAsset_CommonCharacter : public UOmegaDemoDataAsset, public IDataInterface_FlowAsset, public IDataInterface_Character,
												public IDataInterface_InventorySource, public IDataInterface_EquipmentSource, public IDataInterface_AppearanceSource,
												public IDataInterface_Combatant, public IDataInterface_ActorIdentitySource, public IDataInterface_MessageInstigator
																		
{
	GENERATED_BODY()

	void L_Init(AActor* a,bool init);

	UFUNCTION() TArray<FName> opts_attributes() const;
	UFUNCTION() TArray<FName> opts_equipSlot() const;
	UFUNCTION() TArray<FName> opts_xp() const;
	
public:
	// Function
	virtual UFlowAsset* GetFlowAsset_Implementation(FGameplayTag Tag) override {return FlowAsset;};
	virtual bool OnIdentityInit_Implementation(AActor* Actor, UGameplayActorComponent* Component) override;
	virtual bool OnIdentityUninit_Implementation(AActor* Actor, UGameplayActorComponent* Component) override;

	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation(UCombatantComponent* Combatant) override;
	
	virtual TMap<UPrimaryDataAsset*,int32> GetInventory_Implementation() override;
	virtual TMap<UEquipmentSlot*,UPrimaryDataAsset*> GetEquipment_Implementation() override;

	UFUNCTION(BlueprintCallable,Category="CommonCharacter")
	void ApplyInitialsToCombatant(UCombatantComponent* Combatant);
	
	UFUNCTION(BlueprintPure,Category="CommonCharacter")
	TMap<UEquipmentSlot*,UPrimaryDataAsset*> GetCharacterEquipment();

	
	UFUNCTION(BlueprintPure,Category="CommonCharacter") TMap<UOmegaAttribute*,float> GetAttributes();

	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Character",meta=(EditCondition="!Appearance_Preset"))
	UOAsset_Appearance* Appearance_Custom;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character")
	UOAsset_Appearance* Appearance_Preset;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Character")
	UFlowAsset* FlowAsset;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat")
	int32 Level=1;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat",Meta=(GetKeyOptions="opts_attributes"))
	TMap<FName,float> Attributes;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat")
	TArray<TScriptInterface<IDataInterface_Skill>> Skills;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat")
	UOmegaGambit_Asset* Gambit;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Initial",meta=(GetKeyOptions="opts_equipSlot"))
    TMap<FName,TScriptInterface<IDataInterface_Equipable>> Equipment;
    UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Initial")
    TMap<UPrimaryDataAsset*,int32> Inventory;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Initial",meta=(GetKeyOptions="opts_xp"))
	TMap<FName,int32> XpLevels;
	
	
	UFUNCTION(BlueprintPure,Category="CommonCharacter") UOAsset_Appearance* GetAppearance() const
	{
		if(Appearance_Preset) {return Appearance_Preset;} if(Appearance_Custom) {return Appearance_Custom;} return nullptr;
	};

	virtual UOAsset_Appearance* GetAppearanceAsset_Implementation() override;
	
	virtual void SetValue_Implementation(FLuaValue Value, const FString& Field = "") override;
};
