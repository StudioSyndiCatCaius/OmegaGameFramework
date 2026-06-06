// Copyright Studio SyndiCat 2023. All Rights Reserved.


#include "Functions/F_DynamicMesh.h"

#include "Components/InstancedStaticMeshComponent.h"
#include "Components/SplineComponent.h"
#include "Engine/OverlapResult.h"

#include "GeometryScript/MeshPrimitiveFunctions.h"
#include "GeometryScript/MeshNormalsFunctions.h"

#include "Kismet/KismetMathLibrary.h"
//#include "Materials/MaterialExpressionStrata.h"

FTransform UOmegaFunctions_DynamicMesh::OffsetTransform(FTransform A, FTransform B)
{
	FTransform out;
	out.SetLocation(A.GetLocation()+B.GetLocation());
	out.SetRotation(UKismetMathLibrary::ComposeRotators(A.GetRotation().Rotator(),B.GetRotation().Rotator()).Quaternion());
	out.SetScale3D(A.GetScale3D()*B.GetScale3D());
	return out;
}

void UOmegaFunctions_DynamicMesh::StretchInstanceMeshAlongSpline(UInstancedStaticMeshComponent* MeshComp,
                                                          USplineComponent* Spline, FVector Offset)
{
	if(MeshComp && Spline && MeshComp->GetStaticMesh())
	{
		for (int i = 0; i < Spline->GetNumberOfSplineSegments(); ++i)
		{
			FVector Local_Start = Spline->GetLocationAtSplinePoint(i, ESplineCoordinateSpace::Local) + Offset;
			FVector Local_End = Spline->GetLocationAtSplinePoint(i+1, ESplineCoordinateSpace::Local) + Offset;

			FRotator Local_Rot = UKismetMathLibrary::FindLookAtRotation(Local_Start, Local_End);
			const float Local_ScaleX = UKismetMathLibrary::Vector_Distance(Local_Start, Local_End)/MeshComp->GetStaticMesh()->GetBoundingBox().Max.X;

			FTransform FinalTrans;
			FinalTrans.SetLocation(Local_Start);
			FinalTrans.SetRotation(Local_Rot.Quaternion());
			FinalTrans.SetScale3D(FVector(Local_ScaleX,1,1));
			
			MeshComp->AddInstance(FinalTrans);
		}
	}
	
}

TArray<FVector2D> UOmegaFunctions_DynamicMesh::Get2DVectorPointsFromSpline(USplineComponent* Spline)
{
	TArray<FVector2D> OutVecs;
	if(Spline)
	{
		for (int i = 0; i < Spline->GetNumberOfSplineSegments(); ++i)
		{
			OutVecs.Add(FVector2D(Spline->GetLocationAtSplinePoint(i, ESplineCoordinateSpace::Local)));
		}
	}
	return OutVecs;
}

void UOmegaFunctions_DynamicMesh::ClampSplineTangents(USplineComponent* Spline, float Min, float Max)
{
	if(Spline)
	{
		TArray<FVector2D> OutVecs;
		for (int i = 0; i < Spline->GetNumberOfSplineSegments(); ++i)
		{
			FVector InVec = Spline->GetTangentAtSplinePoint(i, ESplineCoordinateSpace::Local);
			InVec = UKismetMathLibrary::ClampVectorSize(InVec, Min, Max);
			Spline->SetTangentAtSplinePoint(i, InVec, ESplineCoordinateSpace::Local);
		}
	}
}

void UOmegaFunctions_DynamicMesh::AddMeshInstancesAtSplinePoints(UInstancedStaticMeshComponent* MeshComp, USplineComponent* Spline, float OffsetSplineDistance, FVector OffsetLocation, FRotator OffsetRotation, FVector Scale)
{
	if(MeshComp && Spline )
	{
		for (int i = 0; i <= Spline->GetNumberOfSplineSegments(); ++i)
		{
			const float LocalDistance = OffsetSplineDistance+Spline->GetDistanceAlongSplineAtSplinePoint(i);
			FTransform LocalTrans;
			
			LocalTrans.SetLocation(Spline->GetLocationAtDistanceAlongSpline(LocalDistance, ESplineCoordinateSpace::Local)+OffsetLocation);
			LocalTrans.SetRotation(FQuat(Spline->GetRotationAtDistanceAlongSpline(LocalDistance, ESplineCoordinateSpace::Local)+OffsetRotation));
			LocalTrans.SetScale3D(Scale);
			
			MeshComp->AddInstance(LocalTrans);
		}
	}
}

