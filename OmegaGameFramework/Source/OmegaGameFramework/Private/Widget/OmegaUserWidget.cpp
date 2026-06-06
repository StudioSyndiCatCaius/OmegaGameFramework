// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/OmegaUserWidget.h"

#include "Actors/Actor_Player.h"
#include "Components/Component_Combatant.h"

AOmegaPlayer* UOmegaUserWidget::GetOwningOmegaPlayer() const
{
	if (AOmegaPlayer* p=Cast<AOmegaPlayer>(GetOwningPlayer()))
	{
		return p;
	}
	return nullptr;
}

UCombatantComponent* UOmegaUserWidget::GetOwningCombatant_Controller() const
{
	if (AOmegaPlayer* p=GetOwningOmegaPlayer())
	{
		return p->Combatant;
	}
	return nullptr;
}

UCombatantComponent* UOmegaUserWidget::GetOwningCombatant_Pawn() const
{
	if (UCombatantComponent* c=Cast<UCombatantComponent>(GetOwningPlayerPawn()->GetComponentByClass(UCombatantComponent::StaticClass())))
	{
		return c;
	}
	return nullptr;
}
