// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Spline.h"
#include "Components/SplineComponent.h"
#include "Kismet/KismetMathLibrary.h"

TArray<FVector2D> UOmegaFunctions_Spline::Get2DVectorPoints(USplineComponent* Spline)
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

void UOmegaFunctions_Spline::ClampTangents(USplineComponent* Spline, float Min, float Max)
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

