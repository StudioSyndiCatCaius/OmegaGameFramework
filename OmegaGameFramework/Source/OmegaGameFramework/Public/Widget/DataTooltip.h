// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DataTooltip.generated.h"

class UImage;
class UDataWidget;
class UTextBlock;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UDataTooltip : public UUserWidget
{
	GENERATED_BODY()

public:
	
	virtual void NativeConstruct() override;

	UPROPERTY()
	UDataWidget* OwningWidget;
	
	UPROPERTY(EditAnywhere,Category="Tooltip")
	bool bOverride_IconSize;
	UPROPERTY(EditAnywhere,Category="Tooltip")
	FVector2D IconSize;
	
	UFUNCTION()
	void SetOwningWidget(UDataWidget* NewOwner);
	
	UFUNCTION(BlueprintCallable, Category="Data Tooltip")
	void Refresh();
	
	UFUNCTION(BlueprintPure, Category="Data Tooltip")
	UDataWidget* GetOwningDataWidget() const;

	UFUNCTION(BlueprintPure, Category="Data Tooltip")
	UObject* GetOwningSourceAsset() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Data Tooltip")
	void OnOwnerSourceAssetChanged(const UObject* Asset);

	//Overrides
	UFUNCTION(BlueprintImplementableEvent, Category="Data Tooltip") UTextBlock* GetAssetNameWidget();
	UFUNCTION(BlueprintImplementableEvent, Category="Data Tooltip") UTextBlock* GetAssetDescriptionWidget();
	UFUNCTION(BlueprintImplementableEvent, Category="Data Tooltip") UImage* GetAssetIconWidget();
	
	//--Getters
};
