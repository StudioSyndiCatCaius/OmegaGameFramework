// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Gameplay/CombatantComponent.h"
#include "EngineUtils.h"

#include "OmegaGameplaySubsystem.generated.h"

class AOmegaGameplaySystem;
class UOmegaSettings;
class UDamageFormula;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatantRegistered, UCombatantComponent*, Combatant);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatantUnegistered, UCombatantComponent*, Combatant);


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGameplaySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	virtual void Initialize(FSubsystemCollectionBase& Colection) override;

	UFUNCTION(BlueprintCallable, Category = "OmegaGameplaySubsystem", meta=(AdvancedDisplay = "Context, Flag"))
	AOmegaGameplaySystem* ActivateGameplaySystem(class TSubclassOf<AOmegaGameplaySystem> Class, class UObject* Context, FString Flag);

	UFUNCTION(BlueprintCallable, Category = "OmegaGameplaySubsystem", meta = (AdvancedDisplay = "Context, Flag"))
	bool ShutdownGameplaySystem(class TSubclassOf<AOmegaGameplaySystem> Class, FString Flag);

	UFUNCTION(BlueprintPure, Category = "OmegaGameplaySubsystem", meta=(DeterminesOutputType = "Class"))
	class AOmegaGameplaySystem* GetGameplaySystem(class TSubclassOf<AOmegaGameplaySystem> Class, bool& bIsActive);
	
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
	
	UFUNCTION()
	void NativeRemoveSystem(AOmegaGameplaySystem* System);

	UPROPERTY()
	TArray<class AOmegaGameplaySystem*> ActiveSystems;

	UPROPERTY(BlueprintAssignable)
	FOnCombatantRegistered OnCombatantRegistered;
	UPROPERTY(BlueprintAssignable)
    FOnCombatantUnegistered OnCombatantUnegistered;
};
