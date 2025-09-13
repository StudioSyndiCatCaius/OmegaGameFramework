// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"



/// BLUEPRINT

class OGF_BP
{
public:

	static UStaticMesh* Load_Mesh(UObject* outer, FString name, FString path="");
	static UMaterialInterface* Load_Material(UObject* outer, FString name, FString path="");

	// Meshes
	static UStaticMesh* Mesh_WaterPlane(UObject* outer);

	//Materials
	static UMaterialInterface* Mat_Blank(UObject* outer);
	static UMaterialInterface* Mat_Water(UObject* outer);
	static UMaterialInterface* Mat_Blocking(UObject* outer);
};