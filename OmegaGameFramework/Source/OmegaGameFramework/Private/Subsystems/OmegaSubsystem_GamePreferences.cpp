// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Subsystems/OmegaSubsystem_GamePreferences.h"
#include "Subsystems/OmegaSubsystem_Save.h"

#include "Functions/OmegaFunctions_Common.h"
#include "OmegaSettings.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/GameInstance.h"


void UGamePreferenceSubsystem::PreloadPrefs()
{
	
	const FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	TArray<FAssetData> AssetData;
	FARFilter Filter;
	Filter.ClassPaths.Add(UGamePreference::StaticClass()->GetClassPathName());
	
	for(const FDirectoryPath NewPath : GetMutableDefault<UOmegaSettings>()->Preferences_ScanPaths)
	{
		//FString LocalString = NewPath.Path;
		Filter.PackagePaths.Add(FName(*NewPath.Path));
	}
	
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
	GetSaveSubsystem()->GetSaveObject(Preference->bGlobal)->PreferenceValues.Add(Preference,value);
	Local_PreferenceUpdate(Preference);
}

FVector UGamePreferenceSubsystem::local_GetPref(UGamePreference* Preference)
{
	UOmegaSaveBase* save_obj = GetSaveSubsystem()->GetSaveObject(Preference->bGlobal);
	if(save_obj->PreferenceValues.Contains(Preference))
	{
		return save_obj->PreferenceValues.FindOrAdd(Preference);
	}
	if(Preference->PreferenceScript)
	{
		return Preference->PreferenceScript->GetDefaultValue();
	}
	return FVector();
}

void UGamePreferenceSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	PreloadPrefs();
	Super::OnWorldBeginPlay(InWorld);
}

void UGamePreferenceSubsystem::Initialize(FSubsystemCollectionBase& Colection)
{
	//-- maybe remove this?
}

//BOOL////////////////////////

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
		Preference->PreferenceScript->OnPreferenceValueUpdated(nullptr, local_GetPref(Preference));
	}
}

void UGamePreferenceSubsystem::Local_PreferenceUpdateAll()
{
	 for(auto* TempPref : PreloadedPreferences)
	 {
		 Local_PreferenceUpdate(TempPref);
	 }
}

bool UGamePreferenceSubsystem::GetGamePreferenceBool(UGamePreference* Preference)
{
	if(!Preference)
	{
		return false;
	}
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
		FVector new_val;
		new_val.X = Value;
		local_SetPref(Preference,new_val);
	}
}

//Int////////////////////////
int32 UGamePreferenceSubsystem::GetGamePreferenceInt(UGamePreference* Preference)
{
	if(!Preference)
	{
		return 0;
	}
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
	if(Preference && Preference->PreferenceScript)
	{
		return Preference->PreferenceScript->GetValueString(local_GetPref(Preference));
	}
	return "";
}

FText UGamePreferenceSubsystem::GetGamePreference_Text(UGamePreference* Preference)
{
	if(Preference && Preference->PreferenceScript)
	{
		return Preference->PreferenceScript->GetValueText(local_GetPref(Preference));
	}
	return FText();
}


FGameplayTag UGamePreference::GetObjectGameplayCategory_Implementation()
{
	return PreferenceCategory;
}

FGameplayTagContainer UGamePreference::GetObjectGameplayTags_Implementation()
{
	return PreferenceTags;
}

void UGamePreference::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
	FText& Description)
{
	Name = PrefernceName;
}

void UGamePreference::GetGeneralAssetLabel_Implementation(FString& Label)
{
	Label = PreferenceLabel;
}
