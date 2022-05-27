// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"

#include "InputMappingContext.h"
#include "Widget/HUDLayer.h"
#include "GameplayTagContainer.h"
#include "OmegaAbility.h"
#include "Gameplay/CombatantComponent.h"
#include "Save/OmegaSaveInterface.h"

#include "OmegaGameplaySystem.generated.h"

class UOmegaGameplaySubsystem;
class UGamePreferenceBool;
class UGamePreferenceFloat;
class AOmegaAbility;
class UOmegaSaveGame;


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


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShutdown, FString, Flag);

UCLASS(config = Game, notplaceable, BlueprintType, Blueprintable, Transient, hideCategories = (Info, Rendering, MovementReplication, Actor, Collision), meta = (ShortTooltip = ""))
class OMEGAGAMEFRAMEWORK_API AOmegaGameplaySystem : public AActor, public IOmegaSaveInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOmegaGameplaySystem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY()
	UOmegaGameplaySubsystem* SubsysRef;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//**Start & End***//
	UFUNCTION(BlueprintImplementableEvent)
		void SystemActivated(class UObject* Context, const FString& Flag);

	UFUNCTION(BlueprintImplementableEvent)
		void SystemShutdown(const FString& Flag);

	//Will shut down this gameplay system//
	UFUNCTION(BlueprintCallable, Category = "Ω|Gameplay")
		void Shutdown(FString Flag);

	//Context Object//
	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = "true"), Category = "Ω|Gameplay")
		class UObject* ContextObject;
	UPROPERTY()
		FString TempFlag;

	UPROPERTY(BlueprintAssignable)
	FOnShutdown OnSystemShutdown;

	////////////////////////////////////
	////////////--PLAYER--/////////////
	////////////////////////////////////

	UPROPERTY(EditDefaultsOnly, Category = "Player")
	TArray<class TSubclassOf<UHUDLayer>> AddedPlayerWidgets;
	
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	TArray<UInputMappingContext*> AddPlayerInputMapping;

	UPROPERTY(EditDefaultsOnly, Category = "Player")
	TArray<FGameplaySystemAbilityRules> GrantedAbilities;

	UFUNCTION()
	void Local_GrantAbilities(UCombatantComponent* Combatant);

	
	
	//UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	//TArray<FGameplaySystemAbilityRules> GrantedAbilties;

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
};


