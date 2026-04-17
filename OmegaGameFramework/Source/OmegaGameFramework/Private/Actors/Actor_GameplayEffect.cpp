// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Actors/Actor_GameplayEffect.h"
#include "Components/TextBlock.h"
#include "DataAssets/DA_Attribute.h"
#include "Functions/F_Common.h"
#include "TimerManager.h"
#include "Components/Component_Combatant.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetTextLibrary.h"


// Sets default values
AOmegaGameplayEffect::AOmegaGameplayEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOmegaGameplayEffect::BeginPlay()
{
	Super::BeginPlay();

	//Construct DamageFormula Object
	//LocalFormula = NewObject<UDamageFormula>(this, DamageFormula, FName("LocalFormula"));

	//Select What Lifetime to use.
	switch (EffectLifetime)
	{
	case EEffectLifetime::EffectLifetime_Instant:
		GetWorldTimerManager().SetTimer(LifetimeTimer, this, &AOmegaGameplayEffect::LifetimeEnd, 0.1f, false);
		break;

	case EEffectLifetime::EffectLifetime_Timer:
		GetWorldTimerManager().SetTimer(LifetimeTimer, this, &AOmegaGameplayEffect::LifetimeEnd, Lifetime, false);
		break;
	case EEffectLifetime::EffectLifetime_OnTrigger:
		//Do code
		break;
	case EEffectLifetime::EffectLifetime_OnDestroy:
		//Do code
		break;
	default: break;
	}

	//CorrectContext
	if(!EffectContext)
	{
		EffectContext = nullptr;
	}

	Local_RemoveEffects(RemoveEffectsOnApplied);
	
	if(TargetedCombatant)
	{
		TargetedCombatant->OnDamaged.AddDynamic(this, &AOmegaGameplayEffect::OnAttributeDamaged);
		
	}
}

void AOmegaGameplayEffect::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if(EndPlayReason == EEndPlayReason::Destroyed)
	{
		
	}
}



//Trigger the Effect
void AOmegaGameplayEffect::LifetimeEnd()
{
	TriggerEffect();
	K2_DestroyActor();
}



//####################################//####################################//####################################
//-----Generals
//####################################//####################################//####################################
void AOmegaGameplayEffect::GetGeneralAssetLabel_Implementation(FString& Label)
{
	Label = UOmegaGameFrameworkBPLibrary::GetObjectLabel(EffectContext);
}

void AOmegaGameplayEffect::GetGeneralAssetColor_Implementation(FGameplayTag Tag, FLinearColor& Color)
{
	if(EffectContext && EffectContext->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		Execute_GetGeneralAssetColor(EffectContext,Tag,Color);
	}
}

void AOmegaGameplayEffect::GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description)
{
	if(EffectContext && EffectContext->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		Execute_GetGeneralDataText(EffectContext,Tag,Name,Description);
	}
}

void AOmegaGameplayEffect::GetGeneralDataImages_Implementation(FGameplayTag Tag, class UTexture2D*& Texture,
	class UMaterialInterface*& Material, FSlateBrush& Brush)
{
	if(EffectContext && EffectContext->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		Execute_GetGeneralDataImages(EffectContext,Tag,Texture,Material,Brush);
	}
}


// Called every frame
void AOmegaGameplayEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

//Trigger the effects and destory this Effect Actor.
void AOmegaGameplayEffect::TriggerEffect()
{
	//Remove Effects
	Local_RemoveEffects(RemoveEffectsOnTrigger);
	
	UE_LOG(LogTemp, Display, TEXT("Applied Effect"));
	
	if(EffectLifetime == EEffectLifetime::EffectLifetime_OnTrigger)
	{
		K2_DestroyActor();
	}
	
}

bool AOmegaGameplayEffect::EffectCanApply_Implementation(UCombatantComponent* EffectInstigator, UObject* Context, FOmegaCommonMeta Meta) const
{
	return true;
}

UOmegaDamageType* AOmegaGameplayEffect::GetDamageType_Implementation(UObject* Context)
{
	return nullptr;
}


void AOmegaGameplayEffect::Local_RemoveEffects(FGameplayTagContainer Effects)
{
	if(TargetedCombatant)
	{
		for(auto* TempEffect: TargetedCombatant->GetEffectsWithTags(Effects))
		{
			if(TempEffect != this)
			{
				TempEffect->Destroy();
			}
		};
	}
}

//Tags
FGameplayTag AOmegaGameplayEffect::GetObjectGameplayCategory_Implementation()
{
	return EffectCategory;
}

FGameplayTagContainer AOmegaGameplayEffect::GetObjectGameplayTags_Implementation()
{
	return EffectTags;
}

