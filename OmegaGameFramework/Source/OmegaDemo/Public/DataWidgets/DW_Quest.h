// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Actor_Quest.h"
#include "Widget/DataWidget.h"
#include "DW_Quest.generated.h"

class UDataList;

// ==============================================================================================================
// Quest
// ==============================================================================================================

UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_Quest : public UDataWidget
{
	GENERATED_BODY()

	UPROPERTY() AOmegaQuestInstance* QuestInstance;

public:

	virtual void OnSourceAssetChanged_Implementation(UObject* Asset) override;
	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;

	UFUNCTION(BlueprintImplementableEvent,Category="Quest")
	UDataList* GetDataList_ActiveTasks();
};
