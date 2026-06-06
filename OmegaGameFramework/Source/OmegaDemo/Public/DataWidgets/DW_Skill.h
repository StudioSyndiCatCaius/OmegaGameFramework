// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/DataWidget.h"
#include "DW_Skill.generated.h"

/**
 * 
 */
UCLASS()
class OMEGADEMO_API UDataWidgetBase_Skill : public UDataWidget
{
	GENERATED_BODY()
	
public:
	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;
	
	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget")
	void GetDataWidgetBindings(
		UDataList*& List_AttributeCosts,
		UImage*& imgIcon_DamageType,
		UImage*& imgIcon_Attribute);
};
