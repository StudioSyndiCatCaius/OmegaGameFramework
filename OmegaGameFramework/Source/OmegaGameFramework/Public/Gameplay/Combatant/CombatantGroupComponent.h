// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatantGroupComponent.generated.h"

class UCombatantComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCombatantSetInGroup, UCombatantComponent*, Combatant, bool, InGroup);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UCombatantGroupComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCombatantGroupComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY()
	TArray<UCombatantComponent*> Local_CombatantList;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CombatantGroup")
	FString GroupName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CombatantGroup")
	int32 MaxGroupMembers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CombatantGroup")
	bool ReplaceIfAtMaxCapacity;

	UFUNCTION(BlueprintPure, Category="Omega|Combatant|Gr0oup")
	bool IsGroupFull();

	UFUNCTION(BlueprintPure, Category="Omega|Combatant|Gr0oup")
	UCombatantComponent* GetCombatantOfIndex(int32 Index);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Combatant|Group")
	bool SetCombatantInGroup(UCombatantComponent* Combatant, bool InGroup);

	UPROPERTY(BlueprintAssignable)
	FOnCombatantSetInGroup OnCombatantSetInGroup;
	
	UFUNCTION(BlueprintPure, Category="Omega|Combatant|Gr0oup")
	TArray<UCombatantComponent*> GetCombatants();

	//#############################
	// Linked Primitive
	//#############################

	//Sets a primitive component to automatiacly add an overlapping combatants to this group.
	UFUNCTION(BlueprintCallable, Category="Omega|Combatant|Group")
	void SetPrimitiveComponentRegister(UPrimitiveComponent* Component, bool bActive);

	UPROPERTY()
	UPrimitiveComponent* LinkedPrimitiveComponent;

	void Local_BreakLinkedComp();
	
	void Local_Overlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void Local_OverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};


 
