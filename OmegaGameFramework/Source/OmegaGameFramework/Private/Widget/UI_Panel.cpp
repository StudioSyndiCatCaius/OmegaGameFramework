// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/UI_Panel.h"


void UOmegaUI_Panel::NativePreConstruct()
{
	if(UCommonBorder* _b = GetWidget_Border_Main())
	{
		if(Override_BorderStyle) { _b->SetStyle(Override_BorderStyle);}
		
	}
	if(UCommonTextBlock* _t = GetWidget_Text_Title())
	{
		SetTitle(Title);
		if(Override_TitleStyle)
		{
			_t->SetStyle(Override_TitleStyle);
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
