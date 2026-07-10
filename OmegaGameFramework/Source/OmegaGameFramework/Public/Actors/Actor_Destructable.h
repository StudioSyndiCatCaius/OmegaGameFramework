// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor_Gameplay.h"
#include "DataAssets/DA_Appearance.h"
#include "DataAssets/DA_DamageType.h"
#include "Engine/DataAsset.h"
#include "Functions/F_Component.h"
#include "Functions/F_TagEvent.h"
#include "GameFramework/Actor.h"
#include "Misc/GeneralDataObject.h"
#include "Actor_Destructable.generated.h"

class UCombatantComponent;
class UOmegaDamageType;
class UActorConfigComponent;
class UOAsset_Appearance;
class UNiagaraSystem;
class UStateTreeComponent;
class UOmegaSaveableComponent;
class UNiagaraComponent;
class UBoxComponent;
class UAudioComponent;

// Runtime configuration bundle for a destructible actor: controls death conditions, size, delay, and the health attribute to watch.
USTRUCT(BlueprintType)
struct FOmegaDestructibleConfig
{
	GENERATED_BODY()

	// When true, the actor triggers its death sequence when the HealthAttribute reaches zero.
	UPROPERTY(BlueprintReadWrite,Category="Destructible") bool bDeathOnHealth0 = false;
	// When true, the range box's size is automatically set to match the mesh's world bounds.
	UPROPERTY(BlueprintReadWrite,Category="Destructible") bool bSizeRangeToMeshBounds = false;
	// Seconds to wait after the death condition is met before the actor is destroyed.
	UPROPERTY(BlueprintReadWrite,Category="Destructible") float DeathDelay = 0.0f;
	// The attribute whose depletion to zero triggers the death sequence.
	UPROPERTY(BlueprintReadWrite,Category="Destructible") UOmegaAttribute* HealthAttribute=nullptr;
};

// Implement on data assets to drive a destructible actor's setup, lifecycle, and death behavior.
UINTERFACE(MinimalAPI,BlueprintType, DisplayName="♎Data🔴 - 🛢️Destructible") class UDataInterface_Destructible : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_Destructible
{
	GENERATED_BODY()
public:

	// Called during OnConstruction; return value is reserved for future use.
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🛢️Destructible",DisplayName="🛢️Destructible - On Construct")
	int32 Destructible_Construct(AOmegaDestructible* Actor);
	// Called at BeginPlay; return value is reserved for future use.
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🛢️Destructible",DisplayName="🛢️Destructible - On BeginPlay")
	int32 Destructible_BeginPlay(AOmegaDestructible* Actor);

	// Fires when Health Attribute <=0.0 (ONLY IF toggled on). Set bDestroyActor to control whether the actor is removed from the world.
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🛢️Destructible",DisplayName="🛢️Destructible - On OnDeath")
	void Destructible_Death(AOmegaDestructible* Actor, bool& bDestroyActor);

	// Called when the actor is destroyed; return value is reserved for future use.
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🛢️Destructible",DisplayName="🛢️Destructible - On ActorDestroyed")
	int32 Destructible_Destroyed(AOmegaDestructible* Actor);
	// Returns the runtime config (death conditions, health attribute, etc.) for this destructible preset.
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🛢️Destructible",DisplayName="🛢️Destructible - Get Config")
	FOmegaDestructibleConfig Destructible_GetConfig();
};


// A non-pawn actor with a CombatantComponent that can receive attribute damage and trigger a death sequence.
UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaDestructible : public AOmegaActorBASE, public IActorTagEventInterface, public IDataInterface_AppearanceSource
{
	GENERATED_BODY()

public:
	UPROPERTY() FOmegaDestructibleConfig _cachedConfig;
	bool dead;
	bool dying=false;
	float DeathDelayRemaining;

	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;
	virtual void Destroyed() override;
	FOmegaDestructibleConfig GetConfig() const;

	UFUNCTION()
	void L_Damaged(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, float FinalDamage, class UCombatantComponent* _Instigator, UOmegaDamageType* DamageType, FHitResult Hit);
	AOmegaDestructible();

	// Replaces the current preset at runtime and re-applies its configuration to the actor.
	UFUNCTION(BlueprintCallable,Category="Destructible") void SetPreset(TScriptInterface<IDataInterface_Destructible> preset);
	// The data interface preset that defines this destructible's configuration and lifecycle callbacks.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Destructible") TScriptInterface<IDataInterface_Destructible> Preset;
	// Tag events fired on this actor (and others) when the death sequence triggers.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Destructible") FOmegaActorTagEventContainer TagEvents_OnDeath;

	// Components
	// Collision box used for interaction and range detection.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UBoxComponent* RangeBox;
	// Static mesh representing the destructible's visual.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UStaticMeshComponent* MeshComponent;
	// Audio component for spawn/death sound effects.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UAudioComponent* Audio;
	// Niagara particle component for spawn/death visual effects.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UNiagaraComponent* NiagaraComponent;
	// The combatant component that receives attribute damage and drives the death condition check.
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components",meta=(ShowOnlyInnerProperties)) UCombatantComponent* CombatantComponent;


};
