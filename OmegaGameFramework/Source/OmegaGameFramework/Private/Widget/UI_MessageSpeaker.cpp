// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/UI_MessageSpeaker.h"

#include "Components/Image.h"
#include "Engine/Texture2D.h"
#include "Engine/World.h"
#include "Functions/F_Message.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInterface.h"
#include "Subsystems/Subsystem_World.h"

UUI_MessageSpeaker::UUI_MessageSpeaker(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	MessageCategoryFilter=FGameplayTag::RequestGameplayTag(FName("Message.Dialog"));
}

void UUI_MessageSpeaker::NativePreConstruct()
{
	Super::NativePreConstruct();
	if (Portrait_Back)
	{
		Portrait_Back->SetRenderOpacity(0.0);
	}
	if (Portrait_Front && SpeakerInstigator)
	{
		Portrait_Front->SetBrush(L_GetSpeakerDefaultPortrait());
	}
}

void UUI_MessageSpeaker::NativeConstruct()
{
	Super::NativeConstruct();
	//match the fade target to however the widget starts, so construction never triggers a fade
	vis_target = GetRenderOpacity()>0.0f ? 1.0f : 0.0f;
	if (GetWorld())
	{
		if (UOmegaSubsystem_World* w=GetWorld()->GetSubsystem<UOmegaSubsystem_World>())
		{
			w->OnGameplayMessage_Begin.AddDynamic(this, &UUI_MessageSpeaker::L_OnMessageBegin);
			w->OnGameplayMessage_End.AddDynamic(this, &UUI_MessageSpeaker::L_OnMessageEnd);
		}
	}
	
	if (Portrait_Back) { Portrait_Back->SetRenderOpacity(0.0); }
	if (Portrait_Front) { Portrait_Front->SetRenderOpacity(0.0); }
}

void UUI_MessageSpeaker::NativeDestruct()
{
	if (GetWorld())
	{
		if (UOmegaSubsystem_World* w=GetWorld()->GetSubsystem<UOmegaSubsystem_World>())
		{
			w->OnGameplayMessage_Begin.RemoveDynamic(this, &UUI_MessageSpeaker::L_OnMessageBegin);
			w->OnGameplayMessage_End.RemoveDynamic(this, &UUI_MessageSpeaker::L_OnMessageEnd);
		}
	}
	Super::NativeDestruct();
}

void UUI_MessageSpeaker::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	// --- Visibility: fade the whole widget toward the target opacity ---
	if (GetRenderOpacity()!=vis_target)
	{
		if (VisibilityFadeDuration>0.0f)
		{
			SetRenderOpacity(FMath::FInterpConstantTo(GetRenderOpacity(),vis_target,InDeltaTime,1.0f/VisibilityFadeDuration));
		}
		else
		{
			SetRenderOpacity(vis_target);
		}
	}

	// --- Portrait: crossfade the new image in on the front, fading the old one out on the back ---
	if (fade_phase==0 || !Portrait_Front || !Portrait_Back)
	{
		return;
	}

	fade_time += InDeltaTime;
	const float fade_alpha = ImageCrossfadeDuration>0 ? FMath::Clamp(fade_time/ImageCrossfadeDuration,0.f,1.f) : 1.f;

	if (fade_phase==1)
	{
		Portrait_Front->SetRenderOpacity(fade_alpha);
		if (ParallelFade)
		{
			Portrait_Back->SetRenderOpacity(fade_backStartOpacity*(1.f-fade_alpha));
		}
		if (fade_alpha>=1.f)
		{
			if (ParallelFade)
			{
				fade_phase=0;
			}
			else
			{
				fade_phase=2;
				fade_time=0;
			}
		}
	}
	else if (fade_phase==2)
	{
		Portrait_Back->SetRenderOpacity(fade_backStartOpacity*(1.f-fade_alpha));
		if (fade_alpha>=1.f)
		{
			fade_phase=0;
		}
	}
}

void UUI_MessageSpeaker::Portrait_SetVisible(bool bIsVisible)
{
	vis_target = bIsVisible ? 1.0f : 0.0f;
}

