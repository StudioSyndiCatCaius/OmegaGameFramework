// Copyright Studio SyndiCat 2023. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GeometryScript/MeshPrimitiveFunctions.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/StaticMesh.h"
#include "F_DynamicMesh.generated.h"

class UInstancedStaticMeshComponent;
class USplineComponent;
class UDynamicMesh;

UENUM(BlueprintType)
enum class EOmegaMeshLengthSelector : uint8

{
	MeshLengthSelect_Custom          UMETA(DisplayName = "Custom"),
	MeshLengthSelect_X				UMETA(DisplayName = "X"),
	MeshLengthSelect_Y          UMETA(DisplayName = "Y"),
	MeshLengthSelect_Z				UMETA(DisplayName = "Z"),
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_DynamicMesh : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	//#####################################################################################//
	// SPLINE //
	//#####################################################################################//
public:
	//#####################################################################################//
	// SPLINE //
	//#####################################################################################//
	UFUNCTION()
	static FTransform OffsetTransform(FTransform A, FTransform B);
	
	UFUNCTION(BlueprintCallable, Category="Level Build")
	static void StretchInstanceMeshAlongSpline(UInstancedStaticMeshComponent* MeshComp, USplineComponent* Spline, FVector Offset);

	UFUNCTION(BlueprintCallable, Category="Level Build")
	static TArray<FVector2D> Get2DVectorPointsFromSpline(USplineComponent* Spline);

	UFUNCTION(BlueprintCallable, Category="Level Build")
	static void ClampSplineTangents(USplineComponent* Spline, float Min, float Max);

	UFUNCTION(BlueprintCallable, Category="Level Build", meta=(AdvancedDisplay="OffsetSplineDistance, OffsetLocation, OffsetRotation, Scale"))
	static void AddMeshInstancesAtSplinePoints(UInstancedStaticMeshComponent* MeshComp, USplineComponent* Spline, float OffsetSplineDistance, FVector OffsetLocation, FRotator OffsetRotation, FVector Scale = FVector(1,1,1));

	UFUNCTION(BlueprintCallable, Category="Level Build", meta=(AdvancedDisplay="OffsetDistance, OffsetLocation, OffsetRotation, Scale, bAimAtNextPoint"))
	static void AddMeshInstancesAlongSpline(UInstancedStaticMeshComponent* MeshComp, USplineComponent* Spline,EOmegaMeshLengthSelector Type,
		float Distance, bool bAtAverageDistance, bool bAimAtNextPoint, float OffsetDistance, FVector OffsetLocation, FRotator OffsetRotation,
		FVector Scale = FVector(1,1,1));

	UFUNCTION(BlueprintCallable, Category="Level Build")
	static TArray<int32> GetSplinePointsInRangeOfVectors(USplineComponent* Spline, TArray<FVector> Vectors, float GetDistance);

	UFUNCTION(BlueprintCallable, Category="Level Build")
	static void FormSplineAsCircle(USplineComponent* Spline, float Radius, int32 Steps);

	UFUNCTION(BlueprintCallable, Category="Level Build")
	static void FormSplineAsBox(USplineComponent* Spline, FVector Driver);
	
	//#####################################################################################//
	// Instance Static Mesh //
	//#####################################################################################//

	UFUNCTION(BlueprintPure, Category="Level Build|Vector")
	static int32 GetMeshInstance_NearestToPoint(const UInstancedStaticMeshComponent* MeshComp, FVector Point, bool bWorldSpace=false);
	
	UFUNCTION(BlueprintCallable, Category="Level Build|Instance Static Mesh")
	static TArray<FTransform> GetMeshInstance_Transforms(UInstancedStaticMeshComponent* MeshComp);
	
	UFUNCTION(BlueprintCallable, Category="Level Build|Instance Static Mesh")
	static TArray<FVector> GetMeshInstance_Locations(UInstancedStaticMeshComponent* MeshComp);

	UFUNCTION(BlueprintCallable, Category="Level Build|Instance Static Mesh")
	static TArray<int32> GetMeshInstance_NearestToPoints(UInstancedStaticMeshComponent* MeshComp, TArray<FVector> Points, bool bWorldSpace=false);
	
	UFUNCTION(BlueprintCallable, Category="Level Build|Instance Static Mesh")
	static void RemoveMeshInstancesFromBooleanPoints(UInstancedStaticMeshComponent* MeshComp, TArray<FVector> Vectors, float VectorRadius);

