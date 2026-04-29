// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Physics.h"

#include "OmegaSettings.h"
#include "Actors/Actor_GameplayCue.h"
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
					UOmegaGameplayCueFunctions::PlayGameplayCue(Instigator,cueClass,hitTransform,_hit,Instigator);
				}
			}
		}
	}
}

