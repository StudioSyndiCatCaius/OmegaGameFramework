// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/ScreenWidget.h"

#include "Components/Image.h"
#include "Misc/GeneralDataObject.h"

#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Components/TextBlock.h"
#include "Functions/F_Player.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_World.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Subsystems/Subsystem_Player.h"
#include "Widget/DataList.h"


void UOmegaScreenWidget::OnInputMethodChanged_Implementation(bool bIsGamepad)
{
	
}

void UOmegaScreenWidget::OnGameplayMessageEnd_Implementation(UOmegaGameplayMessage* Message,
	FGameplayTag MessageCategory, FOmegaGameplayMessageMeta meta)
{
}

void UOmegaScreenWidget::NativeConstruct()
{
	if (UOmegaSubsystem_Player* p=OGF_Subsystems::oPlayer(GetOwningPlayer()))
	{
		SS_Player=p;
	}
	if (UOmegaSubsystem_World* p=OGF_Subsystems::oWorld(GetOwningPlayer()))
	{
		SS_World=p;
	}
	if (UOmegaSubsystem_GameInstance* p=OGF_Subsystems::oGameInstance(GetOwningPlayer()))
	{
		SS_GI=p;
	}
	
	if(ContextObject && ContextObject->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		FText _name;
		FText _desc;
		FSlateBrush _icon;
		UTexture2D* _texture=nullptr;
		UMaterialInterface* _mat=nullptr;
		
		IDataInterface_General::Execute_GetGeneralDataText(ContextObject,FGameplayTag(),_name,_desc);
		IDataInterface_General::Execute_GetGeneralDataImages(ContextObject,FGameplayTag(),_texture,_mat,_icon);
		
		if(UTextBlock* t = GetWidget_Text_ContextName()) { t->SetText(_name); }
		if(UTextBlock* t = GetWidget_Text_ContextDescription()) { t->SetText(_desc); }
		if(UImage* t = GetWidget_Image_ContextIcon()) { t->SetBrush(_icon); }
	}

	if(GetOwningPlayer() && GetOwningPlayer()->K2_GetPawn())
	{
		APawn* _pawn = GetOwningPlayer()->K2_GetPawn();
		for(auto* d : GetDataLists_LinkedToPlayerPawn())
		{
			if(d) { d->SetListOwner(_pawn);}
		}
		for(auto* d : GetDataWidgets_LinkedToPlayerPawn())
		{
			if(d) { d->SetSourceAsset(_pawn);}
		}
	}
	
	if (GetGameInstance())
	{
		GetGameInstance()->GetSubsystem<UOmegaSubsystem_GameInstance>()->OnGlobalEvent.AddDynamic(this, &UOmegaScreenWidget::OnGlobalEvent);
		GetGameInstance()->GetSubsystem<UOmegaSubsystem_GameInstance>()->OnTaggedGlobalEvent.AddDynamic(this, &UOmegaScreenWidget::OnTaggedGlobalEvent);
		
		if (UOmegaSubsystem_World* w=GetWorld()->GetSubsystem<UOmegaSubsystem_World>())
		{
			w->OnGameplayMessage_Begin.AddDynamic(this, &UOmegaScreenWidget::OnGameplayMessage);
			w->OnGameplayMessage_End.AddDynamic(this, &UOmegaScreenWidget::OnGameplayMessageEnd);
			w->OnActorTaggedTargetChange.AddDynamic(this, &UOmegaScreenWidget::OnActorTaggedTargetChanged);
		}
		GetOwningLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>()->OnInputDeviceChanged.AddDynamic(this, &UOmegaScreenWidget::OnInputMethodChanged);
	}
	UOmegaPlayerFunctions::SetInputActionTargetActive(GetOwningPlayer(),this,true);
	Super::NativeConstruct();
}

void UOmegaScreenWidget::NativeDestruct()
{
	UOmegaPlayerFunctions::SetInputActionTargetActive(GetOwningPlayer(),this,false);
	Super::NativeDestruct();
}

void UOmegaScreenWidget::SetSubstate_Name(FName State)
{
	if (Substates.Contains(State))
	{
		SetSubstate_Index(Substates.Find(State));
	}
}

void UOmegaScreenWidget::SetSubstate_Index(int32 State)
{
	if (State!=Substate)
	{
		int32 OldState=Substate;
		Substate=State;
		
		OnSubstateChange(State,GetSubstate_NameFromIndex(State),OldState,GetSubstate_NameFromIndex(OldState));
	}
}

FName UOmegaScreenWidget::GetSubstate_NameFromIndex(int32 index) const
{
	if (Substates.IsValidIndex(index))
	{
		return Substates[index];
	}
	return FName();
}

void UOmegaScreenWidget::OnGlobalEvent_Implementation(FName Event, UObject* Context,FOmegaCommonMeta meta)
{
}

void UOmegaScreenWidget::OnTaggedGlobalEvent_Implementation(FGameplayTag Event, UObject* Context,FOmegaCommonMeta meta)
{
}

void UOmegaScreenWidget::OnGameplayMessage_Implementation(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory,
	FOmegaGameplayMessageMeta meta)
{
}

void UOmegaScreenWidget::OnActorTaggedTargetChanged_Implementation(AActor* Instigator, FGameplayTag Tag, AActor* Target,
	bool bRegsitered)
{
}