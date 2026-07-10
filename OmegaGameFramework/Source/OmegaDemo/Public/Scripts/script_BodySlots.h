#pragma once

#include "DataAssets/DA_Body.h"
#include "Functions/F_Component.h"
#include "Materials/MaterialInterface.h"
#include "script_BodySlots.generated.h"

// ---------------------------------------------------------------------------------------------------------
// Skel Mesh Array
// ---------------------------------------------------------------------------------------------------------

UCLASS(DisplayName="(🧍 Body Slot) Skeletal Mesh from Array")
class OMEGADEMO_API UBodySlotScript_SkelMeshFromArray : public UOmegaBodySlotScript
{
	GENERATED_BODY()
public:
	
	virtual USkeletalMesh* GetMeshFromIndex_Implementation(FOmegaBodyOptionValue OptionValue) const override;
	virtual FVector GetMaxValue_Implementation() const override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mod") TArray<TSoftObjectPtr<USkeletalMesh>> Meshes;
};


// ---------------------------------------------------------------------------------------------------------
// Material
// ---------------------------------------------------------------------------------------------------------

UCLASS(DisplayName="(🧍 Body Slot) Material from Array")
class OMEGADEMO_API UBodySlotScript_MaterialFromArray : public UOmegaBodySlotScript
{
	GENERATED_BODY()
public:
	
	virtual void OnApplied_ToMeshComponent_Implementation(USkeletalMeshComponent* Component, FOmegaBodyOptionValue OptionValue) const override;
	virtual FVector GetMaxValue_Implementation() const override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mod") FName MaterialSlot;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mod") TArray<TSoftObjectPtr<UMaterialInterface>> Materials;
};
