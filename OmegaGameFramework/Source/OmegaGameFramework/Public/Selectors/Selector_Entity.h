// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/GeneralDataObject.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Selector_Entity.generated.h"

class UOmegaSaveSubsystem;


UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaEntity_Linker : public UOmegaInstancableObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintImplementableEvent,Category="Selector")
	FOmegaEntity GetEntityData(UOmegaSaveSubsystem* Subsystem) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Selector")
	void SetEntityData(UOmegaSaveSubsystem* Subsystem,FOmegaEntity Data) const;
};


USTRUCT(BlueprintType)
struct FOmegaEntity_LinkerData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="Entity") UOmegaEntity_Linker* Linker;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Entity") FName Default_Dataset;

	void Set_Dataset(UOmegaSaveSubsystem* sys, const FOmegaEntityDataset& dataset) const
	{
		if(Linker)
		{
			FOmegaEntity E=Linker->GetEntityData(sys);
			E.Dataset_Set(Default_Dataset,dataset);
			Linker->SetEntityData(sys,E);
		}
	}
	FOmegaEntityDataset Get_Dataset(UOmegaSaveSubsystem* sys) const
	{
		if(Linker)
		{
			FOmegaEntity E=Linker->GetEntityData(sys);
			return E.Dataset_Get(Default_Dataset);
		}
		return FOmegaEntityDataset();
	}
};
