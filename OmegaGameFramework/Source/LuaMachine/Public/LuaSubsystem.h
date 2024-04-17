// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "LuaSubsystem.generated.h"

class ULuaSettings;
/**
 * 
 */
UCLASS()
class LUAMACHINE_API ULuaSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY()
	ULuaSettings* settings_ref;
	
public:
	UFUNCTION(BlueprintPure,Category="Lua")
	FString GetLocalFilesPath();
	
	UFUNCTION(BlueprintCallable,Category="Lua")
	FLuaValue RunLocalFile(const FString& file,bool bNonLocal);
	
	UFUNCTION(BlueprintCallable,Category="Lua")
	void RunLocalFilesInPath(const FString& path,bool bRecursive,bool bNonLocal);
};

