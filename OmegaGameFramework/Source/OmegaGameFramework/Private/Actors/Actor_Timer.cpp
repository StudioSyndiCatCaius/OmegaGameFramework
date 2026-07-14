// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_Timer.h"
#include "Components/AudioComponent.h"
#include "Components/BillboardComponent.h"
#include "Sound/SoundBase.h"
#include "Functions/F_TagEvent.h"
#include "UObject/ConstructorHelpers.h"

AOmegaTimerActor::AOmegaTimerActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SpriteComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("Sprite"));
	RootComponent = SpriteComponent;

	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	AudioComponent->SetupAttachment(RootComponent);
	AudioComponent->bAutoActivate = false;
	//AudioComponent->SetWorldScale3D(FVector::Zero());
	
	static ConstructorHelpers::FObjectFinder<USoundBase> DefaultTickFinder(TEXT("/OmegaGameFramework/audio/ui/wav_ui_tick_001.wav_ui_tick_001"));
	if (DefaultTickFinder.Succeeded()) Sound_Default = DefaultTickFinder.Object;
	static ConstructorHelpers::FObjectFinder<USoundBase> AtPercentTickFinder(TEXT("/OmegaGameFramework/audio/ui/wav_ui_tick_003.wav_ui_tick_003"));
	if (AtPercentTickFinder.Succeeded()) Sound_AtPercent.Add(AtPercentTickFinder.Object, 0.3f);

#if WITH_EDITORONLY_DATA
	if (SpriteComponent)
	{
		SpriteComponent->SetSprite(LoadObject<UTexture2D>(nullptr,
			TEXT("/OmegaGameFramework/Textures/icons/pixel/OmegaIcon_I_Clock.OmegaIcon_I_Clock")));
		SpriteComponent->SetRelativeScale3D(FVector(3.0f));
	}
#endif
}

void AOmegaTimerActor::BeginPlay()
{
	Super::BeginPlay();
	TimeRemaining = 0.0f;
	AudioComponent->OnAudioFinished.AddDynamic(this, &AOmegaTimerActor::Local_OnAudioFinished);
	if (bAutoPlay)
	{
		PlayTimer();
	}
}

void AOmegaTimerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TimeRemaining > 0.0f)
	{
		TimeRemaining -= DeltaTime;
		if (TimeRemaining <= 0.0f)
		{
			TimeRemaining = 0.0f;
			Local_OnTimerEnd();
		}
		else
		{
			Local_TickSound();
		}
	}
}

bool AOmegaTimerActor::IsTimerPlaying() const
{
	return TimeRemaining > 0.0f;
}

bool AOmegaTimerActor::PlayTimer()
{
	TimeRemaining = FMath::Max(Duration, KINDA_SMALL_NUMBER);
	Local_ActivePercentSound = nullptr;

	// Start the default looping sound; Local_TickSound will switch it if a percent-threshold is crossed
	if (bPlaySound && AudioComponent && Sound_Default)
	{
		AudioComponent->SetSound(Sound_Default);
		AudioComponent->Play();
	}

	if (Event_Begin.IsValid())
	{
		UActorTagEventFunctions::FireTagEventOnActor(this, Event_Begin);
	}
	UActorTagEventFunctions::FireActorTagEvents_Container(EventsOn_Begin);

	return true;
}

bool AOmegaTimerActor::StopTimer()
{
	if (!IsTimerPlaying())
	{
		return false;
	}

	TimeRemaining = 0.0f;
	Local_OnTimerEnd();
	return true;
}

void AOmegaTimerActor::OnTagEvent_Implementation(FGameplayTag Event)
{
	IActorTagEventInterface::OnTagEvent_Implementation(Event);
	if (Event == Event_Begin && !IsTimerPlaying())
	{
		PlayTimer();
	}
	else if (Event == Event_End)
	{
		StopTimer();
	}
}

void AOmegaTimerActor::Local_OnTimerEnd()
{
	if (AudioComponent && AudioComponent->IsPlaying())
	{
		AudioComponent->Stop();
	}
	Local_ActivePercentSound = nullptr;

	if (Event_End.IsValid())
	{
		UActorTagEventFunctions::FireTagEventOnActor(this, Event_End);
	}
	UActorTagEventFunctions::FireActorTagEvents_Container(EventsOn_End);

	if (bLoop)
	{
		PlayTimer();
	}
}

void AOmegaTimerActor::Local_OnAudioFinished()
{
	if (bPlaySound && IsTimerPlaying() && Local_ActivePercentSound)
	{
		AudioComponent->Play();
	}
}

void AOmegaTimerActor::Local_TickSound()
{
	if (!bPlaySound || !AudioComponent || Sound_AtPercent.IsEmpty())
	{
		return;
	}

	const float CurrentPercent = (Duration > 0.0f) ? (TimeRemaining / Duration) : 0.0f;

	// Find the Sound_AtPercent entry with the smallest threshold that CurrentPercent is still at-or-under.
	// e.g. with {SoundA:0.5, SoundB:0.25} at 20%: both qualify, SoundB (0.25) wins as the most specific.
	USoundBase* DesiredSound = nullptr;
	float BestThreshold = TNumericLimits<float>::Max();

	for (const TPair<USoundBase*, float>& Entry : Sound_AtPercent)
	{
		if (Entry.Key && CurrentPercent <= Entry.Value && Entry.Value < BestThreshold)
		{
			DesiredSound = Entry.Key;
			BestThreshold = Entry.Value;
		}
	}

	// Fall back to the default sound when no percent-threshold is met
	if (!DesiredSound)
	{
		DesiredSound = Sound_Default;
	}

	// Only restart the audio component when the desired sound actually changes
	if (DesiredSound != Local_ActivePercentSound)
	{
		Local_ActivePercentSound = DesiredSound;
		if (DesiredSound)
		{
			AudioComponent->SetSound(DesiredSound);
			AudioComponent->Play();
		}
		else
		{
			AudioComponent->Stop();
		}
	}
}
