// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/UI_Panel.h"

#include "Components/Border.h"
#include "Components/TextBlock.h"
#include "Widget/UI_Widgets.h"


void UOmegaUI_Panel::NativePreConstruct()
{
	if(UBorder* _b = GetWidget_Border_Title())
	{
		if(TitleBorder_Style)
		{
			TitleBorder_Style->Apply(_b);
		}
		
	}
	if(UBorder* _b = GetWidget_Border_Body())
	{
		if(BodyBorder_Style)
		{
			BodyBorder_Style->Apply(_b);
		}
		
	}
	if(UTextBlock* _t = GetWidget_Text_Title())
	{
		SetTitle(Title);
		if(TitleText_Style)
		{
			TitleText_Style->Apply(_t);
		}
	}
	Super::NativePreConstruct();
}

void UOmegaUI_Panel::SetTitle(FText NewTitle)
{
	Title=NewTitle;
	if(GetWidget_Text_Title())
	{
		GetWidget_Text_Title()->SetText(NewTitle);
	}
}
