// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Components/ActorComponent.h"
#include "UObject/Interface.h"
#include "Tickable.h"
#include "Engine/World.h"
#include "Gameplay/CombatantComponent.h"
#include "JsonObjectWrapper.h"

#include "OmegaGameplaySubsystem.generated.h"

class AOmegaGameplaySystem;
class UOmegaSettings;
class UDamageFormula;
class UCombatantFilter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatantRegistered, UCombatantComponent*, Combatant);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatantUnegistered, UCombatantComponent*, Combatant);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FOnCombatantDamaged, UCombatantComponent*, Combatant, UOmegaAttribute*, Attribute, float, FinalDamage, class UCombatantComponent*, Instigator, UOmegaDamageType*, DamageType, FHitResult, Hit);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameplayStateChange, FGameplayTag, NewState);


UCLASS(DisplayName="Omega Subsystem: Gameplay")
class OMEGAGAMEFRAMEWORK_API UOmegaGameplaySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	virtual void Initialize(FSubsystemCollectionBase& Colection) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="OmegaGameManager|GlobalJson")
	FJsonObjectWrapper WorldJsonObject;
	
	//////////////////
	/// Gameplay Systems
	/////////////////

	UFUNCTION()
	void NativeRemoveSystem(AOmegaGameplaySystem* System);

	UPROPERTY()
	TArray<class AOmegaGameplaySystem*> ActiveSystems;
	
	UFUNCTION(BlueprintCallable, Category = "OmegaGameplaySubsystem", meta=(AdvancedDisplay = "Context, Flag"))
	AOmegaGameplaySystem* ActivateGameplaySystem(class TSubclassOf<AOmegaGameplaySystem> Class, class UObject* Context = nullptr, FString Flag="");

	UFUNCTION(BlueprintCallable, Category = "OmegaGameplaySubsystem", meta = (AdvancedDisplay = "Context, Flag"))
	bool ShutdownGameplaySystem(class TSubclassOf<AOmegaGameplaySystem> Class, UObject* Context = nullptr, FString Flag = "");

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
	/// Gameplay States
	/////////////////

	UPROPERTY(BlueprintAssignable)
	FOnGameplayStateChange OnGameplayStateChange;
	
	UPROPERTY()
	FGameplayTag GameplayState;

	UFUNCTION(BlueprintCallable, Category="OmegaGameplaySubsystem|State")
	void SetGameplayState(FGameplayTag State);
	
	UFUNCTION(BlueprintPure, Category="OmegaGameplaySubsystem|State")
	FGameplayTag GetGameplayState() const
	{
		return GameplayState;	
	};
	
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
	
	UPROPERTY(BlueprintAssignable)
	FOnCombatantDamaged OnCombatantDamaged;
	UFUNCTION()
	void Native_OnDamaged(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, float FinalDamage, class UCombatantComponent* Instigator, UOmegaDamageType* DamageType, FHitResult Hit);

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

	//--------------------------
	// Gameplay Pause
	//--------------------------

	UPROPERTY()
	TArray<UGameplayPauseComponent*> PauseComps;

	//Sets all actors with the pause component and the included category tag to the set pause state. Blank Tags will apply to all.
	UFUNCTION(BlueprintCallable, Category="Pause")
	void SetActorsPaused(FGameplayTagContainer Tags, bool bIsPaused);

};

//------------------------------------------------------------------------------
// GAMEPLAY PAUSE COMPONENT
//------------------------------------------------------------------------------

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UGameplayPauseComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

	UPROPERTY(EditAnywhere, Category="Pause")
	FGameplayTag PauseCategory;

protected:
	UPROPERTY()
	UOmegaGameplaySubsystem* SubsysRef;

	UFUNCTION()
	UOmegaGameplaySubsystem* GetSubsys();
	
public:
	void SetPausedActor(bool Paused)
	{
		if(GetOwner())
		{
			GetOwner()->CustomTimeDilation = !Paused;
		}
	}
	
};