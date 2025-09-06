// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Actor.h"

#include "Components/ArrowComponent.h"
#include "Components/Component_ActorIdentity.h"
#include "Components/Component_ActorConfig.h"
#include "Functions/OmegaFunctions_Utility.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Subsystems/OmegaSubsystem_Actors.h"

// =====================================================================================================================
// ACTOR
// =====================================================================================================================

void UOmegaActorFunctions::SnapActorToSuface(AActor* Actor, FVector Trace_Start, FVector Trace_End, TEnumAsByte<EObjectTypeQuery> CollisionType)
{
	if(Actor)
	{
		FHitResult hitResult;
		TArray<AActor*> a_ignore;
		a_ignore.Add(Actor);
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		ObjectTypes.Add(CollisionType);
		if(UKismetSystemLibrary::LineTraceSingleForObjects(Actor,Trace_Start+Actor->GetActorLocation(),Trace_End+Actor->GetActorLocation(),ObjectTypes,
			false,a_ignore,EDrawDebugTrace::None,hitResult,true))
		{
			FVector v_origin;
			FVector v_bounds;
			Actor->GetActorBounds(true,v_origin,v_bounds);
			Actor->SetActorLocation(hitResult.ImpactPoint);
			Actor->AddActorLocalOffset(FVector(0,0,v_bounds.Z/2));
		}
	}
}

bool UOmegaActorFunctions::CheckActorCondition(AActor* Actor, FOmegaConditions_Actor Conditions)
{
	return Conditions.CheckConditions(Actor);
}

bool UOmegaActorFunctions::CheckIsActorInteractable(AActor* Actor, AActor* Instigator,FGameplayTag Tag,FOmegaCommonMeta meta, bool& Result)
{
	Result=false;
	if(Actor &&
		Actor->GetClass()->ImplementsInterface(UActorInterface_Interactable::StaticClass())
			&& !IActorInterface_Interactable::Execute_IsInteractionBlocked(Actor,Instigator,Tag,meta))
	{
		Result=true;	
	}
	return Result;
}

bool UOmegaActorFunctions::IsActorPlayer(AActor* Actor, APawn*& Pawn, APlayerController*& Controller, bool& Result)
{
	if(Actor)
	{
		if(APlayerController* _controller=Cast<APlayerController>(Actor))
		{
			Controller=_controller;
			Pawn=_controller->K2_GetPawn();
			Result=true;
			return true;
		}
		if(APawn* _pawn=Cast<APawn>(Actor))
		{
			if(_pawn->IsPlayerControlled())
			{
				Pawn=_pawn;
				Controller=Cast<APlayerController>(_pawn->GetController());
				Result=true;
				return true;
			}
		}
	}
	
	Pawn=nullptr;
	Controller=nullptr;
	Result=false;
	return false;
}

void UOmegaActorFunctions::ApplyActorConfigAsset(AActor* Actor, UOmegaActorConfig* Config)
{
	if(Actor && Config)
	{
		for(auto* i : Config->Scripts)
		{
			i->OnActorConfigured(Actor);
		}
	}
}

AActor* UOmegaActorFunctions::ConfigureChildActor(UChildActorComponent* ChildActor, TSubclassOf<AActor> NewClass,
	UPrimaryDataAsset* NewIdentity, AActor* NewOwner)
{
	
	if(ChildActor)
	{
		if(NewClass)
		{
			ChildActor->SetChildActorClass(NewClass);
		}
		if(AActor* _actor = ChildActor->GetChildActor())
		{
			if(NewOwner)
			{
				_actor->SetOwner(NewOwner);
			}
			if(NewIdentity)
			{
				if(UActorIdentityComponent* _actorIdComp =  Cast<UActorIdentityComponent>(_actor->GetComponentByClass(UActorIdentityComponent::StaticClass())))
				{
					_actorIdComp->SetIdentitySourceAsset(NewIdentity);
				}
			}
			return _actor;
		}
	}
	return nullptr;
}

// =====================================================================================================================
// Actor - filters
// =====================================================================================================================

TArray<AActor*> UOmegaActorFunctions::FilterActors_ByDistanceToVector(TArray<AActor*> actors, FVector vector,
	float distance, bool invert)
{
	TArray<AActor*> filteredActors;
    
	for (AActor* actor : actors)
	{
		if (!actor)
		{
			continue;
		}
        
		float actorDistance = FVector::Dist(actor->GetActorLocation(), vector);
		bool isWithinDistance = actorDistance <= distance;
        
		// If invert is true, we want actors OUTSIDE the distance
		// If invert is false, we want actors INSIDE the distance
		if (isWithinDistance != invert)
		{
			filteredActors.Add(actor);
		}
	}
    
	return filteredActors;
}

TArray<AActor*> UOmegaActorFunctions::FilterActors_OnScreen(TArray<AActor*> actors, float ScreenEdgeTolerance,
	bool invert, APlayerController* player)
{
	TArray<AActor*> filteredActors;
    
	// Get the player controller
	if(!actors.IsValidIndex(0) || !actors[0])
	{
		return filteredActors;
	}
	APlayerController* playerController = actors[0]->GetWorld()->GetFirstPlayerController();
	if(player)
	{
		playerController=player;
	}
	if (!playerController)
	{
		return filteredActors;
	}
    
	// Get viewport size
	int32 viewportWidth = 0;
	int32 viewportHeight = 0;
	playerController->GetViewportSize(viewportWidth, viewportHeight);
    
	for (AActor* actor : actors)
	{
		if (!actor)
		{
			continue;
		}
        
		// Project the actor's location to screen space
		FVector2D screenPosition;
		bool bIsOnScreen = UGameplayStatics::ProjectWorldToScreen(
			playerController, 
			actor->GetActorLocation(), 
			screenPosition, 
			false // Don't use player screen, use actual screen
		);
        
		// Check if it's within the viewport bounds plus tolerance
		bool isVisible = bIsOnScreen && 
						 screenPosition.X >= -ScreenEdgeTolerance && 
						 screenPosition.Y >= -ScreenEdgeTolerance && 
						 screenPosition.X <= viewportWidth + ScreenEdgeTolerance && 
						 screenPosition.Y <= viewportHeight + ScreenEdgeTolerance;
        
		// Add to results based on the invert flag
		if (isVisible != invert)
		{
			filteredActors.Add(actor);
		}
	}
    
	return filteredActors;
}

