// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/Interface.h"
#include "Misc/GeneralDataObject.h"
#include "Types/Struct_Appearance.h"
#include "Animation/AnimInstance.h"
#include "Component_Skin.generated.h"



class USkeletalMeshComponent;
class USkeletalMesh;

// Manages applying and assembling an AOmegaSkin onto the owning actor's skeletal mesh, including body appearance parameters.
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API USkinComponent : public UActorComponent
{
	GENERATED_BODY()

	USkinComponent();
	UPROPERTY() USkeletalMeshComponent* REF_SkelMesh;
	UPROPERTY() UChildActorComponent* REF_skinComponent;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void Deactivate() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	// The skin class to spawn and apply to this actor.
	UPROPERTY(EditAnywhere, Category="Omega")
	TSubclassOf<AOmegaSkin> Skin;

	UFUNCTION()
	void Update_Skin();

	// Links an external skeletal mesh and child actor component that this skin component will drive.
	UFUNCTION(BlueprintCallable,Category="Skin")
	void SetupLinkedComponents(USkeletalMeshComponent* SkeletalMesh, UChildActorComponent* ChildActor);

	// Sets only the child actor component link (use when you do not need to override the skeletal mesh).
	UFUNCTION(BlueprintCallable,Category="Skin")
	void SetLinkedChildActorComponent(UChildActorComponent* LinkedComp);

	// Spawns (or replaces) the skin of the given class and applies it to the linked mesh. Returns the new skin actor.
	UFUNCTION(BlueprintCallable, Category="Omega")
	AOmegaSkin* SetSkin(TSubclassOf<AOmegaSkin> SkinClass);
	// Returns the currently active skin actor, or null if none is applied.
	UFUNCTION(BlueprintPure,Category="Omega")
	AOmegaSkin* GetSkin() const;

	// Returns the skeletal mesh component this skin is targeting.
	UFUNCTION(BlueprintPure,Category="Omega|Skin")
	USkeletalMeshComponent* GetTargetMesh() const
	{
		if(REF_SkelMesh) { return REF_SkelMesh;} return nullptr;
	}

	// Builds and applies all skin mesh parts onto the target mesh. Pass OverrideMesh to redirect to a different mesh.
	UFUNCTION(BlueprintCallable, Category="Omega", meta=(AdvancedDisplay="Preset"))
	void Assemble(USkeletalMeshComponent* OverrideMesh=nullptr);

	UPROPERTY()
	TArray<USkeletalMeshComponent*> MeshComponents;

	// Current body appearance data (body type, parameters) applied to the skin.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Omega|Skin")
	FOmegaBodyAppearanceInfo Appearance;

	// Replaces the entire body appearance data set and rebuilds the skin.
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	void SetBodyAppearanceData(FOmegaBodyAppearanceInfo AppearanceData);

	// Sets the body type asset, which drives which meshes are used per body slot.
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	void SetBody_Type(UOmegaBodyType* BodyType);
	// Returns the current body type asset.
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	UOmegaBodyType* GetBody_Type() const;

	// Sets a vector parameter on the specified body slot (e.g. scale or offset).
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	void SetBodyParam_Vector(UOmegaBodySlot* Param, FVector Value);
	// Gets the vector parameter on the specified body slot.
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	FVector GetBodyParam_Vector(UOmegaBodySlot* Param);

	// Sets a boolean parameter on the specified body slot (e.g. toggle a part on/off).
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	void SetBodyParam_Bool(UOmegaBodySlot* Param, bool Value);
	// Gets the boolean parameter on the specified body slot.
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	bool GetBodyParam_Bool(UOmegaBodySlot* Param);

	// Sets an integer parameter on the specified body slot (e.g. a variant index).
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	void SetBodyParam_Int(UOmegaBodySlot* Param, int32 Value);
	// Gets the integer parameter on the specified body slot.
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	int32 GetBodyParam_Int(UOmegaBodySlot* Param);

	// Sets a float parameter on the specified body slot (e.g. a blend weight).
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	void SetBodyParam_Float(UOmegaBodySlot* Param, float Value);
	// Gets the float parameter on the specified body slot.
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	float GetBodyParam_Float(UOmegaBodySlot* Param);
};

// Abstract base for objects that apply post-process modifications to an assembled skin (e.g. material overrides).
UCLASS(Blueprintable,BlueprintType,CollapseCategories,EditInlineNew,Abstract)
class OMEGAGAMEFRAMEWORK_API USkinModifier : public UObject
{
	GENERATED_BODY()
public:
	// Creates a dynamic material instance for the named material slot on MeshComp, optionally applying it immediately.
	UFUNCTION(BlueprintCallable,Category="Omega|Skins")
	UMaterialInstanceDynamic* CreateDynamicMaterial_FromSlot(USkeletalMeshComponent* MeshComp, FName Slot, bool ApplyToComponent);

	// Override in Blueprint or C++ to apply this modifier's changes to the skin's mesh.
	UFUNCTION(BlueprintNativeEvent,Category="Omega|Skins")
	void ApplyModifier(AOmegaSkin* Skin, USkeletalMeshComponent* MeshComponent);
};

// A skin modifier that creates dynamic material instances on specified slots and lets Blueprint set parameters on them.
UCLASS()
class OMEGAGAMEFRAMEWORK_API USkinModifier_DynamicMaterial : public USkinModifier
{
	GENERATED_BODY()
public:

