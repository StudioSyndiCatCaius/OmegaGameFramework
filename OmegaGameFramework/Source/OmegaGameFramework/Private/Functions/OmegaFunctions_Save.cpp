// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Save.h"

#include "Subsystems/OmegaSubsystem_Save.h"

UOmegaSaveBase* _getSaveObj(const UObject* context,bool bGlobal)
{
	if(context) 
	{
		return context->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->GetSaveObject(bGlobal);
	}
	return nullptr;
}

void UOmegaSaveFunctions::SetSaveParam_Tag_Int(const UObject* WorldContextObject, FGameplayTag Param, int32 Value, bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getSaveObj(WorldContextObject,bGlobal))
	{
		_sav->TagVars_int.Add(Param,Value);
	}
}

void UOmegaSaveFunctions::SetSaveParam_Tag_Bool(const UObject* WorldContextObject, FGameplayTag Param, bool Value, bool bGlobal)
{
	if (Value)
	{
		SetSaveParam_Tag_Int(WorldContextObject,Param,1,bGlobal);
	}
	else
	{
		SetSaveParam_Tag_Int(WorldContextObject,Param,0,bGlobal);
	}
}

int32 UOmegaSaveFunctions::GetSaveParam_Tag_Int(const UObject* WorldContextObject, FGameplayTag Param, bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getSaveObj(WorldContextObject,bGlobal))
	{
		return _sav->TagVars_int.FindOrAdd(Param);
	}
	return 0;
}

bool UOmegaSaveFunctions::GetSaveParam_Tag_Bool(const UObject* WorldContextObject, FGameplayTag Param, bool bGlobal)
{
	return static_cast<bool>(GetSaveParam_Tag_Int(WorldContextObject,Param,bGlobal));
}

bool UOmegaSaveFunctions::CheckSaveParam_Tag_Bool(const UObject* WorldContextObject, FGameplayTag Param, bool bGlobal,
                                                  TEnumAsByte<EOmegaBranch>& Outcome)
{
	bool _out=GetSaveParam_Tag_Bool(WorldContextObject,Param,bGlobal);
	if(_out){ Outcome=No; } else { Outcome=Yes; }
	return _out;
}

int32 UOmegaSaveFunctions::CheckSaveParam_Tag_Int(const UObject* WorldContextObject, FGameplayTag Param,
	int32 CheckValue, bool bGlobal, TEnumAsByte<EOmegaComparisonMethodSimple>& Outcome)
{
	int32 _out=GetSaveParam_Tag_Int(WorldContextObject,Param,bGlobal);

	if(_out<CheckValue) { Outcome=IsLess; }
	else if(_out==CheckValue) { Outcome=IsEqual; }
	else if(_out>CheckValue) { Outcome=IsGreater; }
	
	return _out;
}
