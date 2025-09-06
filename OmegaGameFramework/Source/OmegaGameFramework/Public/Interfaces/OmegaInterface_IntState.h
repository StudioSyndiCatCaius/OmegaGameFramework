// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Misc/OmegaUtils_Enums.h"
#include "OmegaInterface_IntState.generated.h"


// ===================================================================================================================
// IntState
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UDataInterface_IntState : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_IntState
{
	GENERATED_BODY()

	public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="IntState",DisplayName="Get IntState")
	int32 IntState_Get();

	UFUNCTION(BlueprintNativeEvent, Category="IntState",DisplayName="On IntState Changed")
    void IntState_Set(int32 state);
};

UCLASS()
class UOmegaIntStateFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|IntState",meta=(AdvancedDisplay="bForce"))
	static void SetIntState(UObject* Object, int32 state, bool bForce);
	UFUNCTION(BlueprintPure,Category="Omega|IntState")
	static int32 GetIntState(UObject* Object);
	UFUNCTION(BlueprintCallable,Category="Omega|IntState",meta=(ExpandEnumAsExecs="Result"))
	static int32 CheckIntState(UObject* Object, int32 state, TEnumAsByte<EOmegaComparisonMethodSimple>& Result);
};

inline void UOmegaIntStateFunctions::SetIntState(UObject* Object, int32 state, bool bForce)
{
	if(Object
		&& Object->GetClass()->ImplementsInterface(UDataInterface_IntState::StaticClass())
		&& (IDataInterface_IntState::Execute_IntState_Get(Object)!=state || bForce) )
	{
		IDataInterface_IntState::Execute_IntState_Set(Object,state);
	}
}

inline int32 UOmegaIntStateFunctions::GetIntState(UObject* Object)
{
	if(Object
		&& Object->GetClass()->ImplementsInterface(UDataInterface_IntState::StaticClass()))
	{
		return IDataInterface_IntState::Execute_IntState_Get(Object);
	}
	return 0;
}

inline int32 UOmegaIntStateFunctions::CheckIntState(UObject* Object, int32 state,
                                                    TEnumAsByte<EOmegaComparisonMethodSimple>& Result)
{
	int32 _cur=GetIntState(Object);
	if(_cur<state) {Result=IsLess;}
	if(_cur==state) {Result=IsEqual;}
	if(_cur>state) {Result=IsGreater;}
	return _cur;
}
