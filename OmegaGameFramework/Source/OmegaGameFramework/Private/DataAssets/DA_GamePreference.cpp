// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "DataAssets/DA_GamePreference.h"

#include "Components/ComboBoxString.h"
#include "Functions/F_Preferences.h"
#include "Subsystems/Subsystem_Save.h"




FVector UGamePreference::L_GetValue(const UOmegaSubsystem_GameInstance* subsys, UOmegaSaveBase* save)
{
	if (PreferenceScript)
	{
		return PreferenceScript->GetCurrentValue(subsys,save,this);
	}
	return FVector();
}

void UGamePreference::L_SetValue(const UOmegaSubsystem_GameInstance* subsys, UOmegaSaveBase* save, FVector _Value)
{
	if (PreferenceScript)
	{
		PreferenceScript->OnPreferenceValueUpdated(subsys,save,this,_Value);
	}
	save->PreferenceValues.Add(this,_Value);
}

void UGamePreference::Configure_ComboBox(UObject* WorldContextObject, UComboBoxString* Widget)
{
	if (Widget && WorldContextObject)
	{
		Widget->ClearOptions();
		for (FString opt : GetPreferenceStringOptions())
		{
			Widget->AddOption(opt);
		}
		Widget->SetSelectedOption(UOmegaFunctions_Preferences::String_Get(WorldContextObject,this));
		Widget->RefreshOptions();
	}
}

EGamePreferenceType UGamePreference::GetPreferenceType() const
{
	if(PreferenceScript)
	{
		return PreferenceScript->GetPreferenceType();
	}
	return EGamePreferenceType::PrefType_Bool;
}

TArray<FString> UGamePreference::GetPreferenceStringOptions() const
{
	TArray<FString> out;
	if(PreferenceScript) { out=PreferenceScript->GetValueStringOptions();}
	return out;
}

void UGamePreferenceScript::OnPreferenceValueUpdated_Implementation(const UOmegaSubsystem_GameInstance* subsys,
	UOmegaSaveBase* save, UGamePreference* Preference, FVector Value) const
{
	save->PreferenceValues.Add(Preference,Value);
}

FVector UGamePreferenceScript::GetCurrentValue_Implementation(const UOmegaSubsystem_GameInstance* subsystem, UOmegaSaveBase* save, UGamePreference* Preference) const
{
	if (subsystem)
	{
		if (!save->PreferenceValues.Contains(Preference))
		{
			save->PreferenceValues.Add(Preference,GetDefaultValue());
		}
		return save->PreferenceValues[Preference];
	}
	return GetDefaultValue();
}

