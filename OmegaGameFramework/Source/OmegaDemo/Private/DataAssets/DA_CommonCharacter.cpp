// Copyright Studio Syndicat 2025. All Rights Reserved.

#include "DataAssets/DA_CommonCharacter.h"

#include "Components/Component_Combatant.h"
#include "Components/Component_CombatantExtension.h"
#include "GameFramework/Character.h"


bool UOAsset_CommonCharacter::OnIdentityInit_Implementation(AActor* Actor, UActorIdentityComponent* Component)
{
	if(ACharacter* c=Cast<ACharacter>(Actor))
	{
		UOmegaComponentModifierFunctions::ApplyModifierTo_SkeletalMesh(Mesh,c->GetMesh());
	}
	if(UCombatantComponent* comp=Cast<UCombatantComponent>(Actor->GetComponentByClass(UCombatantComponent::StaticClass())))
	{
		if(Auto_SetCombatantSource) { comp->SetMasterDataSourceActive(this,true); }
	}
	FActorModifiers mods;
	mods.Script=ActorModifiers_OnInit;
	UOmegaComponentModifierFunctions::ApplyModifierTo_Actor(mods,Actor);
	
	return true;
}

bool UOAsset_CommonCharacter::OnActorTagEvent_Implementation(AActor* Actor, UActorIdentityComponent* Component,
	FGameplayTag Event)
{
	if(Actor && ActorModifiers_OnTagEvent.Contains(Event))
	{
		UOmegaComponentModifierFunctions::ApplyModifierTo_Actor(ActorModifiers_OnTagEvent[Event],Actor);
	}
	return IDataInterface_ActorIdentitySource::OnActorTagEvent_Implementation(Actor, Component, Event);
}
