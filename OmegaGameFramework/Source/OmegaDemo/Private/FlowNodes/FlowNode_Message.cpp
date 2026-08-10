// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_Message.h"

#include "OmegaSettings_Demo.h"
#include "TimerManager.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Engine/World.h"
#include "Functions/F_Message.h"
#include "Functions/F_Player.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_World.h"
#include "Widget/UI_MessageSpeaker.h"

UOmegaMessageStageComponent* UFlowNode_MsgStage::GetMsgStageComponent() const
{
	if (UOmegaSubsystem_World* ss=OGF_Subsystems::oWorld(this))
	{
		if (ss->message_stages.Contains(StageID))
		{
			if (UOmegaMessageStageComponent* _s=ss->message_stages[StageID])
			{
				return _s;
			}
		}
		//OGF_Log::Warning(TEXT("Could not find message stage component with ID %s"),*StageID.ToString())
	}
	return nullptr;
}

// ==================================================================================================
// Speaker Edit
// ==================================================================================================

void UFlowNode_Msg_SpeakerEdit::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);

	if (UOmegaMessageStageComponent* _stage=GetMsgStageComponent())
	{
		if (bRemoveAllSpeakers)
		{
			_stage->SpeakerActor_RemoveAll();
		}
		for (UPrimaryDataAsset* _s : SpeakersRemoved)
		{
			_stage->SpeakerActor_Remove(_s);
		}
		for (const TPair<UPrimaryDataAsset*,UOAsset_TransformPreset*>& _pair : SpeakersAdded)
		{
			if (!_pair.Key) { continue; }
			if (AOmegaMessageActor* _a=_stage->SpeakerActor_Get(_pair.Key,true))
			{
				if (_pair.Value)
				{
					_a->Position_Set(_pair.Value);
				}
			}
		}
		for (const TPair<UPrimaryDataAsset*,UMaterialInstance*>& _pair : SpeakerPortraits)
		{
			if (!_pair.Key) { continue; }
			if (AOmegaMessageActor* _a=_stage->SpeakerActor_Get(_pair.Key,true))
			{
				_a->Img_SetMaterial(_pair.Value);
			}
		}
	}
	if (GetWorld())
	{
		TArray<UUI_MessageSpeaker* > _speakerWidgets=UOmegaFunctions_Message::SpeakerWidgets_GetAll(this);
			
		//remove speakers. clearing the assignment (not just hiding), so stale widgets can't react to later messages
		if (bRemoveAllSpeakers)
		{
			for (auto* w: _speakerWidgets)
			{
				w->Speaker_Set(nullptr,false);
			}
		}
		else
		{
			for (auto* sp : SpeakersRemoved)
			{
				for (auto* w : _speakerWidgets)
				{
					if (w->SpeakerInstigator==sp)
					{
						w->Speaker_Set(nullptr,false);
					}
				}
			}
		}

		//add speakers. Speaker_Set clears the speaker from any widget at another position.
		//speakers without a position only get a stage actor, never a widget
		for (const TPair<UPrimaryDataAsset*,UOAsset_TransformPreset*>& _pair : SpeakersAdded)
		{
			if (!_pair.Key || !_pair.Value) { continue; }
			if (UUI_MessageSpeaker* wg=UOmegaFunctions_Message::SpeakerWidgets_GetByPosition(this,_pair.Value))
			{
				//skip the default portrait fade if a portrait for this speaker is set right below
				wg->Speaker_Set(_pair.Key,true,!SpeakerPortraits.Contains(_pair.Key));
			}
		}
			
		//update portraits
		for (const TPair<UPrimaryDataAsset*,UMaterialInstance*>& _pair : SpeakerPortraits)
		{
			if (!_pair.Key) { continue; }
			if (UUI_MessageSpeaker* wg=UOmegaFunctions_Message::SpeakerWidgets_GetBySpeaker(this,_pair.Key))
			{
				wg->Portrait_SetImage_Material(_pair.Value);
			}
		}
	}
	TriggerFirstOutput(true);
}

#if WITH_EDITOR
FString UFlowNode_Msg_SpeakerEdit::GetNodeDescription() const
{
	TArray<FString> _parts;
	if (bRemoveAllSpeakers) { _parts.Add(TEXT("Remove ALL speakers")); }
	else if (SpeakersRemoved.Num()>0) { _parts.Add(FString::Printf(TEXT("Remove %d speaker(s)"),SpeakersRemoved.Num())); }
	if (SpeakersAdded.Num()>0) { _parts.Add(FString::Printf(TEXT("Add %d speaker(s)"),SpeakersAdded.Num())); }
	if (SpeakerPortraits.Num()>0) { _parts.Add(FString::Printf(TEXT("Set %d portrait(s)"),SpeakerPortraits.Num())); }
	if (_parts.Num()==0) { return TEXT("(No edits set)"); }
	return FString::Join(_parts,TEXT("\n"));
}
#endif

// ==================================================================================================
// Image Edit
// ==================================================================================================

void UFlowNode_Msg_ImgEdit::L_Finished()
{
	TriggerFirstOutput(true);
}

void UFlowNode_Msg_ImgEdit::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	if (UOmegaMessageStageComponent* _stage=GetMsgStageComponent())
	{
		if (AOmegaMessageActor* _a=_stage->MsgActor_GetFromID(ImageSlotTag))
		{
			if (bRemoveImage)
			{
				_a->Visibility_Set(false);
				const float _fade=_a->ActorConfig_Get().VisibilityBlendTime;
				if (_fade>0.0f)
				{
					GetWorld()->GetTimerManager().SetTimer(timer_handle,this,&UFlowNode_Msg_ImgEdit::L_Finished,_fade,false);
					return;
				}
			}
			else
			{
				_a->Image_UseDualBlend = ChangeTime>0.0f;
				_a->Image_DualBlendTime=ChangeTime;
				_a->Img_SetBrush(Image,ImageParams);
				_a->Visibility_Set(true);
				if (ChangeTime>0.0f)
				{
					GetWorld()->GetTimerManager().SetTimer(timer_handle,this,&UFlowNode_Msg_ImgEdit::L_Finished,ChangeTime,false);
					return;
				}
			}
		}
	}
	TriggerFirstOutput(true);
}

#if WITH_EDITOR
FString UFlowNode_Msg_ImgEdit::GetNodeDescription() const
{
	if (bRemoveImage)
	{
		return FString::Printf(TEXT("Remove image [%s]"),*ImageSlotTag.ToString());
	}
	FString _img=TEXT("None");
	if (UObject* _res=Image.GetResourceObject())
	{
		_img=_res->GetName();
	}
	return FString::Printf(TEXT("[%s] = %s (%.2fs)"),*ImageSlotTag.ToString(),*_img,ChangeTime);
}
#endif
