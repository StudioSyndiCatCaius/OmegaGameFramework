// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/ScreenWidget.h"
#include "Misc/GeneralDataObject.h"

#include "Components/TextBlock.h"
#include "Widget/DataList.h"


void UOmegaScreenWidget::NativeConstruct()
{
	if(ContextObject && ContextObject->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		FText _name;
		FText _desc;
		FSlateBrush _icon;
		UTexture2D* _texture=nullptr;
		UMaterialInterface* _mat=nullptr;
		
		IDataInterface_General::Execute_GetGeneralDataText(ContextObject,"",this,_name,_desc);
		IDataInterface_General::Execute_GetGeneralDataImages(ContextObject,"",this,_texture,_mat,_icon);
		
		if(UTextBlock* t = GetWidget_Text_ContextName()) { t->SetText(_name); }
		if(UTextBlock* t = GetWidget_Text_ContextDescription()) { t->SetText(_desc); }
		if(UImage* t = GetWidget_Image_ContextIcon()) { t->SetBrush(_icon); }
	}

	if(GetOwningPlayer() && GetOwningPlayer()->K2_GetPawn())
	{
		APawn* _pawn = GetOwningPlayer()->K2_GetPawn();
		for(auto* d : GetDataLists_LinkedToPlayerPawn())
		{
			if(d) { d->SetListOwner(_pawn);}
		}
		for(auto* d : GetDataWidgets_LinkedToPlayerPawn())
		{
			if(d) { d->SetSourceAsset(_pawn);}
		}
	}
	
	Super::NativeConstruct();
}
