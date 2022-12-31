// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "DataTooltip.generated.h"

class UDataWidget;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UDataTooltip : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY()
	UDataWidget* OwningWidget;

	UFUNCTION()
	void SetOwningWidget(UDataWidget* NewOwner);
	
	UFUNCTION(BlueprintPure, Category="Data Tooltip")
	UDataWidget* GetOwningDataWidget();

	UFUNCTION(BlueprintPure, Category="Data Tooltip")
	UObject* GetOwningSourceAsset();

	UFUNCTION(BlueprintImplementableEvent, Category="Data Tooltip")
	void OnOwnerSourceAssetChanged(const UObject* Asset);

	//Overrides
	UFUNCTION(BlueprintImplementableEvent, Category="Data Tooltip")
	UTextBlock* GetAssetNameWidget();
	UFUNCTION(BlueprintImplementableEvent, Category="Data Tooltip")
	UTextBlock* GetAssetDescriptionWidget();
	
	//--Getters
};
