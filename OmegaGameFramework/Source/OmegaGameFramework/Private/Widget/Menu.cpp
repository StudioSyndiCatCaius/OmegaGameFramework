// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/Menu.h"

#include "OmegaSettings_Slate.h"
#include "Engine/GameInstance.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Subsystems/OmegaSubsystem_GameManager.h"
#include "Subsystems/OmegaSubsystem_Gameplay.h"
#include "Subsystems/OmegaSubsystem_Message.h"
#include "Subsystems/OmegaSubsystem_Player.h"
#include "Widget/DataList.h"

void UMenu::OpenMenu(FGameplayTagContainer Tags, UObject* Context, APlayerController* PlayerRef, const FString& Flag)
{
	if(Context) { ContextObject=Context;}
	AddToPlayerScreen(200);
	
	if(GetDefaultDataList() && ContextObject && ContextObject->GetClass()->ImplementsInterface(UDataInterface_CommonMenu::StaticClass()))
	{
		GetDefaultDataList()->AddAssetsToList(IDataInterface_CommonMenu::Execute_GetDataListEntries(ContextObject,this),"");
	}
	SetOwningPlayer(PlayerRef);
	if (!bIsOpen)
	{
		//BIND EVENTS
		GetGameInstance()->GetSubsystem<UOmegaMessageSubsystem>()->OnGameplayMessage.AddDynamic(this, &UMenu::OnGameplayMessage);
		GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->OnInputDeviceChanged.AddDynamic(this, &UMenu::OnInputMethodChanged);
		Local_BindGlobalEvent();

		Reset();
		
		TempTags = Tags;
		PrivateInputBlocked = true;
		InputBlock_Remaining=InputBlockDelay;
		SetIsEnabled(true);
		SetVisibility(VisibilityOnOpen);
		
		OnOpened.Broadcast(Tags, Flag);
		MenuOpened(Tags, Context, Flag);
		Native_UpdateState();
		
		//ANIMATION

		if(CustomInputMode)
		{
			GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->SetCustomInputMode(CustomInputMode);
		}
		
		if(ParallelGameplaySystem)
		{
			GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->ActivateGameplaySystem(ParallelGameplaySystem, this);
		}

		
		if(OpenSound)
		{
			PlaySound(OpenSound);
		}
		else if(DefaultToStyleSounds && UOmegaSlateFunctions::GetCurrentSlateStyle() && UOmegaSlateFunctions::GetCurrentSlateStyle()->Sound_Menu_Open)
		{
			PlaySound(UOmegaSlateFunctions::GetCurrentSlateStyle()->Sound_Menu_Open);
		}
		
		if(GetOpenAnimation())
		{
			bIsPlayingAnimation=true;
			if(ReverseOpenAnimation)
			{
				PlayAnimationReverse(GetOpenAnimation());
			}
			else
			{
				PlayAnimationForward(GetOpenAnimation());
			}
		}
		else
		{
			Native_CompleteOpen();
		}
	}
}

void UMenu::CloseMenu(FGameplayTagContainer Tags, UObject* Context, const FString& Flag)
{
	if (bIsOpen && CanCloseMenu(Tags,Context,Flag))
	{
		bIsOpen = false;
		PrivateInputBlocked = true;
		
		TempTags = Tags;
		MenuClosed(TempTags, Flag);
		OnClosed.Broadcast(TempTags, Context, Flag);

		//Handle Subsystem
		UOmegaPlayerSubsystem* SubsystemRef = GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>();
		SubsystemRef->RemoveMenuFromActiveList(this);
		const bool LastMenu = !SubsystemRef->OpenMenus.IsValidIndex(0);
		SubsystemRef->OnMenuClosed.Broadcast(this, TempTags, LastMenu);

		if(SubsystemRef->FocusMenu && SubsystemRef->FocusMenu==this)
		{
			SubsystemRef->ClearControlWidget();
		}

		SetVisibility(ESlateVisibility::HitTestInvisible);

		if(CloseSound)
		{
			PlaySound(CloseSound);
		}
		else if(DefaultToStyleSounds && UOmegaSlateFunctions::GetCurrentSlateStyle() && UOmegaSlateFunctions::GetCurrentSlateStyle()->Sound_Menu_Close)
		{
			PlaySound(UOmegaSlateFunctions::GetCurrentSlateStyle()->Sound_Menu_Close);
		}
		
		//ANIMATION
		if(GetCloseAnimation())
		{
			bIsPlayingAnimation=true;
			if(ReverseCloseAnimation)
			{
				PlayAnimationReverse(GetCloseAnimation());
			}
			else
			{
				PlayAnimationForward(GetCloseAnimation());
			}
		}
		else
		{
			Native_CompleteClose();
		}
		
		bIsClosing = true;
	}
}

