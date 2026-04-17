// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Math.h"

#include "Kismet/KismetMathLibrary.h"



FWidgetTransform UOmegaMathFunctions::LerpWidgetTransform(FWidgetTransform a, FWidgetTransform b, float alpha)
{
	FWidgetTransform out;
	out.Angle=UKismetMathLibrary::Lerp(a.Angle,b.Angle,alpha);
	
	out.Scale=LerpVector2D(a.Scale,b.Scale,alpha);
	out.Shear=LerpVector2D(a.Shear,b.Shear,alpha);
	out.Translation=LerpVector2D(a.Translation,b.Translation,alpha);

	return out;
}

FVector2D UOmegaMathFunctions::LerpVector2D(FVector2D a, FVector2D b, float alpha)
{
	FVector2D out;
	out.X=UKismetMathLibrary::Lerp(a.X,b.X,alpha);
	out.Y=UKismetMathLibrary::Lerp(a.Y,b.Y,alpha);
	return out;
}

float UOmegaMathFunctions::GetAngle_FromVectors(FVector A, FVector B)
{
	return UKismetMathLibrary::DegAcos(UKismetMathLibrary::Dot_VectorVector(UKismetMathLibrary::Normal(A),UKismetMathLibrary::Normal(B)));
}

float UOmegaMathFunctions::GetAngle_FromRotators(FRotator A, FRotator B)
{
	return GetAngle_FromVectors(UKismetMathLibrary::Conv_RotatorToVector(A),UKismetMathLibrary::Conv_RotatorToVector(B));
}

FRotator UOmegaMathFunctions::Conv_VectorToRot_Flat(FVector Vector)
{
	FRotator _out;
	_out.Pitch=Vector.Y;
	_out.Roll=Vector.X;
	_out.Yaw=Vector.Z;
	return _out;
}

FWidgetTransform UOmegaMathFunctions::Conv_Transform3DToTransformWidget(const FTransform Transform)
{
	FWidgetTransform _ts;
	_ts.Translation=UKismetMathLibrary::Conv_VectorToVector2D(Transform.GetLocation());
	_ts.Angle=Transform.GetRotation().Rotator().Roll;
	_ts.Scale=UKismetMathLibrary::Conv_VectorToVector2D(Transform.GetScale3D());
	return _ts;
}

float UOmegaMathFunctions::NormalizeToRange_int32(int32 value, int32 min, int32 max)
{
	return UKismetMathLibrary::NormalizeToRange(value,min,max);
}

int32 UOmegaMathFunctions::GetSeedFromGuid(FGuid Guid)
{
	return Guid.A+Guid.B+Guid.C+Guid.D;
}

bool UOmegaMathFunctions::RNG_RollFromFloat(float chance, bool& Outcome)
{
	float _rand = UKismetMathLibrary::RandomFloat();
	if(_rand==0.0 || _rand<=chance)
	{
		Outcome=true;
		return true;
	}
	Outcome=false;
	return false;
}

float UOmegaMathFunctions::Variate_Float(float in, float amount, bool bAmountIsScale)
{
	float _offset = UKismetMathLibrary::RandomFloatInRange(amount*-1,amount);
	if(bAmountIsScale) { return in+(_offset*in);} return in+_offset;
}

FVector UOmegaMathFunctions::Offset_Vector(FVector Vector, const FRotator& Rotation, FVector Offset)
{
	return Vector+
		(UKismetMathLibrary::GetForwardVector(Rotation)*Offset.X)+
		(UKismetMathLibrary::GetRightVector(Rotation)*Offset.Y)+
		(UKismetMathLibrary::GetUpVector(Rotation)*Offset.Z);
}

FVector UOmegaMathFunctions::Offset_ActorLocation(const AActor* Actor, FVector Offset)
{
	if(Actor)
	{
		return Offset_Vector(Actor->GetActorLocation(),Actor->GetActorRotation(),Offset);
	}
	return FVector();
}

