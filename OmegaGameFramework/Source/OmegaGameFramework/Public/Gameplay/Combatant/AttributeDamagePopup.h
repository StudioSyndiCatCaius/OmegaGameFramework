// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "AttributeDamagePopup.generated.h"

class UCombatantComponent;
class UOmegaAttribute;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UAttributeDamagePopup : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UFUNCTION()
	void Native_OnDamagePopup(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, float FinalDamage, class UObject* Instigator);
	UFUNCTION(BlueprintImplementableEvent)
	void OnDamagePopup(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, float FinalDamage, class UObject* Instigator);

	UFUNCTION(BlueprintImplementableEvent)
	UTextBlock* GetDamageText();

	UFUNCTION(BlueprintNativeEvent)
	float GetPopupLifetime();

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
