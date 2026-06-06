// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor_Gameplay.h"
#include "DataAssets/DA_Appearance.h"
#include "Engine/DataAsset.h"
#include "Functions/F_Component.h"
#include "Functions/F_TagEvent.h"
#include "GameFramework/Actor.h"
#include "Misc/GeneralDataObject.h"
#include "Actor_Prop.generated.h"

class UActorConfigComponent;
class UOAsset_Appearance;
class UNiagaraSystem;
class UStateTreeComponent;
class UOmegaSaveableComponent;
class UNiagaraComponent;
class UBoxComponent;
class UAudioComponent;

// A data asset that fully defines a prop's static/skeletal mesh, audio, particles, collision, and modifier scripts.
UCLASS(DisplayName="Ω Prop")
class OMEGAGAMEFRAMEWORK_API UOmegaProp_Preset : public UOmegaDataAsset, public IDataInterface_AppearanceSource
{
	GENERATED_BODY()

	void L_setBoundsFromComp(UBoxComponent* bounds, USceneComponent* comp,FBoxSphereBounds BoxBounds);
	void L_InitToSocket(USceneComponent* target, USceneComponent* socket_source,FName socket);

public:
	virtual UOAsset_Appearance* GetAppearanceAsset_Implementation() override;

	// When true, the prop's range box is automatically sized to match the mesh's world bounds.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop") bool SetRangeToMeshBounds=false;
	// When true, this prop's actor tick is enabled.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop") bool bCanTick=false;
	// Collision mode applied to the prop's mesh components when this preset is applied.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop")
	TEnumAsByte<ECollisionEnabled::Type> CollisionType=ECollisionEnabled::NoCollision;
	// Mobility setting applied to the prop's mesh components.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop")
	TEnumAsByte<EComponentMobility::Type> Mobility=EComponentMobility::Type::Static;

	// Scale transform applied to the range box when SetRangeToMeshBounds is enabled.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop")
	FTransform BoundsScale;

	// Script that assigns a static mesh and its material/collision settings to the prop.
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Prop")
	UComponentModScript_StaticMesh* StaticMesh;
	// Script that assigns a skeletal mesh and its animation settings to the prop.
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Prop")
	UComponentModScript_SkeletalMesh* SkeletalMesh;
	// Sound played on the prop's audio component when this preset is applied.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop")
	USoundBase* Audio;
	// Niagara particle system activated on the prop when this preset is applied.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop")
	UNiagaraSystem* Niagara;

	// A pre-made appearance asset applied to this prop for quick visual setup.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Appearance")
	UOAsset_Appearance* Appearance_Preset;
	// An inline custom appearance asset, used when no preset fits.
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Appearance")
	UOAsset_Appearance* Appearance_Custom;

	// Socket name on the mesh where the audio component is attached.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop",AdvancedDisplay) FName Audio_AttachSocket=TEXT("root_fx");
	// Socket name on the mesh where the Niagara component is attached.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop",AdvancedDisplay) FName Niagara_AttachSocket=TEXT("root_fx");

	// Modifier scripts applied to the prop actor during OnConstruction.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modifiers")
	TArray<UActorModifierScript*> Mods_Construct;
	// Modifier scripts applied to the prop actor at BeginPlay.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modifiers")
	TArray<UActorModifierScript*> Mods_BeginPlay;

	void Apply(AOmegaProp* prop);


	void aConstruct(AOmegaProp* a);
	void aBeginPlay(AOmegaProp* a);
};

// Implement on data assets to drive a prop actor's setup at construction and BeginPlay.
UINTERFACE(MinimalAPI, DisplayName="♎Data🔴 - 📦Prop") class UDataInterface_Prop : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_Prop
{
	GENERATED_BODY()
public:

	// Called during the prop's OnConstruction; return value is reserved for future use.
	UFUNCTION(BlueprintNativeEvent,Category="♎I|📦Prop",DisplayName="📦Prop - On Construct")
	int32 Prop_Construct(AOmegaProp* Actor);
	// Called at the prop's BeginPlay; return value is reserved for future use.
	UFUNCTION(BlueprintNativeEvent,Category="♎I|📦Prop",DisplayName="📦Prop - On BeginPlay")
	int32 Prop_BeginPlay(AOmegaProp* Actor);

};


// A world actor driven by UOmegaProp_Preset or IDataInterface_Prop, providing a mesh, audio, particle, and range box all in one place.
UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaProp : public AOmegaActorBASE, public IActorTagEventInterface, public IDataInterface_AppearanceSource
{
	GENERATED_BODY()

public:
	virtual UOAsset_Appearance* GetAppearanceAsset_Implementation() override;

	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

	AOmegaProp();

	// Components

	// Collision box for interaction and range detection.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UBoxComponent* RangeBox;
	// Static mesh visual component.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UStaticMeshComponent* MeshStatic;
	// Skeletal mesh visual component (for animated props).
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") USkeletalMeshComponent* MeshSkeletal;
	// Audio component for ambient or triggered sounds.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UAudioComponent* Audio;
	// Niagara particle component for ambient or triggered effects.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UNiagaraComponent* Niagara;

	// The data interface preset that configures this prop's mesh, audio, particles, and modifiers.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop") TScriptInterface<IDataInterface_Prop> Preset;


};
