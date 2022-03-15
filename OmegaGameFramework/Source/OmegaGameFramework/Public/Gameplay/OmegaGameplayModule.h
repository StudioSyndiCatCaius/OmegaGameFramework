// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "OmegaGameMode.h"

#include "OmegaGameplayModule.generated.h"

class UGameInstance;
class UWorld;
class UOmegaSaveGame;

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, EditInlineNew)
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayModule : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	UWorld* WorldPrivate = nullptr;

protected:

	UFUNCTION()
	void Native_OnLevelOpened(FString LevelName, AOmegaGameMode* GameMode);
	
public:

	UOmegaGameplayModule(const FObjectInitializer& ObjectInitializer);
	virtual UWorld* GetWorld() const override;
	
	UFUNCTION()
	void Native_Initialize();
	
	UFUNCTION()
	virtual UGameInstance* GetGameInstance() const;
	
	//Functions
	UFUNCTION(BlueprintImplementableEvent, Category = "GameplayModule")
	void Initialized();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "GameplayModule")
	void Shutdown();

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayModule")
	void GameFileStarted(UOmegaSaveGame* SaveFile);

	UFUNCTION(BlueprintNativeEvent, Category="GameplayModule")
	bool GameFileSaved(UOmegaSaveGame* SaveFile);

	UFUNCTION(BlueprintImplementableEvent, Category="Event")
	void OnGlobalEvent(FName Event, UObject* Instigator);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLevelOpened(const FString& LevelName, AOmegaGameMode* GameMode);

	//Properties
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay")
	TArray<TSubclassOf<AOmegaGameplaySystem>> AutoGameplaySystems;

};
