// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/I_StandardInput.h"
#include "UI_InputAction.generated.h"


class UButton;
class UTextBlock;
class UImage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInpuActionUIDelegate,UOmegaUI_InputAction*, Widget);

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaUI_InputAction : public UUserWidget, public IDataInterface_InputAction
{
	GENERATED_BODY()
	
public:

	UFUNCTION()void L_Trigger();
	UFUNCTION() void L_OnInputDeviceChange(bool bIsUsingGamepad);
	
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	
	virtual bool InputAction_Disabled_Implementation(APlayerController* Player, FGameplayTag Action) override;
	virtual void OnInputAction_Begin_Implementation(APlayerController* Player, FGameplayTag Action, FVector axis) override;
	virtual void OnInputAction_End_Implementation(APlayerController* Player, FGameplayTag Action, FVector axis) override;
	
	UFUNCTION(BlueprintImplementableEvent,Category="InputAction")
	void GetWidget_Bindings(UImage*& Image_Icon, UTextBlock*& Text_Name,UButton*& Button_TriggerInput);
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="InputAction",meta=(Categories="INPUT")) FGameplayTag InputAction;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="InputAction") bool bShow_Image=true;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="InputAction") bool bShow_Text=true;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="InputAction") FVector2D IconSize=FVector2D(50,50);
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="InputAction") FText CustomName;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="InputAction") bool bPreviewGamepad;
	
	UPROPERTY(BlueprintAssignable,Category="InputAction") FInpuActionUIDelegate OnInputBegin;
	UPROPERTY(BlueprintAssignable,Category="InputAction") FInpuActionUIDelegate OnInputEnd;
};
