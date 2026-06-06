// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Slate/WidgetTransform.h"
#include "F_Math.generated.h"

USTRUCT(BlueprintType)
struct FOmegaLine
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Line")
	FVector2D Start = FVector2D::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Line")
	FVector2D End = FVector2D::ZeroVector;

	FOmegaLine() = default;
	FOmegaLine(const FVector2D& InStart, const FVector2D& InEnd) : Start(InStart), End(InEnd) {}
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaMathFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintPure,Category="Omega|Math",DisplayName="📐 Compare - Float")
	static bool Compare_Float(float A, TEnumAsByte<EOmegaComparisonMethod> is,float B);
	
	UFUNCTION(BlueprintPure,Category="Omega|Math",DisplayName="📐 Compare - Int")
	static bool Compare_Int(int32 A, TEnumAsByte<EOmegaComparisonMethod> is, int32 B);

	UFUNCTION(BlueprintPure,Category="Omega|Math")
	static FTransform AddTransforms(const FTransform A, const FTransform B);

	UFUNCTION(BlueprintPure,Category="Omega|Widget",DisplayName="📐 Lerp - Widget Transform")
	static FWidgetTransform LerpWidgetTransform(FWidgetTransform a, FWidgetTransform b, float alpha);

	UFUNCTION(BlueprintPure,Category="Omega|Widget",DisplayName="📐 Lerp - Vector2D")
	static FVector2D LerpVector2D(FVector2D a, FVector2D b, float alpha);

	UFUNCTION(BlueprintPure,Category="Omega|Math",DisplayName="📐 Get Angle - From Vectors")
	static float GetAngle_FromVectors(FVector A, FVector B);

	UFUNCTION(BlueprintPure,Category="Omega|Math",DisplayName="📐 Get Angle - From Rotators")
	static float GetAngle_FromRotators(FRotator A, FRotator B);

	UFUNCTION(BlueprintPure,Category="Omega|Math",DisplayName="📐 Conv - Vector -> Rotation (FLAT)")
	static FRotator Conv_VectorToRot_Flat(FVector Vector);

	UFUNCTION(BlueprintPure,Category="Omega|Math",DisplayName="📐 Conv - Transform3D -> Widget Transform")
	static FWidgetTransform Conv_Transform3DToTransformWidget(const FTransform Transform);
	
	UFUNCTION(BlueprintPure,Category="Omega|Math", DisplayName="📐 Normalize to Range - Int32")
	static float NormalizeToRange_int32(int32 value, int32 min, int32 max);

	// Seed Randomization
	UFUNCTION(BlueprintPure,Category="Omega|Math")
	static int32 GetSeedFromGuid(FGuid Guid);

	UFUNCTION(BlueprintPure,Category="Omega|Math|Curve")
	static float GetCurve_Value(FFloatCurve Curve, float time)
	{
		return  Curve.Evaluate(time);
	}
	UFUNCTION(BlueprintCallable,Category="Omega|Math",meta=(ExpandBoolAsExecs="Outcome"))
	static bool RNG_RollFromFloat(float chance, bool& Outcome);
	
	UFUNCTION(BlueprintPure,Category="Omega|Math")
	static float Variate_Float(float in, float amount, bool bAmountIsScale);

	UFUNCTION(BlueprintPure,Category="Omega|Math", DisplayName="📐 Offset - Vector")
	static FVector Offset_Vector(FVector Vector, const FRotator& Rotation, FVector Offset);
	UFUNCTION(BlueprintPure,Category="Omega|Math", DisplayName="📐 Offset - Actor Location")
	static FVector Offset_ActorLocation(const AActor* Actor, FVector Offset);
	UFUNCTION(BlueprintPure,Category="Omega|Math", DisplayName="📐 Offset - Pawn From Control")
	static FVector Offset_PawnLocationFromControl(const APawn* Pawn, FVector Offset);

	UFUNCTION(BlueprintPure,Category="Omega|Math", DisplayName="📐 Random - Vector in Range")
	static FVector Random_VectorInRange(FVector Min, FVector Max);

	UFUNCTION(BlueprintPure,Category="Omega|Math", DisplayName="📐 Random - Rotator in Range")
	static FRotator Random_RotatorInRange(const FRotator& Min, const FRotator& Max);

	//
	UFUNCTION(BlueprintPure,Category="Omega|Math")
	static TMap<UPrimaryDataAsset*,int32> InvertMapValues_AssetInt(TMap<UPrimaryDataAsset*,int32> in);
	UFUNCTION(BlueprintPure,Category="Omega|Math")
	static TMap<UPrimaryDataAsset*,float> InvertMapValues_Assetfloat(TMap<UPrimaryDataAsset*,float> in);
	
	// ----------------------------------------------------------------------------------------
private:
	// 2D cross product: (B-A) × (C-A)
	FORCEINLINE static double Cross2D(const FVector2D& A, const FVector2D& B, const FVector2D& C)
	{
		return (B.X - A.X) * (C.Y - A.Y) - (B.Y - A.Y) * (C.X - A.X);
	}

	// Check if two points are within squared tolerance
	FORCEINLINE static bool PointsNear(const FVector2D& A, const FVector2D& B, double TolSq)
	{
		return FVector2D::DistSquared(A, B) <= TolSq;
	}

	// Check if lines share any endpoint within tolerance
	FORCEINLINE static bool SharesEndpoint(const FVector2D& P1, const FVector2D& Q1,
											const FVector2D& P2, const FVector2D& Q2, double TolSq)
	{
		return PointsNear(P1, P2, TolSq) || PointsNear(P1, Q2, TolSq) ||
			   PointsNear(Q1, P2, TolSq) || PointsNear(Q1, Q2, TolSq);
	}

	// Check if point is within tolerance of any of the 4 segment endpoints
	FORCEINLINE static bool IsNearEndpoint(const FVector2D& Point, const FVector2D& P1, const FVector2D& Q1,
											const FVector2D& P2, const FVector2D& Q2, double TolSq)
	{
		return PointsNear(Point, P1, TolSq) || PointsNear(Point, Q1, TolSq) ||
			   PointsNear(Point, P2, TolSq) || PointsNear(Point, Q2, TolSq);
	}

public:
	/**
	 * Check if two line segments intersect.
	 * @param Line1 First line segment
	 * @param Line2 Second line segment
	 * @param Tolerance Floating point tolerance for collinear/parallel detection
	 * @param PointTolerance If intersection is within this distance of any endpoint, returns false (0 = disabled)
	 * @return True if the segments intersect (and not within PointTolerance of endpoints)
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Omega|Geometry", meta = (Keywords = "intersect cross segment"))
	static bool DoLinesCross(const FOmegaLine& Line1, const FOmegaLine& Line2, float Tolerance = 1e-8f, float PointTolerance = 0.0f);

	/**
	 * Check if any pair of line segments intersect and report which lines are involved.
	 * @param Lines Array of line segments to test
	 * @param CrossingLineIndices Output: indices of all lines that cross at least one other line
	 * @param Tolerance Floating point tolerance for collinear/parallel detection
	 * @param PointTolerance If intersection is within this distance of any endpoint, not counted (0 = disabled)
	 * @return True if any two segments intersect
	 */
	UFUNCTION(BlueprintCallable, Category = "Omega|Geometry", meta = (Keywords = "intersect cross segment any"))
	static bool DoAnyLinesCross(const TArray<FOmegaLine>& Lines, TArray<int32>& CrossingLineIndices,
	                            float Tolerance = 1e-8f, float PointTolerance = 0.0f);
	
};