void UOmegaFunctions_DynamicMesh::AddMeshInstancesAlongSpline(UInstancedStaticMeshComponent* MeshComp,
	USplineComponent* Spline,  EOmegaMeshLengthSelector Type, float Distance, bool bAtAverageDistance, bool bAimAtNextPoint,
	float OffsetDistance, FVector OffsetLocation, FRotator OffsetRotation, FVector Scale)
{
	if(MeshComp && Spline )
	{
		float LocalDistance = Distance;
		
		switch (Type)
		{
		case EOmegaMeshLengthSelector::MeshLengthSelect_Custom:
			LocalDistance = Distance;
			break;
		case EOmegaMeshLengthSelector::MeshLengthSelect_X:
			LocalDistance = MeshComp->GetStaticMesh()->GetBoundingBox().Max.X;
			break;
		case EOmegaMeshLengthSelector::MeshLengthSelect_Y:
			LocalDistance = MeshComp->GetStaticMesh()->GetBoundingBox().Max.Y;
			break;
		case EOmegaMeshLengthSelector::MeshLengthSelect_Z:
			LocalDistance = MeshComp->GetStaticMesh()->GetBoundingBox().Max.Z;
			break;
		default: ;
		}
		
		int32 NumOfPoints;

		if(bAtAverageDistance)
		{
			for (int i = 0; i <= Spline->GetNumberOfSplineSegments(); ++i)
			{
				float floatpoints=UKismetMathLibrary::Vector_Distance(
					Spline->GetLocationAtSplinePoint(i,ESplineCoordinateSpace::Local),
					Spline->GetLocationAtSplinePoint(i+1,ESplineCoordinateSpace::Local))/Distance;
				
				NumOfPoints=UKismetMathLibrary::FTrunc(floatpoints);

				for (int lerpval = 0; lerpval < NumOfPoints; ++lerpval)
				{
					if(lerpval!=0)
					{
						float newdistance=UKismetMathLibrary::Lerp(
						Spline->GetDistanceAlongSplineAtSplinePoint(i),
						Spline->GetDistanceAlongSplineAtSplinePoint(i+1),
						UKismetMathLibrary::Conv_IntToDouble(lerpval)/NumOfPoints);

						FTransform new_inst_trans=Spline->GetTransformAtDistanceAlongSpline(newdistance,ESplineCoordinateSpace::Local);
					
						new_inst_trans.SetScale3D(Scale);
						new_inst_trans.SetRotation(FQuat(Spline->GetRotationAtDistanceAlongSpline(newdistance, ESplineCoordinateSpace::Local)+OffsetRotation));
						MeshComp->AddInstance(new_inst_trans);
					}
				}
			}
		}
		else
		{
			NumOfPoints = UKismetMathLibrary::FTrunc(Spline->GetSplineLength()/LocalDistance);
			for (int i = 0; i <= NumOfPoints; ++i)
			{
				FVector VecPoint_This = Spline->GetLocationAtDistanceAlongSpline(i*LocalDistance+OffsetDistance, ESplineCoordinateSpace::Local)+OffsetLocation;
				FVector VecPoint_Next = Spline->GetLocationAtDistanceAlongSpline((i+1)*LocalDistance+OffsetDistance, ESplineCoordinateSpace::Local)+OffsetLocation;
			
				FTransform LocalTrans;
				LocalTrans.SetLocation(VecPoint_This);
				if(bAimAtNextPoint)
				{
					LocalTrans.SetRotation(FQuat(UKismetMathLibrary::FindLookAtRotation(VecPoint_This, VecPoint_Next)+OffsetRotation));
				}
				else
				{
					LocalTrans.SetRotation(FQuat(Spline->GetRotationAtDistanceAlongSpline(i*LocalDistance+OffsetDistance, ESplineCoordinateSpace::Local)+OffsetRotation));
				}
				LocalTrans.SetScale3D(Scale);
			
				MeshComp->AddInstance(LocalTrans);
			}
		}
	}
}

TArray<int32> UOmegaFunctions_DynamicMesh::GetSplinePointsInRangeOfVectors(USplineComponent* Spline, TArray<FVector> Vectors,
	float GetDistance)
{
	TArray<int32> OutIndices;

	for (const FVector TempVec : Vectors)
	{
		if(Spline)
		{
			for (int i = 0; i < Spline->GetNumberOfSplinePoints()-1; ++i)
			{
				if(UKismetMathLibrary::Vector_Distance(Spline->GetLocationAtSplinePoint(i, ESplineCoordinateSpace::Local), TempVec)<=GetDistance)
				{
					OutIndices.AddUnique(i);
					break;
				}
			}
		}
	}
	return OutIndices;
}

void UOmegaFunctions_DynamicMesh::FormSplineAsCircle(USplineComponent* Spline, float Radius, int32 Steps)
{
	if(Spline)
	{
		Spline->ClearSplinePoints(true);
		for (int i = 0; i < Steps; ++i)
		{
			const FRotator LocalRot = UKismetMathLibrary::MakeRotator(0,0, float(i)/float(Steps)*360);
			FVector LocalDir = Radius*UKismetMathLibrary::Conv_RotatorToVector(LocalRot);
			Spline->AddSplinePoint(LocalDir, ESplineCoordinateSpace::Local);
		}
		Spline->SetClosedLoop(true);
	}
}

