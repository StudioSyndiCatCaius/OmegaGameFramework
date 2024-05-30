// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Blueprint/UserWidget.h"
#include "OmegaFunctions_Popup.generated.h"

class UTextBlock;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaPopupWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	//Only one of this widget class is allowed to be rendered at a time.
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Popup")
	bool Singleton;
	//If true, this widget will ignore any input position and appear across the full screen.
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Popup")
	bool Fullscreen;
	
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Popup")
	float Subpanel_RandomOffsetRange;
	
	UPROPERTY(BlueprintReadOnly,Category="Popup")
	FVector Spawn_Root;
	UPROPERTY(BlueprintReadOnly,Category="Popup")
	FText popup_text;
	UPROPERTY(BlueprintReadOnly,Category="Popup")
	FLinearColor popup_color;
	UPROPERTY(BlueprintReadOnly,Category="Popup")
	FGameplayTagContainer popup_tags;
	UPROPERTY(BlueprintReadOnly,Category="Popup")
	UObject* popup_context=nullptr;

	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;


	//############################################################################################
	//  Location
	//############################################################################################
	UPROPERTY() FVector2D InitPosition;
	UPROPERTY() FVector2D CurrentPosition;
	
	UFUNCTION(BlueprintNativeEvent,Category="Popup")
	float GetPopupLifetime();
	UFUNCTION(BlueprintImplementableEvent,Category="Popup")
	UTextBlock* GetPopupText();
	UFUNCTION(BlueprintImplementableEvent,Category="Popup")
	FVector2D GetTargetViewportPosition();
	//Gets the child widget to apply additional procedural effects to. (E.G. random position offset)
	UFUNCTION(BlueprintImplementableEvent,Category="Popup")
	UWidget* GetSubpanelWidget();
	
	UPROPERTY()
	FTimerHandle LifetimeTimer;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_Popup : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable,Category="Omega|Popup",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Context,Color,Tags"))
	static UOmegaPopupWidget* CreatePopupWidget(UObject* WorldContextObject, TSubclassOf<UOmegaPopupWidget> Class, FText Text,
		FVector Location, UObject* Context, FLinearColor Color, FGameplayTagContainer Tags);
};
