// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Misc/OmegaUtils_Structs.h"
#include "ListenFor_GlobalBinding.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListenGEvent_GlobalBindName, FName, Binding, AActor*, Actor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListenGEvent_GlobalBindTag, FGameplayTag, Binding, AActor*, Actor);


UCLASS()
class OMEGAFLOW_API UListenFor_NameGlobalBinding : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable, Category="Omega") FOnListenGEvent_GlobalBindName OnBound;
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnListenGEvent_GlobalBindName OnUnbound;

	UPROPERTY() const UObject* LocalWorldContext;

	UFUNCTION() void Native_OnBound(FName Event, AActor* Actor);
	UFUNCTION() void Native_OnUnbound(FName Event, AActor* Actor);

	virtual void Activate() override;
	
	UFUNCTION(BlueprintInternalUseOnly, Category="Omega|ListenFor", meta = (WorldContext = "WorldContextObject"),DisplayName="👂Listen For - Global Binding (Named)") 
	static UListenFor_NameGlobalBinding* ListenFor_NameGlobalBinding(const UObject* WorldContextObject);
	
};




UCLASS()
class OMEGAFLOW_API UListenFor_TagGlobalBinding : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable, Category="Omega") FOnListenGEvent_GlobalBindTag OnBound;
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnListenGEvent_GlobalBindTag OnUnbound;

	UPROPERTY() const UObject* LocalWorldContext;

	UFUNCTION() void Native_OnBound(FGameplayTag Event, AActor* Actor);
	UFUNCTION() void Native_OnUnbound(FGameplayTag Event, AActor* Actor);

	virtual void Activate() override;
	
	UFUNCTION(BlueprintInternalUseOnly, Category="Omega|ListenFor", meta = (WorldContext = "WorldContextObject"),DisplayName="👂Listen For - Global Binding (Tagged)") 
	static UListenFor_TagGlobalBinding* ListenFor_TagGlobalBinding(const UObject* WorldContextObject);
	
};


