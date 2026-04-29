// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_GlobalScripting.generated.h"


UCLASS(Blueprintable,BlueprintType,Abstract,CollapseCategories,EditInlineNew,DefaultToInstanced,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaGlobalScriptBASE : public UObject
{
	GENERATED_BODY()

public:
	
	FString GetFunctionCall_Name() const;
	FString GetFunctionCall_Description() const;
	
	
	UFUNCTION(BlueprintImplementableEvent) void LuaInterpret(const TArray<FLuaValue>& args);
	UFUNCTION(BlueprintImplementableEvent) void GetEditorDescription(TArray<FString>& param_desc, FString& Override) const;
};

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaGlobalScript : public UOmegaGlobalScriptBASE
{
	GENERATED_BODY()

public:
	UFUNCTION() FLuaValue LuaCall(const TArray<FLuaValue>& args);
	UFUNCTION(BlueprintImplementableEvent) int32 Run(UGameInstance* GameInstance) const;
	
};

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaGlobalCondition : public UOmegaGlobalScriptBASE
{
	GENERATED_BODY()

public:
	UFUNCTION() FLuaValue LuaCall(const TArray<FLuaValue>& args);
	UFUNCTION(BlueprintImplementableEvent) bool Check(UGameInstance* GameInstance) const;
	
};

USTRUCT(BlueprintType)
struct FOmegaGlobalScripts
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Conditions") TArray<UOmegaGlobalScript*> Scripts;
};

USTRUCT(BlueprintType)
struct FOmegaGlobalConditions
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Conditions") TArray<UOmegaGlobalCondition*> Conditions;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_GlobalScripting : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable,Category="Omega|GlobalScripting",meta=(WorldContext="WorldContextObject"))
	static void RunGlobalScripts(UObject* WorldContextObject, FOmegaGlobalScripts scripts);
	
	UFUNCTION(BlueprintCallable,Category="Omega|GlobalScripting",meta=(WorldContext="WorldContextObject"))
	static bool RunGlobalConditions(const UObject* WorldContextObject, FOmegaGlobalConditions scripts);
	
};
