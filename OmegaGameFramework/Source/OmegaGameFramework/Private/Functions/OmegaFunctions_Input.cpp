// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Input.h"

UObject* UOmegaInputFunctions::GetFirstObjectWithContextInputKey(TArray<UObject*> Objects, FKey Key, TEnumAsByte<EOmegaFunctionResult>& Outcome,
	FGameplayTag ContextTag)
{
	for(auto* temp_obj: Objects)
	{
		if(temp_obj
			&& temp_obj->GetClass()->ImplementsInterface(UDataInterface_Input::StaticClass())
			&& IDataInterface_Input::Execute_GetContext_InputKey(temp_obj,ContextTag)==Key)
		{
			Outcome=Success;
			return temp_obj;
		}
	}
	Outcome=Fail;
	return nullptr;
}
