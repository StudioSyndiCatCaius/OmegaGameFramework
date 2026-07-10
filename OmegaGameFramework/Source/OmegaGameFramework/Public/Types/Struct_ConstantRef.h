// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Struct_ConstantRef.generated.h"

USTRUCT(BlueprintType)
struct FOmegaGlobalConst_Byte
{
	GENERATED_BODY()

	TArray<FName> L_GetVals() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Const", meta=(InlineEditConditionToggle))
	bool UseConstant = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Const", meta=(EditCondition="UseConstant", GetValueOptions="L_GetVals"))
	FName Constant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Const", meta=(EditCondition="!UseConstant"))
	uint8 Value = 0;

	uint8 GetValue() const;
};

USTRUCT(BlueprintType)
struct FOmegaGlobalConst_Float
{
	GENERATED_BODY()

	TArray<FName> L_GetVals() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Const", meta=(InlineEditConditionToggle))
	bool UseConstant = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Const", meta=(EditCondition="UseConstant", GetValueOptions="L_GetVals"))
	FName Constant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Const", meta=(EditCondition="!UseConstant"))
	float Value = 0.f;

	float GetValue() const;
};

USTRUCT(BlueprintType)
struct FOmegaGlobalConst_Int32
{
	GENERATED_BODY()

	TArray<FName> L_GetVals() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Const", meta=(InlineEditConditionToggle))
	bool UseConstant = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Const", meta=(EditCondition="UseConstant", GetValueOptions="L_GetVals"))
	FName Constant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Const", meta=(EditCondition="!UseConstant"))
	int32 Value = 0;

	int32 GetValue() const;
};

USTRUCT(BlueprintType)
struct FOmegaGlobalConst_String
{
	GENERATED_BODY()

	TArray<FName> L_GetVals() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Const", meta=(InlineEditConditionToggle))
	bool UseConstant = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Const", meta=(EditCondition="UseConstant", GetValueOptions="L_GetVals"))
	FName Constant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Const", meta=(EditCondition="!UseConstant"))
	FString Value;

	FString GetValue() const;
};

USTRUCT(BlueprintType)
struct FOmegaGlobalConst_Text
{
	GENERATED_BODY()

	TArray<FName> L_GetVals() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Const", meta=(InlineEditConditionToggle))
	bool UseConstant = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Const", meta=(EditCondition="UseConstant", GetValueOptions="L_GetVals"))
	FName Constant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Const", meta=(EditCondition="!UseConstant"))
	FText Value;

	FText GetValue() const;
};

USTRUCT(BlueprintType)
struct FOmegaGlobalConst_DataAsset
{
	GENERATED_BODY()

	TArray<FName> L_GetVals() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Const", meta=(InlineEditConditionToggle))
	bool UseConstant = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Const", meta=(EditCondition="UseConstant", GetValueOptions="L_GetVals"))
	FName Constant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Const", meta=(EditCondition="!UseConstant"))
	TObjectPtr<UPrimaryDataAsset> Value = nullptr;

	UPrimaryDataAsset* GetValue() const;
};
