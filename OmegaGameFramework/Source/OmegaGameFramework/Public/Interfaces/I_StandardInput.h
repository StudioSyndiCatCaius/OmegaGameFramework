// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Styling/SlateBrush.h"
#include "Engine/DataAsset.h"
#include "I_StandardInput.generated.h"


UINTERFACE(MinimalAPI) class UDataInterface_StandardInput : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_StandardInput
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable,Category="ΩI|Input",DisplayName="Input - On Move")
	void OnReceiveInput_Movement(FVector2D Value, APlayerController* Controller);
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable,Category="ΩI|Input",DisplayName="Input - On Control")
	void OnReceiveInput_Control(FVector2D Value, APlayerController* Controller);

	UFUNCTION(BlueprintImplementableEvent,Category="ΩI|Input",DisplayName="Input - On Page Int")
	void OnReceiveInput_PageShoulder(int32 Value, bool bActive, APlayerController* Controller);
	UFUNCTION(BlueprintImplementableEvent,Category="ΩI|Input",DisplayName="Input - On Page Float")
	void OnReceiveInput_PageTrigger(float Value, bool bActive, APlayerController* Controller);
};


