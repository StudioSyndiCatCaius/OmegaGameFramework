// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_CurveAligner.h"
#include "Subsystems/OmegaSubsystem_Save.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Functions/OmegaFunctions_Utility.h"
#include "Kismet/KismetMathLibrary.h"


TArray<AActor*> UCurveAlignerComponent::CleanArray() const
{
	TArray<AActor*> out;
	for(auto* a : REF_Actors)
	{
		if(a) { out.Add(a);}
	}
	return out;
}

UCurveAlignerComponent::UCurveAlignerComponent()
{
	PrimaryComponentTick.bCanEverTick=true;
	PrimaryComponentTick.bStartWithTickEnabled=true;
}

void UCurveAlignerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	REF_Actors=CleanArray();
	for(auto* a : REF_Actors)
	{
		float _ratio=UOmegaMathFunctions::NormalizeToRange_int32(REF_Actors.Find(a),0,REF_Actors.Num()-1);
		if(a)
		{
			FVector _loc;
			if(Offset_Curve)
			{
				_loc = Offset_Curve->GetVectorValue(_ratio)*Offset_Scale;
			}
			a->SetActorLocation(UKismetMathLibrary::VInterpTo(a->GetActorLocation(),_loc+GetComponentLocation(),DeltaTime,1/Offset_InterpTime));
			
			FRotator _rot=FRotator();
			if(Rotate_Curve)
			{
				_rot =UOmegaMathFunctions::Conv_VectorToRot_Flat(Rotate_Curve->GetVectorValue(_ratio)*Rotate_Scale);
			}
			a->SetActorRotation(UKismetMathLibrary::RInterpTo(a->GetActorRotation(),
				UKismetMathLibrary::ComposeRotators(_rot,GetComponentRotation()),DeltaTime,1/Rotate_InterpTime));
		}
	}
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCurveAlignerComponent::SetActorRegistered(AActor* Actor, bool is_registered)
{
	if(Actor)
	{
		if(is_registered && !REF_Actors.Contains(Actor))
		{
			REF_Actors.Add(Actor);
			OnActorRegistered.Broadcast(this,Actor);
		}
		if(!is_registered && REF_Actors.Contains(Actor))
		{
			REF_Actors.Remove(Actor);
			OnActorUnregistered.Broadcast(this,Actor);
		}
	}
}

void UCurveAlignerComponent::SetActorsRegistered(TArray<AActor*> Actors, bool is_registered)
{
	for(auto* a : Actors) { if(a) { SetActorRegistered(a,is_registered);} }
}
