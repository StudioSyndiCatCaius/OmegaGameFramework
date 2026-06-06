// Copyright Studio Syndicat 2026. All Rights Reserved.

#include "modifiers_component.h"



bool USkelMeshMod_Mesh::OnAppliedToComponent_Implementation(USkeletalMeshComponent* Component) const
{
	if (Component)
	{
		if (SkeletalMesh)
		{
			Component->SetSkeletalMesh(SkeletalMesh);
			
			const TArray<FSkeletalMaterial>& MeshMaterials = SkeletalMesh->GetMaterials();
			for (int32 _ind = 0; _ind < MeshMaterials.Num(); _ind++)
			{
				UMaterialInterface* inMat = MeshMaterials[_ind].MaterialInterface;
				if (Materials.IsValidIndex(_ind) && Materials[_ind])
				{
					inMat = Materials[_ind];
				}
				Component->SetMaterial(_ind, inMat);
			}
			
			TArray<FName> slot_list=Component->GetMaterialSlotNames();
			for (FName n : slot_list)
			{
				if (Materials_BySlot.Contains(n))
				{
					Component->SetMaterial(slot_list.Find(n),Materials_BySlot[n]);
				}
			}
			if (bEditLocation)
			{
				Component->SetRelativeLocation(Location);
			}
			if (bEditRotation)
			{
				Component->SetRelativeRotation(Rotation);
			}
			if (bEditScale)
			{
				Component->SetRelativeScale3D(Scale);
			}
		}
	}
	return true;
}
