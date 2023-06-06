// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/Interface.h"
#include "Animation/AnimNotifies/AnimNotify.h"
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

	UFUNCTION(BlueprintCallable, Category="Omega|ActorTagEvent")
	static void FireTagEventOnActors(TArray<AActor*> Actors, FGameplayTag Event);

	UFUNCTION(BlueprintCallable, Category="Omega|ActorTagEvent")
	static void FireTagEventOnActor(AActor* Actor, FGameplayTag Event);

	UFUNCTION(BlueprintCallable, Category="Omega|ActorTagEvent")
	static void FireTagEventsOnActors(TArray<AActor*> Actors, FGameplayTagContainer Events);

	UFUNCTION(BlueprintCallable, Category="Omega|ActorTagEvent")
	static void FireTagEventsOnActor(AActor* Actor, FGameplayTagContainer Events);
	
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API ATagEventDisperser : public AActor, public IActorTagEventInterface
{
	GENERATED_BODY()

public:

	ATagEventDisperser();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Actors")
	TArray<AActor*> TargetActors;
	
	virtual void OnTagEvent_Implementation(FGameplayTag Event) override;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UAnimNotify_TagEvent : public UAnimNotify
{
	GENERATED_BODY()

public:

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

	UPROPERTY(EditAnywhere, Category="Events")
	FGameplayTagContainer Events;
	
};