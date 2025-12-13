// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Selector_Object.h"
#include "Misc/GeneralDataObject.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Selector_Entity.generated.h"

class UOmegaSaveSubsystem;


UCLASS(Abstract,NotBlueprintable)
class OMEGAGAMEFRAMEWORK_API UOmegaSelector_Entity : public UOmegaSelector_Object
{
	GENERATED_BODY()
	
public:
	virtual FOmegaEntity GetEntityData(UOmegaSaveSubsystem* Subsystem) const;
	virtual void SetEntityData(UOmegaSaveSubsystem* Subsystem,FOmegaEntity Data) const;
};

inline FOmegaEntity UOmegaSelector_Entity::GetEntityData(UOmegaSaveSubsystem* Subsystem) const
{
	return FOmegaEntity();
}

inline void UOmegaSelector_Entity::SetEntityData(UOmegaSaveSubsystem* Subsystem, FOmegaEntity Data) const
{
}


UCLASS(DisplayName="(Entity) Data Asset")
class OMEGAGAMEFRAMEWORK_API UOmegaSelector_Entity_Asset : public UOmegaSelector_Entity
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Default") UPrimaryDataAsset* Key;
};

UCLASS(DisplayName="(Entity) Guid")
class OMEGAGAMEFRAMEWORK_API UOmegaSelector_Entity_Guid : public UOmegaSelector_Entity
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Default") FGuid Key;
};

UCLASS(DisplayName="(Entity) Name")
class OMEGAGAMEFRAMEWORK_API UOmegaSelector_Entity_Name : public UOmegaSelector_Entity
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Default") FName Key;
};