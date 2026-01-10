// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_Actors.h"

#include "FlowAsset.h"
#include "Functions/F_Actor.h"
#include "GameFramework/Character.h"


AActor* UFlowNode_ActorBase::GetNodeInstigator()
{
	return GetActor();
}

AActor* UFlowNode_ActorBase::GetActor() const
{
	if(Actor && GetWorld())
	{
		if(AActor* a = Actor->Private_GetActor(GetWorld()))
		{
			return a;
		}
	}
	if(Actor_Identity)
	{
		if(AActor* a=GetFlowAsset()->GetActorByBinding_Asset(Actor_Identity,true))
		{
			return a;
		}
	}
	return nullptr;
}

TArray<AActor*> UFlowNode_ActorBase::GetActors() const
{
	TArray<AActor*> out;
	if(Actor && GetWorld())
	{
		out.Append(Actor->GetActors(GetWorld()));
	}
	
	if(Actor_Identity)
	{
		if(AActor* a=GetFlowAsset()->GetActorByBinding_Asset(Actor_Identity,true))
		{
			out.Add(a);
		}
	}
	return out;
}

void UFlowNode_Actor_Modify::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);

	FActorModifiers mods;
	mods.Script=Modifiers;
	
	for(auto * a : GetActors())
	{
		if(a)
		{
			UOmegaComponentModifierFunctions::ApplyModifierTo_Actor(mods,a);
		}
	}
	TriggerFirstOutput(true);
}

bool UFlowNode_Actor_Condition::L_CheckCondition()
{
	for(auto* a : GetActors())
	{
		if (a)
		{
			for(auto* c : Conditions)
			{
				if(!c->CheckActorCondition(a))
				{
					return false;
				}
			}
		}
	}
	return true;
}

UFlowNode_Actor_Condition::UFlowNode_Actor_Condition()
{
	InputPins.Empty();
	OutputPins.Empty();
	InputPins.Add(FFlowPin(TEXT("In")));
	
	OutputPins.Add(FFlowPin(TEXT("true")));
	OutputPins.Add(FFlowPin(TEXT("false")));
}

void UFlowNode_Actor_Condition::ExecuteInput(const FName& PinName)
{
	if(L_CheckCondition())
	{
		TriggerOutput(TEXT("true"));
	}
	else
	{
		TriggerOutput(TEXT("false"));	
	}
}
/*
UFlowNode_Actor_Montage::UFlowNode_Actor_Montage()
{
	OutputPins.Empty();
}

void UFlowNode_Actor_Montage::OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted)
{
}

void UFlowNode_Actor_Montage::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	if (Montage)
	{
		if(ACharacter* c=Cast<ACharacter>(L_GetActor()))
		{
			if(UAnimInstance* AnimInstance=c->GetMesh()->GetAnimInstance())
			{
				const float MontageLength = AnimInstance->Montage_Play(Montage, PlayRate, EMontagePlayReturnType::MontageLength, StartingPosition);
				bool bPlayedSuccessfully = (MontageLength > 0.f);

				
				if (bPlayedSuccessfully)
				{
					AnimInstancePtr = AnimInstance;
					if (FAnimMontageInstance* MontageInstance = AnimInstance->GetActiveInstanceForMontage(MontageToPlay))
					{
						MontageInstanceID = MontageInstance->GetInstanceID();
					}

					if (StartingSection != NAME_None)
					{
						AnimInstance->Montage_JumpToSection(StartingSection, MontageToPlay);
					}


					AnimInstance->OnMontageBlendingOut.AddDynamic(this, &UFlowNode_Actor_Montage::OnMontageBlendingOut);

					AnimInstance->OnMontageEnded.AddDynamic(this, &UFlowNode_Actor_Montage::OnMontageEnded);
				}
			}
		}
	}
	TriggerOutput(TEXT("Start"));
}
*/