// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_DataWidget.h"
#include "GameFramework/Actor.h"
#include "Widget/DataWidget.h"


void UDataWidgetComponent::L_OnSelect(UDataWidget* DataWidget)
{
	OnWidgetSelected.Broadcast(this,DataWidget);
}

void UDataWidgetComponent::L_OnHover(UDataWidget* DataWidget, bool bIsHovered)
{
	OnWidgetHovered.Broadcast(this,DataWidget,bIsHovered);
}

void UDataWidgetComponent::L_OnHighlight(UDataWidget* DataWidget, bool bIsHighlight)
{
	OnWidgetHighlight.Broadcast(this,DataWidget,bIsHighlight);
}

void UDataWidgetComponent::L_OnNotify(UDataWidget* DataWidget, FName Notify)
{
	OnWidgetNotify.Broadcast(this,DataWidget,Notify);
}

void UDataWidgetComponent::SetWidget(UUserWidget* InWidget)
{
	if(InWidget)
	{
		if(UDataWidget* loc_wid=GetDataWidget())
		{
			loc_wid->OnSelected.RemoveDynamic(this,&UDataWidgetComponent::L_OnSelect);
			loc_wid->OnHovered.RemoveDynamic(this,&UDataWidgetComponent::L_OnHover);
			loc_wid->OnHighlight.RemoveDynamic(this,&UDataWidgetComponent::L_OnHighlight);
			loc_wid->OnWidgetNotify.RemoveDynamic(this,&UDataWidgetComponent::L_OnNotify);
		}
		if(UDataWidget* loc_wid=Cast<UDataWidget>(InWidget))
		{
			loc_wid->SetSourceAsset(GetOwner());
			loc_wid->OnSelected.AddDynamic(this,&UDataWidgetComponent::L_OnSelect);
			loc_wid->OnHovered.AddDynamic(this,&UDataWidgetComponent::L_OnHover);
			loc_wid->OnHighlight.AddDynamic(this,&UDataWidgetComponent::L_OnHighlight);
			loc_wid->OnWidgetNotify.AddDynamic(this,&UDataWidgetComponent::L_OnNotify);
		}
	}
	Super::SetWidget(InWidget);
}

void UDataWidgetComponent::BeginPlay()
{
	Super::BeginPlay();
	SetWidget(GetWidget());
}

UDataWidget* UDataWidgetComponent::GetDataWidget()
{
	if(UDataWidget* dat_wig = Cast<UDataWidget>(GetWidget()))
	{
		return dat_wig;
	}
	return nullptr;
}
