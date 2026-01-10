// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Misc/GeneralDataObject.h"
#include "LuaBlueprintFunctionLibrary.h"
//#include "Misc/OmegaUtils_Enums.h"
#include "Functions/F_Common.h"


#define LUACFG() GetMutableDefault<ULuaSettings>()

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

FString UOmegaDataAsset::GetSoftProperty_Implementation(FName Property)
{
	FLuaValue val=LuaData.GetField(Property.ToString());
	if (val.IsNil())
	{
		return "";
	}
	return val.ToString();
}

TArray<FName> UOmegaDataAsset::GetMetatags_Implementation()
{
	TArray<FName> out=Metatags;
	out.Append(ULuaBlueprintFunctionLibrary::Conv_LuaValueToName_Array(LuaData.GetField(
		LUACFG()->FieldKey_Metatags)));
	return out;
}

FOmegaClassNamedLists UOmegaDataAsset::GetClassNamedLists_Implementation()
{
	FOmegaClassNamedLists out=NamedLists;
	FLuaValue fieldtemp=LuaData.GetField(LUACFG()->FieldKey_CustomLists);
	for (FLuaValue v : ULuaBlueprintFunctionLibrary::LuaTableGetKeys(fieldtemp))
	{
		FOmegaCustomNamedList l;
		l.ListID=v.ToName();
		l.Option=fieldtemp.GetField(v.ToString()).ToName();
		out.CustomNamedList.Add(v.ToName(),l);
	}
	return out;
}

void UOmegaDataAsset::SetValue_Implementation(FLuaValue Value, const FString& Field)
{
	if(DisplayName.IsEmpty() && !Value.GetField("name").ToString().IsEmpty())
	{
		DisplayName=FText::FromString(Value.GetField("name").ToString());
	}
	if(DisplayName.IsEmpty() && !Value.GetField("description").ToString().IsEmpty())
	{
		DisplayName=FText::FromString(Value.GetField("description").ToString());
	}
	if(GameplayTags.IsEmpty())
	{
		
	}
	if(!CategoryTag.IsValid() && !Value.GetField("category").ToString().IsEmpty())
	{
		FString _TargetTag=Value.GetField("category").ToString();
		if (FGameplayTag::IsValidGameplayTagString(_TargetTag))
		{
			CategoryTag=FGameplayTag::RequestGameplayTag(*_TargetTag);	
		}
	}
	LuaData=Value;
}

void UOmegaDataAsset::SetKey_Implementation(FLuaValue Key)
{
	LuaKey=Key.ToName();
	CustomLabel=LuaKey.ToString();
}

UPrimaryDataAsset* UOmegaDataAsset::GetDataAsset_Named_Implementation(FName name)
{

	return nullptr;
}


bool UOmegaDataAsset::UseIconAsThumbnail_Implementation()
{
	{ return false;}
}

#undef LUACFG