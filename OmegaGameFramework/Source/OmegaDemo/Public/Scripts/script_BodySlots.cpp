#include "script_BodySlots.h"

USkeletalMesh* UBodySlotScript_SkelMeshFromArray::GetMeshFromIndex_Implementation(
	FOmegaBodyOptionValue OptionValue) const
{
	int32 ind=OptionValue.value_float;
	if (Meshes.IsValidIndex(ind))
	{
		if (USkeletalMesh* skMesh=Meshes[ind].LoadSynchronous())
		{
			return skMesh;
		}
	}
	return nullptr;
}

FVector UBodySlotScript_SkelMeshFromArray::GetMaxValue_Implementation() const
{
	FVector out;
	out.X = Meshes.Num()-1;
	return out;
}


void UBodySlotScript_MaterialFromArray::OnApplied_ToMeshComponent_Implementation(USkeletalMeshComponent* Component,
	FOmegaBodyOptionValue OptionValue) const
{
	if (Component->GetMaterialSlotNames().Contains(MaterialSlot))
	{
		int32 ind=OptionValue.value_float;
		int32 matInd=Component->GetMaterialSlotNames().Find(MaterialSlot);
		if (Materials.IsValidIndex(ind))
		{
			if (UMaterialInterface* mat=Materials[ind].LoadSynchronous())
			{
				Component->SetMaterial(matInd,mat);
			}
		}
	}
}

FVector UBodySlotScript_MaterialFromArray::GetMaxValue_Implementation() const
{
	FVector out;
	out.X = Materials.Num()-1;
	return out;
}