void UOmegaFunctions_DynamicMesh::FormSplineAsBox(USplineComponent* Spline, FVector Driver)
{
	if(Spline)
	{
		Spline->ClearSplinePoints();
		TArray<FVector> Pulls;
		Pulls.Add(FVector(0,0,0));
		Pulls.Add(FVector(1,0,0));
		Pulls.Add(FVector(1,1,0));
		Pulls.Add(FVector(0,1,0));

		for (FVector TempPull : Pulls)
		{
			Spline->AddSplineLocalPoint(TempPull*Driver);
		}
		Spline->UpdateSpline();
	}
}

int32 UOmegaFunctions_DynamicMesh::GetMeshInstance_NearestToPoint(const UInstancedStaticMeshComponent* MeshComp, FVector Point, bool bWorldSpace)
{
	// Validate input
	if (!MeshComp || MeshComp->GetInstanceCount() == 0)
	{
		return INDEX_NONE;
	}

	// Convert point to component space if it's in world space
	FVector SearchPoint = Point;
	if (bWorldSpace)
	{
		SearchPoint = MeshComp->GetComponentTransform().InverseTransformPosition(Point);
	}

	int32 NearestInstanceIndex = INDEX_NONE;
	float MinDistanceSquared = FLT_MAX;

	// Iterate through all instances
	for (int32 InstanceIndex = 0; InstanceIndex < MeshComp->GetInstanceCount(); ++InstanceIndex)
	{
		FTransform InstanceTransform;
		if (MeshComp->GetInstanceTransform(InstanceIndex, InstanceTransform, true)) // true for world space transform
		{
			// Convert instance position to component space for comparison
			FVector InstancePosition = InstanceTransform.GetLocation();
			if (bWorldSpace)
			{
				// If search point is in world space, keep instance position in world space
				// (InstanceTransform is already in world space)
			}
			else
			{
				// Convert instance position to component space
				InstancePosition = MeshComp->GetComponentTransform().InverseTransformPosition(InstancePosition);
			}

			// Calculate squared distance (faster than using square root)
			float DistanceSquared = FVector::DistSquared(SearchPoint, InstancePosition);

			// Update nearest if this instance is closer
			if (DistanceSquared < MinDistanceSquared)
			{
				MinDistanceSquared = DistanceSquared;
				NearestInstanceIndex = InstanceIndex;
			}
		}
	}

	return NearestInstanceIndex;
}

TArray<FTransform> UOmegaFunctions_DynamicMesh::GetMeshInstance_Transforms(UInstancedStaticMeshComponent* MeshComp)
{
	TArray<FTransform> out;
	if(MeshComp)
	{
		for (int i = 0; i < MeshComp->GetInstanceCount(); ++i)
		{
			FTransform v;
			MeshComp->GetInstanceTransform(i,v);
			out.Add(v);
		}
	}
	return out;
}

TArray<FVector> UOmegaFunctions_DynamicMesh::GetMeshInstance_Locations(UInstancedStaticMeshComponent* MeshComp)
{
	TArray<FVector> out;
	if(MeshComp)
	{
		for (int i = 0; i < MeshComp->GetInstanceCount(); ++i)
		{
			FTransform v;
			MeshComp->GetInstanceTransform(i,v);
			out.Add(v.GetLocation());
		}
	}
	return out;
}

TArray<int32> UOmegaFunctions_DynamicMesh::GetMeshInstance_NearestToPoints(UInstancedStaticMeshComponent* MeshComp,
	TArray<FVector> Points, bool bWorldSpace)
{
	TArray<int32> out;
	if(MeshComp)
	{
		for(FVector v : Points)
		{
			out.Add(GetMeshInstance_NearestToPoint(MeshComp,v,bWorldSpace));
		}
	}
	return out;
}

void UOmegaFunctions_DynamicMesh::RemoveMeshInstancesFromBooleanPoints(UInstancedStaticMeshComponent* MeshComp, TArray<FVector> Vectors, float VectorRadius)
{
	if(MeshComp)
	{
		for (const int32 LocalInt : GetMeshInstance_NearestToPoints(MeshComp,Vectors))
		{
			Local_RemoveMeshInstance(MeshComp, LocalInt);
		}
	}
}

void UOmegaFunctions_DynamicMesh::RemoveMeshInstances_InActorTags(UInstancedStaticMeshComponent* MeshComp,
	const TArray<FName>& RequiredTags, float SphereRadius)
{
	if(MeshComp)
	{
		TArray<int32> _ToRemove;
		for (int i = 0; i < MeshComp->GetInstanceCount(); ++i)
		{
			FTransform _t;
			MeshComp->GetInstanceTransform(i,_t,true);
			if(CheckWorldLocationOverlapWithTags(MeshComp,_t.GetLocation(),RequiredTags,SphereRadius))
			{
				_ToRemove.Add(i);
			}
		}
		MeshComp->RemoveInstances(_ToRemove);
	}
}

