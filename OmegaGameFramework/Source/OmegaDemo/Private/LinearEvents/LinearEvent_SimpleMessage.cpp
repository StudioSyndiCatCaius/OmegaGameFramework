// Fill out your copyright notice in the Description page of Project Settings.


#include "LinearEvents/LinearEvent_SimpleMessage.h"

#include "FlowAsset.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"
#include "OmegaDemo_Const.h"
#include "Selectors/Selector_Object.h"
#include "Subsystems/OmegaSubsystem_GameManager.h"
#include "OmegaLinearEventSubsystem.h"
#include "GameFramework/Character.h"
#include "MovieSceneSequencePlaybackSettings.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "Selectors/Selector_LevelSequence.h"
#include "Selectors/Selector_Montage.h"
#include "Subsystems/OmegaSubsystem_Actors.h"
#include "Subsystems/OmegaSubsystem_Message.h"

UObject* ULinearEvent_SimpleMessage::local_GetInstigator() const
{
	if(GetWorld())
	{
		if(Instigator_Alt)
		{
			if(UObject* out = Instigator_Alt->GetSelected_Obj(this))
			{
				return out;
			}
		}
		
		if(Instigator_Asset)
		{
			return Instigator_Asset;
		}
	}
	return nullptr;
}

FString ULinearEvent_SimpleMessage::GetLogString_Implementation() const
{
	FString SpeakerString;
	if(local_GetInstigator())
	{
		SpeakerString = local_GetInstigator()->GetName();
	}

	const FText OutText = FText::Format(FText::FromString("{0}: {1}"), FText::FromString(SpeakerString), Text);

	return OutText.ToString();
}

void ULinearEvent_SimpleMessage::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context,
                                                                   FText& Name, FText& Description)
{
	Description = Text;
}


void ULinearEvent_SimpleMessage::Native_Begin(const FString& Flag)
{
	Super::Native_Begin();
	
	GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.AddDynamic(this, &ULinearEvent_SimpleMessage::LocalGEvent);
	msg=GetWorld()->GetGameInstance()->GetSubsystem<UOmegaMessageSubsystem>()->FireCustomGameplayMessage(local_GetInstigator(),Text,MessageCategory,meta);
	GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->FireGlobalEvent(FName(GE_MESSAGE_START), msg.Message);
}

void ULinearEvent_SimpleMessage::LocalGEvent(FName Event, UObject* Context)
{
	if(Event==FName(GE_MESSAGE_END) && Context==msg.Message)
	{
		GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.RemoveDynamic(this, &ULinearEvent_SimpleMessage::LocalGEvent);
		Finish("");
	}
}

UObject* UFlowNode_SimpleMessage::local_GetInstigator() const
{
	if(GetWorld())
	{
		if(Instigator_Alt)
		{
			if(UObject* out = Instigator_Alt->GetSelected_Obj(this))
			{
				return out;
			}
		}
		if(Instigator_Asset)
		{
			return Instigator_Asset;
		}
	}
	return nullptr;
}

void UFlowNode_SimpleMessage::LocalGEvent(FName Event, UObject* Context)
{
	if(UOmegaGameplayMessage* msg=Cast<UOmegaGameplayMessage>(Context))
	{
		if(Event==FName(GE_MESSAGE_END) && MessageKey==msg->meta.key)
		{
			GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.RemoveDynamic(this, &UFlowNode_SimpleMessage::LocalGEvent);
			TriggerFirstOutput(true);
		}
	}
}

//####################################################
// FLOW NODE
//####################################################

UFlowNode_SimpleMessage::UFlowNode_SimpleMessage()
{
	InputPins.Empty();
	InputPins.Add(FFlowPin(TEXT("In")));
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("Finish")));
	OutputPins.Add(FFlowPin(TEXT("Begin")));
#if WITH_EDITOR
	Category = TEXT("GameFlow");
#endif
	Autokey_ByNext();
}

