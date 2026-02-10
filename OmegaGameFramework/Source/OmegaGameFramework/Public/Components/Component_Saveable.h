// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Component_Saveable.generated.h"

class UOmegaSaveCondition;
class UOmegaSaveBase;
class UOmegaSaveSubsystem;

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
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Saveable",AdvancedDisplay) FGuid EntityGuid;
	
	UFUNCTION(BlueprintCallable,Category="Saveable") FOmegaEntity GetEntityData() const;
	UFUNCTION(BlueprintCallable,Category="Saveable") void SetEntityData(FOmegaEntity data);

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Saveable",AdvancedDisplay) bool bSaveToGlobal;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Saveable") bool bSave_Transform;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Saveable") bool bSave_ActorTags;
	
	//Save conditions required for this actor to be visible. If blank, will always be visible.
	//UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Saveable") TArray<UOmegaSaveCondition*> Conditions_Visible;

	//o
	UFUNCTION(BlueprintCallable,Category="Saveable|Param") void SaveToEntity();
	UFUNCTION(BlueprintCallable,Category="Saveable|Param") void LoadFromEntity();
	
	UFUNCTION(BlueprintPure,Category="Saveable|Param") bool GetSaveParam_Bool(FName Param) const;
	UFUNCTION(BlueprintCallable,Category="Saveable|Param") void SetSaveParam_Bool(FName Param, bool Value);
	
	UFUNCTION(BlueprintPure,Category="Saveable|Param") int32 GetSaveParam_Int(FName Param) const;
	UFUNCTION(BlueprintCallable,Category="Saveable|Param") void SetSaveParam_Int(FName Param, int32 Value);
};
