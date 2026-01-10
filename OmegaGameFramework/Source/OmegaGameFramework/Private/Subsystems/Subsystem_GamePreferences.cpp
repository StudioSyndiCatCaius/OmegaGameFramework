// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Subsystems/Subsystem_GamePreferences.h"
#include "Subsystems/Subsystem_Save.h"

#include "Functions/F_Common.h"
#include "OmegaSettings.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/GameInstance.h"
#include "GameFramework/GameUserSettings.h"


void UGamePreferenceSubsystem::PreloadPrefs()
{
	const FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	TArray<FAssetData> AssetData;
	FARFilter Filter;
	Filter.ClassPaths.Add(UGamePreference::StaticClass()->GetClassPathName());
	
	for(const FDirectoryPath& NewPath : GetMutableDefault<UOmegaSettings>()->Preferences_ScanPaths)
	{
		//FString LocalString = NewPath.Path;
		Filter.PackagePaths.Add(FName(*NewPath.Path));
	}
	Filter.PackagePaths.Add(TEXT("/OmegaGameFramework/DEMO/Preferences/"));
	
	Filter.bRecursiveClasses = true;
	Filter.bRecursivePaths = true;
	AssetRegistryModule.Get().GetAssets(Filter, AssetData);

	for(FAssetData TempAssetData : AssetData)
	{
		if(Cast<UGamePreference>(TempAssetData.GetAsset()))
		{
			PreloadedPreferences.AddUnique(Cast<UGamePreference>(TempAssetData.GetAsset()));
		}
	}
	
	Local_PreferenceUpdateAll();
}

void UGamePreferenceSubsystem::local_SetPref(UGamePreference* Preference, FVector value)
{
	if(Preference)
	{
		if(!Preference->PreferenceLabel.IsEmpty() && Preference->PreferenceScript && Preference->bSaveToConfig)
		{
			
			FString in_label=Preference->PreferenceLabel;
			FString in_section=Preference->PreferenceCategory.ToString();
			
			FConfigCacheIni::NormalizeConfigIniPath(ConfigFilePath);
			
			switch (Preference->PreferenceScript->GetPreferenceType()) {
			case EGamePreferenceType::PrefType_Bool:
				GConfig->SetBool(*in_section,*in_label,static_cast<bool>(value.X),ConfigFilePath);
				break;
			case EGamePreferenceType::PrefType_Float:
				GConfig->SetFloat(*in_section,*in_label,value.X,ConfigFilePath);
				break;
			case EGamePreferenceType::PrefType_Int:
				GConfig->SetInt(*in_section,*in_label,static_cast<int32>(value.X),ConfigFilePath);
				break;
			}

			GConfig->Flush(false, ConfigFilePath);
		}
		else
		{
			GetSaveSubsystem()->GetSaveObject(Preference->bGlobal)->PreferenceValues.Add(Preference,value);
			if(Preference->PreferenceScript)
			{
				Preference->PreferenceScript->OnPreferenceValueUpdated(UGameUserSettings::GetGameUserSettings(), value);
			}
		}
		OnPreferenceUpdated.Broadcast(Preference,value);
	}
}

FVector UGamePreferenceSubsystem::local_GetPref(UGamePreference* Preference)
{
	if(Preference)
	{
		UOmegaSaveBase* save_obj = GetSaveSubsystem()->GetSaveObject(Preference->bGlobal);
		FVector out;

		// FIRST: Try get from config file
        if(Preference->PreferenceScript && Preference->bSaveToConfig)
        {
        	FString in_label=Preference->PreferenceLabel;
        	FString in_section=Preference->PreferenceCategory.ToString();
 
        	FString dump_val;
        	if(GConfig->GetValue(*in_section,*in_label,dump_val,ConfigFilePath))
        	{
        		switch (Preference->PreferenceScript->GetPreferenceType()) {
        		case EGamePreferenceType::PrefType_Bool:
        			bool temp_bool;
        			GConfig->GetBool(*in_section,*in_label,temp_bool,ConfigFilePath);
        			out.X=static_cast<float>(temp_bool);
        			break;
        		case EGamePreferenceType::PrefType_Float:
        			float temp_float;
        			GConfig->GetFloat(*in_section,*in_label,temp_float,ConfigFilePath);
        			out.X=temp_float;
        			break;
        		case EGamePreferenceType::PrefType_Int:
        			int32 temp_int;
        			GConfig->GetInt(*in_section,*in_label,temp_int,ConfigFilePath);
        			out.X=static_cast<float>(temp_int);
        			break;
        		}
        	}
        }
		// SECOND: Try get from save object
        else if(save_obj->PreferenceValues.Contains(Preference))
        {
        	out=save_obj->PreferenceValues[Preference];
        }
		// THIRD: Get default value
		else if(Preference->PreferenceScript)
		{
			out=Preference->PreferenceScript->GetDefaultValue();
		}

		if(Preference->PreferenceScript)
		{
			return Preference->PreferenceScript->GetCurrentValue(out);
		}
		return out;
	}
	return FVector();
}

void UGamePreferenceSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	GConfig->LoadFile(ConfigFilePath);
	PreloadPrefs();
	
	Super::OnWorldBeginPlay(InWorld);
}

