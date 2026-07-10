// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataWidgets/DW_Combatant.h"
#include "Components/Component_Leveling.h"
#include "DW_Leveling.generated.h"

class UTextBlock;
class UProgressBar;

// ==============================================================================================================
// Leveling
// ==============================================================================================================

UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_Leveling : public UDataWidgetBase_CombatantBASE
{
	GENERATED_BODY()

	void L_SetTextFromVal(float val, UTextBlock* text) const;

public:
	

	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Leveling")
	UOmegaLevelingAsset* LevelingAsset=nullptr;

	UFUNCTION(BlueprintCallable,Category="Leveling") void SetLevelingAsset(UOmegaLevelingAsset* Asset);
	
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	void GetLevelingWidgets(UTextBlock*& text_RankName, UTextBlock*& text_RankValue, UTextBlock*& text_xpName, UTextBlock*& text_xpCurrent,
		UTextBlock*& text_xpMax, UProgressBar*& ProgressBar_xpPercent);
};
