// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_ObjectTraits.h"



UOmegaObjectTrait* UOmegaObjectTraitsFunctions::TryGetObjectTrait(UObject* Object, TSubclassOf<UOmegaObjectTrait> Class,
                                                                  bool& result)
{
	for(auto* t : GetObjectTraits(Object))
	{
		if(t && t->GetClass()->IsChildOf(Class))
		{
			result=true;
			return t;
		}
	}
	result=false;
	return nullptr;
}

TArray<UOmegaObjectTrait*> UOmegaObjectTraitsFunctions::GetObjectTraits(UObject* Object)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_Traits::StaticClass()))
	{
		return IDataInterface_Traits::Execute_GetTraits(Object);
	}
	TArray<UOmegaObjectTrait*> nil;
	return nil;
}
