// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSettings_Slate.h"

#include "CommonBorder.h"
#include "CommonTextBlock.h"
#include "OmegaSettings.h"
#include "Components/Button.h"
#include "Functions/F_Text.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Widget/DataWidget.h"


UOmegaStyleSettings::UOmegaStyleSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DefaultSlateTheme=TSoftObjectPtr<UOmegaSlateTheme>(FSoftObjectPath(TEXT("/OmegaGameFramework/DataAssets/UIStyle/StyleTheme_OMEGA_1.StyleTheme_OMEGA_1")));
	
}

TArray<UOmegaTextFormater_Collection*> UOmegaStyleSettings::L_GetTextFormaters()
{
	TArray<UOmegaTextFormater_Collection*> out;
	for (auto t :TextFormaters)
	{
		if (UOmegaTextFormater_Collection* o=Cast<UOmegaTextFormater_Collection>(t.LoadSynchronous()))
		{
			out.Add(o);
		}
	}
	return out;
}

FText UOmegaStyleSettings::L_FormatGameplayText(FText text, UObject* WorldContext, FGameplayTag Tag, FOmegaCommonMeta meta)
{
	FText out=text;
	for (auto* o : L_GetTextFormaters())
	{
		if (o)
		{
			out=o->ApplyTextFormat(out,WorldContext,Tag,meta);
		}
	}
	return out;
}
