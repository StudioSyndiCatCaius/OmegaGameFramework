// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DA_CommonBattleAction.h"
#include "Components/Component_Inventory.h"
#include "Functions/F_Component.h"
#include "Functions/F_ScriptedEffects.h"
#include "Interfaces/I_Skill.h"

#include "Misc/GeneralDataObject.h"
#include "Misc/OmegaUtils_Structs.h"
#include "DA_CommonItem.generated.h"


UCLASS(Blueprintable, BlueprintType,DisplayName="Ω-🧪 Item")
class OMEGADEMO_API UOAsset_CommonItem : public UOAsset_CommonBattleAction, public IDataAssetCollectionInterface
{
	GENERATED_BODY()
public:
	virtual TMap<UPrimaryDataAsset*,int32> GetTradeAssetRequirements_Implementation(FGameplayTag TradeTag) override;
	virtual int32 GetMaxCollectionNumber_Implementation() override;
	virtual bool CanUseSkill_Implementation(UCombatantComponent* Combatant) override { return true;};
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Item") int32 Rank=1;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Item") int32 CollectionMax=99;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Trade",meta=(DisallowCreateNew),DisplayName="🛍️Trade Cost")
	TMap<UPrimaryDataAsset*, int32> TradeCosts;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Trade",meta=(ForceInlineRow),DisplayName="🛍️Trade Cost (Tagged)")
	TMap<FGameplayTag,FOmegaMap_AssetInt> TradeCosts_Tagged;

};
