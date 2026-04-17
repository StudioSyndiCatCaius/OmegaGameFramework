// Copyright Studio Syndicat 2026. All Rights Reserved.

#include "modifiers_component.h"


bool USkelMeshMod_Mesh::OnAppliedToComponent_Implementation(USkeletalMeshComponent* Component) const
{
	if (Component)
	{
		if (SkeletalMesh)
		{
			Component->SetSkeletalMesh(SkeletalMesh);
			
			for (auto* m : Materials)
			{
				if (m)
				{
					Component->SetMaterial(Materials.Find(m),m);
				}
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
