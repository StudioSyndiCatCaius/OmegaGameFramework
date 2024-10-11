// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Materials/MaterialExpression.h"
#include "GameplayTags.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OmegaSubsystem_QueuedQuery.generated.h"

UINTERFACE(MinimalAPI)
class UInterface_QueuedQuery : public UInterface { GENERATED_BODY() };

class OMEGAGAMEFRAMEWORK_API IInterface_QueuedQuery
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, Category = "Queued Delay")
	bool GetQueuedQueryValue(FGameplayTag Tag, UObject* Context=nullptr);
	
};



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSubsystem_QueuedQuery : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<UObject*> QuerySources;

public:

	UFUNCTION(BlueprintCallable, Category="Omega|Queued Delay")
	bool CheckQueuedQuery(FGameplayTag Tag, UObject* Context);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Queued Delay")
	bool SetQueuedQuerySourceRegistered(UObject* Source, bool bIsRegistered);
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_QueueQuery : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category="Omega|Queued Delay",meta=(WorldContext="WorldContextObject"))
	static bool CheckQueuedQuery(UObject* WorldContextObject, FGameplayTag Tag, UObject* Context);

};
