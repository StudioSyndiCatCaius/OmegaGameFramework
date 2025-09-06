// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "Engine/DataAsset.h"
#include "Component_DataWidget.generated.h"

class UDataWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWidgetSelected, UDataWidgetComponent*, Component, UDataWidget*, Widget);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnWidgetHovered, UDataWidgetComponent*, Component, UDataWidget*, Widget, bool, Hovered);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnWidgetHighlight, UDataWidgetComponent*, Component, UDataWidget*, Widget, bool, Highlighted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnWidgetNotified, UDataWidgetComponent*, Component, UDataWidget*, Widget, FName, Notify);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UDataWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

	//UDataWidgetComponent();

	UFUNCTION() void L_OnSelect(UDataWidget* DataWidget);
	UFUNCTION() void L_OnHover(UDataWidget* DataWidget, bool bIsHovered);
	UFUNCTION() void L_OnHighlight(UDataWidget* DataWidget, bool bIsHighlight);
	UFUNCTION() void L_OnNotify(UDataWidget* DataWidget, FName Notify);

public:
	virtual void SetWidget(UUserWidget* Widget) override;
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable) FOnWidgetSelected OnWidgetSelected;
	UPROPERTY(BlueprintAssignable) FOnWidgetHovered OnWidgetHovered;
	UPROPERTY(BlueprintAssignable) FOnWidgetHighlight OnWidgetHighlight;
	UPROPERTY(BlueprintAssignable) FOnWidgetNotified OnWidgetNotify;

	UFUNCTION(BlueprintCallable,Category="DataWidget")
	UDataWidget* GetDataWidget();
	
};
