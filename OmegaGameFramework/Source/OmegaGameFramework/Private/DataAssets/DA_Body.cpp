// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "DataAssets/DA_Body.h"

#include "SkeletalMergingLibrary.h"

USkeletalMesh* UOmegaBodyType::GenerateMesh_FromParams(FOmegaBodyAppearanceData data)
{
	if(BaseSkeleton)
	{
		FOmegaBodyAppearanceData _data=data;
		FSkeletalMeshMergeParams MergeParams;
		TArray<USkeletalMesh*> mesh_list;

		TArray<FName> slot_names;
		TArray<UOmegaBodySlot*> _slots;
		BodySlots.GenerateValueArray(_slots);
		BodySlots.GetKeys(slot_names);
		//get meshes from slots
		for(FName n : slot_names)
		{
			if(BodySlots.Contains(n))
			{
				if(UOmegaBodySlot* s=BodySlots[n])
				{
					if(USkeletalMesh* m=s->GetMeshFromIndex(_data.params_int.FindOrAdd(n)))
					{
						if(m->GetSkeleton())
						{
							mesh_list.Add(m);	
						}
					}
				}
			}
		}
		
		//merge meshes
		MergeParams.Skeleton=BaseSkeleton;
		MergeParams.MeshesToMerge=mesh_list;
		
		if(USkeletalMesh* newm=USkeletalMergingLibrary::MergeMeshes(MergeParams))
		{
			for(auto* s :_slots)
			{
				if(s)
				{
					s->PostMeshEdit(newm);
				}
			}
			return newm;
		}
	}
	return nullptr;
}

USkeletalMesh* UOmegaBodyType::GenerateMesh_FromSeed(int32 seed)
{
	FOmegaBodyAppearanceData _data;
	TArray<FName> slot_names;
	BodySlots.GetKeys(slot_names);
	for(FName n : slot_names)
	{
		if(BodySlots.Contains(n))
		{
			if(UOmegaBodySlot* s=BodySlots[n])
			{
				FRandomStream stream=FRandomStream(seed);
				_data.params_int.Add(n,stream.RandRange(0,s->GetMaxValue().X));
			}
		}
		
	}
	return GenerateMesh_FromParams(_data);
}

TArray<UOmegaBodySlot*> UOmegaBodyType::GetSlots() const
{
	TArray<UOmegaBodySlot*>	v;
	BodySlots.GenerateValueArray(v);
	return v;
}

FVector UOmegaBodySlot::GetDefaultValue()
{
	return FVector();
}

FVector UOmegaBodySlot::GetMaxValue() const
{
	if(Script) { return Script->GetMaxValue(); }
	return FVector();
}

EOmegaBodySlotType UOmegaBodySlot::GetSlotType()
{
	return EOmegaBodySlotType::BODYSLOT_BOOL;
}

USkeletalMesh* UOmegaBodySlot::GetMeshFromIndex(int32 index) const
{
	if(Script) { return Script->GetMeshFromIndex(index); }
	return nullptr;
}

bool UOmegaBodySlot::PostMeshEdit(USkeletalMesh* Mesh) const
{
	if(Mesh && Script)
	{
		Script->PostMeshCreationEdit(Mesh);
		for(FSkeletalMaterial m : Mesh->GetMaterials())
		{
			Script->PostMaterialSlotEdit(Mesh,Mesh->GetMaterials().Find(m),m.MaterialSlotName,m.MaterialInterface);
		}
		return true;
	}
	return false;
}
