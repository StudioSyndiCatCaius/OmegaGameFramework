// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Misc/GeneralDataObject.h"
#include "LuaBlueprintFunctionLibrary.h"
//#include "Misc/OmegaUtils_Enums.h"
#include "GroomVisualizationData.h"
#include "PCGPoint.h"
#include "Functions/F_Common.h"


#define LUACFG() GetMutableDefault<ULuaSettings>()


UOmegaDataAsset::UOmegaDataAsset()
{
	if(!Guid.IsValid()) { Guid= FGuid::NewGuid();}
}
/*
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
*/


void UOmegaDataAsset::GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description,
	FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig)
{
	Name=DisplayName;
	Description=DisplayDescription;
	iconBrush=Icon;
	Color=color;
	if (CustomLabel.IsEmpty())
	{
		Label=GetName();
	}
	else
	{
		Label=CustomLabel;
	}
	MetaConfig.guid=Guid;
	MetaConfig.seed=Guid.A;
}

void UOmegaDataAsset::GetObjectGameplayTags_Implementation(FGameplayTag& OutCategoryTag,
                                                           FGameplayTagContainer& OutGameplayTags)
{
	OutCategoryTag=CategoryTag;
	OutGameplayTags=GameplayTags;
}

void UOmegaDataAsset::SetValue_Implementation(FLuaValue Value, const FString& Field)
{
	if(DisplayName.IsEmpty() && !Value.GetField("name").ToString().IsEmpty())
	{
		DisplayName=FText::FromString(Value.GetField("name").ToString());
	}
	if(DisplayDescription.IsEmpty() && !Value.GetField("description").ToString().IsEmpty())
	{
		DisplayDescription=FText::FromString(Value.GetField("description").ToString());
	}
	bool found_icon=false;
	if(UTexture2D* _ico=Cast<UTexture2D>(UOmegaGameFrameworkBPLibrary::GetAsset_FromPath(Value.GetField("icon").ToString(),UTexture2D::StaticClass(),found_icon)))
	{
		Icon.SetResourceObject(_ico);
	}
	if(!CategoryTag.IsValid() && !Value.GetField("category").ToString().IsEmpty())
	{
		FString _TargetTag=Value.GetField("category").ToString();
		if (FGameplayTag::IsValidGameplayTagString(_TargetTag))
		{
			CategoryTag=FGameplayTag::RequestGameplayTag(*_TargetTag,false);	
		}
	}
	GameplayTags=UOmegaGameFrameworkBPLibrary::MakeGameplayTagContainerFromStrings(ULuaBlueprintFunctionLibrary::Conv_LuaValueToString_Array(Value.GetField("tags")));
	LuaData=Value;
}

void UOmegaDataAsset::SetKey_Implementation(FLuaValue Key)
{
	LuaKey=Key.ToName();
	CustomLabel=LuaKey.ToString();
}

void UOmegaDemoDataAsset::GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description,
	FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig)
{
	FOmegaObjectGeneralMetaconfig _cfg;
	Super::GetGeneralDataText_Implementation(Tag, Name, Description, iconBrush, Color, Label, _cfg);
	_cfg.bitflags=Flags;
	_cfg.named_lists=NamedLists;
	_cfg.relative_assets=RelativeAssets;
	
	MetaConfig=_cfg;
}



bool UOmegaDataAsset::UseIconAsThumbnail_Implementation()
{
	{ return false;}
}

#undef LUACFG