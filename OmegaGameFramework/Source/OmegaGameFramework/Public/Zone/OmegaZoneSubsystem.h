// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LevelSequence.h"
#include "LevelSequencePlayer.h"
#include "Subsystems/WorldSubsystem.h"
#include "GameFramework/Actor.h"
#include "OmegaZone.h"
#include "Blueprint/UserWidget.h"
#include "OmegaZonePoint.h"
#include "OmegaZoneSubsystem.generated.h"

class AOmegaGameplaySystem;
class UOmegaZoneGameInstanceSubsystem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnZoneLoaded, UOmegaZoneData*, Zone);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnZoneUnloaded, UOmegaZoneData*, Zone);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnZoneTransitInRange, AOmegaZoneTransit*, ZoneTransit, bool, bInRange);

UCLASS(DisplayName="Omega Subsystem: Zones")
class OMEGAGAMEFRAMEWORK_API UOmegaZoneSubsystem : public UWorldSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

public:

	virtual void Tick(float DeltaTime) override;
	
	virtual ETickableTickType GetTickableTickType() const override
	{
		return ETickableTickType::Always;
	}
	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT( FMyTickableThing, STATGROUP_Tickables );
	}
	virtual bool IsTickableWhenPaused() const
	{
		return true;
	}
	virtual bool IsTickableInEditor() const
	{
		return false;
	}
	// FTickableGameObject End

	UPROPERTY()
	bool bIsInLevelTransit;
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;

	UFUNCTION(BlueprintCallable, Category="Omega|Zone", meta=(AdvancedDisplay="UnloadPreviousZones"))
	void LoadZone(UOmegaZoneData* Zone, bool UnloadPreviousZones = true);

	UFUNCTION(BlueprintCallable, Category="Omega|Zone")
	void UnloadZone(UOmegaZoneData* Zone);

	UPROPERTY(BlueprintAssignable)
	FOnZoneTransitInRange OnZoneTransitInRange;
	
	UPROPERTY()
	TArray<UOmegaZoneData*> LoadedZones;
	
	UFUNCTION(BlueprintPure, Category="Omega|Zone")
	TArray<UOmegaZoneData*> GetLoadedZones();

	UFUNCTION(BlueprintPure, Category="Omega|Zone")
	UOmegaZoneData* GetTopLoadedZones();

	UFUNCTION(BlueprintPure, Category="Omega|Zone")
	bool IsZoneLoaded(UOmegaZoneData* Zone);

	UPROPERTY(BlueprintAssignable)
	FOnZoneLoaded OnZoneLoaded;
	UPROPERTY(BlueprintAssignable)
	FOnZoneUnloaded OnZoneUnloaded;
	
protected:
	UPROPERTY()
	UOmegaZoneGameInstanceSubsystem* GamInstSubsys;

	UFUNCTION()
	void OnLoadFromLevelComplete();
	
public:
	//#########################################################################################################
	// TRANSIT
	//#########################################################################################################
	UPROPERTY()
	TArray<AOmegaZonePoint*> ZonePoints;

	UFUNCTION()
	AOmegaZonePoint* GetZonePointFromID(FGameplayTag ID);
	
	UFUNCTION(BlueprintCallable, Category="Zone", meta=(AdvancedDisplay="Player"))
	void TransitPlayerToPoint(AOmegaZonePoint* Point, APlayerController* Player);

	UFUNCTION(BlueprintCallable, Category="Zone", meta=(AdvancedDisplay="Player"))
	void TransitPlayerToPointID(FGameplayTag PointID, APlayerController* Player);

	UFUNCTION(BlueprintCallable, Category="Zone", meta=(MetaClass="World"))
	void TransitPlayerToLevel(TSoftObjectPtr<UWorld> Level, FGameplayTag SpawnID);
	
	UPROPERTY()
	bool IsMidPlayerTransit;

	UFUNCTION()
	void Local_CompleteTransit();

	UFUNCTION()
	void Local_PreBeginTransitActions();
	
protected:

	UPROPERTY()
	bool bUnloadPreviousZones;
	UPROPERTY()
	UOmegaZoneData* IncomingZone_Load;
	UPROPERTY()
	AOmegaZonePoint* Incoming_SpawnPoint;
	UPROPERTY()
	UOmegaZoneData* IncomingZone_Unload;
	UPROPERTY()
	TArray<FName> Incoming_LoadList;
	UPROPERTY()
	bool Incoming_LoadState;
	UPROPERTY()
	UOmegaZoneData* Incoming_LoadTaskZone;
	
	UFUNCTION()
	void Local_OnBeginLoadTaskList(TArray<FName> Levels, bool Loaded);
	UFUNCTION()
	void Local_OnNextLoadEvent();
	UFUNCTION()
	void Local_OnFinishLoadTask(bool LoadState);

	UPROPERTY()
	FName IncomingLevelName;
	UPROPERTY()
	bool Local_IsWaitForLoad;
	UFUNCTION()
	void Local_FinishZoneLoad();

	UFUNCTION()
	TSubclassOf<AOmegaGameplaySystem> GetZoneGameplaySystem();

	//#############################################
	// Transit Sequence
	//#############################################

	UFUNCTION()
	ULevelSequence* GetTransitSequence();

	UFUNCTION()
	ULevelSequencePlayer* GetTransitSequencePlayer();
	UPROPERTY()
	 ALevelSequenceActor* LocalSeqPlayer;
	
	UPROPERTY()
	bool bSequenceTransit_IsForward;
	
	UPROPERTY()
	bool bSequenceTransit_IsPlaying;
	
	UFUNCTION()
	void Local_OnBeginTransitSequence(bool bForward);

	UFUNCTION()
	void Local_OnFinishTransitSequence();
	
};


/*
UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaZoneTransitManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOmegaZoneTransitManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY()
	UStaticMesh* ShapeMeshRef_sphere;
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	UOmegaZoneSubsystem* ZoneSubsystem;
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnFinishLoadEvent();

};
*/


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaZoneHUD : public UUserWidget
{
	GENERATED_BODY()
    
public:
	//UOmegaZoneHUD(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintImplementableEvent, Category="Zone")
	void OnZoneTransitNotified(AOmegaZoneTransit* ZoneTransit, bool Notified);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Zone")
	void OnZoneTransitBegin(AOmegaZonePoint* ZonePoint);

	UFUNCTION(BlueprintImplementableEvent, Category="Zone")
	void OnZoneTransitEnd(AOmegaZonePoint* ZonePoint);

protected:
	//virtual void NativeConstruct() override;
};
