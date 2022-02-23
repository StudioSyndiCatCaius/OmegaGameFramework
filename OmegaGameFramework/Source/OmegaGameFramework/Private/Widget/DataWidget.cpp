// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/DataWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "DataInterface_General.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"

void UDataWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	bIsFocusable = true;

	SetSourceAsset(ReferencedAsset);

	//TryEnabled/Disable
		SetIsEnabled(!IsEntityDisabled(ReferencedAsset));
	
}

void UDataWidget::NativeOnAddedToFocusPath(const FFocusEvent& InFocusEvent)
{
	Super::OnAddedToFocusPath(InFocusEvent);
	Hover();
}

void UDataWidget::NativeOnRemovedFromFocusPath(const FFocusEvent& InFocusEvent)
{
	Super::OnRemovedFromFocusPath(InFocusEvent);
	Unhover();
}

void UDataWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (GetButtonWidget())
	{
		GetButtonWidget()->OnClicked.AddDynamic(this, &UDataWidget::Select);
		GetButtonWidget()->OnHovered.AddDynamic(this, &UDataWidget::Hover);
	}
}

FString UDataWidget::GetAssetLabel()
{
	FString OutString = "None";
	if (ReferencedAsset)
	{
		IDataInterface_General::Execute_GetGeneralAssetLabel(ReferencedAsset, OutString);
	}
	return OutString;
}

void UDataWidget::Select()
{
	if(bIsEnabled)
	{
		if (GetSelectAnimation())
		{
			PlayAnimationForward(GetSelectAnimation(), 1.0f, false);
		}
		OnSelected.Broadcast(this);
		
		if(SelectSound)
		{
			UGameplayStatics::PlaySound2D(this, SelectSound);
		}
	}
	else
	{
		if(ErrorSound)
		{
			UGameplayStatics::PlaySound2D(this, ErrorSound);
		}
	}
}

void UDataWidget::Hover()
{
	if(bIsHovered)
	{
		return;
	}
	TArray<UUserWidget*> TempWidgets;
	UWidgetBlueprintLibrary::GetAllWidgetsOfClass(this, TempWidgets, UDataWidget::StaticClass(), false);
	for(UUserWidget* TempWidget : TempWidgets)
	{
		UE_LOG(LogTemp, Warning, TEXT("Attempt Unhvover"));
		Cast<UDataWidget>(TempWidget)->Unhover();
	}
	

	UE_LOG(LogTemp, Warning, TEXT("Success Hover"));
	if(HoverSound)
	{
		UGameplayStatics::PlaySound2D(this, HoverSound);
	}
	
	if (GetHoverAnimation())
	{
		PlayAnimationForward(GetHoverAnimation(), 1.0f, false);
	}
	OnHovered.Broadcast(this, true);
	bIsHovered=true;
}

void UDataWidget::Unhover()
{
	if(!bIsHovered)
	{
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("Success Unhover"));
	OnHovered.Broadcast(this, false);
	if (GetHoverAnimation())
	{
		PlayAnimationReverse(GetHoverAnimation(), 1.0f, false);
	}
	bIsHovered = false;
}

void UDataWidget::SetHighlighted(bool Highlighted)
{
	//Check if already highlighted
	if (bIsHighlighted != Highlighted)
	{
		//Set new State
		bIsHighlighted = !Highlighted;
		//Check if Valid Highlight Anim exists
		if (GetHighlightAnimation())
		{
			//play correct animation
			if (bIsHighlighted)
			{
				PlayAnimationForward(GetHighlightAnimation(), 1.0f, false);
			}
			else
			{
				PlayAnimationReverse(GetHighlightAnimation(), 1.0f, false);
			}
		}
	}
}

void UDataWidget::SetSourceAsset(UObject* Asset)
{
	if (Asset)	 //Only if valid asset
	{
		if (Asset->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))		//Only run if asset uses Data interface
		{
			FText LocalDesc;
			FText LocalName;
			
			IDataInterface_General::Execute_GetGeneralDataText(Asset, AssetLabel, this, LocalName, LocalDesc);
			if (GetNameTextWidget())
			{
				GetNameTextWidget()->SetText(LocalName);
			}
			if (GetDescriptionTextWidget())
			{
				GetDescriptionTextWidget()->SetText(LocalDesc);
			}
			
			UTexture2D* LocalTexture = nullptr;
			UMaterialInterface* LocalMat = nullptr;
			FSlateBrush LocalBrush;
			IDataInterface_General::Execute_GetGeneralDataImages(Asset, AssetLabel, this, LocalTexture, LocalMat, LocalBrush);
			if(GetTextureImage()&&LocalTexture)
			{
				GetTextureImage()->SetBrushFromTexture(LocalTexture);
			}
			if(GetMaterialImage()&&LocalMat)
			{
				
				GetMaterialImage()->SetBrushFromMaterial(LocalMat);
			}
			if(GetBrushImage())
			{
				GetBrushImage()->SetBrush(LocalBrush);
			}
		}
	}
}
