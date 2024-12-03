// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "OmegaGameMode.h"
#include "Subsystems/OmegaSubsystem_QueuedQuery.h"

#include "OmegaGameplayModule.generated.h"

class UGameInstance;
class UWorld;
class UOmegaSaveGame;

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, EditInlineNew)
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayModule : public UObject, public IInterface_QueuedQuery
{
	GENERATED_BODY()


	UPROPERTY(Transient) UWorld* WorldPrivate = nullptr;
	UPROPERTY() UOmegaGameManager* REF_OwningManager;

	
protected:
	virtual bool GetQueuedQueryValue_Implementation(FGameplayTag Tag, UObject* Context=nullptr) { return true; };
	
	UFUNCTION()
	void Native_OnLevelOpened(FString LevelName, AOmegaGameMode* GameMode);
	
public:
	UOmegaGameplayModule(const FObjectInitializer& ObjectInitializer);
	virtual UWorld* GetWorld() const override;
	UFUNCTION() virtual UGameInstance* GetGameInstance() const;
	
	UFUNCTION()
	void Native_Initialize();
	
	//Functions
	UFUNCTION(BlueprintImplementableEvent, Category = "GameplayModule")
	void Initialized();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "GameplayModule")
	void Shutdown();

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayModule")
	void GameFileStarted(UOmegaSaveGame* SaveFile, FGameplayTagContainer Tags);

	UFUNCTION(BlueprintNativeEvent, Category="GameplayModule")
	bool GameFileSaved(UOmegaSaveGame* SaveFile);

	UFUNCTION(BlueprintImplementableEvent, Category="Event")
	void OnGlobalEvent(FName Event, UObject* Instigator);
	UFUNCTION(BlueprintImplementableEvent, Category="Event")
	void OnTaggedGlobalEvent(FGameplayTag Event, UObject* Instigator);
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnLevelOpened(const FString& LevelName, AOmegaGameMode* GameMode);

	//Properties
	//True = This module will automatically be registered and activated on game start.
	UPROPERTY()
	bool AutoRegisterModule;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay")
	TArray<TSubclassOf<AOmegaGameplaySystem>> AutoGameplaySystems;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay")
	FGameplayTagContainer ModuleTags;

};
