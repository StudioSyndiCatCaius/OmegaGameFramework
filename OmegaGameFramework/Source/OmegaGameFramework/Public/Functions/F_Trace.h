// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Trace.generated.h"

UCLASS(Blueprintable,BlueprintType,EditInlineNew)
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedTraceLogic : public UObject
{
	GENERATED_BODY()
	


public:
	UPROPERTY(Transient)
	UWorld* WorldPrivate = nullptr;
	UOmegaScriptedTraceLogic(const FObjectInitializer& ObjectInitializer);
	virtual UWorld* GetWorld() const override;
	UFUNCTION()
	virtual UGameInstance* GetGameInstance() const;
	
	UFUNCTION(BlueprintImplementableEvent, Category="Trace")
	FHitResult RunTrace(AActor* Instigator,bool& Success);
	UFUNCTION(BlueprintImplementableEvent, Category="Trace")
	TArray<FHitResult> RunTrace_Multi(AActor* Instigator,bool& Success);
};


USTRUCT(BlueprintType)
struct FOmegaScriptedTrace
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Trace")
	UOmegaScriptedTraceLogic* Logic=nullptr;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedTraceFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable, Category="Omega")
	static const FHitResult ScriptedTrace_Single(AActor* Instigator, FOmegaScriptedTrace Trace,bool& Success);

	UFUNCTION(BlueprintCallable, Category="Omega")
	static const TArray<FHitResult> ScriptedTrace_Multi(AActor* Instigator, FOmegaScriptedTrace Trace,bool& Success);
};


