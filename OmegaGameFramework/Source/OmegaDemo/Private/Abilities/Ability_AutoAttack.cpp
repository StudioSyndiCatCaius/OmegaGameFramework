// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/Ability_AutoAttack.h"
#include "AnimGraphRuntime/Public/PlayMontageCallbackProxy.h"
#include "GameFramework/Character.h"
#include "Gameplay/CombatantFunctions.h"
#include "Kismet/KismetMathLibrary.h"

// SETUP ABILITY BLUEPRINT
AAbility_AutoAttack::AAbility_AutoAttack()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// ABILTY GRANTED
void AAbility_AutoAttack::BeginPlay()
{
	Super::BeginPlay();
	if(GetAbilityOwnerCharacter())
	{
		LocalAnimInst = GetAbilityOwnerMesh()->GetAnimInstance();
	}
}

// Charge & Try Attack
void AAbility_AutoAttack::Tick(float DeltaTime)
{
	if(AttackChargeAmount >= 1)	//Is attack is charged?
		{
			if (CombatantOwner->GetActiveTarget() && (CombatantOwner->GetOwner()->GetDistanceTo(CombatantOwner->GetActiveTarget()->GetOwner())) <=GetAttackRange()) //targetInRange?
			{
				Execute(nullptr);
			}
		}
	else if(!bIsActive)
	{
		//Charge Attack
		AttackChargeAmount = UKismetMathLibrary::FInterpTo_Constant(AttackChargeAmount, 1.0, DeltaTime, 1/GetAttackCooldownTime());
	}
	
	Super::Tick(DeltaTime);
}

//Get Attack Animation
UAnimMontage* AAbility_AutoAttack::GetNextAttackMontage()
{
	CurrentAttackIndex = CurrentAttackIndex+1;
	if(!GetAttackMontages().IsValidIndex(CurrentAttackIndex))
	{
		CurrentAttackIndex = 0;
	}
	if(GetAttackMontages().IsValidIndex(CurrentAttackIndex))
	{
		;
		return GetAttackMontages()[CurrentAttackIndex];
	}
	return nullptr;
}

//Begin Attack
void AAbility_AutoAttack::Native_AbilityActivated(UObject* Context)
{
	
	if(GetNextAttackMontage())
	{
		//LocalAnimInst->OnPlayMontageNotifyBegin.AddDynamic(this, &AAbility_AutoAttack::Local_OnNotify);
		LocalAnimInst->OnMontageEnded.AddDynamic(this, &AAbility_AutoAttack::Local_OnAttackEnd);
		LocalAnimInst->Montage_Play(GetNextAttackMontage());
	}
	else
	{
		CancelAbility();
	}
	Super::Native_AbilityActivated(Context);
}

// Attack Notify
void AAbility_AutoAttack::Local_OnNotify(FName Notify, const FBranchingPointNotifyPayload& DumPayload)
{
	if(Notify == ImpactNotifyName)
	{
		if(CombatantOwner->GetActiveTarget())
		{
			//UCombatantFunctions::ApplyEffectFromAsset(CombatantOwner->GetActiveTarget(), CombatantOwner, this);
		}
	}
}

//Attack Ends
void AAbility_AutoAttack::Local_OnAttackEnd(UAnimMontage* Montage, bool bInterrupted)
{
	if(bInterrupted)
	{
		CancelAbility();
	}
	else
	{
		CompleteAbility();
	}
}

//Finish Ability
void AAbility_AutoAttack::Native_AbilityFinished(bool Cancelled)
{
	LocalAnimInst->OnMontageEnded.RemoveDynamic(this, &AAbility_AutoAttack::Local_OnAttackEnd);
	AttackChargeAmount = 0;
	Super::Native_AbilityFinished(Cancelled);
}



