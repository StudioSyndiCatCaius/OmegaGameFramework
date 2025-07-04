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


TArray<FOmegaAttributeModifier> UOmegaLuaBaseObject::GetModifierValues_Implementation(UCombatantComponent* CombatantComponent)
{
	TArray<FOmegaAttributeModifier> out;
	FLuaValue mod_list = ILuaInterface::Execute_GetValue(this,"").GetField(Param_AttributeMods);
	for(FLuaValue att_name : ULuaBlueprintFunctionLibrary::LuaTableGetKeys(mod_list))
	{
		bool result;
		UObject* output = UOmegaGameFrameworkBPLibrary::GetAsset_FromPath(att_name.String,UOmegaAttribute::StaticClass(),result);
		if(output && result)
		{
			FOmegaAttributeModifier new_mod;
			new_mod.Attribute=Cast<UOmegaAttribute>(output);
			new_mod.Incrementer=mod_list.GetField(att_name.String).ToFloat();
			out.Add(new_mod);
		}
	}
	return out;
}

UOmegaDataAsset::UOmegaDataAsset()
{
	if(!Guid.IsValid()) { Guid= FGuid::NewGuid();}
}

UObject* UOmegaDataAsset::GetObject_Parent_Implementation() const
{
	return ParentAsset;
}

TArray<UObject*> UOmegaDataAsset::GetObject_Children_Implementation() const
{
	TArray<UObject*> out;
	for(auto* c : ChildAssets)
	{
		if(c) { out.Add(c); }
	}
	return out;
}

bool UOmegaDataAsset::UseIconAsThumbnail_Implementation()
{
	{ return false;}
}
