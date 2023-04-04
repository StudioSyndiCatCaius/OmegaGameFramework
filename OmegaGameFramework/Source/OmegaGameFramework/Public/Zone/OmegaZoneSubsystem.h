// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "GameFramework/Actor.h"
#include "OmegaZone.h"
#include "OmegaZonePoint.h"
#include "OmegaZoneSubsystem.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnZoneLoaded, UOmegaZoneData*, Zone);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnZoneUnloaded, UOmegaZoneData*, Zone);

UCLASS(DisplayName="Omega Subsystem: Zones")
class OMEGAGAMEFRAMEWORK_API UOmegaZoneSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	//virtual void Initialize(FSubsystemCollectionBase& Colection) override;

	UFUNCTION(BlueprintCallable, Category="Omega|Zone", meta=(AdvancedDisplay="UnloadPreviousZones"))
	void LoadZone(UOmegaZoneData* Zone, bool UnloadPreviousZones = true);

	UFUNCTION(BlueprintCallable, Category="Omega|Zone")
	void UnloadZone(UOmegaZoneData* Zone);

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
	void TransitPlayerToLevel(FSoftObjectPath Level, FGameplayTag SpawnID);
	
	UPROPERTY()
	bool IsMidPlayerTransit;

	UFUNCTION()
	void Local_FinishPlayerTransit();
	
protected:

	UPROPERTY()
	UOmegaZoneData* IncomingZone_Load;
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
	bool Local_IsWaitForLoad;
	UFUNCTION()
	void Local_FinishZoneLoad();
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