// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MetasoundEnum.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
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

DECLARE_DYNAMIC_DELEGATE_RetVal_OneParam(bool, FOmegaTraceQueryCheck, FHitResult, Hit);

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedTraceFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category="Omega",DisplayName="Trace by Query - Line",meta=(WorldContext="WorldContextObject",AutoCreateRefTerm="ActorsToIgnore"))
	static bool Query_Line(UObject* WorldContextObject,FVector Start,FVector End, FOmegaTraceQueryCheck Query,
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes,bool TraceComplex,
		const TArray<AActor*>& ActorsToIgnore,EDrawDebugTrace::Type DrawDebugType,FHitResult& OutHit);

	UFUNCTION(BlueprintCallable, Category="Omega",DisplayName="Trace by Query - Sphere",meta=(WorldContext="WorldContextObject",AutoCreateRefTerm="ActorsToIgnore"))
	static bool Query_Sphere(UObject* WorldContextObject,FVector Start,FVector End,float Radius, FOmegaTraceQueryCheck Query,
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes,bool TraceComplex,
		const TArray<AActor*>& ActorsToIgnore,EDrawDebugTrace::Type DrawDebugType,FHitResult& OutHit);

	UFUNCTION(BlueprintCallable, Category="Omega",DisplayName="Trace by Query - Box",meta=(WorldContext="WorldContextObject",AutoCreateRefTerm="ActorsToIgnore"))
	static bool Query_Box(UObject* WorldContextObject,FVector Start,FVector End,FVector HalfSize,FRotator Orientation, FOmegaTraceQueryCheck Query,
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes,bool TraceComplex,
		const TArray<AActor*>& ActorsToIgnore,EDrawDebugTrace::Type DrawDebugType,FHitResult& OutHit);

	
	UFUNCTION(BlueprintCallable, Category="Omega")
	static FHitResult ScriptedTrace_Single(AActor* Instigator, FOmegaScriptedTrace Trace,bool& Success);

	UFUNCTION(BlueprintCallable, Category="Omega")
	static TArray<FHitResult> ScriptedTrace_Multi(AActor* Instigator, FOmegaScriptedTrace Trace,bool& Success);
};


UCLASS(Blueprintable, BlueprintType, EditInlineNew, meta=(ShowWorldContextPin),Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedTraceCommon : public UOmegaScriptedTraceLogic
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace",meta=(EditCondition="!bTraceByObjects"))
	TEnumAsByte<ETraceTypeQuery> TraceChannel = TraceTypeQuery1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	bool bTraceByObjects = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace",meta=(EditCondition="bTraceByObjects"))
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	bool bTraceComplex = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	bool bDebug = false;

};


// ---------------------------------------------------------------------------------------------------------------------
// Trace Types
// ---------------------------------------------------------------------------------------------------------------------

UCLASS(Blueprintable, BlueprintType, EditInlineNew, meta=(ShowWorldContextPin), DisplayName="Line Trace")
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedTrace_Line : public UOmegaScriptedTraceCommon
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	FVector OffsetStart = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	FVector OffsetEnd = FVector(200.f, 0.f, 0.f);



	virtual FHitResult RunTrace_Implementation(AActor* Instigator, bool& Success) override;
	virtual TArray<FHitResult> RunTrace_Multi_Implementation(AActor* Instigator, bool& Success) override;
};

UCLASS(Blueprintable, BlueprintType, EditInlineNew, meta=(ShowWorldContextPin), DisplayName="Sphere Trace")
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedTrace_Sphere : public UOmegaScriptedTraceCommon
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	FVector OffsetStart = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	FVector OffsetEnd = FVector(200.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trace")
	float Radius = 32.f;


	virtual FHitResult RunTrace_Implementation(AActor* Instigator, bool& Success) override;
	virtual TArray<FHitResult> RunTrace_Multi_Implementation(AActor* Instigator, bool& Success) override;
};

UCLASS(Blueprintable, BlueprintType, EditInlineNew, meta=(ShowWorldContextPin), DisplayName="Box Trace")
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedTrace_Box : public UOmegaScriptedTraceCommon
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



	virtual FHitResult RunTrace_Implementation(AActor* Instigator, bool& Success) override;
	virtual TArray<FHitResult> RunTrace_Multi_Implementation(AActor* Instigator, bool& Success) override;
};

UCLASS(Blueprintable, BlueprintType, EditInlineNew, meta=(ShowWorldContextPin), DisplayName="Capsule Trace")
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedTrace_Capsule : public UOmegaScriptedTraceCommon
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

	virtual FHitResult RunTrace_Implementation(AActor* Instigator, bool& Success) override;
	virtual TArray<FHitResult> RunTrace_Multi_Implementation(AActor* Instigator, bool& Success) override;
};
