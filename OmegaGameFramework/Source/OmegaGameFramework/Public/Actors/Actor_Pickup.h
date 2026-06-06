// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor_GameplayCue.h"
#include "GameFramework/Actor.h"
#include "Misc/GeneralDataObject.h"
#include "Actor_Pickup.generated.h"

class USplineComponent;
class UNiagaraComponent;
class USphereComponent;
class AOmegaGameplayCue;
class UAudioComponent;


// Configuration for a pickup actor's visual and audio feedback (screen flash, movement, color, cue, sound).
USTRUCT(BlueprintType)
struct FOmegaPickupConfig
{
	GENERATED_BODY()
	// When true, the screen briefly flashes the pickup's color when it is collected.
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Pickup") bool bFlashScreen;
	// When true, the pickup slides toward the collecting pawn before being removed.
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Pickup") bool MoveToActorOnPickup;
	// Duration in seconds for the slide-to-actor movement.
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Pickup") float MoveToActorDuration=0.2;
	// Starting opacity for the screen flash effect.
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Pickup",meta=(AdvancedDisplay)) float FlashStartOpacity=0.3;
	// Duration of the screen flash in seconds.
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Pickup",meta=(AdvancedDisplay)) float FlashDuration=0.3;
	// Tint color used for the screen flash.
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Pickup") FLinearColor Color=FLinearColor::White;
	// Niagara particle effect played at the pickup point when collected.
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Pickup") UNiagaraSystem* NiagaraSystem;
	// Mesh passed to the Niagara system as a particle mesh parameter.
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Pickup") UStaticMesh* NiagaraMesh;
	// Sound played when the pickup is collected.
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Pickup") USoundBase* PickupSound;
	// Gameplay cue spawned at the pickup location when collected.
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Pickup")
	FOmegaGameplayCueConfig PickupCue;

};

// Implement on data assets or objects that define a pickup's behavior: whether it can be picked up, what happens on pickup, and its display config.
UINTERFACE(MinimalAPI,BlueprintType, DisplayName="♎Data🔴 - 💸Pickup") class UDataInterface_Pickup : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_Pickup
{
	GENERATED_BODY()
public:
	// Called when the preset is first applied to the pickup actor.
	UFUNCTION(BlueprintNativeEvent,Category="♎I|💸Pickup",DisplayName="Pickup - On Preset Init")
	bool PickupActor_OnInit(AOmegaPickupActor* Actor);

	// Called during OnConstruction when the preset is set.
	UFUNCTION(BlueprintNativeEvent,Category="♎I|💸Pickup",DisplayName="Pickup - On Construct")
	bool PickupActor_Construct(AOmegaPickupActor* Actor);

	// Called at BeginPlay once the preset is ready.
	UFUNCTION(BlueprintNativeEvent,Category="♎I|💸Pickup",DisplayName="Pickup - On BeginPlay")
	bool PickupActor_BeginPlay(AOmegaPickupActor* Actor);

	// Return true to allow the given pawn/controller to collect this pickup.
	UFUNCTION(BlueprintNativeEvent,Category="♎I|💸Pickup",DisplayName="Pickup - Can Pickup?")
	bool CanPickup(APawn* Pawn, APlayerController* Controller);

	// Called when the pickup is successfully collected; return value is reserved for future use.
	UFUNCTION(BlueprintNativeEvent,Category="♎I|💸Pickup",DisplayName="Pickup - On Pickup")
	int32 OnPickup(APawn* Pawn, APlayerController* Controller);

	// Returns the visual/audio configuration for this pickup.
	UFUNCTION(BlueprintNativeEvent, Category="♎I|💸Pickup",DisplayName="Pickup - Get Config")
	FOmegaPickupConfig GetPickupConfig();
};




// A world pickup actor that detects player overlap and calls its preset's pickup logic.
UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaPickupActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY() FVector move_origin;
	UPROPERTY() APawn* pawn_target;
	UPROPERTY() APlayerController* controller_target;
	UPROPERTY() float move_to_actor_time;
	UPROPERTY() bool is_picking_up;
	void pickup_finish();

	bool L_ValidPreset() const;
	bool bIsSettingPreset = false;

protected:

	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;
	AOmegaPickupActor();
public:

	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	FOmegaPickupConfig GetConfig() const;

	// Override in Blueprint to add custom conditions for whether this pickup can be collected.
	UFUNCTION(BlueprintNativeEvent,Category="Pickup") bool CanPickup(APawn* Pawn, APlayerController* Controller);

	// Called in Blueprint when a pawn successfully collects this pickup.
	UFUNCTION(BlueprintImplementableEvent,Category="Pickup") void OnPickup(APawn* Pawn, APlayerController* Controller);

	// Replaces the active preset at runtime and rebuilds the pickup's configuration.
	UFUNCTION(BlueprintCallable,Category="Pickup") void SetPreset(TScriptInterface<IDataInterface_Pickup> preset);
	// The data interface preset that drives this pickup's behavior. Must implement IDataInterface_Pickup.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pickup",meta=(MustImplement="/Script/OmegaGameFramework.IDataInterface_Pickup"))
	TScriptInterface<IDataInterface_Pickup> Preset;
	// Optional numeric ID used to differentiate pickups of the same type in save data.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Pickup",AdvancedDisplay) int32 ID;

	// Inline config used when no Preset is set.
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Pickup", meta=(ShowOnlyInnerProperties,EditCondition="!Preset")) FOmegaPickupConfig Config;
	// Sphere collision component that detects pawn overlap.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") USphereComponent* Range;
	// Niagara particle component for idle or pickup visual effects.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UNiagaraComponent* NiagaraComponent;
	// Audio component for idle or pickup sound effects.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UAudioComponent* AudioComponent;
};

// A spline-based actor that places multiple pickup actors along a path, useful for item trails or collectible chains.
UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaPickupTrail : public AActor
{
	GENERATED_BODY()


public:
	AOmegaPickupTrail();
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

	// Replaces the active preset and rebuilds the trail.
	UFUNCTION(BlueprintCallable,Category="Pickup") void SetPreset(TScriptInterface<IDataInterface_Pickup> preset);
	// The pickup preset applied to each pickup actor spawned along the trail.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pickup",meta=(MustImplement="/Script/OmegaGameFramework.IDataInterface_Pickup"))
	TScriptInterface<IDataInterface_Pickup> Preset;
	// How many pickup actors are distributed along the spline.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Pickup") int32 Count=3;
	// Optional numeric ID shared by all pickups in this trail.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Pickup",AdvancedDisplay) int32 ID;

	//only used for visible references for the pickup. hidden in game, no collision, and all instances removed on beginplay
	UPROPERTY() UInstancedStaticMeshComponent* ReferenceMesh;

	// Spline component defining the path along which pickup actors are distributed.
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="PickupTrail") USplineComponent* SplineComponent;

};