FVector UOmegaMathFunctions::Offset_PawnLocationFromControl(const APawn* Pawn, FVector Offset)
{
	if(Pawn)
	{
		return Offset_Vector(Pawn->GetActorLocation(),Pawn->GetControlRotation(),Offset);
	}
	return FVector();
}

FVector UOmegaMathFunctions::Random_VectorInRange(FVector Min, FVector Max)
{
	FVector _out;
	_out.X=UKismetMathLibrary::RandomFloatInRange(Min.X,Max.X);
	_out.Y=UKismetMathLibrary::RandomFloatInRange(Min.Y,Max.Y);
	_out.Z=UKismetMathLibrary::RandomFloatInRange(Min.Z,Max.Z);
	return _out;
}

FRotator UOmegaMathFunctions::Random_RotatorInRange(const FRotator& Min, const FRotator& Max)
{
	FRotator _out;
	_out.Yaw=UKismetMathLibrary::RandomFloatInRange(Min.Yaw,Max.Yaw);
	_out.Pitch=UKismetMathLibrary::RandomFloatInRange(Min.Pitch,Max.Pitch);
	_out.Roll=UKismetMathLibrary::RandomFloatInRange(Min.Roll,Max.Roll);
	return _out;
}


TMap<UPrimaryDataAsset*, int32> UOmegaMathFunctions::InvertMapValues_AssetInt(TMap<UPrimaryDataAsset*, int32> in)
{
	TMap<UPrimaryDataAsset*, int32> out;
	for(const auto& p : in)
	{
		out.Add(p.Key,p.Value*-1);
	}
	return out;
}

TMap<UPrimaryDataAsset*, float> UOmegaMathFunctions::InvertMapValues_Assetfloat(TMap<UPrimaryDataAsset*, float> in)
{
	TMap<UPrimaryDataAsset*, float> out;
	for(const auto& p : in)
	{
		out.Add(p.Key,p.Value*-1);
	}
	return out;
}

bool UOmegaMathFunctions::Compare_Int(int32 A, TEnumAsByte<EOmegaComparisonMethod> is, int32 B)
{
	switch (is)
	{
	case Compare_Equal: return A == B ;
	case Compare_Great: return A > B ;
	case Compare_Less: return A < B ;
	case Compare_GreatEqual: return A >= B ;
	case Compare_LessEqual: return A <= B ;
	default: return false; 
	}
}

bool UOmegaMathFunctions::Compare_Float(float A, TEnumAsByte<EOmegaComparisonMethod> is, float B)
{
	switch (is)
	{
	case Compare_Equal: return A == B ;
	case Compare_Great: return A > B ;
	case Compare_Less: return A < B ;
	case Compare_GreatEqual: return A >= B ;
	case Compare_LessEqual: return A <= B ;
	default: return false; 
	}
}

FTransform UOmegaMathFunctions::AddTransforms(const FTransform A, const FTransform B)
{
	FTransform out;
	out.SetLocation(A.GetLocation()+B.GetLocation());
	out.SetScale3D(A.GetScale3D()+B.GetScale3D());
	out.SetRotation(UKismetMathLibrary::ComposeRotators(A.GetRotation().Rotator(),B.GetRotation().Rotator()).Quaternion());
	return out;
}

// ----------------------------------------------------------------------------------------


