// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetSwitcher.h"
#include "Widget/DataWidget.h"
#include "Widget/HUDLayer.h"
#include "OmegaDemo_HUDs.generated.h"

UCLASS(Abstract)
class OMEGADEMO_API UHUD_Dialogue : public UHUDLayer
{
	GENERATED_BODY()

public:
	virtual void OnGameplayMessage_Implementation(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FLuaValue meta) override;

	UPROPERTY(EditAnywhere,Category="Menu")
	FGameplayTagContainer AllowedMessageTypes;

	UFUNCTION(BlueprintImplementableEvent,Category="Menu")
	UWidgetSwitcher* GetWidgetSwitcher_MessageStyle();

	UFUNCTION(BlueprintImplementableEvent,Category="Menu")
	UDataWidget* GetDataWidgetOnMessage(UOmegaGameplayMessage* Message);
};
