// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Styling/SlateBrush.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "I_StandardInput.generated.h"


UINTERFACE(MinimalAPI) class UDataInterface_InputAction : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_InputAction
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Input",DisplayName="Input - Disabled?")
	bool InputAction_Disabled(APlayerController* Player, FGameplayTag Action);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable,Category="ΩI|Input",DisplayName="Input - Action Begin")
	void OnInputAction_Begin(APlayerController* Player, FGameplayTag Action, FVector axis);
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="ΩI|Input",DisplayName="Input - Action Tick")
	void OnInputAction_Update(APlayerController* Player, FGameplayTag Action, float DeltaTime, FVector axis);
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="ΩI|Input",DisplayName="Input - Action End")
	void OnInputAction_End(APlayerController* Player, FGameplayTag Action, FVector axis);
	
};



UINTERFACE(MinimalAPI) class UDataInterface_StandardInput : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_StandardInput
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable,Category="ΩI|Input",DisplayName="Input - On Vector2D")
	void OnReceiveInput_Vector2D(FVector2D Value, APlayerController* Controller, int32 InputIndex);
	
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable,Category="ΩI|Input",DisplayName="Input - on Int")
	void OnReceiveInput_Int(int32 Value, APlayerController* Controller, int32 InputIndex);
	
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable,Category="ΩI|Input",DisplayName="Input - On Float")
	void OnReceiveInput_Float(float Value, APlayerController* Controller, int32 InputIndex);
	
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable,Category="ΩI|Input",DisplayName="Input - On Name")
	void OnReceiveInput_Named(FName Value, APlayerController* Controller, int32 InputIndex);
	
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable,Category="ΩI|Input",DisplayName="Input - On Key")
	void OnReceiveInput_Key(FKey Value, APlayerController* Controller, int32 InputIndex);
};


