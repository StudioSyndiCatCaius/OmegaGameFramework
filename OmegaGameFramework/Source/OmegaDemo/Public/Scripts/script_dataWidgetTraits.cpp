// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "script_dataWidgetTraits.h"

#include "Components/TextBlock.h"
#include "Widget/DataList.h"
#include "Widget/UI_Widgets.h"

void UDataWidgetTrait_General::OnInit_Implementation(UDataWidget* Widget) const
{
	if (!Widget) { return; }
	Super::OnInit_Implementation(Widget);
	if (Style_Name)
	{
		if (UOmegaTextBlock* b=Cast<UOmegaTextBlock>(Widget->GetNameTextWidget()))
		{
			b->SetStyleAsset(Style_Name);
		}
	}
	if (Style_Description)
	{
		if (UOmegaTextBlock* b=Cast<UOmegaTextBlock>(Widget->GetDescriptionTextWidget()))
		{
			b->SetStyleAsset(Style_Description);
		}
	}
}

void UDataWidgetTrait_CurveOffset::OnAddedToList_Implementation(UDataWidget* Widget, UDataList* List, int32 index) const
{
	if(!List) { return;}
	int32 _len=List->Entries.Num();
	for (int i = 0; i < _len; ++i)
	{
		if (UDataWidget* w=List->Entries[i])
		{
			float _lep=i/_len-1;
			FVector _curve=EntryLayoutCurve.GetValue(_lep);
			w->SetRenderTranslation(FVector2D(_curve.X,_curve.Y));
			w->SetRenderTransformAngle(_curve.Z);
		}
	}
}


