// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LevelSequence.h"
#include "LevelSequencePlayer.h"
#include "OmegaSubsystem_Actors.h"
#include "Subsystems/WorldSubsystem.h"
#include "Subsystems/OmegaSubsystem_BGM.h"
#include "Engine/GameInstance.h"
#include "GameFramework/Actor.h"
#include "Functions/OmegaFunctions_Common.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Components/ArrowComponent.h"
#include "Misc/OmegaUtils_Volume.h"
#include "Engine/DataAsset.h"
#include "Components/TextRenderComponent.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/SpringArmComponent.h"

#include "OmegaSubsystem_Zone.generated.h"

class AOmegaGameplaySystem;
class UOmegaZoneGameInstanceSubsystem;
class UBrushComponent;
class UBillboardComponent;
class UBoxComponent;
class UOmegaZoneSubsystem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlaySpawnedAtPoint, APlayerController*, Player, AOmegaZonePoint*, Point);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnZoneLoaded, UOmegaZoneData*, Zone);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnZoneUnloaded, UOmegaZoneData*, Zone);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnZoneTransitInRange, AOmegaZoneTransit*, ZoneTransit, bool, bInRange);

// =============================================================================================================
// Zone Entity
// =============================================================================================================

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UZoneEntityComponent : public UActorComponent, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

	UZoneEntityComponent();

	UPROPERTY() AZoneEntityDisplayActor* Ref_DisplayActor;

public:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Zone Entity")
	FText DisplayName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Zone Entity",meta=(MultiLine))
	FText DisplayDescription;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Zone Entity",meta=(MultiLine))
	FGameplayTagContainer ExtraTags;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Zone Entity")
	UZoneLegendAsset* LegendAsset;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Zone Entity")
	UOmegaZoneData* CurrentZone;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Zone Entity")
	TSubclassOf<AZoneEntityDisplayActor> DisplayActorClass;
	UFUNCTION(BlueprintPure,Category="Zone Entity")
	AZoneEntityDisplayActor* GetDisplayActor() const
	{
		if(Ref_DisplayActor)
		{
			return Ref_DisplayActor;
		}
		return nullptr;
	}

	
	UFUNCTION(BlueprintPure,Category="Zone Entity")
	FVector2D GetPosition2D();
	UFUNCTION(BlueprintPure,Category="Zone Entity")
	float GetRotation2D();

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;
	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;
};

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API AZoneEntityDisplayActor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY() UZoneEntityComponent* owning_component;
	UFUNCTION(BlueprintPure,Category="Zone Entity Display")
	UZoneEntityComponent* GetZoneEntityComponent() const { if(owning_component) {return owning_component;} return nullptr;};
	
	//virtual void BeginPlay() override;
	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API AZoneEntityViewCamera : public APawn
{
	GENERATED_BODY()

	AZoneEntityViewCamera();

public:

	virtual void BeginPlay() override;
	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="ZoneEntityViewCamera") USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="ZoneEntityViewCamera") UCameraComponent* CameraComponent;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="ZoneEntityViewCamera") USceneCaptureComponent2D* SceneCaptureComponent;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UZoneLegendAsset : public UOmegaDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly,Category="Legend")
	TSubclassOf<AZoneEntityDisplayActor> DefaultDisplayActor;
};

// =============================================================================================================
// Zone Subsystem
// =============================================================================================================

UCLASS(DisplayName="Omega Subsystem: Zones")
class OMEGAGAMEFRAMEWORK_API UOmegaZoneSubsystem : public UWorldSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

public:

	virtual void Tick(float DeltaTime) override;
	
	virtual ETickableTickType GetTickableTickType() const override { return ETickableTickType::Always; }
	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT( FMyTickableThing, STATGROUP_Tickables ); }
	virtual bool IsTickableWhenPaused() const { return true; }
	virtual bool IsTickableInEditor() const
	{ return false; }
	// FTickableGameObject End
	
	UPROPERTY() bool bIsInLevelTransit;
	
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
	UPROPERTY(BlueprintAssignable)
	FOnPlaySpawnedAtPoint OnPlaySpawnedAtPoint;

	//----------------------------------------------------------------------------------------------------------------a
	// Level Data
	//----------------------------------------------------------------------------------------------------------------
	UPROPERTY()
	UOmegaLevelData* LevelData = nullptr;

	UFUNCTION(BlueprintPure, Category="Omega|Zone")
	UOmegaLevelData* GetLevelData(TSoftObjectPtr<UWorld> SoftLevelReference);

	UFUNCTION(BlueprintPure, Category="Omega|Zone")
	UOmegaLevelData* GetCurrentLevelData();

	UFUNCTION(BlueprintPure, Category="Omega|Zone")
	TSoftObjectPtr<UWorld> GetCurrentLevelSoftReference();
	
	//----------------------------------------------------------------------------------------------------------------
	// Zone Entities
	//----------------------------------------------------------------------------------------------------------------
	void RegisterZoneEntity(UZoneEntityComponent* entity, bool bIsEntityRegistered)
	{
		if(bIsEntityRegistered && !registered_entities.Contains(entity))
		{
			registered_entities.AddUnique(entity);
		}
		if(!bIsEntityRegistered && registered_entities.Contains(entity))
		{
			registered_entities.Remove(entity);
		}
	}
	
	UPROPERTY() TArray<UZoneEntityComponent*> registered_entities;
	
	UFUNCTION(BlueprintPure,Category="Zone|Entities")
	TArray<UZoneEntityComponent*> GetRegisteredZoneEntities() const;

	UFUNCTION(BlueprintPure,Category="Zone|Entities")
	TArray<UZoneEntityComponent*> GetRegisteredZoneEntities_OfLegend(UZoneLegendAsset* Legend) const;
	
