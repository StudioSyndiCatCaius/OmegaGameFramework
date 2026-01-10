// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSettings_Gameplay.h"

#include "MaterialKeyGeneratorContext.h"
#include "Subsystems/Subsystem_Gameplay.h"
#include "OmegaSettings.h"

UOmegaSettings_Gameplay::UOmegaSettings_Gameplay()
{
	//DefaultInteractionType=FGameplayTag::RequestGameplayTag("Event.Actor.Interact");
}

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

bool UOmegaGameplayStyleFunctions::OmegaGameplayInputCall(APlayerController* Player, const FKey& Key, bool End)
{
	bool out=false;
	if(Player && GetCurrentGameplayStyle())
	{
		
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