	UFUNCTION(BlueprintCallable, Category="Level Build|Instance Static Mesh")
	static void RemoveMeshInstances_InActorTags(UInstancedStaticMeshComponent* MeshComp,  const TArray<FName>& RequiredTags, float SphereRadius = 1.0f);
	
	UFUNCTION(BlueprintCallable, Category="Level Build|Instance Static Mesh")
	static void ReplaceMeshInstancesAtLocation(UInstancedStaticMeshComponent* OldMesh, UInstancedStaticMeshComponent* NewMesh, TArray<FVector> Vectors, float VectorRadius);

	static void Local_RemoveMeshInstance(UInstancedStaticMeshComponent* OldMesh, int32 Inst);
	
	UFUNCTION(BlueprintCallable, Category="Level Build|Instance Static Mesh")
	static void AppendMeshInstancesAtLocation(UInstancedStaticMeshComponent* OldMesh, UInstancedStaticMeshComponent* AppendedMesh, TArray<FVector> Vectors, float VectorRadius);
	
	UFUNCTION(BlueprintCallable, Category="Level Build|Instance Static Mesh")
	static void RemoveMultiMeshInstancesFromBooleanPoints(TArray<UInstancedStaticMeshComponent*> MeshComps, TArray<FVector> Vectors, float VectorRadius);
	
	UFUNCTION(BlueprintCallable, Category="Level Build|Instance Static Mesh")
	static void OffsetMeshInstances(UInstancedStaticMeshComponent* MeshComp, FVector Location, FRotator Rotation, FVector Scale = FVector(1,1,1));

	UFUNCTION(BlueprintCallable, Category="Level Build|Instance Static Mesh", meta=(AdvancedDisplay="OffsetDistance,OffsetLocation,OffsetRotation"))
	static void AddMeshInstancesAlongDriver(UInstancedStaticMeshComponent* MeshComp, FVector Driver, FVector DriverPull, FVector OffsetPull, FRotator Direction, float Distance,float OffsetDistance, FVector OffsetLocation, FRotator OffsetRotation);

	UFUNCTION(BlueprintCallable, Category="Level Build|Instance Static Mesh", meta=(AdvancedDisplay="OffsetDistance,OffsetLocation,OffsetRotation"),DisplayName="Add Mesh Instances Along Driver (Multi)")
	static void AddMeshInstancesAlongDriver_Multi(TArray<UInstancedStaticMeshComponent*> MeshComps, bool RandomOrder, int32 RandomSeed, FVector Driver, FVector DriverPull, FVector OffsetPull, FRotator Direction, float Distance, float OffsetDistance, FVector OffsetLocation, FRotator OffsetRotation);

	UFUNCTION(BlueprintCallable, Category="Level Build|Instance Static Mesh", meta=(AdvancedDisplay="ApplyFlippedOffset, ApplyFlippedOffset, MaxHeightSteps, Wall1,Wall2,Wall3,Wall4"))
	static void BuildMeshBoxFromDriver(UInstancedStaticMeshComponent* MeshComp, FVector Driver, float Distance, float OffsetDistance, float Height, bool ApplyFlippedOffset, bool ApplyOffsetPull, int32 MaxHeightSteps=10, bool Wall1=true, bool Wall2=true, bool Wall3=true, bool Wall4=true);
	
	UFUNCTION(BlueprintCallable, Category="Level Build|Instance Static Mesh", meta=(AdvancedDisplay="ApplyFlippedOffset, ApplyFlippedOffset, MaxHeightSteps, Wall1,Wall2,Wall3,Wall4"))
	static void BuildMeshBoxFromDriver_Multi(TArray<UInstancedStaticMeshComponent*> MeshComps,  bool RandomOrder, int32 RandomSeed, FVector Driver, float Distance, float OffsetDistance, float Height, bool ApplyFlippedOffset, bool ApplyOffsetPull, int32 MaxHeightSteps=10, bool Wall1=true, bool Wall2=true, bool Wall3=true, bool Wall4=true);

	UFUNCTION(BlueprintPure, Category="Level Build|Instance Static Mesh")
	static UInstancedStaticMeshComponent* GetRandomInstanceMeshComponentFromSeed(TArray<UInstancedStaticMeshComponent*> MeshComps, int32 Seed);

	UFUNCTION(BlueprintCallable, Category="Level Build|Instance Static Mesh", meta=(AdvancedDisplay="Wall1,Wall2,Wall3,Wall4"))
	static void BuildMeshTilesFromDriver(UInstancedStaticMeshComponent* MeshComp, FVector Driver, float Distance, FVector OffsetLocation, FRotator OffsetRotation, bool X=true, bool Y=true, bool Z=true);

