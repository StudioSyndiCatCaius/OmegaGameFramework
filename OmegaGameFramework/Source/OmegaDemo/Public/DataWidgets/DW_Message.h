// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/DataWidget.h"
#include "DW_Message.generated.h"

class UOmegaGameplayMessage;
class UTextBlock;
class UImage;

// ==============================================================================================================
// Message
// ==============================================================================================================

UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_Message : public UDataWidget
{
	GENERATED_BODY()

	UPROPERTY() bool __bTextIsUpdating;
	UPROPERTY() float __TextWriteTime;
	UPROPERTY() TArray<FString> __stringsRemaining;
	UPROPERTY() int32 __stringAmount;

	UPROPERTY() UOmegaGameplayMessage* REF_message;
	UPROPERTY() UObject* REF_lastInstigator=nullptr;

public:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual void Native_OnSourceAssetChanged(UObject* SourceAsset) override;

	UPROPERTY(EditAnywhere,Category="Message")
	bool bWriteTextOverTime;
	UPROPERTY(EditAnywhere,Category="Message")
	float TextWriteFrequency=0.02;

	UFUNCTION(BlueprintPure,Category="DataWidget")
	UOmegaGameplayMessage* GetCurrentMessage() const;

	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget")
	void OnMessageUpdate(UOmegaGameplayMessage* Message);

	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget")
	void OnInstigatorChange(UObject* New=nullptr, UObject* Old=nullptr);

	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UTextBlock* GetWidget_Text_Message();
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UDataWidget* GetDataWidget_MessageInstigator();

	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UImage* GetImage_InstigatorBrush();
};
