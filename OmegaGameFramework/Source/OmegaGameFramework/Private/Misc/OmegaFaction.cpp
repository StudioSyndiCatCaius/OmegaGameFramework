// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Misc/OmegaFaction.h"


void UOmegaFaction::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
	FText& Description)
{
	Name=FactionName;
}

void UOmegaFaction::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context,
	UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
{
	Brush=FactionIcon;
}

void UOmegaFaction::GetGeneralAssetColor_Implementation(FLinearColor& Color)
{
	Color=FactionColor;
}
