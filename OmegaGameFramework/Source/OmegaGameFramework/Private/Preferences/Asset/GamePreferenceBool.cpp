// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Preferences/Asset/GamePreferenceBool.h"

#include "Components/CheckBox.h"
#include "Preferences/GamePreferenceSubsystem.h"

UGamePreferenceBool::UGamePreferenceBool()
{
	PreferenceType = EGamePreferenceType::PrefType_Bool;
}

void UGamePreferenceBool::ApplyToCheckBox(UGamePreferenceSubsystem* Subsystem, UCheckBox* CheckBox)
{
	if(Subsystem && CheckBox)
	{
		CheckBox->SetIsChecked(Subsystem->GetGamePreferenceBool(this));
	}
}
