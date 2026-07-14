// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_Trace.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/HitResult.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Functions/F_Math.h"
#include "Kismet/KismetSystemLibrary.h"

// Shared fast path for the "Trace by Query" functions. Hits raw UWorld scene queries directly
// (no UKismetSystemLibrary overhead) and early-outs on the first hit the query delegate accepts.
static bool Omega_RunQueryTrace(UObject* WorldContextObject, const FVector& Start, const FVector& End,
	const FCollisionShape* Shape, const FQuat& ShapeRot, const FOmegaTraceQueryCheck& Query,
	const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes, bool bTraceComplex,
	const TArray<AActor*>& ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult& OutHit)
{
	OutHit = FHitResult();
	UWorld* World = GEngine ? GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull) : nullptr;
	if(!World) { return false; }

	FCollisionObjectQueryParams ObjectParams;
	for(const EObjectTypeQuery ObjectType : ObjectTypes)
	{
		ObjectParams.AddObjectTypesToQuery(UEngineTypes::ConvertToCollisionChannel(ObjectType));
	}
	if(!ObjectParams.IsValid()) { return false; }

	FCollisionQueryParams Params(SCENE_QUERY_STAT(OmegaQueryTrace), bTraceComplex);
	Params.AddIgnoredActors(ActorsToIgnore);

	TArray<FHitResult> Hits;
	if(Shape)
	{
		World->SweepMultiByObjectType(Hits, Start, End, ShapeRot, ObjectParams, *Shape, Params);
	}
	else
	{
		World->LineTraceMultiByObjectType(Hits, Start, End, ObjectParams, Params);
	}

	// Hits come back sorted near-to-far, so the first accepted hit is the closest valid one.
	int32 AcceptedIndex = INDEX_NONE;
	for(int32 i = 0; i < Hits.Num(); i++)
	{
		if(!Query.IsBound() || Query.Execute(Hits[i]))
		{
			AcceptedIndex = i;
			break;
		}
	}

#if ENABLE_DRAW_DEBUG
	if(DrawDebugType != EDrawDebugTrace::None)
	{
		const bool bPersistent = DrawDebugType == EDrawDebugTrace::Persistent;
		const float DrawTime = DrawDebugType == EDrawDebugTrace::ForDuration ? 5.f : 0.f;
		const FColor TraceColor = AcceptedIndex != INDEX_NONE ? FColor::Green : FColor::Red;
		DrawDebugLine(World, Start, End, TraceColor, bPersistent, DrawTime);
		if(Shape)
		{
			if(Shape->IsSphere())
			{
				DrawDebugSphere(World, Start, Shape->GetSphereRadius(), 16, TraceColor, bPersistent, DrawTime);
				DrawDebugSphere(World, End, Shape->GetSphereRadius(), 16, TraceColor, bPersistent, DrawTime);
			}
			else if(Shape->IsBox())
			{
				DrawDebugBox(World, Start, Shape->GetExtent(), ShapeRot, TraceColor, bPersistent, DrawTime);
				DrawDebugBox(World, End, Shape->GetExtent(), ShapeRot, TraceColor, bPersistent, DrawTime);
			}
		}
		// Evaluated hits: red = rejected by the query, green = accepted. Hits beyond the accepted one were never evaluated.
		const int32 NumEvaluated = AcceptedIndex != INDEX_NONE ? AcceptedIndex + 1 : Hits.Num();
		for(int32 i = 0; i < NumEvaluated; i++)
		{
			DrawDebugPoint(World, Hits[i].ImpactPoint, 16.f, i == AcceptedIndex ? FColor::Green : FColor::Red, bPersistent, DrawTime);
		}
	}
#endif

	if(AcceptedIndex != INDEX_NONE)
	{
		OutHit = MoveTemp(Hits[AcceptedIndex]);
		return true;
	}
	return false;
}

bool UOmegaScriptedTraceFunctions::Query_Line(UObject* WorldContextObject, FVector Start, FVector End,
	FOmegaTraceQueryCheck Query, TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes, bool TraceComplex,
	const TArray<AActor*>& ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult& OutHit)
{
	return Omega_RunQueryTrace(WorldContextObject, Start, End, nullptr, FQuat::Identity, Query, ObjectTypes, TraceComplex, ActorsToIgnore, DrawDebugType, OutHit);
}

