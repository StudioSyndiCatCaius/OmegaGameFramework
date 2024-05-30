// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSettings_Gameplay.h"
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
	if(GetCurrentGameplayStyle())
	{
		for(auto* temp_set : GetCurrentGameplayStyle()->MetaSettings)
		{
			if(temp_set && temp_set->GetClass()==Class)
			{
				return temp_set;
			}
		}
	}
	return nullptr;
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

