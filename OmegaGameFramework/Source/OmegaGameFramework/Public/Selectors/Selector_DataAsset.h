// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Selector_Object.h"
#include "Misc/GeneralDataObject.h"
#include "Selector_DataAsset.generated.h"


UCLASS(Abstract,CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaSelector_DataAsset : public UOmegaInstancableObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintNativeEvent,Category="Selector")
	UPrimaryDataAsset* Get_DataAsset(const UObject* Context) const ;
};

inline UPrimaryDataAsset* UOmegaSelector_DataAsset::Get_DataAsset_Implementation(const UObject* Context) const
{
	return nullptr;
}


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSelector_DataAsset_Literal : public UOmegaSelector_DataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere,Category="DataAsset") UPrimaryDataAsset* DataAsset;
	virtual UPrimaryDataAsset* Get_DataAsset_Implementation(const UObject* Context) const override { return DataAsset; };
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSelector_Object_DataAsset : public UOmegaSelector_Object
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere,Instanced,Category="DataAsset") UOmegaSelector_DataAsset* DataAsset;
	virtual UObject* GetSelected_Obj_Implementation(const UObject* Context) const override { return DataAsset->Get_DataAsset(Context); };
};



USTRUCT(BlueprintType)
struct FOmegaSelect_DataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced,Category="Selector")
	UOmegaSelector_DataAsset* Selector=nullptr;
	
};


