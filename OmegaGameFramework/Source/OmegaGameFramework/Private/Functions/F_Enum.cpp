// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Enum.h"


DEFINE_FUNCTION(UOmegaFunctions_Enum::execGetEnumValueDescription)
{
	Stack.MostRecentPropertyAddress = nullptr;
	Stack.MostRecentProperty = nullptr;
	Stack.StepCompiledIn<FProperty>(nullptr);  // Step as generic FProperty, not FEnumProperty

	void* ValueAddr = Stack.MostRecentPropertyAddress;
	FProperty* Prop = Stack.MostRecentProperty;

	P_FINISH;
	P_NATIVE_BEGIN;

	UEnum* Enum = nullptr;
	int64 RawValue = 0;

	if (FEnumProperty* EnumProp = CastField<FEnumProperty>(Prop))
	{
		// C++ native enums (non-uint8 underlying type)
		Enum = EnumProp->GetEnum();
		RawValue = EnumProp->GetUnderlyingProperty()->GetSignedIntPropertyValue(ValueAddr);
	}
	else if (FByteProperty* ByteProp = CastField<FByteProperty>(Prop))
	{
		// Blueprint enums and C++ UENUM(uint8) enums come through here
		Enum = ByteProp->Enum;
		RawValue = (int64)ByteProp->GetPropertyValue(ValueAddr);
	}

	if (Enum && ValueAddr)
	{
#if WITH_EDITOR
		const int32 Index = Enum->GetIndexByValue(RawValue);
		*static_cast<FText*>(RESULT_PARAM) = (Index != INDEX_NONE)
			? Enum->GetToolTipTextByIndex(Index)
			: FText::GetEmpty();
#endif
		
	}
	else
	{
		*static_cast<FText*>(RESULT_PARAM) = FText::GetEmpty();
	}

	P_NATIVE_END;
}