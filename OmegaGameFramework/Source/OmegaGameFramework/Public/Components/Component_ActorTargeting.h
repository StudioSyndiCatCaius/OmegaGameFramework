// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Component_ActorTargeting.generated.h"

class UActorModifierScript;
class UOmegaCondition_Actor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorRegisteredUpdate, AActor*, Actor, bool, bRegistered);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorTargetUpdate, AActor*, Actor, bool, bTargeted);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UActorTargetingComponent : public UActorComponent
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleInstanceOnly,Category="Actors") TArray<AActor*> REF_Actors;
	UPROPERTY(VisibleInstanceOnly,Category="Actors") AActor* REF_TargetActor;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	static void L_setTagsOnActor(AActor* Actor, TArray<FName> tags, bool bActive);
	
public:

	UPROPERTY(BlueprintAssignable) FOnActorRegisteredUpdate OnActorRegisteredUpdate;
	UPROPERTY(BlueprintAssignable) FOnActorTargetUpdate OnActorTargetUpdate;

	//Classes that are required to be added to target registry. Blank will allow all classes.
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="ActorTargeting")
	TArray<UActorModifierScript*> ActorMods_OnRegister;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="ActorTargeting")
	TArray<UActorModifierScript*> ActorMods_OnUnregister;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="ActorTargeting")
	TArray<UActorModifierScript*> ActorMods_OnTargeted;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="ActorTargeting")
	TArray<UActorModifierScript*> ActorMods_OnUntargeted;

	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="ActorTargeting")
	TArray<UOmegaCondition_Actor*> Conditions_CanRegister;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="TagEvents")
	FGameplayTagContainer TagEvents_OnRegister;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="TagEvents")
	FGameplayTagContainer TagEvents_OnUnregister;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="TagEvents")
	FGameplayTagContainer TagEvents_OnTargeted;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="TagEvents")
	FGameplayTagContainer TagEvents_OnUntargeted;
	
	//Classes that are required to be added to target registry. Blank will allow all classes.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mouse")
	bool bTargetFromMouseCursor;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mouse")
	int32 Mouse_PlayerIndex;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mouse")
	float Mouse_TraceRadius=20;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mouse")
	TEnumAsByte<ETraceTypeQuery> Mouse_TraceChannel;
    	

	UFUNCTION(BlueprintCallable,Category="ActorTargeting")
	bool SetActorRegistered(AActor* Actor, bool bRegister);

	UFUNCTION(BlueprintCallable,Category="ActorTargeting", DisplayName="Set Actor Registered (List)")
	void SetActorRegistered_List(TArray<AActor*> Actors, bool bRegister, bool bEmptyFirst);

	UFUNCTION(BlueprintCallable,Category="ActorTargeting")
	void ClearRegisteredTargets();

	UFUNCTION(BlueprintCallable,Category="ActorTargeting")
	bool IsActorRegistered(AActor* Actor) const;

	
	UFUNCTION(BlueprintCallable,Category="ActorTargeting")
	TArray<AActor*> GetRegisteredTargets();
	
	UFUNCTION(BlueprintCallable,Category="ActorTargeting")
	void SetActiveTarget(AActor* Actor, bool bAutoRegisterActor);
	
	UFUNCTION(BlueprintPure,Category="ActorTargeting")
	AActor* GetActiveTarget() const;

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