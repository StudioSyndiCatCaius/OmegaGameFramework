// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSettings_Gameplay.h"
#include "Subsystems/OmegaSubsystem_Gameplay.h"
#include "OmegaSettings.h"

UOmegaSettings_Gameplay* UOmegaGameplayStyleFunctions::GetCurrentGameplayStyle()
{
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

UPrimaryDataAsset* UOmegaGameplayStyleFunctions::GetGlobalDataAsset_Common(FGameplayTag Tag)
{
	if(GetCurrentGameplayStyle()->GlobalDataAssets_Common.Contains(Tag))
	{
		return GetCurrentGameplayStyle()->GlobalDataAssets_Common[Tag];	
	}
	return nullptr;
}

UOmegaAttribute* UOmegaGameplayStyleFunctions::GetGlobalDataAsset_Attribute(FGameplayTag Tag)
{
	if(GetCurrentGameplayStyle()->GlobalDataAssets_Attribute.Contains(Tag))
	{
		return GetCurrentGameplayStyle()->GlobalDataAssets_Attribute[Tag];	
	}
	return nullptr;
}

UEquipmentSlot* UOmegaGameplayStyleFunctions::GetGlobalDataAsset_EquipSlot(FGameplayTag Tag)
{
	if(GetCurrentGameplayStyle()->GlobalDataAssets_EquipSlot.Contains(Tag))
	{
		return GetCurrentGameplayStyle()->GlobalDataAssets_EquipSlot[Tag];	
	}
	return nullptr;
}

