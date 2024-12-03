// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Actors/Actor_GameplayEffect.h"
#include "Components/TextBlock.h"
#include "Misc/OmegaAttribute.h"
#include "Functions/OmegaFunctions_Common.h"
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
		for(FName TempTag : ActorsTagsGranted)
		{
			TargetedCombatant->GetOwner()->Tags.Add(TempTag);
		}
	}
	EffectBeginPlay(EffectContext);
}

void AOmegaGameplayEffect::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if(EndPlayReason == EEndPlayReason::Destroyed)
	{
		if(TargetedCombatant)
		{
			for(FName TempTag : ActorsTagsGranted)
			{
				TargetedCombatant->GetOwner()->Tags.Remove(TempTag);
			}
		}
	}
}

void AOmegaGameplayEffect::ApplyAdditionalDamage(UOmegaAttribute* Attribute, float Amount)
{
	TargetedCombatant->ApplyAttributeDamage(Attribute, Amount, CombatantInstigator, EffectContext, GetDamageType(EffectContext), GetImpactHitResult());
}

//Trigger the Effect
void AOmegaGameplayEffect::LifetimeEnd()
{
	
	TriggerEffect();
	K2_DestroyActor();
}


//Run Damage Calculation
float AOmegaGameplayEffect::CalculateDamageValue()
{
	if(LocalFormula)
	{
		float LocalDamage;
		LocalFormula->GetDamageAmount(CombatantInstigator, TargetedCombatant, LocalDamage);
		LocalDamage = LocalDamage * Power;
		return LocalDamage;
	}
	return 0;
}

//####################################//####################################//####################################
//-----Generals
//####################################//####################################//####################################
void AOmegaGameplayEffect::GetGeneralAssetLabel_Implementation(FString& Label)
{
	Label = UOmegaGameFrameworkBPLibrary::GetObjectLabel(EffectContext);
}

void AOmegaGameplayEffect::GetGeneralAssetColor_Implementation(FLinearColor& Color)
{
	if(EffectContext && EffectContext->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		Execute_GetGeneralAssetColor(EffectContext, Color);
	}
}

void AOmegaGameplayEffect::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
	FText& Description)
{
	if(EffectContext && EffectContext->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		Execute_GetGeneralDataText(EffectContext,Label,Context,Name,Description);
	}
}

void AOmegaGameplayEffect::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context,
                                                               UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
{
	if(EffectContext && EffectContext->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		Execute_GetGeneralDataImages(EffectContext,Label,Context,Texture,Material,Brush);
	}
}

// Called every frame
void AOmegaGameplayEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetWorldTimerManager().IsTimerActive(LifetimeTimer))
	{
		PastLifetime = GetWorldTimerManager().GetTimerElapsed(LifetimeTimer);
		RemainingLifetime = GetWorldTimerManager().GetTimerRemaining(LifetimeTimer);

		LifetimeUpdated(PastLifetime, RemainingLifetime);
	};
}

//Trigger the effects and destory this Effect Actor.
void AOmegaGameplayEffect::TriggerEffect()
{
	float DamageVal = CalculateDamageValue();
	float DamageFinal = 0;
	// Damage Attributes //
	if(EffectedAttribute)
	{
		if(AttrbuteEffectType == EOmegaEffectType::OET_Heal)
		{
			DamageVal = DamageVal*-1;
		}
		if(TargetedCombatant)
		{
			 DamageFinal = TargetedCombatant->ApplyAttributeDamage(EffectedAttribute, DamageVal, CombatantInstigator, EffectContext, GetDamageType(EffectContext), GetImpactHitResult());
		}
	}
	
	//--Popup--//
	if(bShowPopupOnTrigger)
	{
		UOmegaEffectPopup* LocalPopup = Cast<UOmegaEffectPopup>(CreateWidget(GetWorld(), Local_GetPopupClass()));
		LocalPopup->OwningEffect = this;
		LocalPopup->Incoming_Color = GetTriggeredPopupColor();
		if(UseCustomPopupText)
		{
			LocalPopup->Incoming_Text = GetTriggeredPopupText();
		}
		else
		{
			LocalPopup->Incoming_Text = UKismetTextLibrary::Conv_FloatToText(DamageFinal, ERoundingMode::FromZero);
		}
		
			
		if(TargetedCombatant)
		{
			LocalPopup->GetOwningPlayer()->ProjectWorldLocationToScreen(TargetedCombatant->GetOwner()->GetActorLocation(), LocalPopup->InitPosition);
		}
		
		// After setting everything, add to viewport
		LocalPopup->AddToViewport();
	}

	//Remove Effects
	Local_RemoveEffects(RemoveEffectsOnTrigger);
	
	EffectApplied(DamageFinal);
	OnEffectTriggered.Broadcast(this, DamageFinal);
	UE_LOG(LogTemp, Display, TEXT("Applied Effect"));
	
	if(EffectLifetime == EEffectLifetime::EffectLifetime_OnTrigger)
	{
		K2_DestroyActor();
	}
	
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

FSlateColor AOmegaGameplayEffect::GetTriggeredPopupColor_Implementation()
{
	FSlateColor NewColor = FLinearColor(1.0,1.0,1.0);
	if(EffectedAttribute)
	{
		switch (AttrbuteEffectType) {
			case EOmegaEffectType::OET_Damage:
				NewColor = EffectedAttribute->DamageColor;
				break;
			case EOmegaEffectType::OET_Heal:
				NewColor = EffectedAttribute->AttributeColor;
				break;
			default: ;
		}
	}
	return NewColor;
}

void UDamageFormula::GetDamageAmount_Implementation(UCombatantComponent* Instigator, UCombatantComponent* Target,
	float& DamageOut)
{
	return;
}

void UOmegaEffectPopup::NativeConstruct()
{
	Super::NativeConstruct();

	GetDamageText()->SetText(Incoming_Text);
	GetDamageText()->SetColorAndOpacity(Incoming_Color);

	CurrentPosition = InitPosition;
	SetPositionInViewport(InitPosition);
	
	GetWorld()->GetTimerManager().SetTimer(LifetimeTimer, this, &UOmegaEffectPopup::RemoveFromParent, GetPopupLifetime(), false);
}

void UOmegaEffectPopup::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	CurrentPosition = UKismetMathLibrary::Vector2DInterpTo(CurrentPosition, InitPosition+GetTargetViewportPosition(), InDeltaTime, 1/GetPopupLifetime());
	SetPositionInViewport(CurrentPosition);
	
}


float UOmegaEffectPopup::GetPopupLifetime_Implementation()
{
	return 2.0;
}
