// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Types/Struct_Message.h"
#include "ListenFor_Message.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnListenGMessage, UOmegaGameplayMessage*, Message, FGameplayTag, MessageCategory, FOmegaGameplayMessageMeta, meta);


UCLASS()
class OMEGAFLOW_API UListenFor_GameMessage : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable) FOnListenGMessage MessageSent;
	UPROPERTY(BlueprintAssignable) FOnListenGMessage MessageEnd;
	
	UPROPERTY() const UObject* LocalWorldContext;

	UFUNCTION()
	void N_MessageStart(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta Meta);
	UFUNCTION()
	void N_MessageEnd(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta Meta);
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|ListenFor", meta = (WorldContext = "WorldContextObject"),DisplayName="👂Listen For - Message") 
	static UListenFor_GameMessage* ListenFor_GameMessage(const UObject* WorldContextObject);
	
};

