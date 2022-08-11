// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/Ability_Montage.h"
#include "AnimGraphRuntime/Public/PlayMontageCallbackProxy.h"
#include "GameFramework/Character.h"

// Sets default values
AAbility_Montage::AAbility_Montage()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAbility_Montage::BeginPlay()
{
	if(GetAbilityOwnerMesh())
	{
		LocalAnimInst = GetAbilityOwnerMesh()->GetAnimInstance();
		LocalAnimInst->OnPlayMontageNotifyBegin.AddDynamic(this, &AAbility_Montage::OnNotifyBeginReceived);
		LocalAnimInst->OnPlayMontageNotifyEnd.AddDynamic(this, &AAbility_Montage::OnNotifyEndReceived);
		LocalAnimInst->OnMontageEnded.AddDynamic(this, &AAbility_Montage::Local_OnMontageEnd);
		UE_LOG(LogTemp, Warning, TEXT("Test Notify") );
	}
	Super::BeginPlay();
}

// Called every frame
void AAbility_Montage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAbility_Montage::Native_AbilityActivated(UObject* Context)
{
	if(GetMontage() && LocalAnimInst)
	{
		LocalAnimInst->Montage_Play(GetMontage());
	}
	
	Super::Native_AbilityActivated(Context);
	
}

void AAbility_Montage::OnNotifyBeginReceived(FName Notify, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload)
{
	OnNotifyBegin(Notify);
}

void AAbility_Montage::OnNotifyEndReceived(FName Notify, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload)
{
	OnNotifyEnd(Notify);
}

void AAbility_Montage::Local_OnMontageEnd(UAnimMontage* Montage, bool bInterrupted)
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
