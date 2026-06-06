// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OmegaGameManager.h"
#include "GameFramework/GameModeBase.h"
#include "Actors/OmegaGameplaySystem.h"
#include "GameFramework/HUD.h"

#include "OmegaGameMode.generated.h"

class UInstanceActorComponent;
class AOmegaDynamicCamera;
class UAssetSquadComponent;
class UCombatantComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOmegaGameModeDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOmegaGameModeActorListDelegate, const TArray<AActor*>&, Actors);


UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	
	UFUNCTION()
	void Local_LoadSystemShutdown(UObject* Context, FString Flag);
	
public:
	AOmegaGameMode();
	void Native_DragSelectEnd(const TArray<AActor*>& actors);
	virtual void BeginPlay() override;
	virtual void PostLogin(APlayerController* NewPlayer) override;
	
	UPROPERTY(BlueprintAssignable, Category="Omega") FOmegaGameModeDelegate OnLoadEventFinish;
	UPROPERTY(BlueprintAssignable, Category="Omega") FOmegaGameModeActorListDelegate OnDragSelectedEnded;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UCombatantComponent* Combatant;
	//UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UGameplayActorComponent* ActorID;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UAssetSquadComponent* AssetSquad;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UInstanceActorComponent* EntityInstances;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UOmegaCalendarComponent* Calendar;
	
	UPROPERTY(EditDefaultsOnly, Category="⚙️OMEGA - Systems", DisplayName="⚙️ Systems (Pre-Load)")
	TArray<TSubclassOf <AOmegaGameplaySystem>> AutoGameplaySystems;

	UPROPERTY(EditDefaultsOnly, Category="⚙️OMEGA - Systems", DisplayName="⚙️ System (Load)")
	TSubclassOf <AOmegaGameplaySystem> LoadGameplaySystem;
	
	UPROPERTY(EditDefaultsOnly, Category="⚙️OMEGA - Systems", DisplayName="⚙️ Systems (Post-Load)")
	TArray<TSubclassOf <AOmegaGameplaySystem>> PostLoadGameplaySystems;

	UPROPERTY(EditDefaultsOnly, Category="⚙️OMEGA - Systems", DisplayName="⚙️ Systems (Persistent)")
	TArray<TSubclassOf <AOmegaGameplaySystem>> PersistentGameplaySystems;
	//Frequency  (in seconds) at which 'Persistent' gameplay systems will tried to be activated.
	UPROPERTY(EditDefaultsOnly, Category="⚙️OMEGA - Systems", DisplayName="⌛ Persistent System - Frequency")
	float PersistentSystemActivationFrequency=0.4;

	UPROPERTY(EditDefaultsOnly, Category="⚙️OMEGA - Systems")
	FGameplayTagContainer AutoBlockSystemTags;
	
	UPROPERTY(EditDefaultsOnly, Category="⚙️OMEGA - Systems")
	TArray<FOmegaGameplaySystemConfig> System_Config;
	
	UPROPERTY(EditDefaultsOnly, Category="🎮️OMEGA - Player")
	bool bAutoActivateDynamicCamera;
	UPROPERTY(EditDefaultsOnly, Category="🎮️OMEGA - Player")
	TSubclassOf<AOmegaDynamicCamera> DefaultDynamicCamera;
	
	UPROPERTY(EditDefaultsOnly, Category="🎮️OMEGA - Player",DisplayName="HUD Layers (Persistent)")
	TArray<TSubclassOf <UHUDLayer>> HUDLayers_Persistent;
	
	//UPROPERTY(EditDefaultsOnly, Category="🎮️OMEGA - Player")
	//TArray<TSubclassOf <AOmegaPlayerSystem>> PlayerSystems_Auto;
	//UPROPERTY(EditDefaultsOnly, Category="🎮️OMEGA - Player")
	//TArray<TSubclassOf <AOmegaPlayerSystem>> PlayerSystems_Persistent;

	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category="🖱️OMEGA - Drag Select")
	bool CanDragSelect;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category="🖱️OMEGA - Drag Select")
	FLinearColor DragSelectColor;
	UPROPERTY(EditDefaultsOnly, Category="🖱️OMEGA - Drag Select")
	TArray<FKey> DragSelectKeys;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="🖱️OMEGA - Drag Select")
	TArray<TSubclassOf<AActor>> DragSelectableActors;

	
	UFUNCTION(BlueprintImplementableEvent, Category="Omega Game Mode")
	void OnLoadEventFinished();
	UFUNCTION(BlueprintImplementableEvent, Category="Omega Game Mode")
	void OnDragSelectEnd(const TArray<AActor*>& actors);
	
#if WITH_EDITOR
	
	virtual void PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif
	void ValidateTemplates();
	
private:
	UFUNCTION()
	void Local_ActivatePersistentSystems();
private:
	FTimerHandle PersistentSystemsTimerHandle;
	

};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaHUD : public AHUD
{
	GENERATED_BODY()

	bool b_isDragSelecting;
	FVector2D dragSelect_start;
	FVector2D dragSelect_end;
	UPROPERTY() AOmegaGameMode* ref_gameMode;
	UPROPERTY() UOmegaSubsystem_World* ss_world;
	bool isDragInputDown() const;
public:
	virtual void BeginPlay() override;
	virtual void DrawHUD() override;
	UCanvas* GetCanvas() { return Canvas;};
};