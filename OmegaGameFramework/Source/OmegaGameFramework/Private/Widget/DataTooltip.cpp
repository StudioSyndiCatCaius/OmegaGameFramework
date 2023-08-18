// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/DataTooltip.h"

#include "OmegaGameFrameworkBPLibrary.h"
#include "Widget/DataWidget.h"

void UDataTooltip::SetOwningWidget(UDataWidget* NewOwner)
{
	OwningWidget = NewOwner;
	if(NewOwner)
	{
		if(GetAssetNameWidget())
		{
			GetAssetDescriptionWidget()->SetText(UOmegaGameFrameworkBPLibrary::GetObjectDisplayDescription(NewOwner->ReferencedAsset));
		}
		if(GetAssetDescriptionWidget())
		{
			GetAssetDescriptionWidget()->SetText(UOmegaGameFrameworkBPLibrary::GetObjectDisplayName(NewOwner->ReferencedAsset));
		}
		
	}
}

UDataWidget* UDataTooltip::GetOwningDataWidget()
{
	if(OwningWidget)
	{
		return OwningWidget;
	}
	return nullptr;
}

UObject* UDataTooltip::GetOwningSourceAsset()
{
	if(OwningWidget)
	{
		return OwningWidget->ReferencedAsset;
	}
	return nullptr;
}
