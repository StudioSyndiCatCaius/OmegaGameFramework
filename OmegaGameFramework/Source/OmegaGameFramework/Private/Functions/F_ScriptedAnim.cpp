// Copyright Studio Syndicat 2023. All Rights Reserved.


#include "Functions/F_ScriptedAnim.h"

void UOmegaScriptedAnimation::Native_Begin(AActor* instigator)
{
	REF_Instigator=instigator;
	OnAnimBegin.Broadcast(this);
	OnBegin();
}

void UOmegaScriptedAnimation::FinishAnimation()
{
	OnAnimEnd.Broadcast(this);
	OnEnd();
}

TArray<UOmegaScriptedAnimation*> FOmegaScriptedAnimationData::GetAllAnimations() const
{
	TArray<UOmegaScriptedAnimation*> out;
	
	for (auto* a : anim_preset)
	{
		if (a)
		{
			out.Append(a->Animations);
		}
	}
	out.Append(anim_inline);
	for (auto* a : anim_presetEnd)
	{
		if (a)
		{
			out.Append(a->Animations);
		}
	}
	return out;
}

AActor* UOmegaScriptedAnimation::GetAnimationInstigator() const
{
	return REF_Instigator;
}

void UOmegaScriptedAnimation::Notify(const FString& notify)
{
	OnAnimNotify.Broadcast(notify);
}

void UAsyncAction_ScriptedAnimation::L_Notify(const FString& Notify)
{
	OnNotify.Broadcast(Notify);
}

void UAsyncAction_ScriptedAnimation::Next_Anim(UOmegaScriptedAnimation* anim)
{
	if (current_anim)
	{
		current_anim->OnAnimEnd.RemoveDynamic(this,&UAsyncAction_ScriptedAnimation::Next_Anim);
		current_anim=nullptr;
	}
	
	anim_index+=1;
	
	if (local_animData.GetAllAnimations().IsValidIndex(anim_index))
	{
		current_anim=local_animData.GetAllAnimations()[anim_index];
		current_anim->OnAnimEnd.AddDynamic(this,&UAsyncAction_ScriptedAnimation::Next_Anim);
		current_anim->OnAnimNotify.AddDynamic(this,&UAsyncAction_ScriptedAnimation::L_Notify);
		current_anim->Native_Begin(local_Instigator);
	}
	else
	{
		Finished.Broadcast("");
		SetReadyToDestroy();
	}
}

void UAsyncAction_ScriptedAnimation::Activate()
{
	Next_Anim(nullptr);
}

UAsyncAction_ScriptedAnimation* UAsyncAction_ScriptedAnimation::PlayScriptedAnimation(UObject* WorldContextObject,
                                                                                      AActor* Instigator, FOmegaScriptedAnimationData AnimationData)
{
	UAsyncAction_ScriptedAnimation* NewNode = NewObject<UAsyncAction_ScriptedAnimation>();
	NewNode->local_Instigator=Instigator;
	NewNode->local_animData=AnimationData;
	return NewNode;
}

void UOmegaScriptedAnimation::OnEnd_Implementation()
{
}

void UOmegaScriptedAnimation::OnBegin_Implementation()
{
}
