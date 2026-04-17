// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaGameplaySystem.h"
#include "GameFramework/PlayerController.h"
#include "Actor_Player.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOmegaPlayerSystemStateChange,AOmegaGameplaySystem*,System,UObject*, Context,const FString&, Flag);

class UCombatantComponent;
class UAudioComponent;
class UAssetSquadComponent;
class UInstanceActorComponent;
class UGameplayActorComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaPlayer : public APlayerController
{
	GENERATED_BODY()

	void L_Print(const FString& str);
	
	UPROPERTY() FOmegaBaseSystemStats SystemStats;
	UPROPERTY() float LastPerSysCall;
	
	virtual void TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
public:
	//(BlueprintAssignable) FOmegaPlayerSystemStateChange OnSystemActivated;
//	UPROPERTY(BlueprintAssignable) FOmegaPlayerSystemStateChange OnSystemShutdown;
	
	AOmegaPlayer();
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UCombatantComponent* Combatant;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UGameplayActorComponent* ActorID;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UAssetSquadComponent* AssetSquad;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UInstanceActorComponent* EntityInstances;
	
	UPROPERTY(EditAnywhere,Category="Omega") TArray<TSubclassOf<AOmegaGameplaySystem>> Systems_Auto;
	UPROPERTY(EditAnywhere,Category="Omega") TArray<TSubclassOf<AOmegaGameplaySystem>> Systems_Persistent;
	UPROPERTY(EditAnywhere,Category="Omega") float PersistentSystemFrequency=0.2f;

	UFUNCTION(BlueprintCallable,Category="Omega|Player")
	AOmegaGameplaySystem* SetSystemActive(TSubclassOf<AOmegaGameplaySystem> System, UObject* Context, const FString& Flag, bool active,FOmegaCommonMeta meta=FOmegaCommonMeta());

	UFUNCTION(BlueprintCallable,Category="Omega|Player")
	void SetSystemsActive(TArray<TSubclassOf<AOmegaGameplaySystem>> Systems, UObject* Context, const FString& Flag, bool active,FOmegaCommonMeta meta=FOmegaCommonMeta());
	
	UFUNCTION(BlueprintPure,Category="Omega|Player")
	bool IsSystemActive(TSubclassOf<AOmegaGameplaySystem> System);
};