void UUI_MessageSpeaker::Portrait_SetImage(FSlateBrush NewImage, FOmegaDynamicMaterialParams params)
{
	if (params.params_scalar.Num() || params.params_vector.Num() || params.params_texture.Num())
	{
		if (UMaterialInterface* _mat=Cast<UMaterialInterface>(NewImage.GetResourceObject()))
		{
			UMaterialInstanceDynamic* _dyn=UMaterialInstanceDynamic::Create(_mat,this);
			params.Apply(_dyn);
			NewImage.SetResourceObject(_dyn);
		}
	}
	if (Portrait_Front && Portrait_Back)
	{
		Portrait_Back->SetBrush(Portrait_Front->GetBrush());
		fade_backStartOpacity = Portrait_Front->GetRenderOpacity();
		Portrait_Back->SetRenderOpacity(fade_backStartOpacity);
		Portrait_Front->SetBrush(NewImage);
		Portrait_Front->SetRenderOpacity(0.0);
		fade_phase=1;
		fade_time=0;
	}
	else if (Portrait_Front)
	{
		Portrait_Front->SetBrush(NewImage);
	}
}

void UUI_MessageSpeaker::Portrait_SetImage_Material(UMaterialInterface* NewImage)
{
	//keep the current front brush so the designer-set ImageSize/tint carry over
	FSlateBrush _brush = Portrait_Front ? Portrait_Front->GetBrush() : FSlateBrush();
	_brush.SetResourceObject(NewImage);
	Portrait_SetImage(_brush,FOmegaDynamicMaterialParams());
}

void UUI_MessageSpeaker::Portrait_SetImage_Texture(UTexture2D* NewImage)
{
	FSlateBrush _brush = Portrait_Front ? Portrait_Front->GetBrush() : FSlateBrush();
	_brush.SetResourceObject(NewImage);
	Portrait_SetImage(_brush,FOmegaDynamicMaterialParams());
}

void UUI_MessageSpeaker::Speaker_Set(UPrimaryDataAsset* Speaker, bool bMakeVisible, bool bUseDefaultPortrait)
{
	if (Speaker!=SpeakerInstigator)
	{
		SpeakerInstigator=Speaker;
		if (Speaker)
		{
			//a speaker can only occupy one position at a time: clear any other widget still holding it
			for (UUI_MessageSpeaker* w : UOmegaFunctions_Message::SpeakerWidgets_GetAll(this))
			{
				if (w && w!=this && w->SpeakerInstigator==Speaker)
				{
					w->Speaker_Set(nullptr,false);
				}
			}
			if (bUseDefaultPortrait)
			{
				Portrait_SetImage(L_GetSpeakerDefaultPortrait(),FOmegaDynamicMaterialParams());
			}
		}
	}
	if (!Speaker)
	{
		Portrait_SetVisible(false);
	}
	else if (bMakeVisible)
	{
		Portrait_SetVisible(true);
	}
}

void UUI_MessageSpeaker::L_OnMessageBegin(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory,
	FOmegaGameplayMessageMeta meta)
{
	if (MessageCategoryFilter.IsValid() && !MessageCategory.MatchesTagExact(MessageCategoryFilter))
	{
		return;
	}
	UPrimaryDataAsset* _speaker=nullptr;
	if (Message)
	{
		_speaker=Cast<UPrimaryDataAsset>(Message->GetMessageInstigator());
	}
	if (!_speaker)
	{
		return;
	}

	if (bAutosetSpeakByPosition && position && meta.TransformPreset==position && _speaker!=SpeakerInstigator)
	{
		Speaker_Set(_speaker,true);
	}
	if (_speaker==SpeakerInstigator)
	{
		_LastMessage=Message;
		//only override the portrait if the message carries a valid brush, otherwise keep the current one
		if (meta.Brush.GetResourceObject())
		{
			Portrait_SetImage(meta.Brush,FOmegaDynamicMaterialParams());
		}
		Portrait_SetVisible(true);
	}
}

void UUI_MessageSpeaker::L_OnMessageEnd(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory,
	FOmegaGameplayMessageMeta meta)
{
	if (Message && Message==_LastMessage)
	{
		_LastMessage=nullptr;
	}
}

FSlateBrush UUI_MessageSpeaker::L_GetSpeakerDefaultPortrait() const
{
	if (SpeakerInstigator && SpeakerInstigator->GetClass()->ImplementsInterface(UDataInterface_MessageInstigator::StaticClass()))
	{
		return IDataInterface_MessageInstigator::Execute_Speaker_GetConfig(SpeakerInstigator).DefaultPortrait;
	}
	return FSlateBrush();
}
