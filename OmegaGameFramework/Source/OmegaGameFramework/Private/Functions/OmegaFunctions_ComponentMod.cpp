// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_ComponentMod.h"

#include "Components/TextRenderComponent.h"
#include "Condition/Condition_Actor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/OmegaUtils_Actor.h"

void UOmegaComponentModifierFunctions::ApplyModifierTo_Actor(FActorModifiers mods, AActor* Actor)
{
	if(Actor)
	{
		for(auto* c : mods.Script)
		{
			if(c) { c->OnAppliedToActor(Actor); }
		}
	}
}

void UOmegaComponentModifierFunctions::RunActorModifierContainer(UObject* WorldContextObject,
	FActorModiferContainer container)
{
	if(WorldContextObject && container.ActorSelector)
	{
		for(auto* a : container.ActorSelector->GetActors(WorldContextObject))
		{
			FOmegaConditions_Actor cond;
			cond.Conditions=container.Conditions;
			if(a && cond.CheckConditions(a))
			{
				FActorModifiers mod;
				mod.Script=container.Modifiers;
				mod.ApplyMods(a);
			}
		}
	}
}

void UOmegaComponentModifierFunctions::ApplyModifierTo_Component(FComponentMods mod, UActorComponent* Component)
{
	if(Component)
	{
		for(auto* c : mod.Script)
		{
			if(c) { c->OnAppliedToComponent(Component); }
		}
	}
}

void UOmegaComponentModifierFunctions::ApplyModifierTo_SkeletalMesh(FComponentMod_SkeletalMesh mod,
                                                                    USkeletalMeshComponent* Component)
{
	if(Component && mod.Script)
	{
		mod.Script->OnAppliedToComponent(Component);
	}
}

void UOmegaComponentModifierFunctions::ApplyModifierTo_StaticMesh(FComponentMod_StaticMesh mod,
	UStaticMeshComponent* Component)
{
	if(Component && mod.Script)
	{
		mod.Script->OnAppliedToComponent(Component);
	}
}

void UOmegaComponentModifierFunctions::ApplyModifierTo_InstancedStaticMesh(FComponentMod_InstancedStaticMesh mod,
	UInstancedStaticMeshComponent* Component)
{
	if(Component && mod.Script)
	{
		mod.Script->OnAppliedToComponent(Component);
	}
}

void UOmegaComponentModifierFunctions::SetTextComponentType_Util(UTextRenderComponent* Component)
{
	if(Component)
	{
		Component->SetMaterial(0,LoadObject<UMaterial>(Component,TEXT("/OmegaGameFramework/Materials/m_OutlineText.m_OutlineText")));
		Component->HorizontalAlignment=EHTA_Center;
		Component->WorldSize=50;
		Component->VerticalAlignment=EVRTA_TextBottom;
		Component->bHiddenInGame=true;
	
	}
}
