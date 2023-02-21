// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Components/ActorComponent.h"
#include "UObject/Interface.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Gameplay/CombatantComponent.h"
#include "EngineUtils.h"

#include "OmegaGameplaySubsystem.generated.h"

class AOmegaGameplaySystem;
class UOmegaSettings;
class UDamageFormula;
class UCombatantFilter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatantRegistered, UCombatantComponent*, Combatant);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatantUnegistered, UCombatantComponent*, Combatant);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGameplayStateChange, FGameplayTag, StateTag, bool, bNewState);

UCLASS(DisplayName="Omega Subsystem: Gameplay")
class OMEGAGAMEFRAMEWORK_API UOmegaGameplaySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	virtual void Initialize(FSubsystemCollectionBase& Colection) override;

	//////////////////
	/// Gameplay Systems
	/////////////////

	UFUNCTION()
	void NativeRemoveSystem(AOmegaGameplaySystem* System);

	UPROPERTY()
	TArray<class AOmegaGameplaySystem*> ActiveSystems;
	
	UFUNCTION(BlueprintCallable, Category = "OmegaGameplaySubsystem", meta=(AdvancedDisplay = "Context, Flag"))
	AOmegaGameplaySystem* ActivateGameplaySystem(class TSubclassOf<AOmegaGameplaySystem> Class, class UObject* Context, FString Flag);

	UFUNCTION(BlueprintCallable, Category = "OmegaGameplaySubsystem", meta = (AdvancedDisplay = "Context, Flag"))
	bool ShutdownGameplaySystem(class TSubclassOf<AOmegaGameplaySystem> Class, UObject* Context, FString Flag);

	UFUNCTION(BlueprintPure, Category = "OmegaGameplaySubsystem", meta=(DeterminesOutputType = "Class"))
	class AOmegaGameplaySystem* GetGameplaySystem(class TSubclassOf<AOmegaGameplaySystem> Class, bool& bIsActive);

	UFUNCTION(BlueprintPure, Category = "OmegaGameplaySubsystem")
	TArray<AOmegaGameplaySystem*> GetActiveGameplaySystems();

	UFUNCTION(BlueprintPure, Category = "OmegaGameplaySubsystem")
	TArray<AOmegaGameplaySystem*> GetActiveGameplaySystemsWithInterface(TSubclassOf<UInterface> Interface);

	UFUNCTION(BlueprintPure, Category = "OmegaGameplaySubsystem")
	bool IsSystemTagBlocked(FGameplayTagContainer Tags);
	
	UFUNCTION(BlueprintPure, Category = "OmegaGameplaySubsystem")
	bool IsSystemTagActive(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintPure, Category = "OmegaGameplaySubsystem")
	TArray<AOmegaGameplaySystem*> GetActiveSystemsWithTags(FGameplayTagContainer Tags);
	
	//PLAYER
	
	UFUNCTION(BlueprintPure, Category = "OmegaGameplaySubsystem")
	APlayerController* GetPlayerController(int32 Index);
	
	//////////////////
	/// Combatants
	/////////////////

	UFUNCTION()
	void Native_RegisterCombatant(UCombatantComponent* Combatant, bool bRegistered);
	
	UPROPERTY()
	TArray<UCombatantComponent*> ActiveCombatants;

	UFUNCTION(BlueprintPure, Category="Combat")
	TArray<UCombatantComponent*> GetAllCombatants();
	
	UPROPERTY(BlueprintAssignable)
	FOnCombatantRegistered OnCombatantRegistered;
	UPROPERTY(BlueprintAssignable)
    FOnCombatantUnegistered OnCombatantUnegistered;

	UFUNCTION(BlueprintCallable, Category="OmegaGameplaySubsystem")
	TArray<UCombatantComponent*> RunCustomCombatantFilter(TSubclassOf<UCombatantFilter> FilterClass, UCombatantComponent* Instigator, const TArray<UCombatantComponent*>& Combatants);

	////////////////////////////////////
	////////////--Actor Binding--/////////////
	////////////////////////////////////

	UPROPERTY()
	TMap<FName, AActor*> GlobalActorBindingRefs;
	
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay Subsystem|Actors")
	void SetGlobalActorBinding(FName Binding, AActor* Actor);
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay Subsystem|Actors")
	void ClearGlobalActorBinding(FName Binding);
	UFUNCTION(BlueprintPure, Category="Omega Gameplay Subsystem|Actors")
	AActor* GetGlobalActorBinding(FName Binding);

	//##################################################################################
	/// Gameplay State
	//##################################################################################

private:

	UPROPERTY()
	TArray<UObject*> GameplayStateObjects;
	
	UFUNCTION()
	TArray<UObject*> GetValidGameplayStateObjects();

public:
	
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay Subsystem|Gameplay State")
	void RegisterGameplayStateSource(UObject* Object, bool bRegistered);

	UFUNCTION(BlueprintPure, Category="Omega Gameplay Subsystem|Gameplay State")
	bool IsGameplayStateActive(FGameplayTag StateTag);


};


//##################################################################################
/// Gameplay State INTERFACE
//##################################################################################

UINTERFACE(MinimalAPI)
class UOmegaGameplayStateInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IOmegaGameplayStateInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayState")
	FGameplayTag GetGameplayStateTag();

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayState")
	bool IsGameplayStateTagActive();
};
