// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_DataWidget.h"
#include "GameFramework/Actor.h"
#include "Widget/DataWidget.h"


void UDataWidgetComponent::SetWidget(UUserWidget* InWidget)
{
	if(InWidget)
	{
		if(UDataWidget* loc_wid=Cast<UDataWidget>(InWidget))
		{
			loc_wid->SetSourceAsset(GetOwner());
		}
	}
	Super::SetWidget(InWidget);
}

UDataWidget* UDataWidgetComponent::GetDataWidget()
{
	if(UDataWidget* dat_wig = Cast<UDataWidget>(GetWidget()))
	{
		return dat_wig;
	}
	return nullptr;
}
