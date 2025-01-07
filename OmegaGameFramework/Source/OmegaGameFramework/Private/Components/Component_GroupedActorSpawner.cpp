// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_GroupedActorSpawner.h"

#include "Functions/OmegaFunctions_Utility.h"
#include "Kismet/KismetMathLibrary.h"

void UGroupedActorSpawnerComponent::BeginPlay()
{
	if(bAutoSpawnOnBeginPlay)
	{
		SpawnAllPossibles(bAutoShuffleSpawnOrder);
	}
	Super::BeginPlay();
}

UChildActorComponent* UGroupedActorSpawnerComponent::Local_GetChildACtorComp(int32 index)
{
	while (!ref_childActors.IsValidIndex(index))
	{
		FString in_name="child_comp" + FString::FromInt(ref_childActors.Num()) + FString::FromInt(1);
		UChildActorComponent* new_comp = Cast<UChildActorComponent>(GetOwner()->AddComponentByClass(UChildActorComponent::StaticClass(),false,FTransform(),false));
		ref_childActors.Add(new_comp);
	}
	if(ref_childActors.IsValidIndex(index))
	{
		return ref_childActors[index];
	}
	return nullptr;
}

UChildActorComponent* UGroupedActorSpawnerComponent::Local_GetFirstEmptyChildACtorComp(int32& out_index)
{
	for (auto* out_child : ref_childActors)
	{
		if(out_child && !out_child->GetChildActor())
		{
			out_index=ref_childActors.Find(out_child);
			return out_child;
		}
	}
	UChildActorComponent* new_comp = Cast<UChildActorComponent>(GetOwner()->AddComponentByClass(UChildActorComponent::StaticClass(),false,FTransform(),false));
	ref_childActors.Add(new_comp);
	out_index=ref_childActors.Find(new_comp);
	return  new_comp;
}

void UGroupedActorSpawnerComponent::SpawnAllPossibles(bool bShuffleSpawnOrder)
{
	TArray<UGroupedActorSpawnerPossible*> valid_Possibles;
	for(auto* possible : Possibles)
	{
		if(possible)
		{
			int32 array_index = Possibles.Find(possible);
			if (possible->CanSpawn(this,array_index))
			{
				valid_Possibles.Add(possible);
			}
		}
	}
	int32 max_OfValid = valid_Possibles.Num()-1;
	if(bShuffleSpawnOrder)
	{
		const int32 LastIndex = valid_Possibles.Num() - 1;
		for (int32 i = 0; i < LastIndex; ++i)
		{
			const int32 Index = FMath::RandRange(i, LastIndex);
			if (i != Index)
			{
				valid_Possibles.Swap(i, Index);
			}
		}
	}
	for(auto* new_possible : valid_Possibles)
	{
		int32 index_OfAll = Possibles.Find(new_possible);
		int32 index_OfValid = valid_Possibles.Find(new_possible);
		float spawn_ratio = UOmegaMathFunctions::NormalizeToRange_int32(index_OfValid,0,max_OfValid);
		int32 tempIndex;
		
		if(UChildActorComponent* target_comp = Local_GetFirstEmptyChildACtorComp(tempIndex))
		{
			target_comp->SetChildActorClass(new_possible->GetActorClass(this));
			FTransform in_transform = GetRelativeTransform();
			FTransform mod_transform = new_possible->GetLocalSpawnTransform(this,index_OfValid,spawn_ratio);
			in_transform.SetLocation(in_transform.GetLocation()+mod_transform.GetLocation());
			FRotator now_rot = UKismetMathLibrary::ComposeRotators(in_transform.GetRotation().Rotator(),mod_transform.GetRotation().Rotator());
			in_transform.SetRotation(now_rot.Quaternion());
			target_comp->SetRelativeTransform(in_transform);
			new_possible->OnActorSpawned(this,target_comp->GetChildActor());
			OnGroupedActorSpawned.Broadcast(this,target_comp->GetChildActor());
		}
	}
}

void UGroupedActorSpawnerComponent::DestroyAllSpawnedActors()
{
	for(auto* temp_child : ref_childActors)
	{
		if(temp_child)
		{
			temp_child->SetChildActorClass(nullptr);
		}
	}
}
