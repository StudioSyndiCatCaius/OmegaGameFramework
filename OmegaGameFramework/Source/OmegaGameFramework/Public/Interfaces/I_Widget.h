// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"

#include "I_Widget.generated.h"

class UUserWidget;

// This class does not need to be modified.
UINTERFACE()
class UWidgetInterface_Input : public UInterface
{
	GENERATED_BODY()
};

class OMEGAGAMEFRAMEWORK_API IWidgetInterface_Input
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintNativeEvent, Category="Input")
	void OnControlSetWidget();
	UFUNCTION(BlueprintNativeEvent, Category="Input")
	void InputNavigate(FVector2D Axis);
	UFUNCTION(BlueprintNativeEvent, Category="Input")
	void InputPage(float Axis);
	UFUNCTION(BlueprintNativeEvent, Category="Input")
	void InputConfirm();
	UFUNCTION(BlueprintNativeEvent, Category="Input")
	void InputCancel();
	UFUNCTION(BlueprintNativeEvent, Category="Input")
	bool InputBlocked();
	UFUNCTION(BlueprintNativeEvent, Category="Input")
	void InputTag(FGameplayTag Tag);
	
};

UINTERFACE(MinimalAPI) class UDataInterface_WidgetTrait : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_WidgetTrait
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent,Category="WidgetState")
	void OnTraitInit(UUserWidget* Widget);

	UFUNCTION(BlueprintNativeEvent,Category="WidgetState")
	void OnWidgetTick(UUserWidget* Widget,float Delta);

	UFUNCTION(BlueprintNativeEvent,Category="WidgetState")
	void OnWidgetConstruct(UUserWidget* Widget);
	
	UFUNCTION(BlueprintNativeEvent,Category="WidgetState")
	void OnWidgetDestruct(UUserWidget* Widget);
};