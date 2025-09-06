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
	if(member)
	{
		if(!SquadData.Assignments.Contains(member))
		{
			SquadData.Assignments.Add(member,nullptr);
		}
		if(!SquadData.Order.Contains(member))
		{
			SquadData.Order.Add(member);
		}
	}
	return -1;
}

void UAssetSquadComponent::ValidateData()
{
	for(auto* i : SquadData.Order)
	{
		if(i) { ValidateMember(i);}
	}
	for(auto& p : SquadData.Assignments)
	{
		if(p.Key) { ValidateMember(p.Key);}
	}
}

TArray<UAssetSquad_Identity*> UAssetSquadComponent::L_GetListedSquads() const
{
	TArray<UAssetSquad_Identity*> sq;
	SquadData.Assignments.GenerateValueArray(sq);
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
	ValidateData();
	return SquadData;
}

void UAssetSquadComponent::RemoveAllMembersFromSquad(UAssetSquad_Identity* Squad)
{
	ValidateData();
	if(Squad)
	{
		TArray<UPrimaryDataAsset*> as;
		SquadData.Assignments.GetKeys(as);
		for(auto* a : as)
		{
			if(a)
			{
				SetMemberInSquad(a,Squad,false);	
			}
		}
	}
}

void UAssetSquadComponent::RemoveMemberFromAllSquads(UPrimaryDataAsset* Member)
{
	ValidateData();
	if(Member)
	{
		TArray<UAssetSquad_Identity*> sq;
		if(SquadData.Assignments.Contains(Member))
		{
			SquadData.Assignments.Remove(Member);
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
			SquadData.Assignments.Add(Member,Squad);
			OnSquadMembersChanged.Broadcast(this,Squad,Member,true);
		}
		else if(!InSquad && IsMemberInSquad(Member,Squad))
		{
			SquadData.Assignments.Add(Member,nullptr);
			OnSquadMembersChanged.Broadcast(this,Squad,Member,false);
		}
	}
}

void UAssetSquadComponent::SetMembersInSquad(TArray<UPrimaryDataAsset*> Members, UAssetSquad_Identity* Squad,
	bool InSquad)
{
	for(auto* a : Members)
	{
		if(a) { SetMemberInSquad(a,Squad,InSquad);}
	}
}

TArray<UPrimaryDataAsset*> UAssetSquadComponent::GetSquadMembers(UAssetSquad_Identity* Squad)
{
	TArray<UPrimaryDataAsset*> out;
	if(!Squad) { return out;}
	ValidateData();
	for(auto* P : SquadData.Order)
	{
		if(P && GetMemberSquad(P)==Squad)
		{
			out.Add(P);
		}
	}
	return out;
}

UAssetSquad_Identity* UAssetSquadComponent::GetMemberSquad(UPrimaryDataAsset* Member)
{
	if(Member && SquadData.Assignments.Contains(Member))
	{
		return SquadData.Assignments.FindOrAdd(Member);
	} 
	return nullptr;
}

int32 UAssetSquadComponent::GetMemberIndex_InFirstSquad(UPrimaryDataAsset* Member)
{
	if(Member)
	{
		ValidateMember(Member);
		if(UAssetSquad_Identity* sq=GetMemberSquad(Member))
		{
			TArray<UPrimaryDataAsset*> l=GetSquadMembers(sq);
			if(l.Contains(Member)) { return l.Find(Member);}
		}
	}
	return -1;
}

bool UAssetSquadComponent::IsMemberInSquad(UPrimaryDataAsset* Member, UAssetSquad_Identity* Squad)
{
	if(Member && Squad && GetMemberSquad(Member)==Squad)
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
	if(SquadData.Order.IsValidIndex(i_a) && SquadData.Order.IsValidIndex(i_b))
	{
		SquadData.Order.Swap(i_a,i_b);
		OnAssetSquadMembersSwapped.Broadcast(this,s_a,s_b);
	}
	
}
