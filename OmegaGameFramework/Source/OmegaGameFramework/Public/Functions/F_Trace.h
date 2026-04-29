// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Trace.generated.h"

UCLASS(Blueprintable,BlueprintType,EditInlineNew,meta=(ShowWorldContextPin),Abstract,CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedTraceLogic : public UObject
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, Category="Trace")
	FHitResult RunTrace(AActor* Instigator,bool& Success);
	UFUNCTION(BlueprintNativeEvent, Category="Trace")
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
	static FHitResult ScriptedTrace_Single(AActor* Instigator, FOmegaScriptedTrace Trace,bool& Success);

	UFUNCTION(BlueprintCallable, Category="Omega")
	static TArray<FHitResult> ScriptedTrace_Multi(AActor* Instigator, FOmegaScriptedTrace Trace,bool& Success);
};


// ---------------------------------------------------------------------------------------------------------------------
// Trace Types
// ---------------------------------------------------------------------------------------------------------------------

UCLASS(Blueprintable, BlueprintType, EditInlineNew, meta=(ShowWorldContextPin), DisplayName="Line Trace")
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedTrace_Line : public UOmegaScriptedTraceLogic
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	FVector OffsetStart = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	FVector OffsetEnd = FVector(200.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	TEnumAsByte<ETraceTypeQuery> TraceChannel = TraceTypeQuery1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	bool bTraceComplex = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	bool bDebug = false;

	virtual FHitResult RunTrace_Implementation(AActor* Instigator, bool& Success) override;
	virtual TArray<FHitResult> RunTrace_Multi_Implementation(AActor* Instigator, bool& Success) override;
};

UCLASS(Blueprintable, BlueprintType, EditInlineNew, meta=(ShowWorldContextPin), DisplayName="Sphere Trace")
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedTrace_Sphere : public UOmegaScriptedTraceLogic
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	FVector OffsetStart = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	FVector OffsetEnd = FVector(200.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	float Radius = 32.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	TEnumAsByte<ETraceTypeQuery> TraceChannel = TraceTypeQuery1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	bool bTraceComplex = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	bool bDebug = false;

	virtual FHitResult RunTrace_Implementation(AActor* Instigator, bool& Success) override;
	virtual TArray<FHitResult> RunTrace_Multi_Implementation(AActor* Instigator, bool& Success) override;
};

UCLASS(Blueprintable, BlueprintType, EditInlineNew, meta=(ShowWorldContextPin), DisplayName="Box Trace")
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedTrace_Box : public UOmegaScriptedTraceLogic
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	FVector OffsetStart = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	FVector OffsetEnd = FVector(200.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	FVector HalfSize = FVector(32.f, 32.f, 32.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	FRotator Orientation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	TEnumAsByte<ETraceTypeQuery> TraceChannel = TraceTypeQuery1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	bool bTraceComplex = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	bool bDebug = false;

	virtual FHitResult RunTrace_Implementation(AActor* Instigator, bool& Success) override;
	virtual TArray<FHitResult> RunTrace_Multi_Implementation(AActor* Instigator, bool& Success) override;
};

UCLASS(Blueprintable, BlueprintType, EditInlineNew, meta=(ShowWorldContextPin), DisplayName="Capsule Trace")
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedTrace_Capsule : public UOmegaScriptedTraceLogic
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	FVector OffsetStart = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	FVector OffsetEnd = FVector(200.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	float Radius = 32.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	float HalfHeight = 64.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	TEnumAsByte<ETraceTypeQuery> TraceChannel = TraceTypeQuery1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	bool bTraceComplex = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	bool bDebug = false;

	virtual FHitResult RunTrace_Implementation(AActor* Instigator, bool& Success) override;
	virtual TArray<FHitResult> RunTrace_Multi_Implementation(AActor* Instigator, bool& Success) override;
};