bool UOmegaScriptedTraceFunctions::Query_Sphere(UObject* WorldContextObject, FVector Start, FVector End, float Radius,
	FOmegaTraceQueryCheck Query, TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes, bool TraceComplex,
	const TArray<AActor*>& ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult& OutHit)
{
	const FCollisionShape Shape = FCollisionShape::MakeSphere(Radius);
	return Omega_RunQueryTrace(WorldContextObject, Start, End, &Shape, FQuat::Identity, Query, ObjectTypes, TraceComplex, ActorsToIgnore, DrawDebugType, OutHit);
}

bool UOmegaScriptedTraceFunctions::Query_Box(UObject* WorldContextObject, FVector Start, FVector End, FVector HalfSize, FRotator Orientation,
	FOmegaTraceQueryCheck Query, TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes, bool TraceComplex,
	const TArray<AActor*>& ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult& OutHit)
{
	const FCollisionShape Shape = FCollisionShape::MakeBox(HalfSize);
	return Omega_RunQueryTrace(WorldContextObject, Start, End, &Shape, Orientation.Quaternion(), Query, ObjectTypes, TraceComplex, ActorsToIgnore, DrawDebugType, OutHit);
}


FHitResult UOmegaScriptedTraceLogic::RunTrace_Implementation(AActor* Instigator, bool& Success)
{
	return FHitResult();
}

TArray<FHitResult> UOmegaScriptedTraceLogic::RunTrace_Multi_Implementation(AActor* Instigator, bool& Success)
{
	return TArray<FHitResult>();
}

FHitResult UOmegaScriptedTraceFunctions::ScriptedTrace_Single(AActor* Instigator, FOmegaScriptedTrace Trace,bool& Success)
{
	if(Trace.Logic && Instigator)
	{
		return Trace.Logic->RunTrace(Instigator,Success);
	}
	return  FHitResult();
}

TArray<FHitResult> UOmegaScriptedTraceFunctions::ScriptedTrace_Multi(AActor* Instigator, FOmegaScriptedTrace Trace,bool& Success)
{
	TArray<FHitResult>  out;
	if(Trace.Logic && Instigator)
	{
		return Trace.Logic->RunTrace_Multi(Instigator,Success);
	}
	return out;
}

// ---------------------------------------------------------------------------------------------------------------------
// Line Trace
// ---------------------------------------------------------------------------------------------------------------------

FHitResult UOmegaScriptedTrace_Line::RunTrace_Implementation(AActor* Instigator, bool& Success)
{
	FHitResult Hit;
	const FVector Start = UOmegaMathFunctions::Offset_ActorLocation(Instigator, OffsetStart);
	const FVector End   = UOmegaMathFunctions::Offset_ActorLocation(Instigator, OffsetEnd);
	TArray<AActor*> Ignore;
	Success = UKismetSystemLibrary::LineTraceSingle(Instigator, Start, End, TraceChannel, bTraceComplex, Ignore, bDebug ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None, Hit, true);
	return Hit;
}

TArray<FHitResult> UOmegaScriptedTrace_Line::RunTrace_Multi_Implementation(AActor* Instigator, bool& Success)
{
	TArray<FHitResult> Hits;
	const FVector Start = UOmegaMathFunctions::Offset_ActorLocation(Instigator, OffsetStart);
	const FVector End   = UOmegaMathFunctions::Offset_ActorLocation(Instigator, OffsetEnd);
	TArray<AActor*> Ignore;
	Success = UKismetSystemLibrary::LineTraceMulti(Instigator, Start, End, TraceChannel, bTraceComplex, Ignore, bDebug ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None, Hits, true);
	return Hits;
}

// ---------------------------------------------------------------------------------------------------------------------
// Sphere Trace
// ---------------------------------------------------------------------------------------------------------------------

