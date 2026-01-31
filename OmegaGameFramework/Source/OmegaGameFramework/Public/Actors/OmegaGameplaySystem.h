// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "InputMappingContext.h"
#include "Widget/HUDLayer.h"
#include "GameplayTagContainer.h"
#include "Actor_Ability.h"
#include "Subsystems/Subsystem_QueueEvents.h"
#include "Subsystems/Subsystem_Save.h"

#include "OmegaGameplaySystem.generated.h"

class AOmegaPlayer;
class UActorIdentityComponent;
class UOmegaGameplaySubsystem;
class UGamePreferenceBool;
class UGamePreferenceFloat;
class AOmegaAbility;
class UOmegaSaveGame;
class UOmegaGameCore;
class UOmegaInputMode;

USTRUCT(BlueprintType)
struct FGameplaySystemAbilityRules
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, Category="GameplaySystemRules")
	TSubclassOf<AOmegaAbility> AbilityClass;
	
	UPROPERTY(EditDefaultsOnly, Category="GameplaySystemRules")
	FGameplayTagContainer AcceptedFactions;
	//Tags required for this ability to be granted. (Blank will add to all)
	UPROPERTY(EditDefaultsOnly, Category="GameplaySystemRules")
	FGameplayTagQuery AcceptedCombatantTags;
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSystemStateChange, UObject*, Context, FString, Flag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNotify, UObject*, Context, FString, Flag);

UCLASS(config = Game, notplaceable, BlueprintType, Blueprintable, Transient, hideCategories = (Info, Rendering, MovementReplication, Collision, HLOD, WorldPartition), meta = (ShortTooltip = ""))
class OMEGAGAMEFRAMEWORK_API AOmegaBaseSystem : public AActor, public IOmegaSaveInterface, public IInterface_QueueDelay, public IInterface_QueuedQuery
{
	GENERATED_BODY()

	UPROPERTY() UOmegaSaveSubsystem* l_subsys_sav;
	UPROPERTY() UOmegaSubsystem_QueueEvents* l_subsys_qquery;
	
public:	
	// Sets default values for this actor's properties
	AOmegaBaseSystem();
	
	void Native_Activate(UObject* Context, const FString& Flag);
	virtual void L_CleanupStateChange(bool state);
	virtual TArray<APlayerController*> L_GetPlayers();
protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Destroyed() override;
	virtual bool GetQueuedQueryValue_Implementation(FGameplayTag Tag, UObject* Context=nullptr) override { return true; };
public:
	
	UPROPERTY() UObject* Shutdown_Context = nullptr;
	UPROPERTY() FString Shutdown_Flag;
	UPROPERTY() bool local_InRestart;
	UPROPERTY() FString TempFlag;
	UPROPERTY() bool bIsInShutdown;
	
	UPROPERTY(BlueprintAssignable) FOnNotify OnSystemNotify;
	UPROPERTY(BlueprintAssignable) FOnSystemStateChange OnSystemShutdown;
	UPROPERTY() TArray<class UHUDLayer*> ActivePlayerWidgets;
	
	//---------------------------------------------------------------------
	// PROPERTIES
	//---------------------------------------------------------------------

