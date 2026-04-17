// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "InputMappingContext.h"
#include "Widget/HUDLayer.h"
#include "GameplayTagContainer.h"
#include "Actor_Ability.h"
#include "OmegaActors.h"
#include "Interfaces/I_StandardInput.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Subsystems/Subsystem_Save.h"

#include "OmegaGameplaySystem.generated.h"

class AOmegaPlayer;
class UGameplayActorComponent;
class UOmegaSubsystem_World;
class UGamePreferenceBool;
class UGamePreferenceFloat;
class AOmegaAbility;
class UOmegaSaveGame;
class UOmegaGameManager;
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


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSubstateChange, UObject*, Context, FString, Flag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNotify, UObject*, Context, FString, Flag);

UCLASS(config = Game, notplaceable, BlueprintType, Blueprintable, Transient, hideCategories = ("Private", Info, Tick, Actor, Rendering, MovementReplication, Replication, LevelInstance, Cooking, Physics, DataLayers, Collision, HLOD, WorldPartition), meta = (ShortTooltip = ""))
class OMEGAGAMEFRAMEWORK_API AOmegaGameplaySystem : public AOmegaActorBASE, public IOmegaSaveInterface, public IDataInterface_InputAction
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AOmegaGameplaySystem();
	
	void Native_Activate(UObject* Context, const FString& Flag);
	virtual void L_CleanupStateChange(bool state);
	virtual TArray<APlayerController*> L_GetPlayers();
protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Destroyed() override;
public:
	
	UPROPERTY() UObject* Shutdown_Context = nullptr;
	UPROPERTY() FString Shutdown_Flag;
	UPROPERTY() bool local_InRestart;
	UPROPERTY() FString TempFlag;
	UPROPERTY() bool bIsInShutdown;
	
	UPROPERTY(BlueprintAssignable) FOnNotify OnSystemNotify;
	UPROPERTY(BlueprintAssignable) FOnSubstateChange OnSystemShutdown;
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
	
	UPROPERTY(EditDefaultsOnly, Category="♎Omega|Misc") bool WidgetsOnPlayerScreen=true;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,Category="♎Omega|Misc") TArray<FName> Substates;
	UPROPERTY() int32 Substate=-1;
	//Tags for this system
	UPROPERTY(EditDefaultsOnly, Category="♎Omega|Tags",meta=(Categories="SYSTEM")) FGameplayTagContainer SystemTags;
	//Will Shutdown and block any systems from activating that use these tags.
	UPROPERTY(EditDefaultsOnly, Category="♎Omega|Tags",meta=(Categories="SYSTEM")) FGameplayTagContainer BlockSystemTags;
	//Will not activate while any systems with these tags are active.
	UPROPERTY(EditDefaultsOnly, Category="♎Omega|Tags",meta=(Categories="SYSTEM")) FGameplayTagContainer BlockedOnSystemTags;
	
	UPROPERTY(EditDefaultsOnly, Category="♎Omega|Tags") FGameplayTagContainer GlobalEvents_OnActivate;
	UPROPERTY(EditDefaultsOnly, Category="♎Omega|Tags") FGameplayTagContainer GlobalEvents_OnShutdown;

	UPROPERTY(EditDefaultsOnly, Category = "♎Omega|Player")
	UOmegaInputMode* PlayerInputMode;
	UPROPERTY(EditDefaultsOnly, Category = "♎Omega|Player")
	TArray<class TSubclassOf<UHUDLayer>> AddedPlayerWidgets;
	UPROPERTY(EditDefaultsOnly, Category = "♎Omega|Player")
	TArray<UInputMappingContext*> AddPlayerInputMapping;
	
	//---------------------------------------------------------------------
	// FUNCTIONS
	//---------------------------------------------------------------------
	UFUNCTION() TArray<FName> L_Substates() const { return Substates; }
	
	UFUNCTION(BlueprintCallable,Category="System State",DisplayName="Set System State (Name)") void SetSubstate_Name(UPARAM(meta=(GetOptions="L_Substates")) FName State);
	UFUNCTION(BlueprintCallable,Category="System State",DisplayName="Set System State (index)") void SetSubstate_Index(int32 State);
	UFUNCTION(BlueprintPure,Category="System State",DisplayName="Get System State (index)") int32 GetSubstate_Index() const { return Substate; };
	UFUNCTION(BlueprintPure,Category="System State",DisplayName="Get System State (Name from index)") FName GetSubstate_NameFromIndex(int32 index) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="System State") void OnSubstateChange(int32 NewState,FName NewState_N,int32 OldState,FName OldState_N);
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//---------------------------------------------------------------------
	// Actors
	//---------------------------------------------------------------------
	UFUNCTION(BlueprintImplementableEvent,Category="Events")
	void OnActor_RegisteredToGroup(AActor* Actor, FGameplayTag Group, bool Registered);
	UFUNCTION(BlueprintImplementableEvent,Category="Events")
	void OnActor_IdentityRegistered(AActor* Actor, UGameplayActorComponent* Component, bool Registered);
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

	UFUNCTION(BlueprintPure,Category="Omega|Systems")
	virtual APawn* GetSystemOwningPlayer_Pawn() const;
	
	UFUNCTION(BlueprintPure,Category="Omega|Systems")
	virtual ACharacter* GetSystemOwningPlayer_Character() const;

	UFUNCTION(BlueprintPure,Category="Omega|Systems")
	virtual UCombatantComponent* GetSystemOwningPlayer_Combatant() const;
	
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
	
	UFUNCTION()
	void Local_GrantAbilities(UCombatantComponent* Combatant);

	//#####################################################################################################################
	//------FLAGS
	//#####################################################################################################################
	
	void Local_SetFlagsActive(bool State);
	
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|GamePreferences")
	bool OnActiveGameSaved();

	UFUNCTION(BlueprintImplementableEvent, Category="Omega Gameplay System")
	void OnGlobalEvent(FName Event, UObject* Context,FOmegaCommonMeta meta);
	UFUNCTION(BlueprintImplementableEvent, Category="Omega Gameplay System")
	void OnTaggedGlobalEvent(FGameplayTag Event, UObject* Context,FOmegaCommonMeta meta);
};

