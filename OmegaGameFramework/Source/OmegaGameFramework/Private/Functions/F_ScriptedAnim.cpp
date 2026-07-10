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
	if (OnNotifyCallback) OnNotifyCallback(Notify);
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
		if (OnFinishCallback) OnFinishCallback("");
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

UAsyncAction_ScriptedAnimation* UOmegaFunctions_ScriptedAnimation::PlayScriptedAnimationWithCallbacks(
	UObject* WorldContextObject,
	AActor* Instigator,
	FOmegaScriptedAnimationData AnimationData,
	TFunction<void(const FString&)> OnFinish,
	TFunction<void(const FString&)> OnNotify)
{
	UAsyncAction_ScriptedAnimation* Node = UAsyncAction_ScriptedAnimation::PlayScriptedAnimation(WorldContextObject, Instigator, AnimationData);
	Node->OnFinishCallback = OnFinish;
	Node->OnNotifyCallback = OnNotify;
	Node->RegisterWithGameInstance(WorldContextObject);
	Node->Activate();
	return Node;
}
