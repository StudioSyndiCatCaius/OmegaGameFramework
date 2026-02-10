// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/GeneralDataObject.h"
#include "Selector_Object.generated.h"


UCLASS(Abstract,CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaSelector_Object : public UOmegaInstancableObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintNativeEvent,Category="Selector")
	UObject* GetSelected_Obj(const UObject* Context) const;
};

inline UObject* UOmegaSelector_Object::GetSelected_Obj_Implementation(const UObject* Context) const
{
	return  nullptr;
}


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSelector_Object_Literal : public UOmegaSelector_Object
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere,Category="DataAsset") UObject* Object;
	virtual UObject* GetSelected_Obj_Implementation(const UObject* Context) const override { return Object; };
};



USTRUCT(BlueprintType)
struct FOmegaSelect_Object
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced,Category="Selector")
	UOmegaSelector_Object* Selector=nullptr;
	
};