	// The material slot names on the mesh that this modifier will create dynamic instances for.
	UPROPERTY(EditAnywhere,Category="SkinModifier")
	TArray<FName> SlotsAppliedTo;

	virtual void ApplyModifier_Implementation(AOmegaSkin* Skin, USkeletalMeshComponent* MeshComponent) override;

	// Override in Blueprint to apply material parameter changes to the dynamic material created for each slot.
	UFUNCTION(BlueprintNativeEvent,Category="Omega|Skins")
	void ApplyModifierMaterial(AOmegaSkin* Skin, USkeletalMeshComponent* MeshComponent, UMaterialInstanceDynamic* Material);
};


// Blueprint function library for merging skeletal meshes at runtime.
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSkinFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	// Merges an array of skeletal meshes into a single mesh using BaseMesh as the skeleton reference.
	UFUNCTION(BlueprintCallable, Category="Omega", DisplayName="Merge Meshes (Omega)")
	static USkeletalMesh* MergeMeshes_Omega(TArray<USkeletalMesh*> Meshes, USkeletalMesh* BaseMesh);

	// Merges the meshes from an array of skeletal mesh components into a single mesh using BaseMesh as the skeleton reference.
	UFUNCTION(BlueprintCallable, Category="Omega", DisplayName="Merge Meshe Components (Omega)")
	static USkeletalMesh* MergeComponentMeshes_Omega(TArray<USkeletalMeshComponent*> Meshes, USkeletalMesh* BaseMesh);

	// Reads the skin class from SourceAsset (via IDataInterface_SkinSource) and applies it to the given SkinComponent.
	UFUNCTION(BlueprintCallable, Category="Omega")
	static void SetSkinFromAsset(USkinComponent* SkinComponent, UObject* SourceAsset);
};


// An actor spawned by USkinComponent that assembles and drives skeletal mesh parts for the owning character's appearance.
UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaSkin : public AActor
{
	GENERATED_BODY()
	AOmegaSkin();

public:
	UPROPERTY() USkinComponent* owning_component;
	virtual void OnConstruction(const FTransform& Transform) override;

	// Called in Blueprint once all skin meshes have been assembled and applied.
	UFUNCTION(BlueprintImplementableEvent,Category="Skin")
	void OnSkinBuildFinished();

	// When true, the skin applies a single mesh with material overrides to the owner's mesh, then destroys itself.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skin")
	bool bIsCompressedSkin;

	// The primary skeleton mesh used for full (non-compressed) skins.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skin",meta=(EditCondition="!bIsCompressedSkin"))
	USkeletalMesh* MasterSkeleton;

	// Optional material applied on top of the master skeleton mesh.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skin",meta=(EditCondition="!bIsCompressedSkin"))
	UMaterialInterface* MasterSkeletonOverrideMaterial;

	// Animation blueprint class to apply to the assembled skin mesh.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skin")
	TSubclassOf<UAnimInstance> AnimationClass;

	// When true, all mesh components in this skin are merged into a single mesh at build time.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skin")
	bool bMerge;

	// When true, this skin's mesh components follow the owner's master mesh component transform each frame.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skin")
	bool bForceFollowMasterComponent;

	// When true, the owning actor's base mesh is hidden after the skin is applied.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skin")
	bool bHideBaseMesh;

	// List of modifier objects applied after the skin meshes are assembled (e.g. for dynamic material setup).
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Skin")
	TArray<USkinModifier*> SkinModifiers;

private:
	void TrySetAnimation(USkeletalMeshComponent* TargetMesh);
	UFUNCTION() void local_applyModifiers(USkeletalMeshComponent* MeshComp);
public:
	// Returns the single mesh component used when this is a compressed skin. Override in Blueprint to point to the correct component.
	UFUNCTION(BlueprintNativeEvent, Category="Omega")
	USkeletalMeshComponent* GetCompressedMeshComponent();

	// Returns the list of mesh components to merge when bMerge is true. Override in Blueprint to supply the correct set.
	UFUNCTION(BlueprintNativeEvent, Category="Omega")
	TArray<USkeletalMeshComponent*> GetMeshMergeComponents();

	// Returns the mesh component assigned to the given gameplay tag slot. Override in Blueprint to map slots to components.
	UFUNCTION(BlueprintNativeEvent, Category="Omega")
	USkeletalMeshComponent* GetMeshComponentBySlot(FGameplayTag Slot);

	// Assembles all mesh components defined by this skin and applies them to the linked character.
	UFUNCTION(BlueprintCallable,Category="Omega")
	void BuildSkin();
};

// Implement on data assets or objects that can provide a skin class and optional list of skin modifiers.
UINTERFACE(MinimalAPI, DisplayName="♎Data🔴 - Skin Source") class UDataInterface_SkinSource : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_SkinSource
{
	GENERATED_BODY()

public:

	// Returns the skin class this object wants to apply to a character.
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="Omega|Skin")
	TSubclassOf<AOmegaSkin> GetSkinClass();

	// Returns additional skin modifiers this object wants to layer on top of the skin.
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="Omega|Skin")
	TArray<USkinModifier*> GetSkinModifiers();
};
