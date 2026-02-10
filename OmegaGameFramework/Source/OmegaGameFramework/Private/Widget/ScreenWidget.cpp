// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/ScreenWidget.h"
#include "Misc/GeneralDataObject.h"

#include "Components/TextBlock.h"
#include "Subsystems/Subsystem_Actors.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Subsystems/Subsystem_Message.h"
#include "Subsystems/Subsystem_Player.h"
#include "Widget/DataList.h"


void UOmegaScreenWidget::OnInputMethodChanged_Implementation(bool bIsGamepad)
{
	
}

void UOmegaScreenWidget::NativeConstruct()
{
	if(ContextObject && ContextObject->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		FText _name;
		FText _desc;
		FSlateBrush _icon;
		UTexture2D* _texture=nullptr;
		UMaterialInterface* _mat=nullptr;
		
		IDataInterface_General::Execute_GetGeneralDataText(ContextObject,"",this,_name,_desc);
		IDataInterface_General::Execute_GetGeneralDataImages(ContextObject,"",this,_texture,_mat,_icon);
		
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
		GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.AddDynamic(this, &UOmegaScreenWidget::OnGlobalEvent);
		GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnTaggedGlobalEvent.AddDynamic(this, &UOmegaScreenWidget::OnTaggedGlobalEvent);
		GetGameInstance()->GetSubsystem<UOmegaMessageSubsystem>()->OnGameplayMessage.AddDynamic(this, &UOmegaScreenWidget::OnGameplayMessage);
		GetWorld()->GetSubsystem<UOmegaActorSubsystem>()->OnActorTaggedTargetChange.AddDynamic(this, &UOmegaScreenWidget::OnActorTaggedTargetChanged);
		GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->OnInputDeviceChanged.AddDynamic(this, &UOmegaScreenWidget::OnInputMethodChanged);
	}
	
	Super::NativeConstruct();
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