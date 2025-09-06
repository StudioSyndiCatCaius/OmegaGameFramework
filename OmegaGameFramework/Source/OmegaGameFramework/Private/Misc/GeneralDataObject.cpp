// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Misc/GeneralDataObject.h"
#include "LuaBlueprintFunctionLibrary.h"
//#include "Misc/OmegaUtils_Enums.h"
#include "Functions/OmegaFunctions_Common.h"

void UGeneralDataObject::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description)
{
	Name = CustomData.DisplayName;
	Description = CustomData.Description;
}

void UGeneralDataObject::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
{
	Texture = CustomData.Texture;
}

void UGeneralDataObject::GetGeneralAssetColor_Implementation(FLinearColor& Color)
{
	Color = CustomData.Color;
}

void UGeneralDataObject::GetGeneralAssetLabel_Implementation(FString& Label)
{
	Label = CustomData.Label;
}


UOmegaDataAsset::UOmegaDataAsset()
{
	if(!Guid.IsValid()) { Guid= FGuid::NewGuid();}
}


bool UOmegaDataAsset::UseIconAsThumbnail_Implementation()
{
	{ return false;}
}
