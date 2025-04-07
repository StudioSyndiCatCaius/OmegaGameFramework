// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Component_ActorList.generated.h"




UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UActorListComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY() TArray<AActor*> REF_Actors;

protected:

	
public:
	
};

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UActorListSceneComponent : public USceneComponent
{
	GENERATED_BODY()

	UPROPERTY() TArray<AActor*> REF_Actors;

protected:

	
public:
	//Classes that are required to be added to target registry. Blank will allow all classes.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorRegistry")
	TArray<TSubclassOf<AActor>> IncludedClasses;

	//Classes that will never be added to the target registry
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorRegistry")
	TArray<TSubclassOf<AActor>> ExcludedClasses;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorRegistry")
	FGameplayTagContainer EventsOnRegister;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorRegistry")
	FGameplayTagContainer EventsOnUnregister;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorRegistry|ActorTags")
	TArray<FName> TagsOnRegister;

	//Tags that are required to be added to target registry. Blank will allow all classes.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorRegistry|ActorTags")
	TArray<FName> IncludedTags;

	//Tags that will never be added to the target registry
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorRegistry|ActorTags")
	TArray<FName> ExcludedTags;
};