bool UOmegaMathFunctions::DoLinesCross(const FOmegaLine& Line1, const FOmegaLine& Line2, float Tolerance,
	float PointTolerance)
{
	const FVector2D& P1 = Line1.Start;
	const FVector2D& Q1 = Line1.End;
	const FVector2D& P2 = Line2.Start;
	const FVector2D& Q2 = Line2.End;

	const double Tol = static_cast<double>(Tolerance);
	const double PtTol = static_cast<double>(PointTolerance);
	const double PtTolSq = PtTol * PtTol;

	// EARLY OUT: If PointTolerance is set and lines share an endpoint, skip entirely
	if (PtTol > 0.0 && SharesEndpoint(P1, Q1, P2, Q2, PtTolSq))
	{
		return false;
	}

	const FVector2D D1 = Q1 - P1;
	const FVector2D D2 = Q2 - P2;
	const double Cross = D1.X * D2.Y - D1.Y * D2.X;

	// Non-parallel case
	if (FMath::Abs(Cross) > Tol)
	{
		const FVector2D D12 = P2 - P1;
		const double InvCross = 1.0 / Cross;
		const double T = (D12.X * D2.Y - D12.Y * D2.X) * InvCross;
		const double S = (D12.X * D1.Y - D12.Y * D1.X) * InvCross;

		// Check if intersection lies within both segments
		if (T >= -Tol && T <= 1.0 + Tol && S >= -Tol && S <= 1.0 + Tol)
		{
			if (PtTol > 0.0)
			{
				// Additional check: if T or S is near 0 or 1, intersection is at endpoint
				const double EndpointParamTol = PtTol / FMath::Max(D1.Size(), D2.Size());
				if (T <= EndpointParamTol || T >= 1.0 - EndpointParamTol ||
				    S <= EndpointParamTol || S >= 1.0 - EndpointParamTol)
				{
					return false;
				}

				// Also verify with actual point distance
				const FVector2D Intersection = P1 + D1 * T;
				if (IsNearEndpoint(Intersection, P1, Q1, P2, Q2, PtTolSq))
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}

	// Parallel case - check if collinear
	const FVector2D D12 = P2 - P1;
	const double CrossCollinear = D12.X * D1.Y - D12.Y * D1.X;

	if (FMath::Abs(CrossCollinear) > Tol)
	{
		// Parallel but not collinear
		return false;
	}

	// Collinear - check for overlap
	const double D1LenSq = D1.SizeSquared();
	if (D1LenSq <= Tol * Tol)
	{
		return false;
	}

	const double InvD1LenSq = 1.0 / D1LenSq;
	const double T_P2 = FVector2D::DotProduct(D12, D1) * InvD1LenSq;
	const double T_Q2 = FVector2D::DotProduct(Q2 - P1, D1) * InvD1LenSq;

	const double MinT = FMath::Max(0.0, FMath::Min(T_P2, T_Q2));
	const double MaxT = FMath::Min(1.0, FMath::Max(T_P2, T_Q2));

	if (MaxT <= MinT + Tol)
	{
		return false;
	}

	// Overlap exists - check if it's just endpoint touching
	if (PtTol > 0.0)
	{
		const double D1Len = FMath::Sqrt(D1LenSq);
		const double OverlapLen = (MaxT - MinT) * D1Len;
		if (OverlapLen <= PtTol)
		{
			return false;
		}
	}
	return true;
}

bool UOmegaMathFunctions::DoAnyLinesCross(const TArray<FOmegaLine>& Lines, TArray<int32>& CrossingLineIndices,
                                          float Tolerance, float PointTolerance)
{
	CrossingLineIndices.Reset();

	const int32 Num = Lines.Num();
	if (Num < 2)
	{
		return false;
	}

	TBitArray<> Flagged;
	Flagged.Init(false, Num);

	const FOmegaLine* RESTRICT Data = Lines.GetData();
	bool bAnyCrossing = false;

	for (int32 i = 0; i < Num - 1; ++i)
	{
		for (int32 j = i + 1; j < Num; ++j)
		{
			if (DoLinesCross(Data[i], Data[j], Tolerance, PointTolerance))
			{
				bAnyCrossing = true;

				if (!Flagged[i])
				{
					Flagged[i] = true;
					CrossingLineIndices.Add(i);
				}
				if (!Flagged[j])
				{
					Flagged[j] = true;
					CrossingLineIndices.Add(j);
				}
			}
		}
	}

	return bAnyCrossing;
}
