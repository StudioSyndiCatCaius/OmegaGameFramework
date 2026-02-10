// Fill out your copyright notice in the Description page of Project Settings.


#include "LinearEvents/LinearEvent_SimpleMessage.h"

#include "FlowAsset.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"
#include "LuaBlueprintFunctionLibrary.h"
#include "OmegaDemo_Const.h"
#include "Selectors/Selector_Object.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "OmegaLinearEventSubsystem.h"
#include "GameFramework/Character.h"
#include "MovieSceneSequencePlaybackSettings.h"
#include "Components/Component_AimTargeter.h"
#include "Functions/F_Component.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "Selectors/Selector_LevelSequence.h"
#include "Selectors/Selector_Montage.h"
#include "Subsystems/Subsystem_Actors.h"
#include "Subsystems/Subsystem_Message.h"

UObject* ULinearEvent_SimpleMessage::local_GetInstigator() const
{
	if(GetWorld())
	{

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
	GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->FireGlobalEvent(FName(GE_MESSAGE_START), msg.Message, FOmegaCommonMeta());
}

void ULinearEvent_SimpleMessage::LocalGEvent(FName Event, UObject* Context,FOmegaCommonMeta _meta)
{
	if(Event==FName(GE_MESSAGE_END) && Context==msg.Message)
	{
		GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.RemoveDynamic(this, &ULinearEvent_SimpleMessage::LocalGEvent);
		Finish("");
	}
}

bool UFlowNode_SimpleMessage::CanPlayMessage()
{
	if (Text.IsEmpty()) { return false; }
	FLuaValue _luaVal=ULuaBlueprintFunctionLibrary::LuaRunString(this,nullptr,LuaCondition.LuaCode);
	if (_luaVal.Type==ELuaValueType::Bool)
	{
		return _luaVal.ToBool();
	}
	return true;
}


AActor* UFlowNode_SimpleMessage::local_GetInstigatorActor() const
{
	if(Instigator_Asset)
	{
		if(AActor* a=GetFlowAsset()->GetActorByBinding_Asset(Instigator_Asset,true))
		{
			return a;
		}
	}
	return nullptr;
}

UObject* UFlowNode_SimpleMessage::local_GetInstigator() const
{
	if(GetWorld())
	{
		if(Instigator_Asset)
		{
			return Instigator_Asset;
		}
	}
	return nullptr;
}

void UFlowNode_SimpleMessage::LocalGEvent(FName Event, UObject* Context,FOmegaCommonMeta meta)
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
	
	if(Instigator_Asset) { LocalMessage->Instigator_Asset= Instigator_Asset; }
	LocalMessage->Text = Text;
	LocalMessage->MessageCategory=GetFlowAsset()->GetMessageCategoryTag();
	FOmegaGameplayMessageMeta msg_meta;
	msg_meta.CommonMeta.Context=this;
	msg_meta.Brush.SetResourceObject(Portrait);
	msg_meta.Tags=Tags;
	msg_meta.key=MessageKey;
	msg_meta.Flags=Flags;
	LocalMessage->meta=msg_meta;
	LocalMessage->Native_Begin("");

	if(AActor* a=local_GetInstigatorActor())
	{
		if(ACharacter* c=Cast<ACharacter>(a))
		{
			if(Montage)
			{
				c->PlayAnimMontage(Montage);
			}
			if(Sequence)
			{
				FMovieSceneSequencePlaybackSettings seqSettings;
				ALevelSequenceActor* seActor;
				ULevelSequencePlayer* seqPlayer=ULevelSequencePlayer::CreateLevelSequencePlayer(this,Sequence,seqSettings,seActor);
				seActor->AddBindingByTag(TEXT("Instigator"),c);
				seqPlayer->Play();
			}
		}

		// Aim Targeting
		if(UAimTargetComponent* c=Cast<UAimTargetComponent>(a->GetComponentByClass(UAimTargetComponent::StaticClass())))
		{
			if(ClearLookAt)
			{
				c->ClearAimTarget();
			}
			else if (AActor* t=GetFlowAsset()->GetActorByBinding_Asset(LookAt,true))
			{
				c->SetAimTarget(t);
			}
			else if(GetWorld() && LookAt_Alt && LookAt_Alt->Private_GetActor(GetWorld()))
			{
				c->SetAimTarget(LookAt_Alt->Private_GetActor(GetWorld()));
			}
		}

		for(auto* l : Listeners)
		{
			if(AActor* ta = GetFlowAsset()->GetActorByBinding_Asset(l,true))
			{
				if(UAimTargetComponent* c=Cast<UAimTargetComponent>(ta->GetComponentByClass(UAimTargetComponent::StaticClass())))
				{
					c->SetAimTarget(a);
				}
			}
		}
	}
	ULuaBlueprintFunctionLibrary::LuaRunString(this,nullptr,LuaScript.LuaCode);
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

	const FText OutText = FText::Format(FText::FromString("   {0}:\n{1}"), FText::FromString(SpeakerString), FText::FromString(in_txt));

	return OutText.ToString();
}

bool UFlowNode_SimpleMessage::GetDynamicTitleColor(FLinearColor& OutColor) const
{
	if (Text.IsEmpty())
	{
		OutColor=FLinearColor(0.2,0.2,0.2,0.8); return true;		
	}
	OutColor=FLinearColor(1,0.2,0,1); return true;
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


void UFlowNode_SimpleMessage::getNodeIndexFromList(TArray<UFlowNode*> baseList)
{
	TArray<UFlowNode_SimpleMessage*> nodesU;
	for(auto* n : baseList)
	{
		if(n && n->GetClass()==GetClass())
		{
			nodesU.Add(Cast<UFlowNode_SimpleMessage>(n));
		}
	}
	
	if (nodesU.Contains(this))
	{
		int32 ind=nodesU.Find(this);
		FString str = FString::FromInt(ind);
		MessageKey=FName(GetFlowAsset()->GetName()+"_"+str);
	}
}

void UFlowNode_SimpleMessage::Autokey_ByNext()
{
	if(GetFlowAsset())
	{
		getNodeIndexFromList(GetFlowAsset()->GetAllNodes());
	}
}

void UFlowNode_SimpleMessage::Autokey_ByPosition()
{
	if(GetFlowAsset())
	{
		getNodeIndexFromList(GetFlowAsset()->GetNodes_OrderedByPosition());
	}
}


void UFlowNode_SimpleMessage::LocalFinish(UOmegaLinearEvent* Event, const FString& Flag)
{
	//TriggerFirstOutput(true);
}

UOAsset_TransformPreset* UFlowNode_SimpleMessage::GetMessage_TransformPreset_Implementation()
{
	return Position;
}

//UOAsset_TransformPreset* UFlowNode_SimpleMessage::GetMessage_TransformPreset_Implementation()
//{
//	return Position.LoadSynchronous();
//}
