// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Actors/Actor_GameplayCue.h"
#include "NiagaraComponent.h"
#include "Components/AudioComponent.h"
#include "Engine/World.h"
#include "Components/PostProcessComponent.h"
#include "Components/BillboardComponent.h"
#include "Camera/CameraShakeSourceComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/OmegaUtils_Methods.h"

AOmegaGameplayCue::AOmegaGameplayCue()
{
	RootComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("CueRoot"));
	
	Niagara = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Niagara"));
	Niagara->SetupAttachment(RootComponent);
	Audio = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	Audio->SetupAttachment(RootComponent);
	PostProcess = CreateDefaultSubobject<UPostProcessComponent>(TEXT("PostProcess"));
	PostProcess->SetupAttachment(RootComponent);
	CameraShake = CreateDefaultSubobject<UCameraShakeSourceComponent>(TEXT("Camera Shake"));
	CameraShake->SetupAttachment(RootComponent);

	PostProcess->bUnbound=false;
	CameraShake->bAutoStart=true;
}

void AOmegaGameplayCue::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("Run begin play on cue: %s"), *GetName());
	// Bind the function to the OnSystemFinished event of the Niagara component

	// Bind the function to the OnAudioFinished event of the Audio component
	
	int32 temp_index=0;
	
	// Play Sound
	temp_index = UKismetMathLibrary::RandomInteger(Sounds.Num()-1);
	if (Sounds.IsValidIndex(temp_index))
	{
		Audio->SetSound(Sounds[temp_index]);
	}
	Audio->Play();
	Audio->OnAudioFinished.AddDynamic(this, &AOmegaGameplayCue::TryFinish);
	
	// Play Niagara
	temp_index = UKismetMathLibrary::RandomInteger(NiagaraParticles.Num()-1);
	if (NiagaraParticles.IsValidIndex(temp_index))
	{
		Niagara->SetAsset(NiagaraParticles[temp_index]);
	}
	Niagara->ResetSystem();
	Niagara->OnSystemFinished.AddDynamic(this, &AOmegaGameplayCue::OnFinishParticle);
	UE_LOG(LogTemp, Warning, TEXT("Finish begin play on cue: %s"), *GetName());
	Super::BeginPlay();
}

void AOmegaGameplayCue::OnFinishParticle(UNiagaraComponent* Comp)
{
	TryFinish();
}

void AOmegaGameplayCue::TryFinish()
{
	if(!bAttemptAutocomplete)
	{
		return;
	}
	if(!Audio->IsPlaying() && Niagara->IsComplete())
	{
		K2_DestroyActor();
	}
}

void AOmegaGameplayCue::Tick(float DeltaTime)
{
	
}

AOmegaGameplayCue* UOmegaGameplayCueFunctions::PlayGameplayCue(UObject* WorldContextObject, TSubclassOf<AOmegaGameplayCue> Cue,
                                                               FTransform Origin, FHitResult Hit, USceneComponent* AttachComponent, EAttachmentRule AttachRules)
{
	if (!WorldContextObject || !WorldContextObject->GetWorld()) { return nullptr; }
	if (Cue)
	{
		AOmegaGameplayCue* CueRef = WorldContextObject->GetWorld()->SpawnActorDeferred<AOmegaGameplayCue>(Cue, Origin, nullptr);
		CueRef->HitData=Hit;
		UGameplayStatics::FinishSpawningActor(CueRef,Origin);
		if(AttachComponent)
		{
			CueRef->AttachToComponent(AttachComponent, FAttachmentTransformRules(AttachRules, false));
		}
		return CueRef;
	}
	OGF_Log::LogWarning("Failed to spawn cue. No valid class");
	return nullptr;
}

AOmegaGameplayCue* UOmegaGameplayCueFunctions::PlayGameplayCue_FromConfig(UObject* WorldContextObject, FOmegaGameplayCueConfig Config,
	FTransform Origin, FHitResult Hit, USceneComponent* AttachComponent, EAttachmentRule AttachRules)
{
	if (!WorldContextObject || !WorldContextObject->GetWorld()) { return nullptr; }
	if (!Config.CueClass)
	{
		OGF_Log::LogWarning("Failed to spawn cue from config. No valid class");
		return nullptr;
	}
	AOmegaGameplayCue* CueRef = WorldContextObject->GetWorld()->SpawnActorDeferred<AOmegaGameplayCue>(Config.CueClass, Origin, nullptr);
	CueRef->HitData = Hit;
	if (Config.OverrideSound)
	{
		CueRef->Sounds.Empty();
		CueRef->Sounds.Add(Config.OverrideSound);
	}
	if (Config.OverrideNiagara)
	{
		CueRef->NiagaraParticles.Empty();
		CueRef->NiagaraParticles.Add(Config.OverrideNiagara);
	}
	UGameplayStatics::FinishSpawningActor(CueRef, Origin);
	if (AttachComponent)
	{
		CueRef->AttachToComponent(AttachComponent, FAttachmentTransformRules(AttachRules, false));
	}
	return CueRef;
}


