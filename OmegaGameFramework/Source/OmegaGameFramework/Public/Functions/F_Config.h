// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "Dom/JsonObject.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Config.generated.h"

/**
 * 
 */

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_Config : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static bool IsInOmegaDeveloperMode();
	
	UFUNCTION(BlueprintPure, Category="Omega|Config", DisplayName="⚙️Config - Get (Bool)")
	static bool GetBool(const FString& Section, const FString& Param);

	UFUNCTION(BlueprintPure, Category="Omega|Config", DisplayName="⚙️Config - Get (Float)")
	static float GetFloat(const FString& Section, const FString& Param);

	UFUNCTION(BlueprintPure, Category="Omega|Config", DisplayName="⚙️Config - Get (Int32)")
	static int32 GetInt(const FString& Section, const FString& Param);

	UFUNCTION(BlueprintPure, Category="Omega|Config", DisplayName="⚙️Config - Get (String)")
	static FString GetString(const FString& Section, const FString& Param);

	UFUNCTION(BlueprintPure, Category="Omega|Config", DisplayName="⚙️Config - Get (Vector)")
	static FVector GetVector(const FString& Section, const FString& Param);
	
	UFUNCTION(BlueprintPure, Category="Omega|Config", DisplayName="⚙️Config - Get (Vector2D)")
	static FVector2D GetVector2D(const FString& Section, const FString& Param);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Config", DisplayName="⚙️Config - Set (Bool)")
	static void SetBool(const FString& Section, const FString& Param, bool Value);

	UFUNCTION(BlueprintCallable, Category="Omega|Config", DisplayName="⚙️Config - Set (Float)")
	static void SetFloat(const FString& Section, const FString& Param, float Value);

	UFUNCTION(BlueprintCallable, Category="Omega|Config", DisplayName="⚙️Config - Set (Int32)")
	static void SetInt(const FString& Section, const FString& Param, int32 Value);

	UFUNCTION(BlueprintCallable, Category="Omega|Config", DisplayName="⚙️Config - Set (String)")
	static void SetString(const FString& Section, const FString& Param, const FString& Value);

	UFUNCTION(BlueprintCallable, Category="Omega|Config", DisplayName="⚙️Config - Set (Vector)")
	static void SetVector(const FString& Section, const FString& Param, FVector Value);

	UFUNCTION(BlueprintCallable, Category="Omega|Config", DisplayName="⚙️Config - Set (Vector2D)")
	static void SetVector2D(const FString& Section, const FString& Param, FVector2D Value);
	
	
	static FString L_GetConfigPath();
	static FString L_GetPluginConfigPath();
	static void L_EnsureFileExists(const FString& Path);
private:
	
};