void UOmegaFunctions_DynamicMesh::ReplaceMeshInstancesAtLocation(UInstancedStaticMeshComponent* OldMesh,
                                                          UInstancedStaticMeshComponent* NewMesh, TArray<FVector> Vectors, float VectorRadius)
{
	if(NewMesh && OldMesh)
	{
		for (const int32 LocalInt : GetMeshInstance_NearestToPoints(OldMesh,Vectors))
		{
			FTransform LocalTrans;
			OldMesh->GetInstanceTransform(LocalInt, LocalTrans);
			NewMesh->AddInstance(LocalTrans);
				
			Local_RemoveMeshInstance(OldMesh, LocalInt);
		}
	}
	
}

void UOmegaFunctions_DynamicMesh::Local_RemoveMeshInstance(UInstancedStaticMeshComponent* OldMesh, int32 Inst)
{
	FTransform NewTrans;
	NewTrans.SetLocation(FVector(0,0,-1000000));
	NewTrans.SetScale3D(FVector(0.0001,0.0001,0.0001));
	if(OldMesh)
	{
		//OldMesh->GetInstanceTransform(Inst, NewTrans);
		OldMesh->UpdateInstanceTransform(Inst, NewTrans,true);
	}
	
}

void UOmegaFunctions_DynamicMesh::AppendMeshInstancesAtLocation(UInstancedStaticMeshComponent* OldMesh,
                                                         UInstancedStaticMeshComponent* AppendedMesh, TArray<FVector> Vectors, float VectorRadius)
{
	if(AppendedMesh && OldMesh)
	{
		for(FVector TempVec : Vectors)
		{
			TArray<int32> LocalInts = OldMesh->GetInstancesOverlappingSphere(TempVec, VectorRadius, false);
			for (const auto LocalInt : LocalInts)
			{
				FTransform LocalTrans;
				OldMesh->GetInstanceTransform(LocalInt, LocalTrans);
				AppendedMesh->AddInstance(LocalTrans);
			}
		}
	}
}

void UOmegaFunctions_DynamicMesh::RemoveMultiMeshInstancesFromBooleanPoints(TArray<UInstancedStaticMeshComponent*> MeshComps, TArray<FVector> Vectors, float VectorRadius)
{
	for (const auto LocalComp : MeshComps)
	{
		if(LocalComp)
		{
			RemoveMeshInstancesFromBooleanPoints(LocalComp, Vectors, VectorRadius);
		}
	}
}

void UOmegaFunctions_DynamicMesh::OffsetMeshInstances(UInstancedStaticMeshComponent* MeshComp, FVector Location,
                                               FRotator Rotation, FVector Scale)
{
	if(MeshComp)
	{
		for (int i = 0; i < MeshComp->GetInstanceCount(); ++i)
		{
			FTransform Local_Trans;
			MeshComp->GetInstanceTransform(i, Local_Trans, ESplineCoordinateSpace::Local);
			Local_Trans.SetLocation(Local_Trans.GetLocation()+Location);
			//Local_Trans.SetRotation(Local_Trans.GetRotation()+FQuat(Rotation));
			Local_Trans.SetScale3D(Local_Trans.GetScale3D()*Scale);
			MeshComp->UpdateInstanceTransform(i,Local_Trans);
		}
	}
}

void UOmegaFunctions_DynamicMesh::AddMeshInstancesAlongDriver(UInstancedStaticMeshComponent* MeshComp, FVector Driver,
	FVector DriverPull, FVector OffsetPull, FRotator Direction, float Distance, float OffsetDistance, FVector OffsetLocation, 
	FRotator OffsetRotation)
{
	TArray<UInstancedStaticMeshComponent*> LocalMeshComps;
	LocalMeshComps.Add(MeshComp);

	AddMeshInstancesAlongDriver_Multi(LocalMeshComps, false,0, Driver, DriverPull, OffsetPull, Direction, Distance, OffsetDistance, OffsetLocation, OffsetRotation);
}

