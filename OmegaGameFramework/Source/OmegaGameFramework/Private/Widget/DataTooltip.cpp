// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/DataTooltip.h"

#include "Components/Image.h"
#include "Functions/F_Common.h"
#include "Widget/DataWidget.h"

void UDataTooltip::NativeConstruct()
{
	if (GetOwningSourceAsset())
	{
		SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}
	else
	{
		SetVisibility(ESlateVisibility::Collapsed);
	}
	Super::NativeConstruct();
}

void UDataTooltip::SetOwningWidget(UDataWidget* NewOwner)
{
	OwningWidget = NewOwner;
	Refresh();
}

void UDataTooltip::Refresh()
{
	if(OwningWidget)
	{
		if (UObject* source_object=OwningWidget->GetTooltip_SourceObject())
		{
			if(GetAssetDescriptionWidget())
			{
				GetAssetDescriptionWidget()->SetText(UOmegaGameFrameworkBPLibrary::GetObjectDisplayDescription(source_object));
			}
			if(GetAssetNameWidget())
			{
				GetAssetNameWidget()->SetText(UOmegaGameFrameworkBPLibrary::GetObjectDisplayName(source_object));
			}
			if(GetAssetIconWidget())
			{
				GetAssetIconWidget()->SetBrush(UOmegaGameFrameworkBPLibrary::GetObjectIcon(source_object));
				if (bOverride_IconSize)
				{
					GetAssetIconWidget()->SetDesiredSizeOverride(IconSize);
				}
			}
		}
	}
	OnOwnerSourceAssetChanged(OwningWidget);
}

UDataWidget* UDataTooltip::GetOwningDataWidget() const
{
	if(OwningWidget)
	{
		return OwningWidget;
	}
	return nullptr;
}

UObject* UDataTooltip::GetOwningSourceAsset() const
{
	if(OwningWidget)
	{
		return OwningWidget->GetTooltip_SourceObject();
	}
	return nullptr;
}
