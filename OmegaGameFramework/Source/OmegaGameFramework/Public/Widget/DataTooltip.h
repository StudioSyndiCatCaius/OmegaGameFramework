// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"
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
	
	UFUNCTION(BlueprintPure, Category="DataTooltip")
	UDataWidget* GetOwningDataWidget();

	UFUNCTION(BlueprintPure, Category="DataTooltip")
	UObject* GetOwningSourceAsset();

	//--Getters
};
