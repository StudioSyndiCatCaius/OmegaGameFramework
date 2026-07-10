// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Component_Saveable.generated.h"

class UOmegaSaveCondition;
class UOmegaSaveBase;
class UOmegaSaveSubsystem;

// Allows the owning actor to persist its state (transform, tags, custom parameters) across saves via a unique entity GUID.
UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaSaveableComponent : public UActorComponent
{
	GENERATED_BODY()

	const int8 flag_SavPos=1;

	virtual void BeginPlay() override;
	UOmegaSaveableComponent();

	UOmegaSaveSubsystem* GetSaveSys() const;
	UOmegaSaveBase* GetSaveObj() const;

public:
	// Unique ID that links this actor to its entry in the save system. Change this to connect the actor to a different save record.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Saveable",AdvancedDisplay) FGuid EntityGuid;

	// Returns the entity data currently stored for this actor in the save system.
	UFUNCTION(BlueprintCallable,Category="Saveable") FOmegaEntity GetEntityData() const;
	// Directly overwrites the entity data for this actor in the save system.
	UFUNCTION(BlueprintCallable,Category="Saveable") void SetEntityData(FOmegaEntity data);

	// When true, data is written to the global save slot instead of the active level save.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Saveable",AdvancedDisplay) bool bSaveToGlobal;
	// When true, the actor's world transform is included when saving and loading.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Saveable") bool bSave_Transform;
	// When true, the actor's gameplay tags are included when saving and loading.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Saveable") bool bSave_ActorTags;

	// Captures the actor's current state and writes it into the save entity.
	UFUNCTION(BlueprintCallable,Category="Saveable|Param") void SaveToEntity();
	// Reads the save entity and restores the actor's state from it.
	UFUNCTION(BlueprintCallable,Category="Saveable|Param") void LoadFromEntity();

	// Gets a named boolean value previously stored in this actor's save entity.
	UFUNCTION(BlueprintPure,Category="Saveable|Param") bool GetSaveParam_Bool(FName Param) const;
	// Stores a named boolean value in this actor's save entity.
	UFUNCTION(BlueprintCallable,Category="Saveable|Param") void SetSaveParam_Bool(FName Param, bool Value);

	// Gets a named integer value previously stored in this actor's save entity.
	UFUNCTION(BlueprintPure,Category="Saveable|Param") int32 GetSaveParam_Int(FName Param) const;
	// Stores a named integer value in this actor's save entity.
	UFUNCTION(BlueprintCallable,Category="Saveable|Param") void SetSaveParam_Int(FName Param, int32 Value);
};
