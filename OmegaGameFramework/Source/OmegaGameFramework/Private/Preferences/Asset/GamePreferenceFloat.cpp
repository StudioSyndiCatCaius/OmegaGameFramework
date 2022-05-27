// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Preferences/Asset/GamePreferenceFloat.h"

#include "Components/Slider.h"
#include "Components/SpinBox.h"
#include "Preferences/GamePreferenceSubsystem.h"

UGamePreferenceFloat::UGamePreferenceFloat()
{
	PreferenceType = EGamePreferenceType::PrefType_Float;
}

void UGamePreferenceFloat::ApplyToSliderWidget(UGamePreferenceSubsystem* Subsystem, USlider* Slider)
{
	if(Subsystem && Slider)
	{
		Slider->SetValue(Subsystem->GetGamePreferenceFloat(this));
		Slider->SetMaxValue(MaxValue);
	}
}

void UGamePreferenceFloat::ApplyToSpinBoxWidget(UGamePreferenceSubsystem* Subsystem, USpinBox* SpinBox)
{
	if(Subsystem && SpinBox)
	{
		SpinBox->SetValue(Subsystem->GetGamePreferenceFloat(this));
		SpinBox->SetMaxValue(MaxValue);
	}
}
