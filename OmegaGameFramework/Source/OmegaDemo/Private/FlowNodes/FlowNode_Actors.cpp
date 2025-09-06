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

bool UFlowNode_Actor_Condition::L_CheckCondition()
{
	if(Actor)
	{
		for(auto* a : Actor->GetActors(GetWorld()))
		{
			if (a)
			{
				for(auto* c : Conditions)
				{
					if(!c->CheckActorCondition(a))
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}

UFlowNode_Actor_Condition::UFlowNode_Actor_Condition()
{
	InputPins.Empty();
	OutputPins.Empty();
	InputPins.Add(FFlowPin(TEXT("In")));
	
	OutputPins.Add(FFlowPin(TEXT("true")));
	OutputPins.Add(FFlowPin(TEXT("false")));
}

void UFlowNode_Actor_Condition::ExecuteInput(const FName& PinName)
{
	if(L_CheckCondition())
	{
		TriggerOutput(TEXT("true"));
	}
	else
	{
		TriggerOutput(TEXT("false"));	
	}
}
