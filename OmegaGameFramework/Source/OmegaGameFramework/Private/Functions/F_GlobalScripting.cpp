// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_GlobalScripting.h"

#include "Kismet/KismetStringLibrary.h"
#include "Subsystems/Subsystem_GameManager.h"

FString UOmegaGlobalScriptBASE::GetFunctionCall_Name() const
{
	return UKismetStringLibrary::Replace(GetClass()->GetName(),"_C","");
}

FString UOmegaGlobalScriptBASE::GetFunctionCall_Description() const
{
	FString _ovr;
	TArray<FString> _argStr;
	GetEditorDescription(_argStr,_ovr);
	if (!_ovr.IsEmpty()) { return _ovr; }
	FString join_args=UKismetStringLibrary::JoinStringArray(_argStr,", ");
	FString out=GetFunctionCall_Name()+" ("+join_args+")";
	return out;
}

FLuaValue UOmegaGlobalScript::LuaCall(const TArray<FLuaValue>& args)
{
	LuaInterpret(args);
	if (UOmegaSubsystem_GameInstance* s=Cast<UOmegaSubsystem_GameInstance>(GetOuter()))
	{
		return FLuaValue(Run(s->GetGameInstance()));
	}
	return FLuaValue();
}

FLuaValue UOmegaGlobalCondition::LuaCall(const TArray<FLuaValue>& args)
{
	LuaInterpret(args);
	if (UOmegaSubsystem_GameInstance* s=Cast<UOmegaSubsystem_GameInstance>(GetOuter()))
	{
		return FLuaValue(Check(s->GetGameInstance()));
	}
	return FLuaValue();
}

void UOmegaFunctions_GlobalScripting::RunGlobalScripts(UObject* WorldContextObject, FOmegaGlobalScripts scripts)
{
	if (WorldContextObject && WorldContextObject->GetWorld() && WorldContextObject->GetWorld()->GetGameInstance())
	{
		for (UOmegaGlobalScript* s : scripts.Scripts)
		{
			if (s)
			{
				s->Run(WorldContextObject->GetWorld()->GetGameInstance());
			}
		}
	}
}

bool UOmegaFunctions_GlobalScripting::RunGlobalConditions(const UObject* WorldContextObject, FOmegaGlobalConditions scripts)
{
	if (WorldContextObject && WorldContextObject->GetWorld() && WorldContextObject->GetWorld()->GetGameInstance())
	{
		for (UOmegaGlobalCondition* s : scripts.Conditions)
		{
			if (s)
			{
				if (!s->Check(WorldContextObject->GetWorld()->GetGameInstance()))
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}
