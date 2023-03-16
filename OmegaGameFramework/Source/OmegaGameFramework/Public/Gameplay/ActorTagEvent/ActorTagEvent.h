// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/Interface.h"
#include "ActorTagEvent.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UActorTagEventInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IActorTagEventInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, Category="Event")
	void OnTagEvent(FGameplayTag Event);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UActorTagEventFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public: 
	UFUNCTION(BlueprintCallable, Category="Omega|ActorTagEvent")
	static void FireActorTagEvents(TMap<AActor*, FGameplayTag> Events);
	
};

inline void UActorTagEventFunctions::FireActorTagEvents(TMap<AActor*, FGameplayTag> Events)
{
	TArray<AActor*> TempActorList;
	Events.GetKeys(TempActorList);
	for(AActor* TempActor : TempActorList)
	{
		if(TempActor && TempActor->GetClass()->ImplementsInterface(UActorTagEventInterface::StaticClass()))
		{
			IActorTagEventInterface::Execute_OnTagEvent(TempActor, Events[TempActor]);
			for(UActorComponent* TempComp : TempActor->GetComponents())
			{
				if(TempComp && TempComp->GetClass()->ImplementsInterface(UActorTagEventInterface::StaticClass()))
				{
					IActorTagEventInterface::Execute_OnTagEvent(TempComp, Events[TempActor]);
				}
			}
		}
	}
}
