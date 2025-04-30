// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSettings_Preferences.h"

#include "OmegaSettings.h"
#include "Subsystems/OmegaSubsystem_GamePreferences.h"

UOmegaSettings_Preferences* UOmegaPreferenceSettingsFunctions::GetSettings_Preferences()
{
	if(UObject* _pref = GetMutableDefault<UOmegaSettings>()->DefaultSettings_Preferences.TryLoad())
	{
		return Cast<UOmegaSettings_Preferences>(_pref);
	}
	return nullptr;
}

FOmega_CameraConfig UOmegaPreferenceSettingsFunctions::GetCameraConfig_FromPreferences(UObject* WorldContextObject)
{
	if(WorldContextObject)
	{
		FOmega_CameraConfig out;
		UOmegaSettings_Preferences* _set = GetSettings_Preferences();
		UGamePreferenceSubsystem* _sys = WorldContextObject->GetWorld()->GetSubsystem<UGamePreferenceSubsystem>();
		if(UGamePreference* _pref= _set->Pref_Camera_InvertX)
		{
			out.invertX=_sys->GetGamePreferenceBool(_pref);
		}
		if(UGamePreference* _pref= _set->Pref_Camera_InvertY)
		{
			out.invertY=_sys->GetGamePreferenceBool(_pref);
		}
		if(UGamePreference* _pref= _set->Pref_Camera_Sensitivity)
		{
			out.scale=_sys->GetGamePreferenceFloat(_pref);
		}

		return out;
	}
	return FOmega_CameraConfig();
}
