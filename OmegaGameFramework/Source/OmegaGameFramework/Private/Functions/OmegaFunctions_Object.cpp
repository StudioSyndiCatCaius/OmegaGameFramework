// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Object.h"



UObject* UOmegaObjectFunctions::Duplicate_Object(UObject* object,UObject* NewOuter, UClass* Class)
{
	if(object && Class && NewOuter)
	{
		UObject* new_obj=DuplicateObject(object,NewOuter);
		if(new_obj && new_obj->GetClass()==Class)
		{
			return new_obj;
		}
	}
	return nullptr;
}

UObject* UOmegaObjectFunctions::RunSelector_Object(UObject* WorldContextObject, FOmegaSelect_Object Selector)
{
	if(WorldContextObject && Selector.Selector)
	{
		return Selector.Selector->GetSelected_Obj(WorldContextObject);
	}
	return nullptr;
}

UPrimaryDataAsset* UOmegaObjectFunctions::RunSelector_DataAsset(UObject* WorldContextObject,
	FOmegaSelect_DataAsset Selector)
{
	if(WorldContextObject && Selector.Selector)
	{
		return Selector.Selector->Get_DataAsset(WorldContextObject);
	}
	return nullptr;
}
