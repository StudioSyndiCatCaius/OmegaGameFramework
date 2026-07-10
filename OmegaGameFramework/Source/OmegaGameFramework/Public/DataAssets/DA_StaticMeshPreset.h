// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/I_ActorPreset.h"
#include "Misc/GeneralDataObject.h"
#include "DA_StaticMeshPreset.generated.h"


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaStaticMeshPreset : public UOmegaMinimalDataAsset, public IDataInterface_ActorPreset
{
	GENERATED_BODY()
	
public:
	
	virtual void ActorPreset_GetConfig_Implementation(TSubclassOf<AActor>& ActorClass, bool& bPreviewActor, bool& bAllowWorldDrop, bool& bPreviewThumbnailFromActor) override;
	virtual bool ActorPreset_PreviewConstruct_Implementation(AActor* Actor) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh") UStaticMesh* StaticMesh;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh") FVector Scale=FVector::One();
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh") TArray<UMaterialInterface*> Materials_ByIndex;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh") TMap<FName,UMaterialInterface*> Materials_BySlot;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh") TEnumAsByte<ECollisionChannel> CollisionChannel = ECC_WorldStatic;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh") bool bHiddenInGame;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh") TArray<FName> ActorTags;
	
};