void UFlowNode_SimpleMessage::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	UOmegaLinearEventSubsystem* SystemRef = GetWorld()->GetSubsystem<UOmegaLinearEventSubsystem>();
	
	ULinearEvent_SimpleMessage* LocalMessage = NewObject<ULinearEvent_SimpleMessage>(GetWorld()->GetGameInstance(), ULinearEvent_SimpleMessage::StaticClass());
	LocalMessage->EventEnded.AddDynamic(this, &UFlowNode_SimpleMessage::LocalFinish);
	GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.AddDynamic(this, &UFlowNode_SimpleMessage::LocalGEvent);
	
	if(Instigator_Alt) { LocalMessage->Instigator_Alt= Instigator_Alt; }
	if(Instigator_Asset) { LocalMessage->Instigator_Asset= Instigator_Asset; }
	LocalMessage->Text = Text;
	FOmegaGameplayMessageMeta msg_meta;
	msg_meta.CommonMeta.Context=this;
	msg_meta.Brush.SetResourceObject(Portrait);
	msg_meta.Tags=Tags;
	msg_meta.key=MessageKey;
	LocalMessage->meta=msg_meta;
	LocalMessage->Native_Begin("");

	if(UOmegaActorSubsystem* actor_subsystem=GetWorld()->GetSubsystem<UOmegaActorSubsystem>())
	{
		if(ACharacter* c=Cast<ACharacter>(actor_subsystem->GetFirstActorIfIdentity(Instigator_Asset)))
		{
			if(Montage && Montage->GetMontage(c))
			{
				c->PlayAnimMontage(Montage->GetMontage(c));
			}
			if(Sequence && Sequence->GetLevelSequence(c))
			{
				FMovieSceneSequencePlaybackSettings seqSettings;
				ALevelSequenceActor* seActor;
				ULevelSequencePlayer* seqPlayer=ULevelSequencePlayer::CreateLevelSequencePlayer(this,Sequence->GetLevelSequence(c),seqSettings,seActor);
				seActor->AddBindingByTag(TEXT("Instigator"),c);
				seqPlayer->Play();
			}
		}
	}
	

	
	TriggerOutput("Begin", false,  EFlowPinActivationType::Default);
}

#if WITH_EDITOR
FString UFlowNode_SimpleMessage::GetNodeDescription() const
{
	FString SpeakerString;
	if(Instigator_Asset)
	{
		SpeakerString = Instigator_Asset->GetName();
	}
	FString in_start=Text.ToString();
	TArray<FString> char_array=UKismetStringLibrary::GetCharacterArrayFromString(in_start);
	int32 len_line=char_array.Num();
	int32 len_max=35;
	
	FString in_txt=UKismetMathLibrary::SelectString(
		UKismetStringLibrary::LeftChop(in_start,len_line-len_max)+"...",
		in_start,len_line>len_max);

	const FText OutText = FText::Format(FText::FromString("{0}: {1}"), FText::FromString(SpeakerString), FText::FromString(in_txt));

	return OutText.ToString();
}
#endif

void UFlowNode_SimpleMessage::GetGeneralAssetLabel_Implementation(FString& Label)
{
	Label=MessageKey.ToString();
}

TMap<FName, FString> UFlowNode_SimpleMessage::GetSoftPropertyMap_Implementation()
{
	return ExtraParams;
}

void UFlowNode_SimpleMessage::Autokey_ByNext()
{
	if(GetFlowAsset())
	{
		TArray<UFlowNode*> nodes=GetFlowAsset()->GetAllNodes();
		TArray<UFlowNode_SimpleMessage*> nodesU;
		for(auto* n : nodes)
		{
			if(n && n->GetClass()==GetClass())
			{
				nodesU.Add(Cast<UFlowNode_SimpleMessage>(n));
			}
		}
		for(auto* n : nodesU)
		{
			if(n && n->GetClass()==GetClass())
			{
				int32 ind=nodes.Find(n);
				FString str = FString::Printf(TEXT("%03d"), ind);
				MessageKey=FName(GetFlowAsset()->GetName()+"_"+str);
			}
		}
	}
}

void UFlowNode_SimpleMessage::Autokey_ByPosition()
{
	TArray<UFlowNode*> nodes=GetFlowAsset()->GetNodes_OrderedByPosition();
	for(auto* n : nodes)
	{
		if(n && n->GetClass()==GetClass())
		{
			int32 ind=nodes.Find(n);
			FString str = FString::Printf(TEXT("%03d"), ind);
			MessageKey=FName(GetFlowAsset()->GetName()+"_"+str);
		}
	}
}


void UFlowNode_SimpleMessage::LocalFinish(UOmegaLinearEvent* Event, const FString& Flag)
{
	//TriggerFirstOutput(true);
}
