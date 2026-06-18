// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LuaValue.h"
#include "UObject/Object.h"
#include "Struct_LevelData.generated.h"

USTRUCT(BlueprintType)
struct FOmegaForge_ActorData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorData") FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorData") TSubclassOf<AActor> Class;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorData") FTransform Transform;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorData") FLuaValue TableData;
};

USTRUCT(BlueprintType)
struct FOmegaForge_LevelData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorData") FLuaValue TableData;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LevelData") TArray<FOmegaForge_ActorData> ActorData;
};
