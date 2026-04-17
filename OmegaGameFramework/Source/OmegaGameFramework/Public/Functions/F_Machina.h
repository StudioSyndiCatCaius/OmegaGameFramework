// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Structs.h"

#include "F_Machina.generated.h"


// ===================================================================================================================
// Interaface
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UObjectInterface_Machina : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IObjectInterface_Machina
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, Category="OMEGA|Machina",DisplayName="MACHINA - On State Begin")
	bool Machina_StateBegin(FName State, FOmegaCommonMeta Meta);
	
	UFUNCTION(BlueprintNativeEvent, Category="OMEGA|Machina",DisplayName="MACHINA - On State Tick")
	bool Machina_StateTick(FName State, float Delta);
	
	UFUNCTION(BlueprintNativeEvent, Category="OMEGA|Machina",DisplayName="MACHINA - On State Begin")
	bool Machina_StateEnd(FName State, FOmegaCommonMeta Meta);
};

// ===================================================================================================================
// Function Lib
// ===================================================================================================================

UCLASS()
class UOmegaFunctions_Machina : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Machina",DisplayName="Machina - Can Set State?")
	static bool CanSetState(UObject* Object,FName state);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Machina",DisplayName="Machina - Set State")
	static void SetState(UObject* Object,FName state, FOmegaCommonMeta Meta);

	UFUNCTION(BlueprintCallable,Category="Omega|Machina",DisplayName="Machina - Stop State")
	static void StopState_Current(UObject* Object, FOmegaCommonMeta Meta);
	
	UFUNCTION(BlueprintPure,Category="Omega|Machina",DisplayName="Machina - Get State")
	static FName GetState(UObject* Object);
	
};

// ===================================================================================================================
// Async Task
// ===================================================================================================================

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMachinaOutputDelegate, FOmegaCommonMeta, metaOut);

UCLASS()
class OMEGAGAMEFRAMEWORK_API UMachina_RunState : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable) FMachinaOutputDelegate Finished;
	
	UPROPERTY() UObject* TargetObject;
	UPROPERTY() FName TargetState;
	UPROPERTY() FOmegaCommonMeta TargetMeta;

	UFUNCTION()
	void EventFinish(UObject* _TargetObject, FName _State,FOmegaCommonMeta Meta);
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|ListenFor", meta = (WorldContext = "WorldContextObject")) 
	static UMachina_RunState* RunObjectMachinaState(UObject* Object,FName State, FOmegaCommonMeta meta);
	
};