	//Context Object//
	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = "true"), Category = "GameplaySystem")
	class UObject* ContextObject;
	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = "true"), Category = "GameplaySystem")
	FString ActivationFlag;
	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = "true"), Category = "GameplaySystem")
	FOmegaCommonMeta SystemMeta;
	
	UPROPERTY(EditDefaultsOnly, Category="Omega - Flags") bool WidgetsOnPlayerScreen=true;
	//Tags for this system
	UPROPERTY(EditDefaultsOnly, Category="Omega - Tags") FGameplayTagContainer SystemTags;
	//Will Shutdown and block any systems from activating that use these tags.
	UPROPERTY(EditDefaultsOnly, Category="Omega - Tags") FGameplayTagContainer BlockSystemTags;
	//Will not activate while any systems with these tags are active.
	UPROPERTY(EditDefaultsOnly, Category="Omega - Tags") FGameplayTagContainer BlockedOnSystemTags;
	
	UPROPERTY(EditDefaultsOnly, Category="Omega - Tags") FGameplayTagContainer GlobalEvents_OnActivate;
	UPROPERTY(EditDefaultsOnly, Category="Omega - Tags") FGameplayTagContainer GlobalEvents_OnShutdown;

	UPROPERTY(EditDefaultsOnly, Category = "Omega - Player")
	UOmegaInputMode* PlayerInputMode;
	UPROPERTY(EditDefaultsOnly, Category = "Omega - Player")
	TArray<class TSubclassOf<UHUDLayer>> AddedPlayerWidgets;
	UPROPERTY(EditDefaultsOnly, Category = "Omega - Player")
	TArray<UInputMappingContext*> AddPlayerInputMapping;

	UPROPERTY(EditAnywhere, Category="Omega - Misc", DisplayName="Flags Active on System")
	TArray<FString> ActiveFlags;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="Omega - Misc")
	FOmegaEntitySet Entities;
	
	UPROPERTY(EditAnywhere, Category="Omega - Misc")
	TArray<TSubclassOf<AOmegaGameplaySystem>> SystemsActivatedOnShutdown;
	//---------------------------------------------------------------------
	// FUNCTIONS
	//---------------------------------------------------------------------
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//---------------------------------------------------------------------
	// Actors
	//---------------------------------------------------------------------
	UFUNCTION(BlueprintImplementableEvent,Category="Events")
	void OnActor_RegisteredToGroup(AActor* Actor, FGameplayTag Group, bool Registered);
	UFUNCTION(BlueprintImplementableEvent,Category="Events")
	void OnActor_IdentityRegistered(AActor* Actor, UActorIdentityComponent* Component, bool Registered);
	UFUNCTION(BlueprintImplementableEvent,Category="Events")
	void OnActor_TagEvent(AActor* Actor, FGameplayTag Event);
	UFUNCTION(BlueprintImplementableEvent,Category="Events")
	void OnActor_Interaction(AActor* InteractInstigator, AActor* Target, FGameplayTag Tag, FOmegaCommonMeta Context);
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnGameplayMessage(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta Meta);
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnGameplayStateChange(FGameplayTag NewState);

	UFUNCTION(BlueprintImplementableEvent,Category="Save")
	void OnNewGameStarted(UOmegaSaveGame* NewSave, FGameplayTagContainer GameplayTags);
	
	
	UFUNCTION(BlueprintNativeEvent, DisplayName="On Activated")
	void SystemActivated(class UObject* Context, const FString& Flag);
	
	UFUNCTION(BlueprintNativeEvent, DisplayName="On Finish Shutdown")
	void SystemShutdown(UObject* Context, const FString& Flag);
	
	//Will shut down this gameplay system//
	UFUNCTION(BlueprintCallable, Category = "Omega|GameplaySystem", meta=(AdvancedDisplay="Context, Flag"))
	void Shutdown(UObject* Context, FString Flag);

	UFUNCTION(BlueprintNativeEvent, Category="Omega|GameplaySystem")
	void OnBeginShutdown(UObject* Context, const FString& Flag);

	//WARNING: Do not use this function unless you are overriding the OnBeginShutdown, as it is used to complete the shutdown event. DO NOT CALL OUTSIDE OF THE SYSTEM.
	UFUNCTION(BlueprintCallable, Category = "Omega|GameplaySystem")
	void CompleteShutdown();
	
	UFUNCTION(BlueprintCallable,Category="Omega|GameplaySystem", meta=(AdvancedDisplay="Context"))
	void OutputNotify(UObject* Context, const FString& Flag);

	//Shutdown and restart the system
	UFUNCTION(BlueprintCallable, Category="Omega|GameplaySystem", meta=(AdvancedDisplay="Context,Flag"))
	void Restart(UObject* Context, FString Flag);
	
	UFUNCTION(BlueprintPure,Category="Omega|Systems")
	virtual AOmegaPlayer* GetSystemOwningPlayer() const;

private:
	void local_globalEventTags(FGameplayTagContainer tags);
	
public:
	

	UFUNCTION(BlueprintImplementableEvent, Category="HUD") 
	TArray<class TSubclassOf<UHUDLayer>> GetAddedHudLayers() const;
private:
	TArray<TSubclassOf<UHUDLayer>> local_GetAllHudClasses() const
	{
		TArray<TSubclassOf<UHUDLayer>> temp_hudlayers = AddedPlayerWidgets;
		temp_hudlayers.Append(GetAddedHudLayers());
		return temp_hudlayers;
	}
public:
	


	UPROPERTY(EditDefaultsOnly, Category = "Player")
	TArray<FGameplaySystemAbilityRules> GrantedAbilities;

	UFUNCTION()
	void Local_GrantAbilities(UCombatantComponent* Combatant);

	//#####################################################################################################################
	//------FLAGS
	//#####################################################################################################################
	
	void Local_SetFlagsActive(bool State);
	
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|GamePreferences")
	bool OnActiveGameSaved();

	UFUNCTION(BlueprintImplementableEvent, Category="Omega Gameplay System")
	void OnGlobalEvent(FName Event, UObject* Context);
	UFUNCTION(BlueprintImplementableEvent, Category="Omega Gameplay System")
	void OnTaggedGlobalEvent(FGameplayTag Event, UObject* Context);
};

USTRUCT()
struct FOmegaBaseSystemStats
{
	GENERATED_BODY()
	
	UPROPERTY() TArray<AOmegaBaseSystem*> active_systems;

	TArray<AOmegaBaseSystem*> GetActiveSystems(bool bIncludeSystemsInShutdown)
	{
		TArray<AOmegaBaseSystem*> out;
		for(AOmegaBaseSystem* a : active_systems)
		{
			if(a && !a->IsActorBeingDestroyed() && (!a->bIsInShutdown || bIncludeSystemsInShutdown))
			{
				out.Add(a);
			}
		}
		return out;
	}

