// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Preferences/GamePreference.h"



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