void UOmegaFunctions_DynamicMesh::AddMeshInstancesAlongDriver_Multi(TArray<UInstancedStaticMeshComponent*> MeshComps,
	bool RandomOrder, int32 RandomSeed, FVector Driver, FVector DriverPull, FVector OffsetPull, FRotator Direction, float Distance,float OffsetDistance, 
	FVector OffsetLocation, FRotator OffsetRotation)
{
	const FVector LocalDriver = Driver*DriverPull;
	const int32 LocalSteps = UKismetMathLibrary::FTrunc(UKismetMathLibrary::VSize(LocalDriver)/Distance);

	int32 MeshCompIndex = -1;

	for (int i = 0; i < LocalSteps; ++i)
	{
		FVector Local_FinalVec = ((i*Distance+OffsetDistance)*UKismetMathLibrary::Conv_RotatorToVector(Direction))+Driver*OffsetPull+OffsetLocation;
		FQuat Local_FinalRot = FQuat(UKismetMathLibrary::ComposeRotators(Direction, OffsetRotation));

		FTransform LocalTrans;
		LocalTrans.SetLocation(Local_FinalVec);
		LocalTrans.SetRotation(Local_FinalRot);

		UInstancedStaticMeshComponent* LocalMeshComp;

		if(RandomOrder)
		{
			LocalMeshComp = GetRandomInstanceMeshComponentFromSeed(MeshComps, RandomSeed);
		}
		else
		{
			if(MeshCompIndex+1<MeshComps.Num())
			{
				MeshCompIndex = MeshCompIndex+1;
			}
			else
			{
				MeshCompIndex = 0;
			}
			LocalMeshComp = MeshComps[MeshCompIndex];
		}
		
		LocalMeshComp->AddInstance(LocalTrans);
	}
}

void UOmegaFunctions_DynamicMesh::BuildMeshBoxFromDriver(UInstancedStaticMeshComponent* MeshComp, FVector Driver,
	float Distance, float OffsetDistance, float Height, bool ApplyFlippedOffset, bool ApplyOffsetPull, int32 MaxHeightSteps, bool Wall1, bool Wall2, bool Wall3, bool Wall4)
{
	if(MeshComp && MeshComp->GetStaticMesh())
	{
		TArray<UInstancedStaticMeshComponent*> LocalMeshComps;
		LocalMeshComps.Add(MeshComp);
		BuildMeshBoxFromDriver_Multi(LocalMeshComps, false, 0, Driver, Distance, OffsetDistance, Height, ApplyFlippedOffset, ApplyOffsetPull, MaxHeightSteps, Wall1, Wall2, Wall3, Wall4);
	}
	
}

void UOmegaFunctions_DynamicMesh::BuildMeshBoxFromDriver_Multi(TArray<UInstancedStaticMeshComponent*> MeshComps, bool RandomOrder,
	int32 RandomSeed, FVector Driver, float Distance, float OffsetDistance, float Height, bool ApplyFlippedOffset,
	bool ApplyOffsetPull, int32 MaxHeightSteps, bool Wall1, bool Wall2, bool Wall3, bool Wall4)
{
	int32 HeightSteps = Driver.Z/Height;
	HeightSteps = UKismetMathLibrary::Clamp(HeightSteps, 0, MaxHeightSteps);

	const float FlippedOffset = UKismetMathLibrary::SelectFloat(Distance,0,ApplyFlippedOffset);
		
	for (int i = 0; i < HeightSteps; ++i)
		{
			const float TempHeight = i*Height;
			if(Wall1)
			{
				AddMeshInstancesAlongDriver_Multi(MeshComps,  RandomOrder, RandomSeed, Driver, FVector(1,0,0), FVector(0,0,0), FRotator(0,0,0), Distance, OffsetDistance, FVector(FlippedOffset,0,TempHeight), FRotator(0,180,0));
			}
			if(Wall2)
			{
				AddMeshInstancesAlongDriver_Multi(MeshComps,  RandomOrder, RandomSeed, Driver, FVector(0,1,0), FVector(0,0,0), FRotator(0,90,0), Distance, OffsetDistance, FVector(0,0,TempHeight), FRotator(0,0,0));
			}
			if(Wall3)
			{
				const float ExtraOffset_3 = UKismetMathLibrary::SelectFloat(Distance,0,ApplyOffsetPull);
				AddMeshInstancesAlongDriver_Multi(MeshComps, RandomOrder, RandomSeed, Driver, FVector(1,0,0), FVector(0,1,0), FRotator(0,0,0), Distance, OffsetDistance, FVector(0,ExtraOffset_3,TempHeight), FRotator(0,0,0));
			}
			if(Wall4)
			{
				const float ExtraOffset_4 = UKismetMathLibrary::SelectFloat(Distance,0,ApplyOffsetPull);
				AddMeshInstancesAlongDriver_Multi(MeshComps,  RandomOrder, RandomSeed, Driver, FVector(0,1,0), FVector(1,0,0), FRotator(0,90,0), Distance, OffsetDistance, FVector(ExtraOffset_4,FlippedOffset,TempHeight), FRotator(0,180,0));
			}
		}
	
}

UInstancedStaticMeshComponent* UOmegaFunctions_DynamicMesh::GetRandomInstanceMeshComponentFromSeed(
	TArray<UInstancedStaticMeshComponent*> MeshComps, int32 Seed)
{
	FRandomStream LocalSteam;
	UKismetMathLibrary::SetRandomStreamSeed(LocalSteam, Seed);
	const int32 LocalIndex = UKismetMathLibrary::RandomIntegerFromStream(MeshComps.Num()-1, LocalSteam.GetCurrentSeed());
	return MeshComps[LocalIndex];
}

