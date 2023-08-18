// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Zone/OmegaZone.h"

void UOmegaLevelData::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
	FText& Description)
{
	Name = DisplayName;
	Description = DisplayDescription;
}

void UOmegaLevelData::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context,
	UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
{
	Brush = DisplayIcon;
}

FGameplayTag UOmegaLevelData::GetObjectGameplayCategory_Implementation()
{
	return CategoryTag;
}

FGameplayTagContainer UOmegaLevelData::GetObjectGameplayTags_Implementation()
{
	return GameplayTags;
}

void UOmegaZoneData::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
	FText& Description)
{
	Name = ZoneName;
	Description = ZoneName;
}

void UOmegaZoneData::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context,
	UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
{
	Brush = ZoneIcon;
}

FGameplayTag UOmegaZoneData::GetObjectGameplayCategory_Implementation()
{
	return ZoneCategory;
}

FGameplayTagContainer UOmegaZoneData::GetObjectGameplayTags_Implementation()
{
	return ZoneTags;
}
