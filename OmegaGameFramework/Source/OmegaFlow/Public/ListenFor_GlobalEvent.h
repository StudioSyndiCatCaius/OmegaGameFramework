// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Misc/OmegaUtils_Structs.h"
#include "ListenFor_GlobalEvent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnListenGEvent_Named, FName, Event, UObject*, Context,FOmegaCommonMeta, meta);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnListenGEvent_Tagged, FGameplayTag, Event, UObject*, Context,FOmegaCommonMeta, meta);

UCLASS()
class OMEGAFLOW_API UListenFor_GlobalEventNamed : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable) FOnListenGEvent_Named OnEvent;
	UPROPERTY() const UObject* LocalWorldContext;
	UFUNCTION() void Native_OnEvent(FName Event, UObject* Context,FOmegaCommonMeta _meta);
	
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|ListenFor", meta = (WorldContext = "WorldContextObject"),DisplayName="👂Listen For - Global Event (Named)") 
	static UListenFor_GlobalEventNamed* ListenFor_GlobalEventNamed(const UObject* WorldContextObject);
	
};


UCLASS()
class OMEGAFLOW_API UListenFor_GlobalEventTagged : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable) FOnListenGEvent_Tagged OnEvent;
	UPROPERTY() const UObject* LocalWorldContext;
	UFUNCTION() void Native_OnEvent(FGameplayTag Event, UObject* Context,FOmegaCommonMeta _meta);
	
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|ListenFor", meta = (WorldContext = "WorldContextObject"),DisplayName="👂Listen For - Global Event (Tagged)") 
	static UListenFor_GlobalEventTagged* ListenFor_GlobalEventTagged(const UObject* WorldContextObject);
	
};