	UFUNCTION(BlueprintCallable, Category="Level Build|Instance Static Mesh", meta=(AdvancedDisplay="Wall1,Wall2,Wall3,Wall4"))
	static void BuildMeshTilesFromDriver_VectorDistance(UInstancedStaticMeshComponent* MeshComp, FVector Driver, FVector Distance, FVector OffsetLocation, FRotator OffsetRotation, bool X=true, bool Y=true, bool Z=true);

	UFUNCTION(BlueprintCallable, Category="Level Build|Instance Static Mesh")
	static void AddNoiseToMeshInstances(UInstancedStaticMeshComponent* MeshComp, FTransform Min, FTransform Max, int32 NoiseSeed);

	UFUNCTION(BlueprintPure, Category="Level Build|Instance Static Mesh")
	static float WorldMasonNoise_Float(int32 Seed);
	
	//#####################################################################################//
	//  Mesh Bounds //
	//#####################################################################################//

	UFUNCTION(BlueprintPure, Category="Level Build|Mesh Bounds")
	static FVector GetScaledMeshBounds(UStaticMesh* Mesh, FVector Multiplied = FVector(1,1,1), FVector Divided = FVector(1,1,1));

	UFUNCTION(BlueprintPure, Category="Level Build|Mesh Bounds")
	static FVector GetScaledComponentMeshBounds(UStaticMeshComponent* MeshComp, FVector Multiplied = FVector(1,1,1), FVector Divided = FVector(1,1,1));

	//#####################################################################################//
    //  Vector //
	//#####################################################################################/

	UFUNCTION(BlueprintCallable, Category="Level Build|Vector", DisplayName="Clamp Vector to Step (Ref)")
	static void ClampVectorToStep_Ref(UPARAM(ref) FVector& Vector, float StepSize);

	UFUNCTION(BlueprintCallable, Category="Level Build|Vector", DisplayName="Clamp Vector to Step (Copy)")
	static FVector ClampVectorToStep_Copy(FVector Vector, float StepSize);
	
	UFUNCTION(BlueprintPure, Category="Level Build|Vector")
	static TArray<FVector> GetScaledVectors(FVector VectorIn, TArray<FVector> Scalars);
	
	UFUNCTION(BlueprintPure, Category="Level Build|Vector")
	static TArray<FVector> GetVectorCornersXY(FVector VectorIn);

	UFUNCTION(BlueprintPure, Category="Level Build|Vector")
	static TArray<FVector> GetVectorCornersXYZ(FVector VectorIn);

	UFUNCTION(BlueprintPure, Category="Level Build|Vector")
	static FVector SelectVector_ClosestToPoint(FVector Point, TArray<FVector> Vectors);
	
	//#####################################################################################//
	// Dynamic Mesh //
	//#####################################################################################//
	
	UFUNCTION(BlueprintCallable, Category="Level Build|Dynamic Mesh")
	static UDynamicMesh* BuildDynamicMeshAlongSpline(UDynamicMesh* DynamicMesh, USplineComponent* Spline, FTransform Transform, float Height,
														FGeometryScriptPrimitiveOptions PrimitiveOption);

	UFUNCTION(BlueprintCallable, Category="Level Build|Dynamic Mesh")
	static UDynamicMesh* BuildDynamicMeshAsRamp(UDynamicMesh* DynamicMesh, FVector Driver, FGeometryScriptPrimitiveOptions PrimitiveOptions);

	UFUNCTION(BlueprintCallable, Category="Level Build|Dynamic Mesh")
	static UDynamicMesh* BuildStepsAlongDriver(UDynamicMesh* DynamicMesh, FVector Driver, FTransform Offset, float StepDistance=30, float StepHeight=10);

	//#####################################################################################//
	// Harvesting //
	//#####################################################################################//

	UFUNCTION(BlueprintCallable, Category = "Level Build", meta = (WorldContext = "WorldContextObject"))
	static bool CheckWorldLocationOverlapWithTags(const UObject* WorldContextObject, const FVector& WorldLocation, const TArray<FName>& RequiredTags, float SphereRadius = 1.0f);

	UFUNCTION(BlueprintCallable, Category = "Level Build",  meta = (WorldContext = "WorldContextObject"))
	static TArray<AActor*> GetActorsOverlappingLocationWithTags(const UObject* WorldContextObject, const FVector& WorldLocation, const TArray<FName>& RequiredTags, float SphereRadius = 1.0f);

	
};