TArray<AActor*> UOmegaActorFunctions::FilterActors_OverlappingActor(AActor* OverlapTarget, TArray<AActor*> actors,TSubclassOf<AActor> Class)
{
	TArray<AActor*> out;
	if(OverlapTarget)
	{
		TArray<AActor*> temp_actors;
		OverlapTarget->GetOverlappingActors(temp_actors,Class);
		for(auto* a : actors)
		{
			if(a && temp_actors.Contains(a))
			{
				out.Add(a);
			}
		}
		return out;
	}
	return actors;
}


float UOmegaActorFunctions::GetActorWeight(AActor* Actor, FActorWeighter Weighter, float fallback)
{
	if(Actor) { return Weighter.GetWeight(Actor);}
	return fallback;
}



// =====================================================================================================================
// PAWN
// =====================================================================================================================


void UOmegaPawnFunctions::MovePawn2D_Grounded(APawn* Pawn, FVector2D Axis, bool bForce, FVector Forward, FVector Right)
{
	if(Pawn)
	{
		Pawn->AddMovementInput(Forward,Axis.X,bForce);
		Pawn->AddMovementInput(Right,Axis.Y,bForce);
	}
}

void UOmegaPawnFunctions::RotateControl2D(APawn* Pawn, FVector2D Axis, FOmega_CameraConfig config)
{
	if(Pawn)
	{
		Pawn->AddControllerPitchInput(Axis.X*config.scale*UKismetMathLibrary::SelectFloat(-1,1,config.invertX));
		Pawn->AddControllerYawInput(Axis.Y*config.scale*UKismetMathLibrary::SelectFloat(-1,1,config.invertY));
	}
}


void UOmegaPawnFunctions::GetPawnControlVectors(APawn* Pawn, bool X, bool Y, bool Z, FVector& Forward, FVector& Right,
                                                FVector& Up)
{
	if(Pawn)
	{
		FRotator control_rot=Pawn->GetControlRotation();
		FRotator base_rot=UKismetMathLibrary::MakeRotator(
			UKismetMathLibrary::SelectFloat(control_rot.Roll,0,X),
			UKismetMathLibrary::SelectFloat(control_rot.Pitch,0,Y),
			UKismetMathLibrary::SelectFloat(control_rot.Yaw,0,Z)
			);
		Forward=UKismetMathLibrary::GetForwardVector(base_rot);
		Right=UKismetMathLibrary::GetRightVector(base_rot);
		Up=UKismetMathLibrary::GetUpVector(base_rot);
	}
}

void UOmegaComponentFunctions::InterpComponentRotation_FromVector(USceneComponent* component, FVector Vector, float InterpSpeed,
	bool bWorldSpace)
{
	if(component)
	{
		FRotator _start=component->GetRelativeRotation();
		if(bWorldSpace) { _start=component->GetComponentRotation();}
		FRotator _inRot=UKismetMathLibrary::RInterpTo(_start,
			UKismetMathLibrary::ComposeRotators(UOmegaMathFunctions::Conv_VectorToRot_Flat(Vector),_start)
			,UGameplayStatics::GetWorldDeltaSeconds(component),InterpSpeed);

		if(bWorldSpace) { component->SetWorldRotation(_inRot);}
		else { component->SetRelativeRotation(_inRot);}
	}
}

void UOmegaComponentFunctions::LerpSceneComponentTransform(USceneComponent* component, FTransform A, FTransform B,
                                                           float lerp, bool bWorld)
{
	if(component)
	{
		if(bWorld)
		{
			component->SetWorldTransform(UKismetMathLibrary::TLerp(A,B,lerp));
		}
		else
		{
			component->SetRelativeTransform(UKismetMathLibrary::TLerp(A,B,lerp));
		}
	}
}

void UOmegaComponentFunctions::LerpSceneComponentBetweenComponents(USceneComponent* component, USceneComponent* A,
	USceneComponent* B, float lerp, bool bWorld)
{
	if(component && A && B)
	{
		if(bWorld)
		{
			LerpSceneComponentTransform(component,A->GetComponentTransform(),B->GetComponentTransform(),lerp,bWorld);
		}
		else
		{
			LerpSceneComponentTransform(component,A->GetRelativeTransform(),B->GetRelativeTransform(),lerp,bWorld);
		}
	}
}

void UOmegaComponentFunctions::PointArrowComponentToTarget(UArrowComponent* Component, FVector Target)
{
	if(Component)
	{
		FRotator rot_arrow=UKismetMathLibrary::FindLookAtRotation(Component->GetRelativeLocation(),Target);
		float distance_toArrow=UKismetMathLibrary::Vector_Distance(Component->GetRelativeLocation(),Target);
		Component->SetRelativeRotation(rot_arrow);
		Component->ArrowLength=distance_toArrow/Component->ArrowSize;
	}
}
