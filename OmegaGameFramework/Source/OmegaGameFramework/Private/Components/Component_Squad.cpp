// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Components/Component_Squad.h"

#include "Components/Component_ActorIdentity.h"
#include "Components/Component_Combatant.h"


UActorSquad_Identity* UActorSquadComponent::ValidateSquadID(UActorSquad_Identity* override) const
{
	if(override) { return override;} return Default_SquadID;
}

void UActorSquadComponent::BeginPlay()
{
	if(!Default_SquadID)
	{
		Default_SquadID=NewObject<UActorSquad_Identity>(this,UActorSquad_Identity::StaticClass());
	}
	Super::BeginPlay();
}

TArray<AActor*> UActorSquadComponent::GetSquadMembers(UActorSquad_Identity* Squad)
{
	TArray<AActor*> out;
	if(UActorSquad_Identity* sq = ValidateSquadID(Squad))
	{
		for(auto* i : SquadData.FindOrAdd(sq).Members)
		{
			if(i) { out.Add(i);}
		}
		SquadData.FindOrAdd(sq).Members=out;
	}
	return out;
}

TArray<UPrimaryDataAsset*> UActorSquadComponent::GetSquadMemberAssets(UActorSquad_Identity* Squad)
{
	TArray<UPrimaryDataAsset*> out;
	for(auto * a : GetSquadMembers(Squad))
	{
		bool res;
		if(UPrimaryDataAsset* asset=UOmegaActorIdentityFunctions::GetActorIdentityAsset(a,res))
		{
			out.Add(asset);
		}
	}
	return out;
}

void UActorSquadComponent::SetSquadOrder_FromAssets(TArray<UPrimaryDataAsset*> Order,UActorSquad_Identity* Squad)
{
	if(UActorSquad_Identity* sq = ValidateSquadID(Squad))
	{
		TArray<AActor*> new_order;
		TArray<AActor*> old_order=GetSquadMembers(sq);
		for(auto* o : Order)
		{
			if(AActor* _act=GetMember_ByAsset(o,sq))
			{
				new_order.Add(_act);
				if(old_order.Contains(_act))
				{
					old_order.Remove(_act);
				}
			}
		}
		for(auto* o : old_order)
		{
			if(o)
			{
				new_order.AddUnique(o);
			}
		}
	}
}

void UActorSquadComponent::SetActorInSquad(AActor* Actor, bool bInSquad,UActorSquad_Identity* Squad)
{
	if(Actor)
	{
		if(UActorSquad_Identity* sq = ValidateSquadID(Squad))
		{
			if(!SquadData.FindOrAdd(sq).Members.Contains(Actor) && bInSquad)
			{
				SquadData.FindOrAdd(sq).Members.Add(Actor);
				OnSquadMembersChanged.Broadcast(this,Actor,true);
			}
			else if (SquadData.FindOrAdd(sq).Members.Contains(Actor) && !bInSquad)
			{
				SquadData.FindOrAdd(sq).Members.Remove(Actor);
				OnSquadMembersChanged.Broadcast(this,Actor,false);
			}
		}
	}
}

void UActorSquadComponent::SwapSquadMembers_ByIndex(int32 A, int32 B,UActorSquad_Identity* Squad)
{
	if(UActorSquad_Identity* sq = ValidateSquadID(Squad))
	{
		if(SquadData.FindOrAdd(sq).Members.IsValidIndex(A) && SquadData.FindOrAdd(sq).Members.IsValidIndex(B))
		{
			GetSquadMembers(sq);
			SquadData.FindOrAdd(sq).Members.Swap(A,B);
		}
	}
}

void UActorSquadComponent::SwapSquadMembers_ByAsset(UPrimaryDataAsset* A, UPrimaryDataAsset* B,UActorSquad_Identity* Squad)
{
	SwapSquadMembers_ByIndex(GetMemberIndex_ByAsset(A,Squad),GetMemberIndex_ByAsset(B,Squad),Squad);
}

AActor* UActorSquadComponent::GetMember_ByAsset(UPrimaryDataAsset* Asset,UActorSquad_Identity* Squad)
{
	if(Asset)
	{
		for(auto* i : GetSquadMembers(Squad))
		{
			bool res;
			if(i && UOmegaActorIdentityFunctions::GetActorIdentityAsset(i,res)==Asset)
			{
				return i;
			}
		}
	}
	return nullptr;
}

int32 UActorSquadComponent::GetMemberIndex_ByAsset(UPrimaryDataAsset* Asset,UActorSquad_Identity* Squad)
{
	if(Asset)
	{
		for(auto* i : GetSquadMembers(Squad))
		{
			bool res;
			if(i && UOmegaActorIdentityFunctions::GetActorIdentityAsset(i,res)==Asset)
			{
				return GetSquadMembers(Squad).Find(i);
			}
		}
	}
	return -1;
}
