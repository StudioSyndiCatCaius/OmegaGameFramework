// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_Util.h"

TArray<FName> UFlowNode_UTIL_ToHUB::L_GetHubs() const
{
	TArray<FName> out;
	if (UOmegaGameAsset* own=GetOwningGameplayAsset())
	{
		for (auto* n : own->FlowNode_GetAll())
		{
			if (UFlowNode_UTIL_HUB* h=Cast<UFlowNode_UTIL_HUB>(n))
			{
				out.AddUnique(h->HUB);
			}
		}
	}
	return out;
}