protected:
	UPROPERTY()
	UOmegaZoneGameInstanceSubsystem* GamInstSubsys;

	UFUNCTION()
	void OnLoadFromLevelComplete();

	void SpawnFromStartingPoint();
	
public:

	UFUNCTION(BlueprintCallable, Category="Zone")
	void LoadDefaultZone();
	
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

	UFUNCTION(BlueprintCallable, Category="Zone", meta=(MetaClass="World"), DisplayName="Transit Player to Level (Name)")
	void TransitPlayerToLevel_Name(FName Level, FGameplayTag SpawnID);

	UFUNCTION(BlueprintCallable, Category="Zone", meta=(MetaClass="World"))
	void TransitPlayerToLevel(TSoftObjectPtr<UWorld> Level, FGameplayTag SpawnID);
	
	UPROPERTY()
	bool IsMidPlayerTransit;

	UFUNCTION()
	void Local_CompleteTransit();

	UFUNCTION()
	void Local_PreBeginTransitActions();
	
protected:

	//That that will be falled back to if no other active zone exists
	UPROPERTY() UOmegaZoneData* FallbackZone=nullptr;
	UPROPERTY() bool bUnloadPreviousZones;
	UPROPERTY() UOmegaZoneData* IncomingZone_Load;
	UPROPERTY() AOmegaZonePoint* Incoming_SpawnPoint;
	UPROPERTY() UOmegaZoneData* IncomingZone_Unload;
	UPROPERTY() TArray<FName> Incoming_LoadList;
	UPROPERTY() bool Incoming_LoadState;
	UPROPERTY() UOmegaZoneData* Incoming_LoadTaskZone;
	
	UFUNCTION() void Local_OnBeginLoadTaskList(TArray<FName> Levels, bool Loaded);
	UFUNCTION() void Local_OnNextLoadEvent();
	UFUNCTION() void Local_OnFinishLoadTask(bool LoadState);

	UPROPERTY() FName IncomingLevelName;
	UPROPERTY() bool Local_IsWaitForLoad;
	UFUNCTION() void Local_FinishZoneLoad();

	UFUNCTION() TSubclassOf<AOmegaGameplaySystem> GetZoneGameplaySystem();

	//#############################################
	// Transit Sequence
	//#############################################

	UFUNCTION() ULevelSequence* GetTransitSequence();
	UFUNCTION(BlueprintPure, Category="Zone") ULevelSequencePlayer* GetTransitSequencePlayer();
	UPROPERTY() ALevelSequenceActor* LocalSeqPlayer;
	UPROPERTY() bool bSequenceTransit_IsForward;
	UPROPERTY() bool bSequenceTransit_IsPlaying;
	UFUNCTION() void Local_OnBeginTransitSequence(bool bForward);
	UFUNCTION() void Local_OnFinishTransitSequence();
};

// =============================================================================================================
// Zone Asset
// =============================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaLevelData : public UPrimaryDataAsset, public  IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Name")
	FText DisplayName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Description")
	FText DisplayDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Icon")
	FSlateBrush DisplayIcon;

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tags")
	FGameplayTag CategoryTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tags")
	FGameplayTagContainer GameplayTags;

	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Level")
	UOmegaZoneData* DefaultZone;

	//If Default zone is empty, this custom zone data will be defaulted to.
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly, Category="Level")
	UOmegaZoneData* OverrideZoneData;

	UOmegaZoneData* GetDefaultZoneData() const
	{
		if(DefaultZone) {return DefaultZone;}
		if(OverrideZoneData) {return  OverrideZoneData;}
		return nullptr;
	}
	
};

UCLASS(EditInlineNew)
class OMEGAGAMEFRAMEWORK_API UOmegaZoneData : public UPrimaryDataAsset, public  IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Name")
	FText ZoneName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Description")
	FText ZoneDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Icon")
	FSlateBrush ZoneIcon;

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tags")
	FGameplayTag ZoneCategory;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tags")
	FGameplayTagContainer ZoneTags;

	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	TArray<FName> StreamedLevels;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	TArray<FActorDataLayer> DataLayers;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	UOmegaBGM* ZoneBGM;

	//Gameplay Systems will be activated when this zone is loaded and shutdown when it is unloaded. The Zone will be sued as the context.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
    TArray<TSubclassOf<AOmegaGameplaySystem>> SystemsActivatedInZone;
};


