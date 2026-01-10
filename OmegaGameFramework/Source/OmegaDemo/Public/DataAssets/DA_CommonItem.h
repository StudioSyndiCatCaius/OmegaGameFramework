// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DA_CommonBattleAction.h"
#include "Components/Component_Inventory.h"
#include "Functions/F_Component.h"
#include "Functions/F_ScriptedEffects.h"
#include "Interfaces/I_BitFlag.h"
#include "Interfaces/I_Skill.h"

#include "Misc/GeneralDataObject.h"
#include "Misc/OmegaUtils_Structs.h"
#include "DA_CommonItem.generated.h"


UCLASS(Blueprintable, BlueprintType)
class OMEGADEMO_API UOAsset_CommonItem : public UOAsset_CommonBattleAction, public IDataAssetCollectionInterface
{
	GENERATED_BODY()
public:
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual TMap<UPrimaryDataAsset*,int32> GetTradeAssetRequirements_Implementation(FGameplayTag TradeTag) override;
	virtual int32 GetMaxCollectionNumber_Implementation() override;
	virtual bool CanUseSkill_Implementation(UCombatantComponent* Combatant) override { return bCanUseAsSkill;};

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags")
	bool bCanUseAsSkill;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags")
	bool bAppendEffectsDescription;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Item")
	int32 Rank;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Item")
	int32 CollectionMax=99;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Item",meta=(DisallowCreateNew))
	TMap<UPrimaryDataAsset*, int32> TradeCosts;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Item")
	TMap<FGameplayTag,FOmegaMap_AssetInt> TradeCosts_Tagged;

};
