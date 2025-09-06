// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSettings_Gameplay.h"
#include "Subsystems/OmegaSubsystem_Gameplay.h"
#include "OmegaSettings.h"

TArray<UOmegaGameplayModule*> UOmegaSettings_Gameplay::GetModules()
{
	TArray<UOmegaGameplayModule*> out;
	for(auto* a : ModuleSets)
	{
		if(a)
		{
			out.Append(a->GetModules());
		}
	}
	out.Append(ScriptedModules);
	return out;
}

UOmegaSettings_Gameplay* UOmegaGameplayStyleFunctions::GetCurrentGameplayStyle()
{
	if(!GetMutableDefault<UOmegaSettings>()->DefaultSettings_Gameplay.IsValid()) { return nullptr; }
	if(UObject* style_ref = GetMutableDefault<UOmegaSettings>()->DefaultSettings_Gameplay.TryLoad())
	{
		return Cast<UOmegaSettings_Gameplay>(style_ref);
	}
	return nullptr;
}

UOmegaGameplayMetaSettings* UOmegaGameplayStyleFunctions::GetCurrentGameplayMetaStyle(
	TSubclassOf<UOmegaGameplayMetaSettings> Class)
{
	if(!Class)
	{
		return nullptr;
	}
	if(GetCurrentGameplayStyle())
	{
		for(auto* temp_set : GetCurrentGameplayStyle()->GetAllMetaSettings())
		{
			if(temp_set && temp_set->GetClass()==Class)
			{
				return temp_set;
			}
		}
	}
	
	
	return Cast<UOmegaGameplayMetaSettings>(Class->ClassDefaultObject);
}

bool UOmegaGameplayStyleFunctions::OmegaGameplayInputCall(APlayerController* Player, const FKey& Key, bool End)
{
	bool out=false;
	if(Player && GetCurrentGameplayStyle())
	{
		for(auto* temp_event : GetCurrentGameplayStyle()->CustomInputEvents)
		{
			if(temp_event && temp_event->InputKeys.Contains(Key))
			{
				if(End)
				{
					temp_event->OnInput_End(Player,Player->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>());
				}
				else
				{
					temp_event->OnInput_Start(Player,Player->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>());	
				}
				out=true;
			}
		}
	}
	return out;
}



UOmegaDataAssetMetaSetting* UOmegaGameplayStyleFunctions::GetDataAssetMetaSetting(UPrimaryDataAsset* DataAsset,
	TSubclassOf<UOmegaDataAssetMetaSetting> Class, bool& Result)
{
	for(FOmegaDataAssetMetaSettingsInfo i : GetCurrentGameplayStyle()->GetAllDataAssetMetaSettings())
	{
		if(i.DataAsset && i.DataAsset==DataAsset)
		{
			for(auto* s : i.Settings)
			{
				if(s && s->GetClass()==Class)
				{
					Result=true;
					return s;
				}
			}
		}
	}
	Result=false;
	return nullptr;
}

