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
	
	
	UFUNCTION(BlueprintImplementableEvent, Category="Omega") void LuaInterpret(const TArray<FLuaValue>& args);
	UFUNCTION(BlueprintImplementableEvent, Category="Omega") void GetEditorDescription(TArray<FString>& param_desc, FString& Override) const;
};

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaGlobalScript : public UOmegaGlobalScriptBASE
{
	GENERATED_BODY()

public:
	UFUNCTION() FLuaValue LuaCall(const TArray<FLuaValue>& args);
	UFUNCTION(BlueprintNativeEvent, Category="Omega") int32 Run(UGameInstance* GameInstance) const;
	
};

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaGlobalCondition : public UOmegaGlobalScriptBASE
{
	GENERATED_BODY()

public:
	UFUNCTION() FLuaValue LuaCall(const TArray<FLuaValue>& args);
	UFUNCTION(BlueprintNativeEvent, Category="Omega") bool Check(UGameInstance* GameInstance) const;
	
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

// ---------------------------------------------------------------------------------------------------------------------
// Iterations
// ---------------------------------------------------------------------------------------------------------------------

UCLASS()
class UOmegaGlobalScriptsPreset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="GlobalScripting",meta=(ShowOnlyInnerProperties))
	FOmegaGlobalScripts Scripts;
	
};

UCLASS(DisplayName="* DO PRESET")
class UOmegaGlobalScript_DoPreset : public UOmegaGlobalScript
{
	GENERATED_BODY()

public:
	virtual int32 Run_Implementation(UGameInstance* GameInstance) const override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="GlobalScripting")
	TArray<UOmegaGlobalScriptsPreset*> Presets;
	
};


UCLASS()
class UOmegaGlobalConditionsPreset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="GlobalScripting",meta=(ShowOnlyInnerProperties))
	FOmegaGlobalConditions Conditions;
	
};

UCLASS(DisplayName="* CHECK PRESET")
class UOmegaGlobalCondition_DoPreset : public UOmegaGlobalCondition
{
	GENERATED_BODY()

public:
	virtual bool Check_Implementation(UGameInstance* GameInstance) const override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="GlobalScripting")
	TArray<UOmegaGlobalConditionsPreset*> Presets;
	
};