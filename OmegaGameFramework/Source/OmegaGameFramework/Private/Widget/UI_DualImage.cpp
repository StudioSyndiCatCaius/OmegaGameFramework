// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/UI_DualImage.h"

#include "Components/Image.h"
#include "Subsystems/Subsystem_Player.h"

void UOmegaDualImageWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	if(Image_Front)
	{
		Image_Front->SetBrush(Image);
		Image_Front->SetRenderOpacity(1.0);
	}
	if(Image_Back)
	{
		Image_Back->SetRenderOpacity(0.0);
	}
}

void UOmegaDualImageWidget::NativeConstruct()
{
	Super::NativeConstruct();
	Refresh();
}

void UOmegaDualImageWidget::NativeDestruct()
{
	if(UOmegaSubsystem_Player* SubsystemRef = GetPlayerSubsystem())
	{
		SubsystemRef->OnImageChanged.RemoveDynamic(this, &UOmegaDualImageWidget::OnGlobalImageChanged);
		SubsystemRef->OnImageRemoved.RemoveDynamic(this, &UOmegaDualImageWidget::OnGlobalImageRemoved);
	}
	Super::NativeDestruct();
}

void UOmegaDualImageWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if(fade_phase==0 || !Image_Front || !Image_Back)
	{
		return;
	}

	fade_time += InDeltaTime;
	const float fade_alpha = ImageCrossfadeDuration>0 ? FMath::Clamp(fade_time/ImageCrossfadeDuration,0.f,1.f) : 1.f;

	if(fade_phase==1)
	{
		Image_Front->SetRenderOpacity(fade_alpha);
		if(ParallelFade)
		{
			Image_Back->SetRenderOpacity(fade_backStartOpacity*(1.f-fade_alpha));
		}
		if(fade_alpha>=1.f)
		{
			if(ParallelFade)
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
	else if(fade_phase==2)
	{
		Image_Back->SetRenderOpacity(fade_backStartOpacity*(1.f-fade_alpha));
		if(fade_alpha>=1.f)
		{
			fade_phase=0;
		}
	}
}

void UOmegaDualImageWidget::SetImage(FSlateBrush NewImage)
{
	Image = NewImage;
	if(Image_Front && Image_Back)
	{
		Image_Back->SetBrush(Image_Front->GetBrush());
		fade_backStartOpacity = Image_Front->GetRenderOpacity();
		Image_Back->SetRenderOpacity(fade_backStartOpacity);
		Image_Front->SetBrush(NewImage);
		Image_Front->SetRenderOpacity(0.0);
		fade_phase=1;
		fade_time=0;
	}
	else if(Image_Front)
	{
		Image_Front->SetBrush(NewImage);
	}
}

void UOmegaDualImageWidget::OnGlobalImageChanged(APlayerController* Player, FGameplayTag Tag, FSlateBrush NewImage)
{
	if(Tag.MatchesTagExact(GlobalImageTag))
	{
		SetImage(NewImage);
	}
}

void UOmegaDualImageWidget::OnGlobalImageRemoved(APlayerController* Player, FGameplayTag Tag, FSlateBrush NewImage)
{
	if(Tag.MatchesTagExact(GlobalImageTag))
	{
		FSlateBrush ClearedBrush;
		ClearedBrush.TintColor = FSlateColor(FLinearColor::Transparent);
		SetImage(ClearedBrush);
	}
}

void UOmegaDualImageWidget::Refresh()
{
	if(GlobalImageTag.IsValid())
	{
		if(UOmegaSubsystem_Player* SubsystemRef = GetPlayerSubsystem())
		{
			SubsystemRef->OnImageChanged.AddDynamic(this, &UOmegaDualImageWidget::OnGlobalImageChanged);
			SubsystemRef->OnImageRemoved.AddDynamic(this, &UOmegaDualImageWidget::OnGlobalImageRemoved);
			if(SubsystemRef->GlobalImages.Contains(GlobalImageTag))
			{
				Image = SubsystemRef->GlobalImages[GlobalImageTag];
				if(Image_Front)
				{
					Image_Front->SetBrush(Image);
					return;
				}
			}
		}
	}
	if (Image_Front) { Image_Front->SetRenderOpacity(0.0); }
	if (Image_Back) { Image_Back->SetRenderOpacity(0.0); }
}

UOmegaSubsystem_Player* UOmegaDualImageWidget::GetPlayerSubsystem() const
{
	if(GetOwningLocalPlayer())
	{
		return GetOwningLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>();
	}
	return nullptr;
}
