// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_ObjectTraits.h"



UOmegaObjectTrait* UOmegaObjectTraitsFunctions::TryGetObjectTrait(UObject* Object, TSubclassOf<UOmegaObjectTrait> Class,FName TraitName,bool FallbackToDefault,
                                                                  bool& result)
{
	if(Class)
	{
		for(auto* t : GetObjectTraits(Object))
		{
			if(t && t->GetClass()->IsChildOf(Class) && (!TraitName.IsValid() || t->Label==TraitName))
			{
				result=true;
				return t;
			}
		}
		if(FallbackToDefault)
		{
			return Class.GetDefaultObject();
		}
	}
	result=false;
	return nullptr;
}

TArray<UOmegaObjectTrait*> UOmegaObjectTraitsFunctions::GetObjectTraits(UObject* Object)
{
	TArray<UOmegaObjectTrait*> out;
	if(Object)
	{
		if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_Traits::StaticClass()))
		{
			out.Append(IDataInterface_Traits::Execute_GetTraits(Object));
		}
		
	}
	return out;
}
