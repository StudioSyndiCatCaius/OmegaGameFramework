// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Widget/Menu.h"
#include "AsyncAction_Menu.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnMenuClosed, FGameplayTagContainer, CloseTags, UObject*, CloseContext, FString, CloseFlag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMenuFailed);

UCLASS()
class OMEGAFLOW_API UAsyncAction_Menu : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
	FOnMenuClosed Closed;
	UPROPERTY(BlueprintAssignable)
	FOnMenuFailed Failed;
	
	UPROPERTY()
	APlayerController* PlayerRef;
	UPROPERTY()
	TSubclassOf<UMenu> MenuRef;
	UPROPERTY()
	FString FlagRef;
	UPROPERTY()
	UObject* ContextRef;
	UPROPERTY()
	FGameplayTagContainer TagsRef;

	UFUNCTION()
	void NativeShutdown(FGameplayTagContainer CloseTags, UObject* Context, const FString OutFlag);
	
	virtual void Activate() override;
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true", WorldContext="WorldContextObject", AdvancedDisplay="Player, OpenTags, OpenFlag"), Category="Omega|AsyncGameplayTasks"
		,DisplayName="Ω🔷 Open Menu")
	static UAsyncAction_Menu* OpenMenu(UObject* WorldContextObject, APlayerController* Player, const TSubclassOf<UMenu> MenuClass, UObject* Context, const FGameplayTagContainer OpenTags, const FString& OpenFlag);

	
};
