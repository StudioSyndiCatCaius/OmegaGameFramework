// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "InputMappingContext.h"
#include "Widget/HUDLayer.h"
#include "GameplayTagContainer.h"
#include "OmegaAbility.h"
#include "Components/CombatantComponent.h"
#include "Subsystems/OmegaSubsystem_QueueDelay.h"
#include "Subsystems/OmegaSubsystem_Save.h"

#include "OmegaGameplaySystem.generated.h"

class UOmegaGameplaySubsystem;
class UGamePreferenceBool;
class UGamePreferenceFloat;
class AOmegaAbility;
class UOmegaSaveGame;
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


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShutdown, UObject*, Context, FString, Flag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNotify, UObject*, Context, FString, Flag);

UCLASS(config = Game, notplaceable, BlueprintType, Blueprintable, Transient, hideCategories = (Info, Rendering, MovementReplication, Collision, HLOD, WorldPartition), meta = (ShortTooltip = ""))
class OMEGAGAMEFRAMEWORK_API AOmegaGameplaySystem : public AActor, public IOmegaSaveInterface, public IInterface_QueueDelay
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOmegaGameplaySystem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Destroyed() override;
public:	

	UPROPERTY()
	UOmegaGameplaySubsystem* SubsysRef;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//**Start & End***//
	UFUNCTION(BlueprintNativeEvent, DisplayName="On Activated")
		void SystemActivated(class UObject* Context, const FString& Flag);

	//---------------------------------------------------------------------
	// SHUTDOWN
	//---------------------------------------------------------------------
	UFUNCTION(BlueprintNativeEvent, DisplayName="On Finish Shutdown")
		void SystemShutdown(UObject* Context, const FString& Flag);

	UPROPERTY()
	UObject* Shutdown_Context = nullptr;
	UPROPERTY()
	FString Shutdown_Flag;
	
	//Will shut down this gameplay system//
	UFUNCTION(BlueprintCallable, Category = "Omega|GameplaySystem", meta=(AdvancedDisplay="Context, Flag"))
		void Shutdown(UObject* Context, FString Flag);

	UFUNCTION(BlueprintNativeEvent, Category="Omega|GameplaySystem")
	void OnBeginShutdown(UObject* Context, const FString& Flag);

	//WARNING: Do not use this function unless you are overriding the OnBeginShutdown, as it is used to complete the shutdown event. DO NOT CALL OUTSIDE OF THE SYSTEM.
	UFUNCTION(BlueprintCallable, Category = "Omega|GameplaySystem")
	void CompleteShutdown();
	
	//---------------------------------------------------------------------
	// Notify
	//---------------------------------------------------------------------
	UFUNCTION(BlueprintCallable,Category="Omega|GameplaySystem", meta=(AdvancedDisplay="Context"))
	void OutputNotify(UObject* Context, const FString& Flag);

	UPROPERTY(BlueprintAssignable)
	FOnNotify OnSystemNotify;
	//---------------------------------------------------------------------
	// RESTART
	//---------------------------------------------------------------------

	//Shutdown and restart the system
	UFUNCTION(BlueprintCallable, Category="Omega|GameplaySystem", meta=(AdvancedDisplay="Context,Flag"))
	void Restart(UObject* Context, FString Flag);

	UPROPERTY()
	bool local_InRestart;
	
	//-----------------------
	// Gameplay State
	//-----------------------

	UFUNCTION(BlueprintImplementableEvent)
	void OnGameplayStateChange(FGameplayTag NewState);
	
	//Context Object//
	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = "true"), Category = "Omega|GameplaySystem")
	class UObject* ContextObject;
	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = "true"), Category = "Omega|GameplaySystem")
	FString ActivationFlag;
	
	UPROPERTY()
		FString TempFlag;

	UPROPERTY()
	bool bIsInShutdown;
	UPROPERTY(BlueprintAssignable)
	FOnShutdown OnSystemShutdown;

	////////////////////////////////////
	////////////--Tags--/////////////
	////////////////////////////////////
	UPROPERTY(EditDefaultsOnly, Category="GameplayTags")
	FGameplayTagContainer SystemTags;
	//With Shutdown and block any systems from activating that use these tags.
	UPROPERTY(EditDefaultsOnly, Category="GameplayTags")
	FGameplayTagContainer BlockSystemTags;
	UPROPERTY(EditDefaultsOnly, Category="GameplayTags")
	FGameplayTagContainer BlockedOnSystemTags;
	////////////////////////////////////
	////////////--PLAYER--/////////////
	////////////////////////////////////
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	UOmegaInputMode* PlayerInputMode;
	
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	TArray<class TSubclassOf<UHUDLayer>> AddedPlayerWidgets;

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
	TArray<UInputMappingContext*> AddPlayerInputMapping;

	UPROPERTY(EditDefaultsOnly, Category = "Player")
	TArray<FGameplaySystemAbilityRules> GrantedAbilities;

	UFUNCTION()
	void Local_GrantAbilities(UCombatantComponent* Combatant);

	//#####################################################################################################################
	//------FLAGS
	//#####################################################################################################################
	UPROPERTY(EditAnywhere, Category="Default", DisplayName="Flags Active on System")
	TArray<FString> ActiveFlags;
	
	UPROPERTY(EditAnywhere, Category="Default")
	TArray<TSubclassOf<AOmegaGameplaySystem>> SystemsActivatedOnShutdown;
	
	void Local_SetFlagsActive(bool State);
	
	UPROPERTY()
	TArray<class UHUDLayer*> ActivePlayerWidgets;

	////////////////////////////////////
	////////////--Preferences--/////////////
	////////////////////////////////////

	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|GamePreferences")
	void GamePreferenceUpdatedBool(class UGamePreferenceBool* Preference, bool Value);

	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|GamePreferences")
	void GamePreferenceUpdatedFloat(class UGamePreferenceFloat* Preference, float Value);

	////////////////////////////////////
	////////////--Save--/////////////
	////////////////////////////////////
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|GamePreferences")
	bool OnActiveGameSaved();

	UFUNCTION(BlueprintImplementableEvent, Category="Omega Gameplay System")
	void OnGlobalEvent(FName Event, UObject* Context);
	UFUNCTION(BlueprintImplementableEvent, Category="Omega Gameplay System")
	void OnTaggedGlobalEvent(FGameplayTag Event, UObject* Context);
};



