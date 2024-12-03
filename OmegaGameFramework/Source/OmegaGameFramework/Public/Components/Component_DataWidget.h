// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "Engine/DataAsset.h"
#include "Kismet/KismetMathLibrary.h"
#include "Component_DataWidget.generated.h"

class UDataWidget;

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UDataWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

	//UDataWidgetComponent();

public:

	virtual void SetWidget(UUserWidget* Widget) override;

	UFUNCTION(BlueprintCallable,Category="DataWidget")
	UDataWidget* GetDataWidget();
	
};
