// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_Trace.h"
#include "Engine/GameInstance.h"
#include "Engine/HitResult.h"


const FHitResult UOmegaScriptedTraceFunctions::ScriptedTrace_Single(AActor* Instigator, FOmegaScriptedTrace Trace,bool& Success)
{
	if(Trace.Logic && Instigator)
	{
		Trace.Logic->WorldPrivate=Instigator->GetWorld();
		return Trace.Logic->RunTrace(Instigator,Success);
	}
	return  FHitResult();
}

const TArray<FHitResult> UOmegaScriptedTraceFunctions::ScriptedTrace_Multi(AActor* Instigator, FOmegaScriptedTrace Trace,bool& Success)
{
	TArray<FHitResult>  out;
	if(Trace.Logic && Instigator)
	{
		Trace.Logic->WorldPrivate=Instigator->GetWorld();
		return Trace.Logic->RunTrace_Multi(Instigator,Success);
	}
	return out;
}

UOmegaScriptedTraceLogic::UOmegaScriptedTraceLogic(const FObjectInitializer& ObjectInitializer)
{
	if (const UObject* Owner = GetOuter())
	{
		WorldPrivate = Owner->GetWorld();
	}
}

UWorld* UOmegaScriptedTraceLogic::GetWorld() const
{
	if(GetGameInstance())
	{
		return GetGameInstance()->GetWorld();
	}
	return nullptr;
}

UGameInstance* UOmegaScriptedTraceLogic::GetGameInstance() const
{
	if(WorldPrivate)
	{
		return WorldPrivate->GetGameInstance();
	}
	return Cast<UGameInstance>(GetOuter());
}