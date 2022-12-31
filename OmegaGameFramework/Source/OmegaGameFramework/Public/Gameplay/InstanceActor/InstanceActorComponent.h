// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataInterface_General.h"
#include "OmegaInstanceActor.h"
#include "Components/ActorComponent.h"
#include "Gameplay/GameplayTagsInterface.h"
#include "InstanceActorComponent.generated.h"

// Create several instances of single actor class
UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UInstanceActorComponent : public UActorComponent, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInstanceActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category="Instanced Actor Component")
	TSubclassOf<AOmegaInstanceActor> InstancedActorClass;

	UPROPERTY()
	TArray<AOmegaInstanceActor*> PrivateInstances;
	
	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component", meta=(AdvancedDisplay="LocalTransform"))
	AOmegaInstanceActor* CreateInstance(UObject* Context, const FString& Flag, FTransform LocalTransform);

	UFUNCTION(BlueprintPure, Category="Instanced Actor Component")
	AOmegaInstanceActor* GetInstanceByIndex(int32 Index);
	
	UFUNCTION(BlueprintPure, Category="Instanced Actor Component")
	AOmegaInstanceActor* GetInstanceByContext(UObject* Context);

	UFUNCTION(BlueprintPure, Category="Instanced Actor Component")
	TArray<AOmegaInstanceActor*> GetInstances();
	
	UFUNCTION(BlueprintPure, Category="Instanced Actor Component")
	TArray<AOmegaInstanceActor*> GetInstancesOfCategory(FGameplayTag CategoryTag, bool bExclude, bool bExact);

	UFUNCTION(BlueprintPure, Category="Instanced Actor Component")
	TArray<AOmegaInstanceActor*> GetInstancesWithGameplayTags(FGameplayTagContainer Tags, bool bExclude, bool bExact);

	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component")
	bool SwapInstanceIndecies(int32 A, int32 B);
};