void UOmegaFunctions_DynamicMesh::BuildMeshTilesFromDriver(UInstancedStaticMeshComponent* MeshComp, FVector Driver,
	float Distance, FVector OffsetLocation, FRotator OffsetRotation, bool X, bool Y, bool Z)
{
	BuildMeshTilesFromDriver_VectorDistance(MeshComp,Driver,FVector(Distance,Distance,Distance),OffsetLocation,OffsetRotation,X,Y,Z);
}

void UOmegaFunctions_DynamicMesh::BuildMeshTilesFromDriver_VectorDistance(UInstancedStaticMeshComponent* MeshComp,
	FVector Driver, FVector Distance, FVector OffsetLocation, FRotator OffsetRotation, bool X, bool Y, bool Z)
{
	if(MeshComp)
	{
		
		int32 StepsX=0; 
		int32 StepsY=0;
		int32 StepsZ=0;
		
		if(X)
		{
			StepsX = UKismetMathLibrary::FTruncVector((Driver/UKismetMathLibrary::Conv_DoubleToVector(Distance.X))-1).X;
		}
		if(Y)
		{
			StepsY = UKismetMathLibrary::FTruncVector((Driver/UKismetMathLibrary::Conv_DoubleToVector(Distance.Y))-1).Y;
		}
		if(Z)
		{
			StepsZ = UKismetMathLibrary::FTruncVector((Driver/UKismetMathLibrary::Conv_DoubleToVector(Distance.Z))-1).Z;
		}
		
		for (int iX = 0; iX <= StepsX; ++iX)
		{
			for (int iY = 0; iY <= StepsY; ++iY)
			{
				for (int iZ = 0; iZ <= StepsZ; ++iZ)
				{
					FVector LocalVec = UKismetMathLibrary::Conv_IntVectorToVector(FIntVector(iX,iY,iZ));
					LocalVec = LocalVec*Distance;
					FTransform LocalTrans;
					LocalTrans.SetLocation(LocalVec+OffsetLocation);
					LocalTrans.SetRotation(FQuat(OffsetRotation));
					
					MeshComp->AddInstance(LocalTrans);
				}
			}
		}
	}
}

void UOmegaFunctions_DynamicMesh::AddNoiseToMeshInstances(UInstancedStaticMeshComponent* MeshComp, FTransform Min,
                                                   FTransform Max, int32 NoiseSeed)
{
	if(MeshComp)
	{
		for (int i = 0; i < MeshComp->GetInstanceCount(); ++i)
		{
			FTransform StartTrans;
			MeshComp->GetInstanceTransform(i, StartTrans);

			FTransform LocalTrans_Min;
			LocalTrans_Min.SetLocation(StartTrans.GetLocation()+Min.GetLocation());
			LocalTrans_Min.SetRotation(StartTrans.GetRotation()*Min.GetRotation());
			LocalTrans_Min.SetScale3D(StartTrans.GetScale3D()*Min.GetScale3D());
			
			
			FTransform LocalTrans_Max;
			LocalTrans_Max.SetLocation(StartTrans.GetLocation()+Max.GetLocation());
			LocalTrans_Max.SetRotation(StartTrans.GetRotation()*Max.GetRotation());
			LocalTrans_Max.SetScale3D(StartTrans.GetScale3D()*Max.GetScale3D());
			
			FTransform FinalTrans = UKismetMathLibrary::TLerp(LocalTrans_Min, LocalTrans_Max, WorldMasonNoise_Float(NoiseSeed+(i*4.632)), ELerpInterpolationMode::QuatInterp);

			MeshComp->UpdateInstanceTransform(i,FinalTrans);
		}
	}
}


FVector UOmegaFunctions_DynamicMesh::GetScaledMeshBounds(UStaticMesh* Mesh, FVector Multiplied, FVector Divided)
{
	FVector LocalVec;
	if(Mesh)
	{
		LocalVec = Mesh->GetBoundingBox().Max*Multiplied/Divided;
	}
	return LocalVec;
}

FVector UOmegaFunctions_DynamicMesh::GetScaledComponentMeshBounds(UStaticMeshComponent* MeshComp, FVector Multiplied,
	FVector Divided)
{
	FVector LocalVec;
	if(MeshComp)
	{
		LocalVec = GetScaledMeshBounds(MeshComp->GetStaticMesh(), Multiplied, Divided);
	}
	return LocalVec;
}

void UOmegaFunctions_DynamicMesh::ClampVectorToStep_Ref(FVector& Vector, float StepSize)
{
	Vector = ClampVectorToStep_Copy(Vector, StepSize);
}