TArray<UObject*> UOmegaCommonMenuDefinition::GetDataListEntries_Implementation(UMenu* Menu)
{
	TArray<UObject*> out;
	for(auto* i : CustomEntry_Assets) { if(i){ out.Add(i);} }
	for(auto* i : CustomEntry_Objects) { if(i){ out.Add(i);} }
	return out;
}

void UMenu::OnAnimationFinished_Implementation(const UWidgetAnimation* MovieSceneBlends)
{
	if(MovieSceneBlends==GetOpenAnimation() && !bIsClosing)
	{
		bIsPlayingAnimation=false;
		UE_LOG(LogTemp, Warning, TEXT("Menu CLOSE Complete") );
		Native_CompleteOpen();
	}
	else if (MovieSceneBlends==GetCloseAnimation() && bIsClosing)
	{
		bIsPlayingAnimation=false;
	}
	Super::OnAnimationFinished_Implementation(MovieSceneBlends);
}


void UMenu::NativeConstruct()
{
	Super::NativeConstruct();
}

void UMenu::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if(InputBlock_Remaining > 0.0)
	{
		InputBlock_Remaining=InputBlock_Remaining-InDeltaTime;
	}
	
	float target_val=0.0;
	if(bIsOpen) { target_val=1.0; }
	if(target_val != OpenCloseInterp_Value)
	{
		isPlayingOpenCloseInterp=true;
		OpenCloseInterp_Value=UKismetMathLibrary::FInterpTo_Constant(OpenCloseInterp_Value,target_val,InDeltaTime,1.0/OpenCloseInterpTime);
		if(AutoInterpOpacityOnOpenClose)
		{
			SetRenderOpacity(OpenCloseInterp_Value);
		}
		UpdateOpenCloseInterp(OpenCloseInterp_Value);
	}
	else
	{
		isPlayingOpenCloseInterp=false;
		if(bIsClosing && !bIsPlayingAnimation)
		{
			Native_CompleteClose();
		}
	}
	
	Super::NativeTick(MyGeometry, InDeltaTime);
}


void UMenu::Native_CompleteOpen()
{
	bIsOpen = true;
	PrivateInputBlocked = false;
}

bool UMenu::CanCloseMenu_Implementation(FGameplayTagContainer Tags, UObject* Context, const FString& Flag)
{
	return true;
}

void UMenu::Native_CompleteClose()
{
	if(!isPlayingOpenCloseInterp)
	{
		bIsClosing = false;
		PrivateInputBlocked = true;
		SetIsEnabled(false);
		SetVisibility(ESlateVisibility::Collapsed);
		UE_LOG(LogTemp, Warning, TEXT("Menu CLOSE Complete") );
	
		if(ParallelGameplaySystem)
		{
			GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->ShutdownGameplaySystem(ParallelGameplaySystem, this);
		}
	
		RemoveFromParent();
	}
}

void UMenu::MenuClosed_Implementation(FGameplayTagContainer Tags, const FString& Flag)
{
}

void UMenu::MenuOpened_Implementation(FGameplayTagContainer Tags, UObject* Context, const FString& Flag)
{
}

bool UMenu::InputBlocked_Implementation()
{
	return IsInputBlocked();
}

void UMenu::Local_BindGlobalEvent()
{
	GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.AddDynamic(this, &UMenu::OnGlobalEvent);
	GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnTaggedGlobalEvent.AddDynamic(this, &UMenu::OnTaggedGlobalEvent);
}

void UMenu::Native_UpdateState()
{
	if(UWidgetSwitcher* _switch=GetWidget_WidgetSwitcher_State())
	{
		_switch->SetActiveWidgetIndex(menu_state);
	}
	OnMenuStateChanged(menu_state);
}

UWidgetSwitcher* UMenu::GetWidget_WidgetSwitcher_State_Implementation()
{
	return nullptr;
}

void UMenu::SetMenuState(int32 state)
{
	if(state!=menu_state)
	{
		menu_state=state;
		Native_UpdateState();
	}
}

void UMenu::OnGameplayMessage_Implementation(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory,
                                             FOmegaGameplayMessageMeta meta)
{
}
