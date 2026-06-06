
#include "Interfaces/I_Common.h"
#include "OmegaGameManager.h"
#include "OmegaSettings.h"
#include "Misc/OmegaUtils_Macros.h"

// ── helpers to call GetGeneralDataText and unpack a single field ──────────────

static void L_GetText(UObject* obj, FGameplayTag Tag, FText& OutName, FText& OutDesc, FSlateBrush& OutIcon, FLinearColor& OutColor, FString& OutLabel, FOmegaObjectGeneralMetaconfig& OutMeta)
{
	if(obj && obj->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		IDataInterface_General::Execute_GetGeneralDataText(obj, Tag, OutName, OutDesc, OutIcon, OutColor, OutLabel, OutMeta);
	}
}

FText UDataInterface_General::GetObjectName(UObject* obj, FGameplayTag Tag)
{
	FText out_name;
	if(obj && obj->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		bool bOverride=false;
		FText OverrideName=OGF_GAME_CORE()->Object_OverrideName(obj,Tag,bOverride);
		if (bOverride) { return OverrideName; }
		FText out_desc; FSlateBrush out_icon; FLinearColor out_color; FString out_label; FOmegaObjectGeneralMetaconfig out_meta;
		IDataInterface_General::Execute_GetGeneralDataText(obj, Tag, out_name, out_desc, out_icon, out_color, out_label, out_meta);
	}
	return out_name;
}

FText UDataInterface_General::GetObjectDesc(UObject* obj, FGameplayTag Tag)
{
	FText out_desc;
	if(obj && obj->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		bool bOverride=false;
		FText OverrideName=OGF_GAME_CORE()->Object_OverrideDescription(obj,Tag,bOverride);
		if (bOverride) { return OverrideName; }
		FText out_name; FSlateBrush out_icon; FLinearColor out_color; FString out_label; FOmegaObjectGeneralMetaconfig out_meta;
		IDataInterface_General::Execute_GetGeneralDataText(obj, Tag, out_name, out_desc, out_icon, out_color, out_label, out_meta);
	}
	return out_desc;
}

FSlateBrush UDataInterface_General::GetObjectIcon(UObject* obj, FGameplayTag Tag)
{
	FSlateBrush out;
	bool bOverride=false;
	FSlateBrush out_brush=OGF_GAME_CORE()->Object_OverrideIcon(obj,Tag,bOverride);
	if (bOverride) { return out_brush; }
	if(obj && obj->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		FText out_name, out_desc; FLinearColor out_color; FString out_label; FOmegaObjectGeneralMetaconfig out_meta;
		IDataInterface_General::Execute_GetGeneralDataText(obj, Tag, out_name, out_desc, out, out_color, out_label, out_meta);
	}
	return out;
}

FString UDataInterface_General::GetObjectLabel(UObject* obj)
{
	if(obj && obj->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		FText out_name, out_desc; FSlateBrush out_icon; FLinearColor out_color; FString label; FOmegaObjectGeneralMetaconfig out_meta;
		IDataInterface_General::Execute_GetGeneralDataText(obj, FGameplayTag(), out_name, out_desc, out_icon, out_color, label, out_meta);
		if(!label.IsEmpty()) { return label; }
	}
	if(obj) { return obj->GetName(); }
	return FString();
}

FLinearColor UDataInterface_General::GetObjectColor(UObject* obj, FGameplayTag Tag)
{
	FLinearColor out;
	if(obj && obj->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		FText out_name, out_desc; FSlateBrush out_icon; FString out_label; FOmegaObjectGeneralMetaconfig out_meta;
		IDataInterface_General::Execute_GetGeneralDataText(obj, Tag, out_name, out_desc, out_icon, out, out_label, out_meta);
	}
	return out;
}

FGameplayTagContainer UDataInterface_General::GetGTags(UObject* o)
{
	FGameplayTagContainer Tags;
	if(o && o->GetClass()->ImplementsInterface(StaticClass()))
	{
		FGameplayTag _cat;
		IDataInterface_General::Execute_GetObjectGameplayTags(o, _cat, Tags);
	}
	return Tags;
}

FGameplayTag UDataInterface_General::GetGCategory(UObject* o)
{
	FGameplayTag Cat;
	if(o && o->GetClass()->ImplementsInterface(StaticClass()))
	{
		FGameplayTagContainer _tags;
		IDataInterface_General::Execute_GetObjectGameplayTags(o, Cat, _tags);
	}
	return Cat;
}
