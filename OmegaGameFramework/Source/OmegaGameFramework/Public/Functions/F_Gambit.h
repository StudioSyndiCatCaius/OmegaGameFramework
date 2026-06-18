// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/DataAsset.h"
#include "F_Gambit.generated.h"


class UCombatantComponent;
class AActor;



UCLASS(Blueprintable, BlueprintType, EditInlineNew, Const, CollapseCategories,Abstract,meta=(ShowWorldContextPin),DefaultToInstanced)
class OMEGAGAMEFRAMEWORK_API UCombatantGambitObject : public UObject
{
	GENERATED_BODY()
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UCombatantGambit_Evaluator : public UCombatantGambitObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Gambit") float Check(const UCombatantComponent* Combatant) const;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGambit_Task : public UCombatantGambitObject
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintNativeEvent, Category="Gambit") bool Begin(const UCombatantComponent* Combatant) const;
	UFUNCTION(BlueprintNativeEvent, Category="Gambit") bool End(const UCombatantComponent* Combatant) const;
	UFUNCTION(BlueprintNativeEvent, Category="Gambit") bool Tick(const UCombatantComponent* Combatant, float DeltaSeconds) const;
	
};

USTRUCT(BlueprintType)
struct FCombatantGambit
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Gambit") FString Name;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Gambit") TArray<TObjectPtr<UCombatantGambit_Evaluator>> Evaluators;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Gambit") TArray<TObjectPtr<UOmegaGambit_Task>> Tasks;
};


USTRUCT(BlueprintType)
struct FCombatantGambitSet
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Gambit",meta=(ShowOnlyInnerProperties,TitleProperty="{Name}")) 
	TArray<FCombatantGambit> Gambits;
};



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGambit_Asset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Gambit",meta=(ShowOnlyInnerProperties)) FCombatantGambitSet GambitSet;

};



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_Gambit : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


};


/// ------------



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGambit_Task_Gambit : public UOmegaGambit_Task
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Gambit",meta=(ShowOnlyInnerProperties)) FCombatantGambitSet GambitSet;
	
	virtual bool Begin_Implementation(const UCombatantComponent* Combatant) const override;
	virtual bool End_Implementation(const UCombatantComponent* Combatant) const override;
	virtual bool Tick_Implementation(const UCombatantComponent* Combatant, float DeltaSeconds) const override;
	
};