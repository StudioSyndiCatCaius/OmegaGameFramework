// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Gameplay/OmegaGameplayCue.h"
#include "NiagaraComponent.h"
#include "Components/AudioComponent.h"
#include "Engine/World.h"
#include "Components/PostProcessComponent.h"
#include "Camera/CameraShakeSourceComponent.h"
#include "Kismet/GameplayStatics.h"

AOmegaGameplayCue::AOmegaGameplayCue()
{
	Niagara = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Niagara"));
	Audio = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	PostProcess = CreateDefaultSubobject<UPostProcessComponent>(TEXT("PostProcess"));
	CameraShake = CreateDefaultSubobject<UCameraShakeSourceComponent>(TEXT("Camera Shake"));

	PostProcess->bUnbound=false;
	CameraShake->bAutoStart=true;
}

void AOmegaGameplayCue::BeginPlay()
{
	// Bind the function to the OnSystemFinished event of the Niagara component
	Niagara->OnSystemFinished.AddDynamic(this, &AOmegaGameplayCue::OnFinishParticle);
	// Bind the function to the OnAudioFinished event of the Audio component
	Audio->OnAudioFinished.AddDynamic(this, &AOmegaGameplayCue::TryFinish);
	//Super::BeginPlay();
}

void AOmegaGameplayCue::OnFinishParticle(UNiagaraComponent* Comp)
{
	TryFinish();
}

void AOmegaGameplayCue::TryFinish()
{
	if(!Audio->IsPlaying() && Niagara->IsComplete())
	{
		K2_DestroyActor();
	}
}

void AOmegaGameplayCue::Tick(float DeltaTime)
{
	
}

void UOmegaGameplayCueFunctions::PlayGameplayCue(UObject* WorldContextObject, TSubclassOf<AOmegaGameplayCue> Cue,
                                                 FTransform Origin, AActor* ActorOrigin)
{
	if(Cue)
	{
		AOmegaGameplayCue* CueRef = WorldContextObject->GetWorld()->SpawnActorDeferred<AOmegaGameplayCue>(Cue, Origin, nullptr);
		UGameplayStatics::FinishSpawningActor(CueRef, Origin);

		if(ActorOrigin)
		{
			CueRef->AttachToActor(ActorOrigin, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));
		}
	}
}
