// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "OmegaEffectPopup.generated.h"

class UCombatantComponent;
class UOmegaAttribute;
class AOmegaGameplayEffect;

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaEffectPopup : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UPROPERTY()
	AOmegaGameplayEffect* OwningEffect;

	UPROPERTY()
	FSlateColor Incoming_Color;
	UPROPERTY()
	FText Incoming_Text;
	
	UFUNCTION(BlueprintImplementableEvent)
	UTextBlock* GetDamageText();

	UFUNCTION(BlueprintNativeEvent)
	float GetPopupLifetime();

	//############################################################################################
	//  Location
	//############################################################################################
	UPROPERTY()
	FVector2D InitPosition;
	UPROPERTY()
	FVector2D CurrentPosition;
	
	UFUNCTION(BlueprintImplementableEvent)
	FVector2D GetTargetViewportPosition();
	
	UPROPERTY()
	FTimerHandle LifetimeTimer;
	
	UPROPERTY(EditDefaultsOnly, Category="Damage Popup")
	TEnumAsByte<ERoundingMode> DamageDisplayRounding;
};
