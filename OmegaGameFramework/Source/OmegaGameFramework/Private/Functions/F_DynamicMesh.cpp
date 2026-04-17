// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_DynamicMesh.h"

#include "Functions/F_Spline.h"
#include "GeometryScript/MeshNormalsFunctions.h"

UDynamicMesh* UOmegaFunctions_DynamicMesh::BuildAlongSpline(UDynamicMesh* DynamicMesh, USplineComponent* Spline,
                                                            FTransform Transform, float Height, FGeometryScriptPrimitiveOptions PrimitiveOptions)
{
	if(Spline && DynamicMesh)
	{
		FGeometryScriptSplitNormalsOptions Local_NormOpt;
		FGeometryScriptCalculateNormalsOptions Local_CalcOpt;
		TArray<FVector2D> VecPoints = UOmegaFunctions_Spline::Get2DVectorPoints(Spline);
		
		UDynamicMesh* Local_DynamicMesh = UGeometryScriptLibrary_MeshPrimitiveFunctions::AppendSimpleExtrudePolygon(
			DynamicMesh, PrimitiveOptions, Transform, VecPoints, Height);
		Local_DynamicMesh = UGeometryScriptLibrary_MeshNormalsFunctions::ComputeSplitNormals(Local_DynamicMesh, Local_NormOpt, Local_CalcOpt);
		
		return Local_DynamicMesh;
	}
	return nullptr;
}
