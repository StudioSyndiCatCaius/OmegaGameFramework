// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_Squad.h"

#include "FlowAsset.h"
#include "FlowMacros.h"
#include "Components/Component_AssetSquad.h"

UAssetSquadComponent* UFlowNode_SquadBASE::GetLinkedSquadComponent() const
{
	if (GetFlowAsset())
	{
		if (AActor* _actor=GetFlowAsset()->GetActorByBinding_Asset(TargetActor_Identity,true))
		{
			if (UAssetSquadComponent* _comp=Cast<UAssetSquadComponent>(_actor->GetComponentByClass(UAssetSquadComponent::StaticClass())))
			{
				return _comp;
			}
		}
	}
	return nullptr;
}

void UFlowNode_Squad_Edit::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	if (UAssetSquadComponent* comp=GetLinkedSquadComponent())
	{
		if (NewDefaultSquad)
		{
			comp->CurrentSquad_Set(NewDefaultSquad);
		}
		
		if (Squad_Identity)
		{
			if (bRemoveAllFirst)
			{
				comp->RemoveAllMembersFromSquad(Squad_Identity);	
			}
			else
			{
				comp->SetMembersInSquad(Members_Removed,Squad_Identity,false);
			}
			comp->SetMembersInSquad(Members_Added,Squad_Identity,true);
			
		}
	}
	TriggerFirstOutput(true);
}

UFlowNode_Squad_Check::UFlowNode_Squad_Check()
{
	FLOW_SETUP_PINS_OUTPUT_BOOL()
}

bool UFlowNode_Squad_Check::L_ValidityCheck()
{
	if (UAssetSquadComponent* comp=GetLinkedSquadComponent())
	{
		if (Squad_Identity)
		{
			for (auto* i : RequiredMembers)
			{
				if (i)
				{
					if (bRequireAllMembers!=comp->IsMemberInSquad(i,Squad_Identity))
					{
						return !bRequireAllMembers;
					}
				}
			}
		}
	}
	return bRequireAllMembers;
}

void UFlowNode_Squad_Check::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	
	if (L_ValidityCheck())
	{
		TriggerOutput(TEXT("true"),true);
	}
	else
	{
		TriggerOutput(TEXT("false"),true);
	}
}
