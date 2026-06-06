// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Physics.h"

#include "OmegaSettings.h"
#include "Actors/Actor_GameplayCue.h"
#include "Functions/F_Math.h"
#include "Functions/F_Trace.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/OmegaUtils_Macros.h"


FHitResult UOmegaPhysicsEvent::GetHit(AActor* Instigator)
{
	if (TraceEvent.Logic)
	{
		bool bResult;
		return UOmegaScriptedTraceFunctions::ScriptedTrace_Single(Instigator,TraceEvent,bResult);
	}
	return FHitResult();
}

void UOmegaAnimNotify_PhysicsEvent::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                           const FAnimNotifyEventReference& EventReference)
{
	if (UOmegaPhysicsEvent* ev=Event.LoadSynchronous())
	{
		if (MeshComp->GetWorld()->GetGameInstance())
		{
			UOmegaFunctions_Physics::RunEvent(MeshComp->GetOwner(),ev);	
		}
			
	}
	
	Super::Notify(MeshComp, Animation, EventReference);
}

FString UOmegaAnimNotify_PhysicsEvent::GetNotifyName_Implementation() const
{
	FString s="Event: ";
	if (Event.IsValid())
	{
		s+=Event.GetAssetName();
	}
	return s;
}

void UOmegaFunctions_Physics::RunEvent(AActor* Instigator, UOmegaPhysicsEvent* Event)
{
	if (Instigator && Event)
	{
		FHitResult _hit=Event->GetHit(Instigator);
		UPhysicalMaterial* _PhysMat=_hit.PhysMaterial.Get();
		if (UOmegaPhysicsSurfaceType* surfaceTypeData=OGF_CFG()->GetSurfaceTypeFromMaterial(_PhysMat))
		{
			if(surfaceTypeData->EventData.Contains(Event->EventTag))
			{
				FOmegaPhysicsEventData eventData=surfaceTypeData->EventData[Event->EventTag];
				if (TSubclassOf<AOmegaGameplayCue> cueClass=eventData.Cue)
				{
					FTransform hitTransform;
					hitTransform.SetLocation(_hit.ImpactPoint);
					FRotator r=UKismetMathLibrary::Conv_VectorToRotator(_hit.ImpactNormal);
					hitTransform.SetRotation(r.Quaternion());
					UOmegaGameplayCueFunctions::PlayGameplayCue(Instigator,cueClass,hitTransform,_hit,Instigator->GetRootComponent());
				}
			}
		}
	}
}

FRotator UOmegaFunctions_Physics::GetRotationFromHitResultNormal(FHitResult Hit, bool bImpact, bool X, bool Y, bool Z)
{
	FVector normal = bImpact ? Hit.ImpactNormal : Hit.Normal;
	FRotator rot = UKismetMathLibrary::Conv_VectorToRotator(normal);
	if (!X) rot.Roll = 0.0f;
	if (!Y) rot.Pitch = 0.0f;
	if (!Z) rot.Yaw = 0.0f;
	return rot;
}

FVector UOmegaFunctions_Physics::OffsetVector_FromHitResult(FHitResult Hit, FVector Offset, FRotator ExtraRotationOffset,
	bool bImpact)
{
	FVector temp_v;
	FVector temp_norm;
	if (bImpact)
	{
		temp_v=Hit.ImpactPoint;
		temp_norm=Hit.ImpactNormal;
	}
	else
	{
		temp_v=Hit.Location;
		temp_norm=Hit.Normal;
	}
	
	FRotator temp_r=UKismetMathLibrary::ComposeRotators(ExtraRotationOffset,UKismetMathLibrary::Conv_VectorToRotator(temp_norm));
	
	return UOmegaMathFunctions::Offset_Vector(temp_v,temp_r,Offset);
}

