// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/DataWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "DataInterface_General.h"
#include "CommonUILibrary.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Player/OmegaPlayerSubsystem.h"

void UDataWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	bIsFocusable = true;

	SetSourceAsset(ReferencedAsset);

	//TryEnabled/Disable
		SetIsEnabled(!IsEntityDisabled(ReferencedAsset));

	if(GetHoveredMaterialInstance())
	{
		GetHoveredMaterialInstance()->SetScalarParameterValue(HoverWidgetPropertyName,0);
		GetHoveredMaterialInstance()->SetScalarParameterValue(HighlightWidgetPropertyName,0);
	}
	
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

void UDataWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if(GetHoveredMaterialInstance() && IsRendered())
	{
		float OutVal;
		
		const float HoverVal = GetHoveredMaterialInstance()->K2_GetScalarParameterValue(HoverWidgetPropertyName);
		if(bIsHovered != static_cast<bool>(HoverVal))
		{
			OutVal = UKismetMathLibrary::FInterpTo_Constant(HoverVal, bIsHovered, InDeltaTime, HoverWidgetSpeed);
			GetHoveredMaterialInstance()->SetScalarParameterValue(HoverWidgetPropertyName,OutVal);
		}
		
		const float HighlightVal = GetHoveredMaterialInstance()->K2_GetScalarParameterValue(HighlightWidgetPropertyName);
		if(bIsHighlighted != static_cast<bool>(HighlightVal))
		{
			OutVal = UKismetMathLibrary::FInterpTo_Constant(HighlightVal, bIsHovered, InDeltaTime, HighlightWidgetSpeed);
			GetHoveredMaterialInstance()->SetScalarParameterValue(HighlightWidgetPropertyName,OutVal);
		}
	}

	Super::NativeTick(MyGeometry, InDeltaTime);
}

UOmegaPlayerSubsystem* UDataWidget::GetPlayerSubsystem() const
{
	return GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>();	
}

//----------------------NATIVE CONSTRUCT-------------------------------------------//

void UDataWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (GetButtonWidget())
	{
		GetButtonWidget()->OnClicked.AddDynamic(this, &UDataWidget::Select);
		GetButtonWidget()->OnHovered.AddDynamic(this, &UDataWidget::Hover);
	}

	TSubclassOf<UDataTooltip> LocalTooltipClass;
	if(DefaultTooltipWidget)
	{
		LocalTooltipClass = DefaultTooltipWidget;
	}
	else
	{
		LocalTooltipClass = UDataTooltip::StaticClass();
	}

	DefaultCreatedTooltip = CreateWidget<UDataTooltip>(this, LocalTooltipClass);
	DefaultCreatedTooltip->SetOwningWidget(this);

	if(UpdateSourceAssetFromParent)
	{
		if(Cast<UDataWidget>(UCommonUILibrary::FindParentWidgetOfType(this, UDataWidget::StaticClass())))
		{
			OwnerDataWidget = Cast<UDataWidget>(UCommonUILibrary::FindParentWidgetOfType(this, UDataWidget::StaticClass()));
			OwnerDataWidget->SourceAssetChanged.AddDynamic(this, &UDataWidget::SetSourceAsset);
		}
	}
	Local_UpdateTooltip(ReferencedAsset);
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

UDataList* UDataWidget::GetOwningList() const
{
	if(ParentList)
	{
		return ParentList;
	}
	return nullptr;
}

void UDataWidget::SetWidgetTagActive(FName Tag, bool bActive)
{
	if(bActive)
	{
		WidgetTags.AddUnique(Tag);
	}
	else
	{
		WidgetTags.Remove(Tag);
	}
	
}

bool UDataWidget::DataWidgetHasTag(FName Tag)
{
	return WidgetTags.Contains(Tag);
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
				GetPlayerSubsystem()->PlayUiSound(SelectSound);
		}
	}
	else
	{
		if(ErrorSound)
		{
				GetPlayerSubsystem()->PlayUiSound(ErrorSound);
		}
	}
}

void UDataWidget::Hover()
{
	if(bIsHovered)
	{
		return;
	}
	if(UUserWidget* TempWidget = GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->HoveredWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("Attempt Unhvover"));
		Cast<UDataWidget>(TempWidget)->Unhover();
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Success Hover"));
	if(HoverSound)
	{
		GetPlayerSubsystem()->PlayUiSound(HoverSound);
	}
	
	if (GetHoverAnimation())
	{
		PlayAnimationForward(GetHoverAnimation(), 1.0f, false);
	}
	OnHovered.Broadcast(this, true);
	bIsHovered=true;
	GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->HoveredWidget = this;
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
		bIsHighlighted = Highlighted;
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

bool UDataWidget::GetIsEntitySelectable()
{
	return !IsEntityDisabled(ReferencedAsset);
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
			bool Local_OverrideSize;
			FVector2D Local_NewSize;
			if(GetBrushImage(Local_OverrideSize, Local_NewSize) && LocalBrush.GetResourceObject())
			{
				
				if(Local_OverrideSize)
				{
					LocalBrush.ImageSize = Local_NewSize;
				}
				GetBrushImage(Local_OverrideSize, Local_NewSize)->SetBrush(LocalBrush);
			}
			
		}//Finish widget setup
		
		//Set Tooltip Asset
		Local_UpdateTooltip(Asset);
			
		ReferencedAsset = Asset;
		SourceAssetChanged.Broadcast(Asset);
		OnSourceAssetChanged(Asset);
	}
	
}

UDataTooltip* UDataWidget::GetDataTooltipWidget()
{
	return DefaultCreatedTooltip;
}

void UDataWidget::Local_UpdateTooltip(UObject* AssetRef)
{
	if(!AssetRef)
	{
		return;
	}
	if(DefaultCreatedTooltip)
	{
		DefaultCreatedTooltip->OnOwnerSourceAssetChanged(AssetRef);

		if(AssetRef->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
		{
			FText LocalDesc;
			FText LocalName;
		
			IDataInterface_General::Execute_GetGeneralDataText(AssetRef, AssetLabel, this, LocalName, LocalDesc);
		
			//update name widget
			if(DefaultCreatedTooltip->GetAssetNameWidget())
			{
				DefaultCreatedTooltip->GetAssetNameWidget()->SetText(LocalName);
			}
			//update description widget
			if(DefaultCreatedTooltip->GetAssetNameWidget())
			{
				DefaultCreatedTooltip->GetAssetDescriptionWidget()->SetText(LocalDesc);
			}
		}
		
	}
}
