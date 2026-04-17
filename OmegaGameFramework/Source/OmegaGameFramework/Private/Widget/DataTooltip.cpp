// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/DataTooltip.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"
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
				GetAssetDescriptionWidget()->SetText(UDataInterface_General::GetObjectDesc(source_object,FGameplayTag()));
			}
			if(GetAssetNameWidget())
			{
				GetAssetNameWidget()->SetText(UDataInterface_General::GetObjectName(source_object,FGameplayTag()));
			}
			if(GetAssetIconWidget())
			{
				GetAssetIconWidget()->SetBrush(UDataInterface_General::GetObjectIcon(source_object,FGameplayTag()));
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