FVector UOmegaFunctions_DynamicMesh::ClampVectorToStep_Copy(FVector Vector, float StepSize)
{
	return UKismetMathLibrary::Conv_IntVectorToVector(UKismetMathLibrary::FTruncVector(Vector/UKismetMathLibrary::Conv_DoubleToVector(StepSize))*StepSize);
}

//#####################################################################################//
//  Vector //
//#####################################################################################/

TArray<FVector> UOmegaFunctions_DynamicMesh::GetScaledVectors(FVector VectorIn, TArray<FVector> Scalars)
{
	TArray<FVector> OutVecs;
	for(FVector TempScale : Scalars)
	{
		OutVecs.Add(TempScale*VectorIn);
	}
	return OutVecs;
}

TArray<FVector> UOmegaFunctions_DynamicMesh::GetVectorCornersXY(FVector VectorIn)
{
	TArray<FVector> LocalScalars;
	LocalScalars.Add(FVector(0,0,0));
	LocalScalars.Add(FVector(1,0,0));
	LocalScalars.Add(FVector(0,1,0));
	LocalScalars.Add(FVector(1,1,0));
	
	return GetScaledVectors(VectorIn, LocalScalars);
}

TArray<FVector> UOmegaFunctions_DynamicMesh::GetVectorCornersXYZ(FVector VectorIn)
{
	TArray<FVector> LocalScalars;
	LocalScalars.Add(FVector(0,0,0));
	LocalScalars.Add(FVector(1,0,0));
	LocalScalars.Add(FVector(0,1,0));
	LocalScalars.Add(FVector(1,1,0));
	LocalScalars.Add(FVector(0,0,1));
	LocalScalars.Add(FVector(1,0,1));
	LocalScalars.Add(FVector(0,1,1));
	LocalScalars.Add(FVector(1,1,1));

	return GetScaledVectors(VectorIn, LocalScalars);
}

FVector UOmegaFunctions_DynamicMesh::SelectVector_ClosestToPoint(FVector Point, TArray<FVector> Vectors)
{
	FVector out;
	bool init=false;
	for(FVector v : Vectors)
	{
		if(!init || UKismetMathLibrary::Vector_Distance(Point,v)<UKismetMathLibrary::Vector_Distance(Point,out))
		{
			init=true;
			out=v;
		}
	}
	return out;
}

UDynamicMesh* UOmegaFunctions_DynamicMesh::BuildDynamicMeshAlongSpline(UDynamicMesh* DynamicMesh, USplineComponent* Spline,
                                                                FTransform Transform, float Height, FGeometryScriptPrimitiveOptions PrimitiveOptions)
{
	if(Spline && DynamicMesh)
	{
		FGeometryScriptSplitNormalsOptions Local_NormOpt;
		FGeometryScriptCalculateNormalsOptions Local_CalcOpt;
		TArray<FVector2D> VecPoints = UOmegaFunctions_DynamicMesh::Get2DVectorPointsFromSpline(Spline);
		
		UDynamicMesh* Local_DynamicMesh = UGeometryScriptLibrary_MeshPrimitiveFunctions::AppendSimpleExtrudePolygon(
			DynamicMesh, PrimitiveOptions, Transform, VecPoints, Height);
		Local_DynamicMesh = UGeometryScriptLibrary_MeshNormalsFunctions::ComputeSplitNormals(Local_DynamicMesh, Local_NormOpt, Local_CalcOpt);
		
		return Local_DynamicMesh;
	}
	return nullptr;
}

UDynamicMesh* UOmegaFunctions_DynamicMesh::BuildDynamicMeshAsRamp(UDynamicMesh* DynamicMesh, FVector Driver, FGeometryScriptPrimitiveOptions PrimitiveOptions)
{
	TArray<FVector2d> PolyVecs;
	TArray<FVector2d> VectorPulls;

	VectorPulls.Add(FVector2d(0,0));
	VectorPulls.Add(FVector2d(1,0));
	VectorPulls.Add(FVector2d(1,1));
	
	for (auto LocalPull : VectorPulls)
	{
		FVector2d LocalDriverVec;
		LocalDriverVec.X = Driver.X;
		LocalDriverVec.Y = Driver.Z;

		PolyVecs.Add(LocalPull*LocalDriverVec);
	}
	FTransform LocalTrans;
	LocalTrans.SetLocation(FVector(0,Driver.Y,0));
	LocalTrans.SetRotation(FQuat(FRotator(0,0,-90)));
	
	FGeometryScriptSplitNormalsOptions Local_NormOpt;
	FGeometryScriptCalculateNormalsOptions Local_CalcOpt;

	UDynamicMesh* Local_DynamicMesh = UGeometryScriptLibrary_MeshPrimitiveFunctions::AppendSimpleExtrudePolygon(
		DynamicMesh, PrimitiveOptions, LocalTrans, PolyVecs, Driver.Y*2);
	Local_DynamicMesh = UGeometryScriptLibrary_MeshNormalsFunctions::ComputeSplitNormals(Local_DynamicMesh, Local_NormOpt, Local_CalcOpt);

	return Local_DynamicMesh;
}

