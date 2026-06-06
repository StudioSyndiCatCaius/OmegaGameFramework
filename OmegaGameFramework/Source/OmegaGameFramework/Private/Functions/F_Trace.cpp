// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_Trace.h"
#include "Engine/GameInstance.h"
#include "Engine/HitResult.h"
#include "Functions/F_Math.h"
#include "Kismet/KismetSystemLibrary.h"


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
