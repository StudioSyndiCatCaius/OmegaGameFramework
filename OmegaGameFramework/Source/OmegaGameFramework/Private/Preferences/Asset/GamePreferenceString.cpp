// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Preferences/Asset/GamePreferenceString.h"

#include "Preferences/GamePreferenceSubsystem.h"

UGamePreferenceString::UGamePreferenceString()
{
	PreferenceType = EGamePreferenceType::PrefType_String;
}

void UGamePreferenceString::ApplyToComboBox(UGamePreferenceSubsystem* Subsystem, UComboBoxString* ComboBox)
{
	if(Subsystem && ComboBox)
	{
		ComboBox->ClearOptions();
		for(FString TempOption : Options)
		{
			ComboBox->AddOption(TempOption);
		}

		ComboBox->RefreshOptions();
		ComboBox->SetSelectedOption(Subsystem->GetGamePreferenceString(this));
	}
}
