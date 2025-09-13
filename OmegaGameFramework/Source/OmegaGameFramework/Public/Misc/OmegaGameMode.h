// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Actors/OmegaGameplaySystem.h"

#include "OmegaGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOmegaGameModeDelegate);

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:

	UFUNCTION()
	void Local_LoadSystemShutdown(UObject* Context, FString Flag);
	
public:
	AOmegaGameMode();

	UPROPERTY(BlueprintAssignable) FOmegaGameModeDelegate OnLoadEventFinish;
	
	UPROPERTY(EditDefaultsOnly, Category="OMEGA - Systems", DisplayName="Pre-Load Gameplay Systems")
	TArray<TSubclassOf <AOmegaGameplaySystem>> AutoGameplaySystems;

	UPROPERTY(EditDefaultsOnly, Category="OMEGA - Systems", DisplayName="Load Gameplay System")
	TSubclassOf <AOmegaGameplaySystem> LoadGameplaySystem;

	UFUNCTION(BlueprintImplementableEvent, Category="Omega Game Mode")
	void OnLoadEventFinished();
	
	UPROPERTY(EditDefaultsOnly, Category="OMEGA - Systems", DisplayName="Post-Load Gameplay Systems")
	TArray<TSubclassOf <AOmegaGameplaySystem>> PostLoadGameplaySystems;

	UPROPERTY(EditDefaultsOnly, Category="OMEGA - Systems")
	TArray<TSubclassOf <AOmegaGameplaySystem>> PersistentGameplaySystems;
	UPROPERTY(EditDefaultsOnly, Category="OMEGA - Systems")
	float PersistentSystemActivationFrequency=0.4;

	UPROPERTY(EditDefaultsOnly, Category="OMEGA - Systems")
	FGameplayTagContainer AutoBlockSystemTags;

	UPROPERTY(EditDefaultsOnly, Category="OMEGA - Player")
	TArray<TSubclassOf <AOmegaPlayerSystem>> PlayerSystems_Auto;
	UPROPERTY(EditDefaultsOnly, Category="OMEGA - Player")
	TArray<TSubclassOf <AOmegaPlayerSystem>> PlayerSystems_Persistent;
	
private:
	UFUNCTION()
	void Local_ActivatePersistentSystems();
private:
	FTimerHandle PersistentSystemsTimerHandle;
	
	protected:
	virtual void BeginPlay() override;
	virtual FString InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal) override;

};
