// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Combatant/AttributeDamagePopup.h"

#include "OmegaAttribute.h"
#include "Gameplay/CombatantComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetTextLibrary.h"

void UAttributeDamagePopup::NativeConstruct()
{
	Super::NativeConstruct();
	GetWorld()->GetTimerManager().SetTimer(LifetimeTimer, this, &UAttributeDamagePopup::RemoveFromParent, GetPopupLifetime(), false);
}

void UAttributeDamagePopup::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	CurrentPosition = UKismetMathLibrary::Vector2DInterpTo(CurrentPosition, InitPosition+GetTargetViewportPosition(), InDeltaTime, 1/GetPopupLifetime());
	SetPositionInViewport(CurrentPosition);
	
}

void UAttributeDamagePopup::Native_OnDamagePopup(UCombatantComponent* Combatant, UOmegaAttribute* Attribute,
                                                 float FinalDamage, UObject* Instigator)
{
	GetOwningPlayer()->ProjectWorldLocationToScreen(Combatant->GetOwner()->GetActorLocation(), InitPosition, true);
	SetPositionInViewport(InitPosition);
	CurrentPosition = InitPosition;
	
	if(GetDamageText())
	{
		GetDamageText()->SetText(UKismetTextLibrary::Conv_FloatToText(FinalDamage, DamageDisplayRounding));
		GetDamageText()->SetColorAndOpacity(Attribute->DamageColor);
	}
	OnDamagePopup(Combatant, Attribute, FinalDamage, Instigator);
}

float UAttributeDamagePopup::GetPopupLifetime_Implementation()
{
	return 2.0;
}