FHitResult UOmegaScriptedTrace_Sphere::RunTrace_Implementation(AActor* Instigator, bool& Success)
{
	FHitResult Hit;
	const FVector Start = UOmegaMathFunctions::Offset_ActorLocation(Instigator, OffsetStart);
	const FVector End   = UOmegaMathFunctions::Offset_ActorLocation(Instigator, OffsetEnd);
	TArray<AActor*> Ignore;
	Success = UKismetSystemLibrary::SphereTraceSingle(Instigator, Start, End, Radius, TraceChannel, bTraceComplex, Ignore, bDebug ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None, Hit, true);
	return Hit;
}

TArray<FHitResult> UOmegaScriptedTrace_Sphere::RunTrace_Multi_Implementation(AActor* Instigator, bool& Success)
{
	TArray<FHitResult> Hits;
	const FVector Start = UOmegaMathFunctions::Offset_ActorLocation(Instigator, OffsetStart);
	const FVector End   = UOmegaMathFunctions::Offset_ActorLocation(Instigator, OffsetEnd);
	TArray<AActor*> Ignore;
	Success = UKismetSystemLibrary::SphereTraceMulti(Instigator, Start, End, Radius, TraceChannel, bTraceComplex, Ignore, bDebug ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None, Hits, true);
	return Hits;
}

// ---------------------------------------------------------------------------------------------------------------------
// Box Trace
// ---------------------------------------------------------------------------------------------------------------------

FHitResult UOmegaScriptedTrace_Box::RunTrace_Implementation(AActor* Instigator, bool& Success)
{
	FHitResult Hit;
	const FVector Start = UOmegaMathFunctions::Offset_ActorLocation(Instigator, OffsetStart);
	const FVector End   = UOmegaMathFunctions::Offset_ActorLocation(Instigator, OffsetEnd);
	TArray<AActor*> Ignore;
	Success = UKismetSystemLibrary::BoxTraceSingle(Instigator, Start, End, HalfSize, Orientation, TraceChannel, bTraceComplex, Ignore, bDebug ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None, Hit, true);
	return Hit;
}

TArray<FHitResult> UOmegaScriptedTrace_Box::RunTrace_Multi_Implementation(AActor* Instigator, bool& Success)
{
	TArray<FHitResult> Hits;
	const FVector Start = UOmegaMathFunctions::Offset_ActorLocation(Instigator, OffsetStart);
	const FVector End   = UOmegaMathFunctions::Offset_ActorLocation(Instigator, OffsetEnd);
	TArray<AActor*> Ignore;
	Success = UKismetSystemLibrary::BoxTraceMulti(Instigator, Start, End, HalfSize, Orientation, TraceChannel, bTraceComplex, Ignore, bDebug ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None, Hits, true);
	return Hits;
}

// ---------------------------------------------------------------------------------------------------------------------
// Capsule Trace
// ---------------------------------------------------------------------------------------------------------------------

FHitResult UOmegaScriptedTrace_Capsule::RunTrace_Implementation(AActor* Instigator, bool& Success)
{
	FHitResult Hit;
	const FVector Start = UOmegaMathFunctions::Offset_ActorLocation(Instigator, OffsetStart);
	const FVector End   = UOmegaMathFunctions::Offset_ActorLocation(Instigator, OffsetEnd);
	TArray<AActor*> Ignore;
	Success = UKismetSystemLibrary::CapsuleTraceSingle(Instigator, Start, End, Radius, HalfHeight, TraceChannel, bTraceComplex, Ignore, bDebug ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None, Hit, true);
	return Hit;
}

TArray<FHitResult> UOmegaScriptedTrace_Capsule::RunTrace_Multi_Implementation(AActor* Instigator, bool& Success)
{
	TArray<FHitResult> Hits;
	const FVector Start = UOmegaMathFunctions::Offset_ActorLocation(Instigator, OffsetStart);
	const FVector End   = UOmegaMathFunctions::Offset_ActorLocation(Instigator, OffsetEnd);
	TArray<AActor*> Ignore;
	Success = UKismetSystemLibrary::CapsuleTraceMulti(Instigator, Start, End, Radius, HalfHeight, TraceChannel, bTraceComplex, Ignore, bDebug ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None, Hits, true);
	return Hits;
}
