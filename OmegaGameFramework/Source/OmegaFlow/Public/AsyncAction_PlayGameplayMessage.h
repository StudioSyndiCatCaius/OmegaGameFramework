// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Types/Struct_Message.h"
#include "AsyncAction_PlayGameplayMessage.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayGameplayMessage, UOmegaGameplayMessage*, Message);

UCLASS()
class OMEGAFLOW_API UAsyncAction_PlayGameplayMessage : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	/** Fires immediately after the message is sent, outputting the active message object. */
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnPlayGameplayMessage Sent;

	/** Fires when this specific message ends. */
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnPlayGameplayMessage Finished;

	UPROPERTY() const UObject* LocalWorldContext;
	UPROPERTY() UOmegaGameplayMessage* ActiveMessage;

	UPROPERTY() UObject* Param_Instigator;
	UPROPERTY() FText Param_Text;
	UPROPERTY() FGameplayTag Param_CategoryTag;
	UPROPERTY() FOmegaGameplayMessageMeta Param_Meta;

	UFUNCTION()
	void Native_OnMessageEnd(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta Meta);

	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly, WorldContext = "WorldContextObject"), Category="Omega|Message", DisplayName="💬 Play Gameplay Message")
	static UAsyncAction_PlayGameplayMessage* PlayGameplayMessage(
		const UObject* WorldContextObject,
		UObject* Instigator,
		FText Text,
		UPARAM(meta=(Categories="Message")) FGameplayTag CategoryTag,
		FOmegaGameplayMessageMeta meta
	);
};