USTRUCT()
struct FOmegaBaseSystemStats
{
	GENERATED_BODY()
	
	UPROPERTY() TArray<AOmegaGameplaySystem*> active_systems;

	TArray<AOmegaGameplaySystem*> GetActiveSystems(bool bIncludeSystemsInShutdown)
	{
		TArray<AOmegaGameplaySystem*> out;
		for(AOmegaGameplaySystem* a : active_systems)
		{
			if(a && !a->IsActorBeingDestroyed() && (!a->bIsInShutdown || bIncludeSystemsInShutdown))
			{
				out.Add(a);
			}
		}
		return out;
	}

	bool IsSystemActive(TSubclassOf<AOmegaGameplaySystem> system)
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
		for(AOmegaGameplaySystem* a : GetActiveSystems(true))
		{
			if(a)
			{
				tags.AppendTags(a->BlockSystemTags);
			}
		}
		return tags;
	}

	bool CanActivateSystem(TSubclassOf<AOmegaGameplaySystem> sys)
	{
		if(sys)
		{
			FGameplayTagContainer tg=GetMutableDefault<AOmegaGameplaySystem>(sys)->SystemTags;
			for(FGameplayTag t : tg.GetGameplayTagArray())
			{
				if(GetBlockedSystemTags().HasTagExact(t))
				{
					//UE_LOG(LogTemp, Log, TEXT("Cannot activate system: %s | Tag %s is Blocked"), *sys->GetName(), *t.ToString());
					return false;
				}
			};
			for(AOmegaGameplaySystem* a : GetActiveSystems(true))
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

	AOmegaGameplaySystem* GetSystem(TSubclassOf<AOmegaGameplaySystem> sys)
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

	AOmegaGameplaySystem* Activate(TSubclassOf<AOmegaGameplaySystem> sys, UObject* Context,const FString& Flag, UObject* WorldC,AActor* owner,FOmegaCommonMeta meta);
	TArray<AOmegaGameplaySystem*> GetActiveSystemsWithTags(FGameplayTagContainer Tags)
	{
		TArray<AOmegaGameplaySystem*> out;
		for(AOmegaGameplaySystem* a : active_systems)
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
		TArray<AOmegaGameplaySystem*> out;
		for(AOmegaGameplaySystem* a : active_systems)
		{
			if(a)
			{
				out.Add(a);
			}
		}
		active_systems=out;
	}
	
	void Shutdown(TSubclassOf<AOmegaGameplaySystem> sys, UObject* Context,const FString& Flag)
	{
		if(AOmegaGameplaySystem* s =GetSystem(sys))
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


