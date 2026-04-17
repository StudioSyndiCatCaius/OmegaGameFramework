// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "GeometryScript/MeshPrimitiveFunctions.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/StaticMesh.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "F_DynamicMesh.generated.h"




UCLASS()
class UOmegaFunctions_DynamicMesh : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	//#####################################################################################//
	// Dynamic Mesh //
	//#####################################################################################//

	UFUNCTION(BlueprintCallable, Category="Omega|Dynamic Mesh",DisplayName="Dynamic Mesh - Build Along Spline")
	static UDynamicMesh* BuildAlongSpline(UDynamicMesh* DynamicMesh, USplineComponent* Spline, FTransform Transform, float Height,
														FGeometryScriptPrimitiveOptions PrimitiveOptions);


};
