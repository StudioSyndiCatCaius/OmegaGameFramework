// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Components/Component_AssetSquad.h"

#include "Components/Component_ActorIdentity.h"
#include "Components/Component_Combatant.h"


UAssetSquad_Identity* UAssetSquadComponent::ValidateSquadID(UAssetSquad_Identity* override) const
{
	if(override) { return override;} return Default_SquadID;
}

int32 UAssetSquadComponent::ValidateMember(UPrimaryDataAsset* member)
{

	return -1;
}

void UAssetSquadComponent::ValidateData()
{

}

TArray<UAssetSquad_Identity*> UAssetSquadComponent::L_GetListedSquads() const
{
	TArray<UAssetSquad_Identity*> sq;
	SquadData.SquadMembers.GetKeys(sq);
	return sq;
}

void UAssetSquadComponent::BeginPlay()
{
	if(!Default_SquadID)
	{
		Default_SquadID=NewObject<UAssetSquad_Identity>(this,UAssetSquad_Identity::StaticClass());
	}
	Super::BeginPlay();
}

void UAssetSquadComponent::SetSquadData(FOmegaAssetSquad_Data Data)
{
	SquadData=Data;
}

FOmegaAssetSquad_Data UAssetSquadComponent::GetSquadData()
{
	return SquadData;
}

void UAssetSquadComponent::RemoveMemberFromAllSquads(UPrimaryDataAsset* Member)
{
	if(Member)
	{
		TArray<UAssetSquad_Identity*> sq;
		SquadData.SquadMembers.GetKeys(sq);
		for(auto* s : sq)
		{
			SetMemberInSquad(Member,s,false);
		}
	}
}

void UAssetSquadComponent::SetMemberInSquad(UPrimaryDataAsset* Member, UAssetSquad_Identity* Squad, bool InSquad)
{
	if(Member && Squad)
	{
		if(InSquad && !IsMemberInSquad(Member,Squad))
		{
			if(OneSquadPerAsset)
			{
				RemoveMemberFromAllSquads(Member);
			}
			SquadData.SquadMembers.FindOrAdd(Squad).List.Add(Member);
			OnSquadMembersChanged.Broadcast(this,Squad,Member,true);
		}
		else if(!InSquad && IsMemberInSquad(Member,Squad))
		{
			SquadData.SquadMembers.FindOrAdd(Squad).List.Remove(Member);
			OnSquadMembersChanged.Broadcast(this,Squad,Member,false);
		}
	}
}

TArray<UPrimaryDataAsset*> UAssetSquadComponent::GetSquadMembers(UAssetSquad_Identity* Squad)
{
	return SquadData.SquadMembers.FindOrAdd(Squad).List;
}

UAssetSquad_Identity* UAssetSquadComponent::GetMemberSquad(UPrimaryDataAsset* Member)
{
	if(Member)
	{
		TArray<UAssetSquad_Identity*> sq;
		SquadData.SquadMembers.GetKeys(sq);
		for(auto* s : sq)
		{
			if(SquadData.SquadMembers.FindOrAdd(s).List.Contains(Member))
			{
				return s;
			}
		}
	}
	return nullptr;
}

int32 UAssetSquadComponent::GetMemberIndex_InFirstSquad(UPrimaryDataAsset* Member)
{
	for(auto* s : L_GetListedSquads())
	{
		if(SquadData.SquadMembers.FindOrAdd(s).List.Contains(Member))
		{
			return SquadData.SquadMembers.FindOrAdd(s).List.Find(Member);
		}
	}
	return -1;
}

bool UAssetSquadComponent::IsMemberInSquad(UPrimaryDataAsset* Member, UAssetSquad_Identity* Squad)
{
	if(SquadData.SquadMembers.Contains(Squad) && SquadData.SquadMembers[Squad].List.Contains(Member))
	{
		return true;
	}
	return false;
}

bool UAssetSquadComponent::CanAddMemberToSquad(UPrimaryDataAsset* Member, UAssetSquad_Identity* Squad)
{
	if(Member && Squad)
	{
		int32 memc=GetSquadMembers(Squad).Num();
	}
	return false;
}

void UAssetSquadComponent::SwapSquadMembers(UPrimaryDataAsset* A, UPrimaryDataAsset* B)
{
	int32 i_a=GetMemberIndex_InFirstSquad(A);
	UAssetSquad_Identity* s_a=GetMemberSquad(A);
	int32 i_b=GetMemberIndex_InFirstSquad(B);
	UAssetSquad_Identity* s_b=GetMemberSquad(B);
	if(s_b)
	{
		SquadData.SquadMembers.FindOrAdd(s_b).List.Insert(A,i_b);
	}
	if(s_a)
	{
		SquadData.SquadMembers.FindOrAdd(s_a).List.Insert(B,i_a);
	}
}
