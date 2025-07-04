// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_Actors.h"

#include "Functions/OmegaFunctions_Actor.h"


void UFlowNode_Actor_Modify::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);

	FActorModifiers mods;
	mods.Script=Modifiers;
	FOmegaActorSelectorData selector;
	selector.Selector=Actor;

	for(auto * a : UOmegaActorUtilFunctions::GetSelectedActors(this,selector))
	{
		if(a)
		{
			UOmegaComponentModifierFunctions::ApplyModifierTo_Actor(mods,a);
		}
	}
	TriggerFirstOutput(true);
}
