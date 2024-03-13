// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/OmegaFunctions_ScriptedTrace.h"
#include "Engine/GameInstance.h"
#include "Engine/HitResult.h"


const FHitResult UOmegaScriptedTraceFunctions::ScriptedTrace_Single(UObject* context, FOmegaScriptedTrace Trace,bool& Success)
{
	if(Trace.Logic)
	{
		return Trace.Logic->RunTrace(context,Success);
	}
	return  FHitResult();
}

const TArray<FHitResult> UOmegaScriptedTraceFunctions::ScriptedTrace_Multi(UObject* context, FOmegaScriptedTrace Trace,bool& Success)
{
	TArray<FHitResult>  out;
	if(Trace.Logic)
	{
		return Trace.Logic->RunTrace_Multi(context,Success);
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
	return Cast<UGameInstance>(GetOuter());
}