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

	UFUNCTION(BlueprintPure, Category="Combatant|Gr0oup")
	bool IsGroupFull();
	
	UFUNCTION(BlueprintCallable, Category="Combatant|Group")
	bool SetCombatantInGroup(UCombatantComponent* Combatant, bool InGroup);

	UPROPERTY(BlueprintAssignable)
	FOnCombatantSetInGroup OnCombatantSetInGroup;
	
	UFUNCTION(BlueprintPure, Category="Combatant|Gr0oup")
	TArray<UCombatantComponent*> GetCombatants();

};

 
