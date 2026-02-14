// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetSwitcher.h"
#include "Widget/DataWidget.h"
#include "Widget/HUDLayer.h"
#include "OmegaDemo_HUDs.generated.h"

UCLASS(Abstract)
class OMEGADEMO_API UHudBase_Dialogue : public UHUDLayer
{
	GENERATED_BODY()

	float f_MessageStateBlend=0.0f;
	float f_MessageStateTarget=0.0f;
	bool b_messageVisible=false;
	
	FTimerHandle timer_waitNextmsg;
	UFUNCTION() void L_WaitNextMsg_Finish();
	
	UPROPERTY() UOmegaGameplayMessage* l_LastMessage;

public:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual void OnGameplayMessage_Implementation(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta meta) override;
	virtual void OnGlobalEvent_Implementation(FName Event, UObject* Context) override;
	
	UPROPERTY(EditAnywhere,Category="Menu") FGameplayTagContainer AllowedMessageTypes;
	UPROPERTY(EditAnywhere,Category="Menu") float MessageEnd_WaitForNext=0.1f;
	UPROPERTY(EditAnywhere,Category="Menu") float MessageState_BlendTime=0.2f;
	UPROPERTY(EditAnywhere,Category="Menu") bool ReverseMessageStartAnimation;
	UPROPERTY(EditAnywhere,Category="Menu") bool ReverseMessageEndAnimation=true;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Menu") UWidgetSwitcher* GetWidgetSwitcher_MessageStyle();
	UFUNCTION(BlueprintImplementableEvent,Category="Menu") UDataWidget* GetDataWidgetOnMessage(UOmegaGameplayMessage* Message);
	UFUNCTION(BlueprintImplementableEvent,Category="Menu") void OnMessageStateBlendUpdate(float Alpha);
};

UCLASS(Abstract)
class OMEGADEMO_API UHudBase_CombatTurnBased : public UHUDLayer
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent,Category="Menu") UDataList* GetList_TurnOrder();
	UFUNCTION(BlueprintImplementableEvent,Category="Menu") UDataList* GetList_FactionMembers(FGameplayTag Faction);
};