// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "Component_DataWidget.generated.h"

class UDataWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWidgetSelected, UDataWidgetComponent*, Component, UDataWidget*, Widget);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnWidgetHovered, UDataWidgetComponent*, Component, UDataWidget*, Widget, bool, Hovered);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnWidgetHighlight, UDataWidgetComponent*, Component, UDataWidget*, Widget, bool, Highlighted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnWidgetNotified, UDataWidgetComponent*, Component, UDataWidget*, Widget, FName, Notify);

// A world-space widget component that forwards selection, hover, highlight, and notify events from a DataWidget to Blueprint delegates.
UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UDataWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

	UFUNCTION() void L_OnSelect(UDataWidget* DataWidget);
	UFUNCTION() void L_OnHover(UDataWidget* DataWidget, bool bIsHovered);
	UFUNCTION() void L_OnHighlight(UDataWidget* DataWidget, bool bIsHighlight);
	UFUNCTION() void L_OnNotify(UDataWidget* DataWidget, FName Notify);

public:
	virtual void SetWidget(UUserWidget* Widget) override;
	virtual void BeginPlay() override;

	// Fires when the DataWidget is selected.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnWidgetSelected OnWidgetSelected;
	// Fires when the DataWidget's hover state changes.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnWidgetHovered OnWidgetHovered;
	// Fires when the DataWidget's highlight state changes.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnWidgetHighlight OnWidgetHighlight;
	// Fires when the DataWidget sends a named notification.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnWidgetNotified OnWidgetNotify;

	// Returns the hosted widget cast to a DataWidget, or null if the widget is not a DataWidget.
	UFUNCTION(BlueprintCallable,Category="DataWidget")
	UDataWidget* GetDataWidget();

};