void UGamePreferenceSubsystem::Initialize(FSubsystemCollectionBase& Colection)
{
	//-- maybe remove this?
}



TArray<UGamePreference*> UGamePreferenceSubsystem::GetAllGamePreferences()
{
	return PreloadedPreferences;
}

UOmegaSaveSubsystem* UGamePreferenceSubsystem::GetSaveSubsystem()
{
	return UGameplayStatics::GetGameInstance(this)->GetSubsystem<UOmegaSaveSubsystem>();
}

void UGamePreferenceSubsystem::Local_PreferenceUpdate(UGamePreference* Preference)
{
	if(Preference && Preference->PreferenceScript)
	{
		Preference->PreferenceScript->OnPreferenceValueUpdated(UGameUserSettings::GetGameUserSettings(), local_GetPref(Preference));
	}
}

void UGamePreferenceSubsystem::Local_PreferenceUpdateAll()
{
	 for(auto* TempPref : PreloadedPreferences)
	 {
		 Local_PreferenceUpdate(TempPref);
	 }
}
//BOOL////////////////////////
bool UGamePreferenceSubsystem::GetGamePreferenceBool(UGamePreference* Preference)
{
	if(!Preference) { return false; }
	return static_cast<bool>(local_GetPref(Preference).X);
}

void UGamePreferenceSubsystem::SetGamePreferenceBool(UGamePreference* Preference, bool bValue)
{
	if(Preference)
	{
		FVector new_val;
		new_val.X = static_cast<float>(bValue);
		local_SetPref(Preference,new_val);
	}
}

//FLOAT////////////////////////
float UGamePreferenceSubsystem::GetGamePreferenceFloat(UGamePreference* Preference)
{
	if(!Preference)
	{
		return 0.0f;
	}
	return local_GetPref(Preference).X;
}

void UGamePreferenceSubsystem::SetGamePreferenceFloat(UGamePreference* Preference, float Value)
{
	if(Preference)
	{
		FVector new_val=FVector();
		new_val.X = Value;
		local_SetPref(Preference,new_val);
	}
}

//Int////////////////////////
int32 UGamePreferenceSubsystem::GetGamePreferenceInt(UGamePreference* Preference)
{
	if(!Preference) { return 0;}
	return static_cast<int32>(local_GetPref(Preference).X);
}

void UGamePreferenceSubsystem::SetGamePreferenceInt(UGamePreference* Preference, int32 Value)
{
	if(Preference)
	{
		FVector new_val;
		new_val.X = static_cast<float>(Value);
		local_SetPref(Preference,new_val);
	}
}

FString UGamePreferenceSubsystem::GetGamePreference_String(UGamePreference* Preference)
{
	if(Preference)
	{
		TArray<FString> opts=Preference->GetPreferenceStringOptions();
		int32 ind=GetGamePreferenceInt(Preference);
		if(opts.IsValidIndex(ind))
		{
			return opts[ind];
		}
	}
	return "";
}

void UGamePreferenceSubsystem::SetGamePreference_String(UGamePreference* Preference, FString Value)
{
	if(Preference)
	{
		TArray<FString> opts=Preference->GetPreferenceStringOptions();
		if(opts.Contains(Value))
		{
			SetGamePreferenceInt(Preference,opts.Find(Value));
		}
	}
}

FText UGamePreferenceSubsystem::GetGamePreference_Text(UGamePreference* Preference)
{
	if(Preference && Preference->PreferenceScript)
	{
		return Preference->PreferenceScript->GetValueText(local_GetPref(Preference));
	}
	return FText();
}

bool UOmegaPreferencesFunctions::CheckGamePreference_Bool(const UObject* WorldContextObject,
	UGamePreference* Preference, bool& Outcome)
{
	if(WorldContextObject && Preference)
	{
		Outcome=true;
		return WorldContextObject->GetWorld()->GetSubsystem<UGamePreferenceSubsystem>()->GetGamePreferenceBool(Preference);
	}
	Outcome=false;
	return false;
}

int32 UOmegaPreferencesFunctions::CheckGamePreference_Int(const UObject* WorldContextObject,
	UGamePreference* Preference, int32 CheckValue, TEnumAsByte<EOmegaComparisonMethodSimple>& Outcome)
{
	int32 out=0;
	if(WorldContextObject && Preference)
	{
		out=WorldContextObject->GetWorld()->GetSubsystem<UGamePreferenceSubsystem>()->GetGamePreferenceInt(Preference);
	}
	if(out<CheckValue) { Outcome=IsLess; }
	else if(out==CheckValue) { Outcome=IsEqual; }
	else if(out>CheckValue) { Outcome=IsGreater; }
	return out;
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

FGameplayTag UGamePreference::GetObjectGameplayCategory_Implementation() { return PreferenceCategory; }
FGameplayTagContainer UGamePreference::GetObjectGameplayTags_Implementation() { return PreferenceTags; }
void UGamePreference::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
	FText& Description) { Name = PrefernceName; }
void UGamePreference::GetGeneralAssetLabel_Implementation(FString& Label) { Label = PreferenceLabel; }

FVector UGamePreferenceScript::GetCurrentValue_Implementation(FVector Value) const
{
	return Value;
}

// ========================================================================================================================
// Function Lib
// ========================================================================================================================


