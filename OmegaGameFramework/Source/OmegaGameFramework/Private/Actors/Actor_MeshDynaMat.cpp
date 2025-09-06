// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_MeshDynaMat.h"

void AStaticMeshDynaMat::OnConstruction(const FTransform& Transform)
{
	if(UStaticMesh* _mesh=GetStaticMeshComponent()->GetStaticMesh())
	{
		TArray<FStaticMaterial> mats=_mesh->GetStaticMaterials();
		for(FStaticMaterial p : mats)
		{
			int32 ind=mats.Find(p);
			UMaterialInterface* baseMat = nullptr;
			if(MaterialOverrides.IsValidIndex(ind) && MaterialOverrides[ind])
			{
				baseMat=MaterialOverrides[ind];
			}
			else if(p.MaterialInterface) { baseMat=p.MaterialInterface; }
			if(baseMat)
			{
				if(UMaterialInstanceDynamic* dynaMat=GetStaticMeshComponent()->CreateDynamicMaterialInstance(ind,baseMat))
				{
					if(MaterialParams_Slot.IsValidIndex(ind))
					{
						MaterialParams_Slot[ind].Apply(dynaMat);
					}
					MaterialParams_Default.Apply(dynaMat);
				}
			}
			
		}
	}
}
