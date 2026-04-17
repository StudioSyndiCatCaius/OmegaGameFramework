// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Zone.generated.h"


class UOmegaLevelData;
class UOmegaZoneData;
class AOmegaZonePoint;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_Zone : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintPure, Category="Omega|Zone",DisplayName="Zone - Get Level Data",meta=(WorldContext="WorldContextObject"))
    static UOmegaLevelData* Level_GetData(UObject* WorldContextObject, TSoftObjectPtr<UWorld> Level);
	
	UFUNCTION(BlueprintPure, Category="Omega|Zone",DisplayName="Zone - Get Level Data (Current)",meta=(WorldContext="WorldContextObject"))
	static UOmegaLevelData* Level_GetDataCurrent(UObject* WorldContextObject);
	
	UFUNCTION(BlueprintPure, Category="Omega|Zone",DisplayName="Zone - Get Current Loaded",meta=(WorldContext="WorldContextObject"))
	static UOmegaZoneData* Zone_GetCurrentLoaded(UObject* WorldContextObject);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Zone",DisplayName="Zone - Transit (To Point)",meta=(WorldContext="WorldContextObject"))
	static void Transit_ToPoint(UObject* WorldContextObject,AOmegaZonePoint* Point,APlayerController* Player);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Zone",DisplayName="Zone - Transit (To Level)",meta=(WorldContext="WorldContextObject"))
	static void Transit_ToLevel(UObject* WorldContextObject,TSoftObjectPtr<UWorld> Level,FGameplayTag Tag);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Zone",DisplayName="Zone - Transit (To Level NAMED)",meta=(WorldContext="WorldContextObject"))
	static void Transit_ToLevelNamed(UObject* WorldContextObject,FName Level,FGameplayTag Tag);
	
	UFUNCTION(BlueprintPure, Category="Omega|Zone",DisplayName="Zone - Get first point of Zone",meta=(WorldContext="WorldContextObject"))
	static AOmegaZonePoint* Point_GetFirstOfZone(UObject* WorldContextObject,UOmegaZoneData* Zone);
	
	UFUNCTION(BlueprintPure, Category="Omega|Zone",DisplayName="Zone - Is Loading?",meta=(WorldContext="WorldContextObject"))
	static bool IsLoading(UObject* WorldContextObject);
};