// =============================================================================================================
// Zone Transit Point
// =============================================================================================================
UCLASS(DisplayName="Omega Actor: Zone Transit Volume")
class OMEGAGAMEFRAMEWORK_API AOmegaZoneTransit : public AActor, public IActorInterface_Interactable
{
	GENERATED_BODY()
	
	AOmegaZoneTransit();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void OnInteraction_Implementation(AActor* InteractInstigator, FGameplayTag Tag, UObject* Context) override;
public:
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zone")
	bool bTransit_OnOverlap=true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zone")
	bool bTransit_OnInteract;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zone")
	bool bShow_DisplayPoint=true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zone", meta=(EditCondition="!bTransitToLevel"),DisplayName="Transition Spawn Point")
	AOmegaZonePoint* TransitPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zone", meta=(EditCondition="!bTransitToLevel"),DisplayName="Transition Transit Point")
	AOmegaZoneTransit* TransitPoint_Linked;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zone", DisplayName="Transit To Level?")
	bool bTransitToLevel;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zone", meta=(EditCondition="bTransitToLevel"))
	TSoftObjectPtr<UWorld> TransitLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zone", meta=(EditCondition="bTransitToLevel"))
	FGameplayTag LevelTransitID;

	UPROPERTY(EditDefaultsOnly, Category="Zone") UBoxComponent* Box_Transit;
	UPROPERTY(EditDefaultsOnly, Category="Zone") UBoxComponent* Box_Notify;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UTextRenderComponent* TextComponent;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UInstancedStaticMeshComponent* DisplayMesh;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UArrowComponent* DirectionalArrow;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") USceneComponent* Spawn_Point_Ref;

	
	UPROPERTY(EditAnywhere, Category="Display") int32 DisplayPoint_Count = 4;
	UPROPERTY(EditAnywhere, Category="Display",AdvancedDisplay) float DisplayPoint_Distance = 100;
	UPROPERTY(EditAnywhere, Category="Display") float Box_X = 500;
	UPROPERTY(EditAnywhere, Category="Display") float Box_Y = 500;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Zone")
	FGameplayTagContainer AcceptedPlayerTags;

	UFUNCTION(BlueprintCallable,Category="Zone")
	void TriggerTransit(APlayerController* Player);
	
	UFUNCTION()
	bool CanPlayerTransit(APawn* PlayerPawn) const
	{
		return AcceptedPlayerTags.IsEmpty() || UOmegaGameFrameworkBPLibrary::GetObjectGameplayTags(PlayerPawn).HasAnyExact(AcceptedPlayerTags);
	}
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Spawn")
	bool bUseLinkedSpawnPoint=true;

	UPROPERTY()
	AOmegaZonePoint* linked_point;

	UFUNCTION(BlueprintPure,Category="Spawn")
	AOmegaZonePoint* GetLinkedSpawnPoint();
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Spawn",meta=(EditCondition="bUseLinkedSpawnPoint",MakeEditWidget=true))
	FVector SpawnPointLocation=FVector(350,0,90);
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Spawn",meta=(EditCondition="bUseLinkedSpawnPoint"))
	TSubclassOf<AOmegaZonePoint> ZoneSpawnPointClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn")
	UOmegaZoneData* SpawnZoneToLoad;
	
protected:
	void UpdateBoxes();

	UPROPERTY()
	UOmegaZoneSubsystem* SubsysRef;

	UFUNCTION()
	void OnBoxTransitOverlapBegin(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnBoxNotifyOverlapBegin(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnBoxNotifyOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};

// =============================================================================================================
// Zone Spawn Point
// =============================================================================================================

UCLASS(DisplayName="Omega Actor: Zone Spawn Point")
class OMEGAGAMEFRAMEWORK_API AOmegaZonePoint : public AActor, public IDataInterface_General
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	AOmegaZonePoint();

	// Components
	UPROPERTY() UArrowComponent* DirectionalArrow;
	UPROPERTY() UZoneEntityComponent* ZoneEntityComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zone")
	FText PointName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zone")
	TSoftObjectPtr<UWorld> FromLevel;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zone")
	FGameplayTag ZonePointID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zone")
	UOmegaZoneData* ZoneToLoad;

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
};
// =============================================================================================================
// Zone GameInstance Subsystem
// =============================================================================================================

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCompleteZoneLoadOnLevelLoad);

UCLASS(Category = "OmegaSubsystems|Instance")
class OMEGAGAMEFRAMEWORK_API UOmegaZoneGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:
	virtual void Initialize(FSubsystemCollectionBase& Colection) override;
	virtual void Deinitialize() override;

public:
	
	void OnLevelChanged(UWorld* World, const UWorld::InitializationValues);
	
	UPROPERTY() bool bIsLoadingGame;
	UPROPERTY() bool IsInlevelTransit;
	
	UPROPERTY() FGameplayTag TargetSpawnPointTag;
	UPROPERTY() TSoftObjectPtr<UWorld> PreviousLevel;
};


// =============================================================================================================
// Zone HUD
// =============================================================================================================

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

};


