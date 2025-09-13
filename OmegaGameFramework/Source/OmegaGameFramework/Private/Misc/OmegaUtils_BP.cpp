// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Misc/OmegaUtils_BP.h"

UStaticMesh* OGF_BP::Load_Mesh(UObject* outer, FString name, FString path)
{
	FString in_path="/OmegaGameFramework/Meshes/"+path+name+"."+name;
	if(UStaticMesh* m =LoadObject<UStaticMesh>(outer,*in_path))
	{
		return m;
	}
	return nullptr;
}

UMaterialInterface* OGF_BP::Load_Material(UObject* outer, FString name, FString path)
{
	FString in_path="/OmegaGameFramework/Materials/"+path+name+"."+name;
	if(UMaterialInterface* m =LoadObject<UMaterialInterface>(outer,*in_path))
	{
		return m;
	}
	return nullptr;
}


UStaticMesh* OGF_BP::Mesh_WaterPlane(UObject* outer)
{
	
	return Load_Mesh(outer,"SM_OMEGA_WaterPlane","geo/");
}

UMaterialInterface* OGF_BP::Mat_Blank(UObject* outer)
{
	return Load_Material(outer,"m_Blank");
}

UMaterialInterface* OGF_BP::Mat_Water(UObject* outer)
{
	return Load_Material(outer,"M_OMEGA_Water","Shaders/");
}

UMaterialInterface* OGF_BP::Mat_Blocking(UObject* outer)
{
	return Load_Material(outer,"m_VolumeDisplay_Blocking","Instances/VolumeDisplay/");
}

