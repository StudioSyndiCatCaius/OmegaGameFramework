// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Component.h"

#include "Components/TextRenderComponent.h"
#include "Condition/Condition_Actor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/OmegaUtils_Actor.h"
#include "Materials/Material.h"

bool UActorModifierScript::OnAppliedToActor_Implementation(AActor* Actor) const
{
	return false;
}

bool UComponentModScript_SkeletalMesh::OnAppliedToComponent_Implementation(USkeletalMeshComponent* Component) const
{
	return false;
}

bool UComponentModScript_StaticMesh::OnAppliedToComponent_Implementation(UStaticMeshComponent* Component) const
{
	return false;
}

bool UComponentModScript_InstancedStaticMesh::OnAppliedToComponent_Implementation(
	UInstancedStaticMeshComponent* Component) const
{
	return false;
}

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
	if(Component)
	{
		for (auto* s : mod.Scripts)
		{
			if(s) { s->OnAppliedToComponent(Component); }
		}
	}
}

void UOmegaComponentModifierFunctions::ApplyModifierTo_StaticMesh(FComponentMod_StaticMesh mod,
	UStaticMeshComponent* Component)
{
	if(Component)
	{
		for (auto* s : mod.Scripts)
		{
			if(s) { s->OnAppliedToComponent(Component); }
		}
	}
}

void UOmegaComponentModifierFunctions::ApplyModifierTo_InstancedStaticMesh(FComponentMod_InstancedStaticMesh mod,
	UInstancedStaticMeshComponent* Component)
{
	if(Component)
	{
		for (auto* s : mod.Scripts)
		{
			if(s) { s->OnAppliedToComponent(Component); }
		}
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

void UOmegaComponentModifierFunctions::SnapLocalToCenterOfBounds(USceneComponent* Component)
{
	if(!Component) { return; }
	Component->UpdateBounds();

	// The point the component is *supposed* to appear at: its attach point (relative location zero).
	// A root/unattached component has no fixed attach point to snap against.
	const USceneComponent* Parent = Component->GetAttachParent();
	if(!Parent) { return; }
	const FVector TargetLocation = Parent->GetSocketTransform(Component->GetAttachSocketName()).GetLocation();

	// Shift the component so its bounds origin lands on that point, making an off-center
	// pivot appear as though it sits at the center of the bounds. Idempotent: once the
	// bounds origin is on the attach point, the offset is zero.
	Component->AddWorldOffset(TargetLocation - Component->Bounds.Origin);
}

void UOmegaComponentModifierFunctions::ScaleAbsoluteByBounds(USceneComponent* Component, float Size)
{
	if(!Component || Size <= 0.f) { return; }
	Component->UpdateBounds();

	// Largest world-space dimension of the current bounds; scaling by Size/CurrentSize makes
	// that dimension equal Size, so differently-sized assets appear identical for the same Size.
	const float CurrentSize = Component->Bounds.BoxExtent.GetMax() * 2.f;
	if(CurrentSize <= UE_KINDA_SMALL_NUMBER) { return; }

	Component->SetWorldScale3D(Component->GetComponentScale() * (Size / CurrentSize));
}
