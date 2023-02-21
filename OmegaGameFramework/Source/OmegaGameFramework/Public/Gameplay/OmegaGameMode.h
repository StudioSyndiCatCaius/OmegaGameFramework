// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OmegaGameplaySystem.h"

#include "OmegaGameMode.generated.h"

/**
 * 
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:

	UFUNCTION()
	void Local_LoadSystemShutdown(UObject* Context, FString Flag);
	
public:
	
	UPROPERTY(EditDefaultsOnly, Category="Gameplay Systems", DisplayName="Pre-Load Gameplay Systems")
	TArray<TSubclassOf<AOmegaGameplaySystem>> AutoGameplaySystems;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay Systems", DisplayName="Load Gameplay System")
	TSubclassOf<AOmegaGameplaySystem> LoadGameplaySystem;

	UFUNCTION(BlueprintImplementableEvent, Category="Omega Game Mode")
	void OnLoadEventFinished();
	
	UPROPERTY(EditDefaultsOnly, Category="Gameplay Systems", DisplayName="Post-Load Gameplay Systems")
	TArray<TSubclassOf<AOmegaGameplaySystem>> PostLoadGameplaySystems;
	
	protected:
	virtual void BeginPlay() override;
};
