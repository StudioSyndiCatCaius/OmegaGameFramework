// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Preferences.h"


#include "DataAssets/DA_GamePreference.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Subsystems/Subsystem_Save.h"


void UOmegaPreferencePreset::Apply(UObject* WorldContextObject) const
{
	
}

bool UOmegaFunctions_Preferences::Bool_Get(const UObject* WorldContextObject, UGamePreference* Preference)
{
	if (UOmegaSubsystem_GameInstance* m=OGF_Subsystems::oGameInstance(WorldContextObject))
	{
		if (UKismetMathLibrary::FTrunc(m->Pref_Get(Preference).X)>0)
		{
			return true;
		}
	}
	return false;
}

void UOmegaFunctions_Preferences::Bool_Set(const UObject* WorldContextObject, UGamePreference* Preference, bool Value)
{
	if (UOmegaSubsystem_GameInstance* m=OGF_Subsystems::oGameInstance(WorldContextObject))
	{
		float in_val=0;
		if (Value) { in_val=1;}
		m->Pref_Set(Preference,FVector(in_val,0,0));
	}
}

int32 UOmegaFunctions_Preferences::Int_Get(const UObject* WorldContextObject, UGamePreference* Preference)
{
	if (UOmegaSubsystem_GameInstance* m=OGF_Subsystems::oGameInstance(WorldContextObject))
	{
		return UKismetMathLibrary::Round(m->Pref_Get(Preference).X);
	}
	return 0;
}

void UOmegaFunctions_Preferences::Int_Set(const UObject* WorldContextObject, UGamePreference* Preference, int32 Value)
{
	if (UOmegaSubsystem_GameInstance* m=OGF_Subsystems::oGameInstance(WorldContextObject))
	{
		m->Pref_Set(Preference,FVector(Value,0,0));
	}
}

float UOmegaFunctions_Preferences::Float_Get(const UObject* WorldContextObject, UGamePreference* Preference)
{
	if (UOmegaSubsystem_GameInstance* m=OGF_Subsystems::oGameInstance(WorldContextObject))
	{
		return m->Pref_Get(Preference).X;
	}
	return 0;
}

void UOmegaFunctions_Preferences::Float_Set(const UObject* WorldContextObject, UGamePreference* Preference, float Value)
{
	if (UOmegaSubsystem_GameInstance* m=OGF_Subsystems::oGameInstance(WorldContextObject))
	{
		m->Pref_Set(Preference,FVector(Value,0,0));
	}
}

FString UOmegaFunctions_Preferences::String_Get(const UObject* WorldContextObject, UGamePreference* Preference)
{
	if (WorldContextObject && Preference)
	{
		int32 out=Int_Get(WorldContextObject,Preference);
		if (Preference->GetPreferenceStringOptions().IsValidIndex(out))
		{
			return Preference->GetPreferenceStringOptions()[out];
		}
	}
	return FString();
}

void UOmegaFunctions_Preferences::String_Set(const UObject* WorldContextObject, UGamePreference* Preference,
	FString Value)
{
	if (WorldContextObject && Preference)
	{
		if (Preference->GetPreferenceStringOptions().Contains(Value))
		{
			int32 out=Preference->GetPreferenceStringOptions().Find(Value);
			Int_Set(WorldContextObject,Preference,out);
		}
	}
}

bool UOmegaFunctions_Preferences::Check_Bool(const UObject* WorldContextObject, UGamePreference* Preference, bool& Outcome)
{
	if(WorldContextObject && Preference)
	{
		Outcome=true;
		return Bool_Get(WorldContextObject,Preference);
	}
	Outcome=false;
	return false;
}

int32 UOmegaFunctions_Preferences::Check_Int(const UObject* WorldContextObject,
	UGamePreference* Preference, int32 CheckValue, TEnumAsByte<EOmegaComparisonMethodSimple>& Outcome)
{
	int32 out=0;
	if(WorldContextObject && Preference)
	{
		out=Int_Get(WorldContextObject,Preference);
	}
	if(out<CheckValue) { Outcome=IsLess; }
	else if(out==CheckValue) { Outcome=IsEqual; }
	else if(out>CheckValue) { Outcome=IsGreater; }
	return out;
}

void UOmegaFunctions_Preferences::ApplyPreset(const UObject* WorldContextObject, UOmegaPreferencePreset* Preset)
{
	if (WorldContextObject)
	{
		UOmegaSaveSubsystem* m=OGF_Subsystems::oSave(WorldContextObject);
		if (Preset)
		{
			
			if (Preset->BaseScalabilityQuality>=0)
			{
				Scalability::FQualityLevels lv;
				lv.SetFromSingleQualityLevel(Preset->BaseScalabilityQuality);
				Scalability::SetQualityLevels(lv);
			}
			
			TArray<FString> cmd_list;
			Preset->CommandList.ParseIntoArray(cmd_list, TEXT("\n"));
			for (FString cmd : cmd_list)
			{
				WorldContextObject->GetWorld()->Exec(WorldContextObject->GetWorld(),*cmd);
			}
			TArray<UGamePreference*> Prefs;
			Preset->PreferencesPresets.GetKeys(Prefs);
			for (UGamePreference* pref : Prefs)
			{
				if (pref)
				{
					Int_Set(WorldContextObject,pref,Preset->PreferencesPresets[pref]);
				}
			}
		}
		else
		{

		}
	}
}

