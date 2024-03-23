// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Blueprint/UserWidget.h"
#include "OmegaFunctions_Popup.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaPopupWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadOnly,Category="Popup")
	FVector Spawn_Root;
	UPROPERTY(BlueprintReadOnly,Category="Popup")
	FText popup_text;
	UPROPERTY(BlueprintReadOnly,Category="Popup")
	FLinearColor popup_color;
	UPROPERTY(BlueprintReadOnly,Category="Popup")
	FGameplayTagContainer popup_tags;
	UPROPERTY()
	UObject* popup_context=nullptr;

	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UFUNCTION(BlueprintNativeEvent,Category="Popup")
	float GetPopupLifetime();
	//############################################################################################
	//  Location
	//############################################################################################
	UPROPERTY()
	FVector2D InitPosition;
	UPROPERTY()
	FVector2D CurrentPosition;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Popup")
	FVector2D GetTargetViewportPosition();
	
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