	bool IsSystemActive(TSubclassOf<AOmegaBaseSystem> system)
	{
		if(system)
		{
			for(auto* a : GetActiveSystems(true))
			{
				if(a && a->GetClass()==system)
				{
					return true;
				}
			}
		}
		return false;
	}

	FGameplayTagContainer GetBlockedSystemTags()
	{
		FGameplayTagContainer tags;
		for(AOmegaBaseSystem* a : GetActiveSystems(true))
		{
			if(a)
			{
				tags.AppendTags(a->BlockSystemTags);
			}
		}
		return tags;
	}

	bool CanActivateSystem(TSubclassOf<AOmegaBaseSystem> sys)
	{
		if(sys)
		{
			FGameplayTagContainer tg=GetMutableDefault<AOmegaBaseSystem>(sys)->SystemTags;
			for(FGameplayTag t : tg.GetGameplayTagArray())
			{
				if(GetBlockedSystemTags().HasTagExact(t))
				{
					//UE_LOG(LogTemp, Log, TEXT("Cannot activate system: %s | Tag %s is Blocked"), *sys->GetName(), *t.ToString());
					return false;
				}
			};
			for(AOmegaBaseSystem* a : GetActiveSystems(true))
			{
				if(a && a->GetClass()==sys)
				{
					//UE_LOG(LogTemp, Log, TEXT("Cannot activate system: %s | System is already active"), *sys->GetName());
					return false;
				}
			}
		}
		return true;
	}

	void ShutdownAll(UObject* Context, const FString& Flag)
	{
		for(auto* a : active_systems)
		{
			if(a)
			{
				a->Shutdown(Context,Flag);
			}
		}
	}

	AOmegaBaseSystem* GetSystem(TSubclassOf<AOmegaBaseSystem> sys)
	{
		for(auto* a : GetActiveSystems(false))
		{
			if(a && a->GetClass()==sys)
			{
				return a;
			}
		}
		return nullptr;
	}

	AOmegaBaseSystem* Activate(TSubclassOf<AOmegaBaseSystem> sys, UObject* Context,const FString& Flag, UObject* WorldC,AActor* owner,FOmegaCommonMeta meta)
	{
		if(!WorldC || !sys)
		{
			//UE_LOG(LogTemp, Log, TEXT("Failed to active system: World or SystemClass invalid"));
			return nullptr;
		}
		if(CanActivateSystem(sys))
		{
			FTransform SpawnWorldPoint;
			if(owner)
			{
				SpawnWorldPoint=owner->GetActorTransform();
			}
			
			AOmegaBaseSystem* DummySystem = WorldC->GetWorld()->SpawnActorDeferred<AOmegaBaseSystem>(sys, SpawnWorldPoint, owner);
			if(!DummySystem)
			{
				UE_LOG(LogTemp, Log, TEXT("Failed to Spawn system Actor: %s "), *sys->GetName());
				return nullptr;
			}
			DummySystem->FinishSpawning(SpawnWorldPoint);
			active_systems.Add(DummySystem);
			if(Context)
			{
				DummySystem->ContextObject = Context;
			}
			DummySystem->ActivationFlag=Flag;
			DummySystem->SystemMeta=meta;
			Validate();
			DummySystem->Native_Activate(Context, Flag);
			UE_LOG(LogTemp, Log, TEXT("System %s - Successfully Activated "), *DummySystem->GetName());
			return DummySystem;
		}
		return nullptr;
	}

	TArray<AOmegaBaseSystem*> GetActiveSystemsWithTags(FGameplayTagContainer Tags)
	{
		TArray<AOmegaBaseSystem*> out;
		for(AOmegaBaseSystem* a : active_systems)
		{
			if(a && a->SystemTags.HasAnyExact(Tags))
			{
				out.Add(a);
			}
		}
		return out;
	}

	void Validate()
	{
		//Shutdown Blocked Systems
		for(auto* TempSys : GetActiveSystemsWithTags(GetBlockedSystemTags()))
		{
			TempSys->Shutdown(nullptr, "Canceled");
		}
		//remove null list entires
		TArray<AOmegaBaseSystem*> out;
		for(AOmegaBaseSystem* a : active_systems)
		{
			if(a)
			{
				out.Add(a);
			}
		}
		active_systems=out;
	}
	
	void Shutdown(TSubclassOf<AOmegaBaseSystem> sys, UObject* Context,const FString& Flag)
	{
		if(AOmegaBaseSystem* s =GetSystem(sys))
		{
			active_systems.Remove(s);
			s->Shutdown(Context,Flag);
			UE_LOG(LogTemp, Log, TEXT("System %s - Successfully Shutdown "), *sys->GetName());
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Failed to Shutdown system: %s -- Does not exist"), *sys->GetName());
		}
	}
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaGameplaySystem : public AOmegaBaseSystem
{
	GENERATED_BODY()
	
	virtual void L_CleanupStateChange(bool state) override;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaPlayerSystem : public AOmegaBaseSystem
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	AOmegaPlayerSystem();
	virtual TArray<APlayerController*> L_GetPlayers() override;
	virtual void L_CleanupStateChange(bool state) override;

	virtual AOmegaPlayer* GetSystemOwningPlayer() const override;
};