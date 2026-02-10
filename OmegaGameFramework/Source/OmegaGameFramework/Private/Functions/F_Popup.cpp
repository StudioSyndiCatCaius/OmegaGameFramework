// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_Popup.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/TextBlock.h"

void UOmegaPopupWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if(!Fullscreen)
	{
		GetOwningPlayer()->ProjectWorldLocationToScreen(Spawn_Root, InitPosition);
		CurrentPosition = InitPosition;
		SetPositionInViewport(InitPosition);
	}
	GetWorld()->GetTimerManager().SetTimer(LifetimeTimer, this, &UOmegaPopupWidget::RemoveFromParent, GetPopupLifetime(), false);

	if(GetSubpanelWidget())
	{
		const float rand_val = UKismetMathLibrary::RandomFloatInRange(Subpanel_RandomOffsetRange*-1.0,Subpanel_RandomOffsetRange);
		GetSubpanelWidget()->SetRenderTranslation(FVector2d(rand_val,rand_val));
	}
	if(GetPopupText())
	{
		GetPopupText()->SetText(popup_text);
		GetPopupText()->SetColorAndOpacity(FSlateColor(popup_color));
	}
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
	
	if(LocalPopup->Singleton)
	{
		TArray<UUserWidget*> widget_list;
		UWidgetBlueprintLibrary::GetAllWidgetsOfClass(WorldContextObject,widget_list,Class_incoming);
		if(widget_list.IsValidIndex(0) && widget_list[0]->IsVisible())
		{
			return nullptr;
		}
	}
	
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
