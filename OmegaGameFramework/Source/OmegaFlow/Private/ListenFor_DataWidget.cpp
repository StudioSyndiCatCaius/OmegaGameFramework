// Fill out your copyright notice in the Description page of Project Settings.


#include "ListenFor_DataWidget.h"

#include "Engine/GameInstance.h"
#include "Subsystems/Subsystem_Player.h"

void UListenFor_DataWidget::OnEvent(UDataWidget* Widget, uint8 Event)
{
	switch (Event)
	{
		case 0: Selected.Broadcast(Widget,this); break;
		case 1: Hover.Broadcast(Widget,this); break;
		case 2: Unhover.Broadcast(Widget,this); break;
	}
}

void UListenFor_DataWidget::Activate()
{
	Super::Activate();
	if (local_player)
	{
		local_player->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>()->DataWidgetSubsystemEvent.AddDynamic(this,&UListenFor_DataWidget::OnEvent);
	}
	else
	{
		SetReadyToDestroy();
	}
}

void UListenFor_DataWidget::KillTask()
{
	SetReadyToDestroy();
}

UListenFor_DataWidget* UListenFor_DataWidget::ListenFor_DataWidget(const APlayerController* Player)
{
	UListenFor_DataWidget* NewNode = NewObject<UListenFor_DataWidget>();
	NewNode->local_player = Player;
	return NewNode;
}
