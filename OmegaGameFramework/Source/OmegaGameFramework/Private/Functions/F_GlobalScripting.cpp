// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_GlobalScripting.h"

#include "Kismet/KismetStringLibrary.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Subsystems/Subsystem_Engine.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Engine/Engine.h"

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

int32 UOmegaGlobalScript::Run_Implementation(UGameInstance* GameInstance) const
{
	return 0;
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

bool UOmegaGlobalCondition::Check_Implementation(UGameInstance* GameInstance) const
{
	return 0;
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
	OGF_GLOBALREFRESH();
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

int32 UOmegaGlobalScript_DoPreset::Run_Implementation(UGameInstance* GameInstance) const
{
	for (auto* p : Presets)
	{
		if (p)
		{
			UOmegaFunctions_GlobalScripting::RunGlobalScripts(GameInstance,p->Scripts);
		}
	}
	return 1;
}

bool UOmegaGlobalCondition_DoPreset::Check_Implementation(UGameInstance* GameInstance) const
{
	for (auto* p : Presets)
	{
		if (p && !UOmegaFunctions_GlobalScripting::RunGlobalConditions(GameInstance,p->Conditions))
		{
			return false;
		}
	}
	return true;
}
