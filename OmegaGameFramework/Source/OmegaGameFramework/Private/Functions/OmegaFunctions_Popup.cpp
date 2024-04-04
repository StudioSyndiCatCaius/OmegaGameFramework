// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/OmegaFunctions_Popup.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"

void UOmegaPopupWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	GetOwningPlayer()->ProjectWorldLocationToScreen(Spawn_Root, InitPosition);
	CurrentPosition = InitPosition;
	SetPositionInViewport(InitPosition);
	
	GetWorld()->GetTimerManager().SetTimer(LifetimeTimer, this, &UOmegaPopupWidget::RemoveFromParent, GetPopupLifetime(), false);
}

void UOmegaPopupWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	CurrentPosition = UKismetMathLibrary::Vector2DInterpTo(CurrentPosition, InitPosition+GetTargetViewportPosition(), InDeltaTime, 1/GetPopupLifetime());
	SetPositionInViewport(CurrentPosition);
}

UOmegaPopupWidget* UOmegaFunctions_Popup::CreatePopupWidget(UObject* WorldContextObject,
	TSubclassOf<UOmegaPopupWidget> Class, FText Text, FVector Location, UObject* Context, FLinearColor Color,
	FGameplayTagContainer Tags)
{
	TSubclassOf<UOmegaPopupWidget> Class_incoming = UOmegaPopupWidget::StaticClass();
	if(Class)
	{
		Class_incoming=Class;
	}
	UOmegaPopupWidget* LocalPopup = Cast<UOmegaPopupWidget>(CreateWidget(WorldContextObject->GetWorld(), Class_incoming));
	LocalPopup->popup_text=Text;
	LocalPopup->popup_color=Color;
	LocalPopup->popup_tags=Tags;
	LocalPopup->Spawn_Root=Location;
	if(Context)
	{
		LocalPopup->popup_context=Context;
	}
	LocalPopup->AddToViewport();
	return LocalPopup;
}



float UOmegaPopupWidget::GetPopupLifetime_Implementation()
{
	return 2.0;
}
