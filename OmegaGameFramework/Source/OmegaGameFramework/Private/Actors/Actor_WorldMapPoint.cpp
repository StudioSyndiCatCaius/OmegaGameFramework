// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_WorldMapPoint.h"

#include "OmegaGameplayConfig.h"
#include "Components/BillboardComponent.h"
#include "Components/Component_ActorConfig.h"
#include "Components/Component_DataWidget.h"
#include "Components/SphereComponent.h"
#include "Widget/DataWidget.h"

AOmegaWorldMapPoint::AOmegaWorldMapPoint()
{
	Range=CreateDefaultSubobject<USphereComponent>("Range");
	Range->ShapeColor=FColor::Yellow;
	Range->SetLineThickness(5);
	Range->SetSphereRadius(200);
	RootComponent=Range;
	DataWidgetComponent=CreateDefaultSubobject<UDataWidgetComponent>("DataWidget");
	DataWidgetComponent->SetupAttachment(RootComponent);
	DataWidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
	cmp_icon=CreateOptionalDefaultSubobject<UBillboardComponent>("cmp_Icon");
	cmp_icon->SetupAttachment(RootComponent);
	Config=CreateOptionalDefaultSubobject<UActorConfigComponent>("Config");

	AActor::SetActorHiddenInGame(true);
}

void AOmegaWorldMapPoint::OnDW_Selected(UDataWidget* DataWidget)
{
	if(!IsHidden())
	{
		OnPointSelected.Broadcast(this,DataWidget->GetOwningPlayer());
	}
}

void AOmegaWorldMapPoint::BeginPlay()
{
	Super::BeginPlay();

}

void AOmegaWorldMapPoint::NotifyActorBeginCursorOver()
{
	Super::NotifyActorBeginCursorOver();
	if(IsHidden()) { return; }
	if(UDataWidget* _dw=DataWidgetComponent->GetDataWidget())
	{
		_dw->Hover();
	}
}

void AOmegaWorldMapPoint::NotifyActorEndCursorOver()
{
	Super::NotifyActorEndCursorOver();
	if(IsHidden()) { return; }
	if(UDataWidget* _dw=DataWidgetComponent->GetDataWidget())
	{
		_dw->Unhover();
	}
}
