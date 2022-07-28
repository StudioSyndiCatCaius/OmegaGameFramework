// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/Ability_Targeting.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AAbility_Targeting::AAbility_Targeting()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	TargetRegistryRange = CreateDefaultSubobject<USphereComponent>(TEXT("Target Registry Range"));
	
	TargetReticle = CreateDefaultSubobject<UWidgetComponent>(TEXT("Target Reticle"));
	TargetReticle->SetWidgetSpace(EWidgetSpace::Screen);
	TargetReticle->SetHiddenInGame(true);

	SetActorHiddenInGame(false);
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAbility_Targeting::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAbility_Targeting::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAbility_Targeting::Native_ActivatedTick(float DeltaTime)
{
	// Camera Look at Target
	if(CameraTracksTargets() && CombatantOwner->GetActiveTarget() && GetOwnerCameraComponent())
	{
		FVector TargetPoint = CombatantOwner->GetActiveTarget()->GetOwner()->GetActorLocation()+LookTargetOffset;
		FVector InitPoint = GetOwnerCameraComponent()->GetComponentLocation();
		FRotator TargetLook = UKismetMathLibrary::FindLookAtRotation(InitPoint, TargetPoint);
		
		FRotator FinalLook = UKismetMathLibrary::RInterpTo(CombatantOwner->GetOwnerController()->GetControlRotation(), TargetLook, DeltaTime, CameraInterpSpeed);
		FinalLook.Pitch = UKismetMathLibrary::Clamp(FinalLook.Pitch, MinCameraRange, MaxCameraRange);
		
		CombatantOwner->GetOwnerController()->SetControlRotation(FinalLook);
	}

	if(bFaceTarget && CombatantOwner->GetActiveTarget())
	{
		FVector TargetPoint = CombatantOwner->GetActiveTarget()->GetOwner()->GetActorLocation();
		FVector InitPoint = CombatantOwner->GetOwner()->GetActorLocation();
		FRotator TargetLook = UKismetMathLibrary::FindLookAtRotation(InitPoint, TargetPoint);
		
		FRotator FinalLook = UKismetMathLibrary::RInterpTo(CombatantOwner->GetOwnerController()->GetControlRotation(), TargetLook, DeltaTime, FaceTargetInterpSeed);
		FinalLook.Pitch = 0;
		FinalLook.Roll = 0;
		
		CombatantOwner->GetOwner()->SetActorRotation(FinalLook);
	}
	
	// Set Reticle to Target
	if(TargetReticle && CombatantOwner->GetActiveTarget())
	{
		TargetReticle->SetWorldLocation(CombatantOwner->GetActiveTarget()->GetOwner()->GetActorLocation());
	}
	Super::Native_ActivatedTick(DeltaTime);
}

/////////////////////////////////////////
//---- AblilityActivated ----//
/////////////////////////////////////////
void AAbility_Targeting::Native_AbilityActivated(UObject* Context)
{
	TargetReticle->SetHiddenInGame(false);
	if(TargetingBeginSound)
	{
		UGameplayStatics::PlaySound2D(this, TargetingBeginSound);
	}
	if(GetAbilityOwnerCharacterMoveComponent() && bFaceTarget)
	{
		GetAbilityOwnerCharacterMoveComponent()->bOrientRotationToMovement = false;
	}
	Super::Native_AbilityActivated(Context);
}

/////////////////////////////////////////
//---- AbilityFinished ----//
/////////////////////////////////////////
void AAbility_Targeting::Native_AbilityFinished(bool Cancelled)
{
	TargetReticle->SetHiddenInGame(true);
	if(TargetingEndSound)
	{
		UGameplayStatics::PlaySound2D(this, TargetingEndSound);
	}
	if(GetAbilityOwnerCharacterMoveComponent() && bFaceTarget)
	{
		GetAbilityOwnerCharacterMoveComponent()->bOrientRotationToMovement = true;
	}
	Super::Native_AbilityFinished(Cancelled);
}

void AAbility_Targeting::NotifyActorBeginOverlap(AActor* OtherActor)
{
	UCombatantComponent* CheckedCombatant = nullptr;
	if(OtherActor->GetComponentByClass(UCombatantComponent::StaticClass()))
	{
		CheckedCombatant = Cast<UCombatantComponent>(OtherActor->GetComponentByClass(UCombatantComponent::StaticClass()));
	}

	if(CheckedCombatant != CombatantOwner && !CombatantOwner->GetRegisteredTargetList().Contains(CheckedCombatant))
	{
		CombatantOwner->AddTargetToList(CheckedCombatant);
		OnTargetRegistered(CheckedCombatant);
	}
	Super::NotifyActorBeginOverlap(OtherActor);
}

void AAbility_Targeting::NotifyActorEndOverlap(AActor* OtherActor)
{
	UCombatantComponent* CheckedCombatant = nullptr;
	if(OtherActor->GetComponentByClass(UCombatantComponent::StaticClass()))
	{
		CheckedCombatant = Cast<UCombatantComponent>(OtherActor->GetComponentByClass(UCombatantComponent::StaticClass()));
	}

	if(CombatantOwner->GetRegisteredTargetList().Contains(CheckedCombatant))
	{
		CombatantOwner->RemoveTargetFromList(CheckedCombatant);
		OnTargetUnregistered(CheckedCombatant);
	}
	Super::NotifyActorEndOverlap(OtherActor);
}
