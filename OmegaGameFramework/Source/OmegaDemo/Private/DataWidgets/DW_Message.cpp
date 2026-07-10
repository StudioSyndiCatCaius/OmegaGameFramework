// Fill out your copyright notice in the Description page of Project Settings.

#include "DataWidgets/DW_Message.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Kismet/KismetStringLibrary.h"
#include "Types/Struct_Message.h"


void UDataWidgetBase_Message::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if(bWriteTextOverTime && __bTextIsUpdating)
	{
		//if count is over max strings, end
		if(!__stringsRemaining.IsValidIndex(__stringAmount))
		{
			__bTextIsUpdating=false;
		}
		else
		{
			if(__TextWriteTime>=TextWriteFrequency)
			{
				__TextWriteTime=0.0;
				if(UTextBlock* _text = GetWidget_Text_Message())
				{
					FString _inStr=_text->GetText().ToString()+__stringsRemaining[__stringAmount];
					_text->SetText(FText::FromString(_inStr));
				}
				__stringAmount+=1;
			}
			else
			{
				__TextWriteTime+=InDeltaTime;
			}
		}
	}
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UDataWidgetBase_Message::Native_OnSourceAssetChanged(UObject* SourceAsset)
{
	if(SourceAsset && SourceAsset->GetClass()->IsChildOf(UOmegaGameplayMessage::StaticClass()))
	{
		REF_message=Cast<UOmegaGameplayMessage>(SourceAsset);
		OnMessageUpdate(REF_message);
		if(GetWidget_Text_Message())
		{
			FText _txt = REF_message->GetMessageText();
			if(bWriteTextOverTime)
			{
				GetWidget_Text_Message()->SetText(FText::FromString(""));
				__stringsRemaining=UKismetStringLibrary::GetCharacterArrayFromString(_txt.ToString());
				__stringAmount=0;

				__bTextIsUpdating=true;
			}
			else
			{
				GetWidget_Text_Message()->SetText(_txt);
			}
		}
		if(GetDataWidget_MessageInstigator())
		{
			GetDataWidget_MessageInstigator()->SetSourceAsset(REF_message->GetMessageInstigator());
		}
		if(REF_message->GetMessageInstigator()!=REF_lastInstigator)
		{
			OnInstigatorChange(REF_message->GetMessageInstigator(),REF_lastInstigator);
			REF_lastInstigator=REF_message->GetMessageInstigator();
		}
		if(REF_lastInstigator)
		{
			if(REF_lastInstigator->GetClass()->ImplementsInterface(UDataInterface_MessageInstigator::StaticClass()))
			{
				if(UImage* _img = GetImage_InstigatorBrush())
				{
					_img->SetBrush(IDataInterface_MessageInstigator::Execute_GetMessageBrush(_img,REF_message));
				}
			}
		}
	}
	Super::Native_OnSourceAssetChanged(SourceAsset);
}

UOmegaGameplayMessage* UDataWidgetBase_Message::GetCurrentMessage() const
{
	if(REF_message) { return REF_message; } return nullptr;
}
