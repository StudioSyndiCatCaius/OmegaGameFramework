// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Interfaces/I_Common.h"
#include "Subsystems/Subsystem_World.h"
#include "DataAssets/DA_Zone.h"
#include "Actor_Zone.generated.h"

class UZoneEntityComponent;
class USpringArmComponent;
class UCameraComponent;
class USceneCaptureComponent2D;
class UUtilMeshComponent;
class UTextRenderComponent;
class UNiagaraComponent;
class UArrowComponent;
class USceneComponent;
class UCapsuleComponent;
class UBoxComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API AZoneEntity_Mesh : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AZoneEntity_Mesh();
	
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Mesh") UZoneEntityComponent* ZoneEntity;

};



// =============================================================================================================
// Zone Entity
// =============================================================================================================

UENUM(Blueprintable)
enum EOmegaZoneMangerState :uint8
{
	zone_Uninitialzed,
	zone_Initializing,
	zone_Idle,
	zone_Unloading,
	zone_Loading,
	
};

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UZoneEntityComponent : public UActorComponent, public IDataInterface_General
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
	bool UseParentAsDisplayActor;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Zone Entity",meta=(EditCondition="!UseParentAsDisplayActor"))
	TSubclassOf<AZoneEntityDisplayActor> DisplayActorClass;
	UFUNCTION(BlueprintPure,Category="Zone Entity")
	AActor* GetDisplayActor() const;
	
	UFUNCTION(BlueprintPure,Category="Zone Entity")
	FVector2D GetPosition2D();
	UFUNCTION(BlueprintPure,Category="Zone Entity")
	float GetRotation2D();
	
	virtual auto GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description) -> void override;
	virtual void GetGeneralDataImages_Implementation(FGameplayTag Tag, class UTexture2D*& Texture, class UMaterialInterface*& Material, FSlateBrush& Brush) override;
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
	void L_RefreshView();
	bool L_ActorIsValidViewable(AActor* a) const;
public:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="ZoneEntityViewCamera")
	TArray<AActor*> ViewFilterActors;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="ZoneEntityViewCamera")
	TMap<UZoneLegendAsset*,bool> LegendVisibility;
	
	UFUNCTION(BlueprintPure,Category="ZoneEntityView")
	bool IsLegendVisible(UZoneLegendAsset* Legend) const;

	UFUNCTION(BlueprintCallable,Category="ZoneEntityView")
	void SetLegendVisible(UZoneLegendAsset* Legend, bool bVisible);

	UFUNCTION(BlueprintCallable,Category="ZoneEntityView")
	void SetViewFilterActorValid(AActor* Actor, bool ValidFilter);

	UFUNCTION(BlueprintCallable,Category="ZoneEntityView")
	void ClearAllViewFilterActors();
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="ZoneEntityViewCamera") USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="ZoneEntityViewCamera") UCameraComponent* CameraComponent;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="ZoneEntityViewCamera") USceneCaptureComponent2D* SceneCaptureComponent;
};


// =============================================================================================================
// Zone Transit Point
// =============================================================================================================
UCLASS(DisplayName="Ω Zone Transit")
class OMEGAGAMEFRAMEWORK_API AOmegaZoneTransit : public AActor, public IActorInterface_Interactable
{
	GENERATED_BODY()
	
	AOmegaZoneTransit();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void OnInteraction_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override;
	virtual bool IsInteractionBlocked_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override;
public:
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zone")
	bool bShow_DisplayPoint=true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zone", meta=(EditCondition="!bTransitToLevel"),DisplayName="Transition Spawn Point")
	AOmegaZonePoint* TransitPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zone", meta=(EditCondition="!bTransitToLevel"),DisplayName="Transition Transit Point")
	AOmegaZoneTransit* TransitPoint_Linked;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zone", DisplayName="Transit To Level?")
	bool bTransitToLevel;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zone", meta=(EditCondition="bTransitToLevel",EditConditionHides))
	TSoftObjectPtr<UWorld> TransitLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zone", meta=(EditCondition="bTransitToLevel",EditConditionHides))
	FGameplayTag LevelTransitID;

	UPROPERTY(EditDefaultsOnly, Category="Zone") UBoxComponent* Box_Transit;
	UPROPERTY(EditDefaultsOnly, Category="Zone") UBoxComponent* Box_Notify;
	
	UPROPERTY() UTextRenderComponent* TextComponent;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UNiagaraComponent* DisplayEmitter;
	UPROPERTY() UArrowComponent* DirectionalArrow;
	UPROPERTY() USceneComponent* Spawn_Point_Ref;
	UPROPERTY() UUtilMeshComponent* UtilMesh;
	UPROPERTY() UCapsuleComponent* Capsule;
	
	UPROPERTY(EditAnywhere, Category="Display") float Box_X = 250;
	UPROPERTY(EditAnywhere, Category="Display") float Box_Y = 400;

	UFUNCTION(BlueprintCallable,Category="Zone")
	void TriggerTransit(APlayerController* Player);
	
	UFUNCTION() bool CanPlayerTransit(APawn* PlayerPawn) const;
	
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

	// EDITOR

	UFUNCTION(BlueprintCallable,CallInEditor,Category="EDITOR") void AutosetTransits();
	
protected:
	void UpdateBoxes();

	UPROPERTY() UOmegaSubsystem_World* SubsysRef;

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

UCLASS(DisplayName="Ω Zone Spawn")
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

	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description) override;
};