UDynamicMesh* UOmegaFunctions_DynamicMesh::BuildStepsAlongDriver(UDynamicMesh* DynamicMesh, FVector Driver, FTransform Offset, float StepDistance,
	float StepHeight)
{
	if(DynamicMesh)
	{
		const int32 StepCount = UKismetMathLibrary::FTrunc(Driver.X/StepDistance);
		for (int i = 0; i <= StepCount; ++i)
		{
			FVector LocalLocation = (UKismetMathLibrary::Conv_IntToDouble(i)/UKismetMathLibrary::Conv_IntToDouble(StepCount)*Driver*FVector(1,0,1));
			FTransform LocalTrans;
			LocalTrans.SetLocation(LocalLocation+Offset.GetLocation());
			LocalTrans.SetRotation(Offset.GetRotation());
			LocalTrans.SetScale3D(Offset.GetScale3D());

			const FGeometryScriptPrimitiveOptions PrimitiveOptions;
			UGeometryScriptLibrary_MeshPrimitiveFunctions::AppendBox(DynamicMesh, PrimitiveOptions, LocalTrans, StepDistance, Driver.Y*2, StepHeight);
		}
		
		return DynamicMesh;
	}
	return nullptr;
}

bool UOmegaFunctions_DynamicMesh::CheckWorldLocationOverlapWithTags(const UObject* WorldContextObject,
	const FVector& WorldLocation, const TArray<FName>& RequiredTags, float SphereRadius)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!World)
	{
		return false;
	}

	// Create a sphere collision shape for the overlap test
	FCollisionShape CollisionSphere = FCollisionShape::MakeSphere(SphereRadius);
    
	// Set up collision query parameters
	FCollisionQueryParams QueryParams;
	QueryParams.bTraceComplex = false;
	QueryParams.bReturnPhysicalMaterial = false;
    
	// Array to store overlapping actors
	TArray<FOverlapResult> OverlapResults;
    
	// Perform sphere overlap at the world location
	bool bHasOverlap = World->OverlapMultiByChannel(
		OverlapResults,
		WorldLocation,
		FQuat::Identity,
		ECollisionChannel::ECC_WorldStatic, // You can change this to ECC_Pawn, ECC_WorldDynamic, etc.
		CollisionSphere,
		QueryParams
	);
    
	if (!bHasOverlap)
	{
		return false;
	}
    
	// Check each overlapping actor for the required tags
	for (const FOverlapResult& Result : OverlapResults)
	{
		AActor* OverlappingActor = Result.GetActor();
		if (!OverlappingActor)
		{
			continue;
		}
        
		// Check if the actor has any of the required tags
		for (const FName& RequiredTag : RequiredTags)
		{
			if (OverlappingActor->Tags.Contains(RequiredTag))
			{
				return true;
			}
		}
	}
    
	return false;
}

TArray<AActor*> UOmegaFunctions_DynamicMesh::GetActorsOverlappingLocationWithTags(const UObject* WorldContextObject,
	const FVector& WorldLocation, const TArray<FName>& RequiredTags, float SphereRadius)
{
	TArray<AActor*> MatchingActors;
    
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!World)
	{
		return MatchingActors;
	}

	FCollisionShape CollisionSphere = FCollisionShape::MakeSphere(SphereRadius);
    
	FCollisionQueryParams QueryParams;
	QueryParams.bTraceComplex = false;
	QueryParams.bReturnPhysicalMaterial = false;
    
	TArray<FOverlapResult> OverlapResults;
    
	bool bHasOverlap = World->OverlapMultiByChannel(
		OverlapResults,
		WorldLocation,
		FQuat::Identity,
		ECollisionChannel::ECC_WorldStatic,
		CollisionSphere,
		QueryParams
	);
    
	if (bHasOverlap)
	{
		for (const FOverlapResult& Result : OverlapResults)
		{
			AActor* OverlappingActor = Result.GetActor();
			if (!OverlappingActor)
			{
				continue;
			}
            
			// Check if the actor has any of the required tags
			for (const FName& RequiredTag : RequiredTags)
			{
				if (OverlappingActor->Tags.Contains(RequiredTag))
				{
					MatchingActors.AddUnique(OverlappingActor);
					break; // No need to check other tags for this actor
				}
			}
		}
	}
    
	return MatchingActors;
}
//#############################################
// NOISE
//#############################################

float UOmegaFunctions_DynamicMesh::WorldMasonNoise_Float(int32 Seed)
{


	return UKismetMathLibrary::Abs(UKismetMathLibrary::PerlinNoise1D(Seed*0.943846));
	
}