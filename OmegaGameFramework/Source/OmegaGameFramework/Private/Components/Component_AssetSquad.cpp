// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Components/Component_AssetSquad.h"

#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_Save.h"


UAssetSquad_Identity* UAssetSquadComponent::ValidateSquadID(UAssetSquad_Identity* override)
{
	if(override) { return override;} return CurrentSquad_Get();
}

int32 UAssetSquadComponent::ValidateMember(UPrimaryDataAsset* member)
{
	if(member)
	{
		if(!L_GetSquadData()->Assignments.Contains(member))
		{
			L_GetSquadData()->Assignments.Add(member,nullptr);
		}
		if(!L_GetSquadData()->Order.Contains(member))
		{
			L_GetSquadData()->Order.Add(member);
		}
	}
	return -1;
}

void UAssetSquadComponent::ValidateData()
{
	for(auto* i : L_GetSquadData()->Order)
	{
		if(i) { ValidateMember(i);}
	}
	for(auto& p : L_GetSquadData()->Assignments)
	{
		if(p.Key) { ValidateMember(p.Key);}
	}
}

TArray<UAssetSquad_Identity*> UAssetSquadComponent::L_GetListedSquads()
{
	TArray<UAssetSquad_Identity*> sq;
	L_GetSquadData()->Assignments.GenerateValueArray(sq);
	return sq;
}

void UAssetSquadComponent::BeginPlay()
{
	if(!CurrentSquad_Get())
	{
		CurrentSquad_Set(NewObject<UAssetSquad_Identity>(this,UAssetSquad_Identity::StaticClass()));
	}
	Super::BeginPlay();
}

FOmegaAssetSquad_Data* UAssetSquadComponent::L_GetSquadData()
{
	if (UOmegaSaveSubsystem* s=OGF_Subsystems::oSave(this))
	{
		return & s->GetSaveObject(false)->SquadData.FindOrAdd(SaveBinding);
	}
	return &SquadData;
}

void UAssetSquadComponent::CurrentSquad_Set(UAssetSquad_Identity* Squad)
{
	if (CurrentSquad_Get()!=Squad)
	{
		L_GetSquadData()->CurrentSquad=Squad;
	}
}

UAssetSquad_Identity* UAssetSquadComponent::CurrentSquad_Get()
{
	return L_GetSquadData()->CurrentSquad;
}

void UAssetSquadComponent::SetSquadData(FOmegaAssetSquad_Data Data)
{
	SquadData=Data;
}

FOmegaAssetSquad_Data UAssetSquadComponent::GetSquadData()
{
	ValidateData();
	return *L_GetSquadData();
}

void UAssetSquadComponent::RemoveAllMembersFromSquad(UAssetSquad_Identity* Squad)
{
	ValidateData();
	if(Squad)
	{
		TArray<UPrimaryDataAsset*> as;
		L_GetSquadData()->Assignments.GetKeys(as);
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
		if(L_GetSquadData()->Assignments.Contains(Member))
		{
			L_GetSquadData()->Assignments.Remove(Member);
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
			L_GetSquadData()->Assignments.Add(Member,Squad);
			OnSquadMembersChanged.Broadcast(this,Squad,Member,true);
		}
		else if(!InSquad && IsMemberInSquad(Member,Squad))
		{
			L_GetSquadData()->Assignments.Add(Member,nullptr);
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
	for(auto* P : L_GetSquadData()->Order)
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
	if(Member && L_GetSquadData()->Assignments.Contains(Member))
	{
		return L_GetSquadData()->Assignments.FindOrAdd(Member);
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
	if(L_GetSquadData()->Order.IsValidIndex(i_a) && L_GetSquadData()->Order.IsValidIndex(i_b))
	{
		L_GetSquadData()->Order.Swap(i_a,i_b);
		OnAssetSquadMembersSwapped.Broadcast(this,s_a,s_b);
	}
	
}
