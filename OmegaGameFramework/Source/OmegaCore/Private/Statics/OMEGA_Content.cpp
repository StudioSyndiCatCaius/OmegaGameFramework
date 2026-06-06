

#include "Statics/OMEGA_Content.h"
#include "Engine/Texture2D.h"

UTexture2D* OMEGA_Content::Load_Icon_AsTexture(UObject* outer, const FString IconName)
{
	if (outer)
	{
		FString in_name="/OmegaGameFramework/Textures/icons/64x/"+IconName+"."+IconName;
		if (UTexture2D* txt=LoadObject<UTexture2D>(outer,*in_name))
		{
			return txt;
		}	
	}
	return nullptr;
}

FSlateBrush OMEGA_Content::Load_Icon_AsBrush(UObject* outer,const FString IconName, int32 size)
{
	FSlateBrush b;
	b.ImageSize.X = size;
	b.ImageSize.Y = size;
	b.SetResourceObject(Load_Icon_AsTexture(outer,IconName));
	return b;
}
