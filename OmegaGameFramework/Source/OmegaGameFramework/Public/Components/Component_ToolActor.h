// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Component_ToolActor.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaTool : public AActor
{
	GENERATED_BODY()

	UPROPERTY() bool is_active;
	virtual void Tick(float DeltaSeconds) override;
	
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite) float TriggerFrequency;

	UPROPERTY() UToolActorComponent* owning_component;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Omega|Tool") void OnSetActive(bool bIsActive);
	UFUNCTION(BlueprintImplementableEvent,Category="Omega|Tool") void OnActivatedTick(float DeltaTime);
	
	UPROPERTY(EditDefaultsOnly,Category="Montages") UAnimMontage* DefaultMontage_Equip;
	UPROPERTY(EditDefaultsOnly,Category="Montages") UAnimMontage* DefaultMontage_Unequip;
	UPROPERTY(EditDefaultsOnly,Category="Montages") UAnimMontage* DefaultMontage_Activate;
	UPROPERTY(EditDefaultsOnly,Category="Montages") UAnimMontage* DefaultMontage_Deactivate;

	UFUNCTION(BlueprintNativeEvent, Category="Omega|Tool") UAnimMontage* GetMontage_Equip();
	UFUNCTION(BlueprintNativeEvent, Category="Omega|Tool") UAnimMontage* GetMontage_Unequip();
	UFUNCTION(BlueprintNativeEvent, Category="Omega|Tool") UAnimMontage* GetMontage_Activate();
	UFUNCTION(BlueprintNativeEvent, Category="Omega|Tool") UAnimMontage* GetMontage_Deactivate();

	
	UFUNCTION(BlueprintCallable,Category="Omega|Tool")
	void SetToolActive(bool bActive);
	UFUNCTION(BlueprintCallable,Category="Omega|Tool")
	bool IsToolActive() const {return is_active;}
	
};

//
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UToolActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UToolActorComponent();

	void local_playToolMontage(UAnimMontage* montage)
	{
		if(montage && GetSkeletaMeshReference())
		{
			GetSkeletaMeshReference()->GetAnimInstance()->Montage_Play(montage);
		}
	}

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY() TArray<TSubclassOf<AOmegaTool>> registered_tools;
	UPROPERTY() AOmegaTool* Current_tool=nullptr;
	UPROPERTY() USkeletalMeshComponent* REF_SkelMesh;

	UFUNCTION()
	USkeletalMeshComponent* GetSkeletaMeshReference();

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	                           
	UFUNCTION(BlueprintCallable,Category="Omega|Tool")
	void SetToolRegistered(TSubclassOf<AOmegaTool> Tool, bool is_registered);

	UFUNCTION(BlueprintCallable,Category="Omega|Tool")
	void SetCurrentToolActive(TSubclassOf<AOmegaTool> Tool, bool bActive);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Tool", DisplayName="Set Tool (by Index)")
	void SetCurrentTool_ByIndex(int32 index);
	UFUNCTION(BlueprintCallable,Category="Omega|Tool", DisplayName="Set Tool (by Class)")
	void SetCurrentTool_ByClass(TSubclassOf<AOmegaTool> Tool);
	UFUNCTION(BlueprintCallable,Category="Omega|Tool")
	void CycleToolIndex(int32 index);

	UFUNCTION(BlueprintPure,Category="Omega|Tool")
	AOmegaTool* GetCurrentTool();
	UFUNCTION(BlueprintPure,Category="Omega|Tool")
	TSubclassOf<AOmegaTool> GetCurrentTool_Class();
	UFUNCTION(BlueprintPure,Category="Omega|Tool")
	int32 GetCurrentTool_Index();
	
};

