// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "EngineUtils.h"

#include "OmegaGameplaySubsystem.generated.h"

class AOmegaGameplaySystem;
class UOmegaSettings;
class UDamageFormula;


/**
 * 
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGameplaySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	virtual void Initialize(FSubsystemCollectionBase& Colection) override;

	UFUNCTION(BlueprintCallable, Category = "Ω|Gameplay", meta=(AdvancedDisplay = "Context, Flag"))
	AOmegaGameplaySystem* ActivateGameplaySystem(class TSubclassOf<AOmegaGameplaySystem> Class, class UObject* Context, FString Flag);

	UFUNCTION(BlueprintCallable, Category = "Ω|Gameplay", meta = (AdvancedDisplay = "Context, Flag"))
	bool ShutdownGameplaySystem(class TSubclassOf<AOmegaGameplaySystem> Class, FString Flag);

	UFUNCTION(BlueprintPure, Category = "Ω|Gameplay", meta=(DeterminesOutputType = "Class"))
	class AOmegaGameplaySystem* GetGameplaySystem(class TSubclassOf<AOmegaGameplaySystem> Class, bool& bIsActive);
	
	UFUNCTION()
	void NativeRemoveSystem(AOmegaGameplaySystem* System);

	UPROPERTY()
	TArray<class AOmegaGameplaySystem*> ActiveSystems;
	
};
