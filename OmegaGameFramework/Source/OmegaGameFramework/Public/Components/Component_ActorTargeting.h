// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Functions/OmegaFunctions_Common.h"
#include "Component_ActorTargeting.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorRegisteredUpdate, AActor*, Actor, bool, bRegistered);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorTargetUpdate, AActor*, Actor, bool, bTargeted);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UActorTargetingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	//UOmegaAOEComponent();

	UPROPERTY() TArray<AActor*> REF_Actors;
	UPROPERTY() AActor* REF_TargetActor;

private:
	// Called when the game starts
	//  void BeginPlay() override;
	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	static void local_setTagsOnActor(AActor* Actor, TArray<FName> tags, bool bActive)
	{
		if(Actor)
		{
			for (FName TempTag : tags)
			{
				UOmegaGameFrameworkBPLibrary::SetActorTagActive(Actor, TempTag,bActive);
			}
		}
	}
	
public:

	UPROPERTY(BlueprintAssignable) FOnActorRegisteredUpdate OnActorRegisteredUpdate;
	UPROPERTY(BlueprintAssignable) FOnActorTargetUpdate OnActorTargetUpdate;

	//Classes that are required to be added to target registry. Blank will allow all classes.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mouse")
	bool bTargetFromMouseCursor;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mouse")
	int32 Mouse_PlayerIndex;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mouse")
	float Mouse_TraceRadius=20;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mouse")
	TEnumAsByte<ETraceTypeQuery> Mouse_TraceChannel;

	//Classes that are required to be added to target registry. Blank will allow all classes.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorTargeting|Classes")
	TArray<TSubclassOf<AActor>> IncludedClasses;

	//Classes that will never be added to the target registry
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorTargeting|Classes")
	TArray<TSubclassOf<AActor>> ExcludedClasses;

	//Gameplay tags that an actor must have to be registered
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorTargeting|GameplayTags")
	FGameplayTagContainer TargetGameplayTagsRequired;
	
	//Gameplay Tags that, if owned, prevent an actor from being registered
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorTargeting|GameplayTags")
	FGameplayTagContainer TargetGameplayTagsBlocked;
    	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorTargeting|TagEvents")
	FGameplayTagContainer EventsOnRegister;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorTargeting|TagEvents")
	FGameplayTagContainer EventsOnUnregister;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorTargeting|TagEvents")
	FGameplayTagContainer EventsOnTarget;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorTargeting|TagEvents")
	FGameplayTagContainer EventsOnUntarget;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorTargeting|ActorTags")
    TArray<FName> TagsOnRegister;
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorTargeting|ActorTags")
    TArray<FName> TagsOnTarget;

	//Tags that are required to be added to target registry. Blank will allow all classes.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorTargeting|ActorTags")
	TArray<FName> IncludedTags;

	//Tags that will never be added to the target registry
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorTargeting|ActorTags")
	TArray<FName> ExcludedTags;

	UFUNCTION(BlueprintCallable,Category="ActorTargeting")
	bool SetActorRegistered(AActor* Actor, bool bRegister);

	UFUNCTION(BlueprintCallable,Category="ActorTargeting", DisplayName="Set Actor Registered (List)")
	void SetActorRegistered_List(TArray<AActor*> Actors, bool bRegister, bool bEmptyFirst);

	UFUNCTION(BlueprintCallable,Category="ActorTargeting")
	void ClearRegisteredTargets();

	UFUNCTION(BlueprintCallable,Category="ActorTargeting")
	TArray<AActor*> GetRegisteredTargets();
	
	UFUNCTION(BlueprintCallable,Category="ActorTargeting")
	void SetActiveTarget(AActor* Actor, bool bAutoRegisterActor);
	
	UFUNCTION(BlueprintPure,Category="ActorTargeting")
	AActor* GetActiveTarget();

	UFUNCTION(BlueprintCallable,Category="ActorTargeting")
	AActor* CycleTarget(int32 CycleAmount);

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorTargeting|Sound") USoundBase* Sound_ChangeTarget;
	
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API AActorTargetingIndicator : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

public:
	// Called every frame
	//virtual void Tick(float DeltaTime) override;


};