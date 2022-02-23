// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaAbility.h"

#include "GameFramework/Character.h"
#include "Gameplay/CombatantComponent.h"
#include "Input/InputReceiverComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"

// Sets default values
AOmegaAbility::AOmegaAbility()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorHiddenInGame(true);
	DefaultInputReceiver = CreateDefaultSubobject<UInputReceiverComponent>(TEXT("Default Input Reciever"));
	bActivateOnStarted = true;
}

// Called when the game starts or when spawned
void AOmegaAbility::BeginPlay()
{
	Super::BeginPlay();

	DefaultInputReceiver->OverrideInputOwner(CombatantOwner->GetOwner());
	//Bind Default Inputs
	if(bActivateOnStarted)
	{
		DefaultInputReceiver->OnInputStarted.AddDynamic(this, &AOmegaAbility::Native_Execute);
	}
	if(bActivateOnTriggered)
	{
		DefaultInputReceiver->OnInputTriggered.AddDynamic(this, &AOmegaAbility::Native_Execute);
	}
	if(bFinishOnInputComplete)
	{
		DefaultInputReceiver->OnInputCompleted.AddDynamic(this, &AOmegaAbility::CompleteAbility);
	}
	if(bFinishOnInputCancel)
	{
		DefaultInputReceiver->OnInputCancel.AddDynamic(this, &AOmegaAbility::CancelAbility);
	}
	
	
	SetInputEnabledForOwner(true);
}

void AOmegaAbility::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	RecieveFinish(true);
}

// Called every frame
void AOmegaAbility::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(bIsActive)
	{
		ActivatedTick(DeltaTime);
	}
}

void AOmegaAbility::Execute(UObject* Context)
{
	// Success if:
	if(!bIsActive																							// Ability is not already active
		&& !CombatantOwner->IsAbilityTagBlocked(AbilityTags)												// Ability tags are not blocked
		&& CanActivate() && !CombatantOwner->CombatantHasAnyTag(RestrictedOwnerTags)						// Combatant does not have any restricted tags
		&& (CombatantOwner->CombatantHasAllTag(RequiredOwnerTags) || RequiredOwnerTags.IsEmpty())			// Combatant has all required tags.
		)
	{
			UE_LOG(LogTemp, Warning, TEXT("Valid Execute"));
			bIsActive = true;
			CombatantOwner->CancelAbilitiesWithTags(CancelAbilities);
			CombatantOwner->SetAbilityActive(true, this);
			AbilityActivated(Context);
	}
}

void AOmegaAbility::Native_Execute()
{
	UE_LOG(LogTemp, Warning, TEXT("Try Execute"));
	Execute(ContextObject);
}

void AOmegaAbility::Native_Trigger()
{

}

////Local Activate / Deactivate

bool AOmegaAbility::CanActivate_Implementation()
{
	return true;
}

bool AOmegaAbility::SetInputEnabledForOwner(bool Enabled)
{
	APlayerController* TempController;
	if(Cast<APlayerController>(GetAbilityOwnerCharacter()->GetController()))
	{
		TempController = Cast<APlayerController>(GetAbilityOwnerCharacter()->GetController());
		if(Enabled)
		{
			EnableInput(TempController);
			return true;
		}
		else
		{
			DisableInput(TempController);
			return true;
		}
	}
	else
	{
		return false;
	}
}

void AOmegaAbility::CompleteAbility()
{
	RecieveFinish(false);
}

void AOmegaAbility::CancelAbility()
{
	RecieveFinish(true);
}

ACharacter* AOmegaAbility::GetAbilityOwnerCharacter()
{
	return CachedCharacter;
}

UCharacterMovementComponent* AOmegaAbility::GetAbilityOwnerCharacterMoveComponent()
{
	TempMoveComp = CachedCharacter->GetMovementComponent();
	if (TempMoveComp)
	{
		return Cast<UCharacterMovementComponent>(TempMoveComp);
	}
	else
	{
		return nullptr;
	}
	
}

USkeletalMeshComponent* AOmegaAbility::GetAbilityOwnerMesh()
{
	if (CachedCharacter)
	{
		return CachedCharacter->GetMesh();
	}
	else
	{
		return nullptr;
	}
}

void AOmegaAbility::AddBlockedAbilityTags(FGameplayTagContainer AddedTags)
{
	TArray<FGameplayTag> TagList;
	AddedTags.GetGameplayTagArray(TagList);
	for (FGameplayTag TempTag : TagList)
	{
		BlockAbilities.AddTag(TempTag);
	}
}

void AOmegaAbility::RemoveBlockedAbilityTags(FGameplayTagContainer RemovedTags)
{
	TArray<FGameplayTag> TagList;
	RemovedTags.GetGameplayTagArray(TagList);
	for (FGameplayTag TempTag : TagList)
	{
		BlockAbilities.RemoveTag(TempTag);
	}
}

/////////////////////
///Input
/////////////////////

//Finish Ability
void AOmegaAbility::RecieveFinish(bool bCancel)
{
	if (bIsActive)
	{
		bIsActive = false;
		CombatantOwner->SetAbilityActive(false, this);
		AbilityFinished(bCancel);
		OnAbilityFinished.Broadcast(bCancel);
		
	}
}
	

