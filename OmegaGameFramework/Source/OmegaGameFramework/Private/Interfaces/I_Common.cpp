
#include "Interfaces/I_Common.h"
#include "OmegaGameManager.h"
#include "OmegaSettings.h"
#include "Misc/OmegaUtils_Macros.h"

FText UDataInterface_General::GetObjectName(UObject* obj,FGameplayTag Tag)
{
	FText out_name;
	if(obj && obj->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		bool bOverride=false;
		FText OutName=OGF_GAME_CORE()->Object_OverrideName(obj,Tag,bOverride);
		FText out_desc;
		if (bOverride)
		{
			return OutName;
		}
		IDataInterface_General::Execute_GetGeneralDataText(obj,Tag,out_name,out_desc);	
	}
	return out_name;
}

FText UDataInterface_General::GetObjectDesc(UObject* obj,FGameplayTag Tag)
{
	
	FText out_desc;
	if(obj && obj->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		bool bOverride=false;
		FText OutName=OGF_GAME_CORE()->Object_OverrideDescription(obj,Tag,bOverride);
		FText out_name;
		if (bOverride)
		{
			return OutName;
		}
		IDataInterface_General::Execute_GetGeneralDataText(obj,Tag,out_name,out_desc);	
	}
	return out_desc;
}

FSlateBrush UDataInterface_General::GetObjectIcon(UObject* obj,FGameplayTag Tag)
{
	FSlateBrush out;
	UTexture2D* dum_txt=nullptr;
	UMaterialInterface* dum_mat=nullptr;
	bool bOverride=false;
	FSlateBrush out_brush=OGF_GAME_CORE()->Object_OverrideIcon(obj,Tag,bOverride);
	if (bOverride)
	{
		return out_brush;
	}
	if(obj && obj->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		IDataInterface_General::Execute_GetGeneralDataImages(obj,Tag,dum_txt,dum_mat,out);
	}
	return out;
}

FString UDataInterface_General::GetObjectLabel(UObject* obj)
{
	FString out;
	if(obj)
	{
		if(obj->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
		{
			IDataInterface_General::Execute_GetGeneralAssetLabel(obj,out);
		}
		else
		{
			out=obj->GetName();
		}
	}
	return out;
}



FGameplayTag UDataInterface_General::GetGCategory(UObject* o)
{
	if(o && o->GetClass()->ImplementsInterface(StaticClass()))
	{
		return IDataInterface_General::Execute_GetObjectGameplayCategory(o);
	}
	return FGameplayTag();
}

FGameplayTagContainer UDataInterface_General::GetGTags(UObject* o)
{
	if(o && o->GetClass()->ImplementsInterface(StaticClass()))
	{
		return IDataInterface_General::Execute_GetObjectGameplayTags(o);
	}
	return FGameplayTagContainer();
}




