// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaScriptedTrace.generated.h"

UCLASS(Blueprintable,BlueprintType,EditInlineNew)
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedTraceLogic : public UObject
{
	GENERATED_BODY()
	
	UPROPERTY(Transient)
	UWorld* WorldPrivate = nullptr;

public:
	UOmegaScriptedTraceLogic(const FObjectInitializer& ObjectInitializer);
	virtual UWorld* GetWorld() const override;
	UFUNCTION()
	virtual UGameInstance* GetGameInstance() const;
	
	UFUNCTION(BlueprintImplementableEvent, Category="Trace")
	FHitResult RunTrace(UObject* context,bool& Success);
	UFUNCTION(BlueprintImplementableEvent, Category="Trace")
	TArray<FHitResult> RunTrace_Multi(UObject* context,bool& Success);
};


USTRUCT(BlueprintType)
struct FOmegaScriptedTrace
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Trace")
	UOmegaScriptedTraceLogic* Logic;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedTraceFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable, Category="Omega")
	static const FHitResult ScriptedTrace_Single(UObject* context, FOmegaScriptedTrace Trace,bool& Success);

	UFUNCTION(BlueprintCallable, Category="Omega")
	static const TArray<FHitResult> ScriptedTrace_Multi(UObject* context, FOmegaScriptedTrace Trace,bool& Success);
};


