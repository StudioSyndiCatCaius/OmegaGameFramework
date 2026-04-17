// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/Menu.h"

#include "OmegaSettings_Slate.h"
#include "Components/Component_Combatant.h"
#include "Engine/GameInstance.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Subsystems/Subsystem_World.h"
#include "Subsystems/Subsystem_Player.h"
#include "Widget/DataList.h"

void UMenu::OpenMenu(FGameplayTagContainer Tags, UObject* Context, APlayerController* PlayerRef, const FString& Flag)
{
	if(Context) { ContextObject=Context;}
	AddToPlayerScreen(SlateLayerIndex);
	
	if(GetDefaultDataList() && ContextObject && ContextObject->GetClass()->ImplementsInterface(UDataInterface_CommonMenu::StaticClass()))
	{
		GetDefaultDataList()->AddAssetsToList(IDataInterface_CommonMenu::Execute_GetDataListEntries(ContextObject,this),"");
	}
	SetOwningPlayer(PlayerRef);
	if (!bIsOpen)
	{
		//BIND EVENTS

		Reset();
		
		WrapperActor=Cast<AOmegaMenuWrapperActor>(GetWorld()->SpawnActor(AOmegaMenuWrapperActor::StaticClass()));
		
		TempTags = Tags;
		PrivateInputBlocked = true;
		InputBlock_Remaining=InputBlockDelay;
		SetIsEnabled(true);
		SetVisibility(VisibilityOnOpen);
		
		OnOpened.Broadcast(Tags, Flag);
		MenuOpened(Tags, Context, Flag);
		Native_UpdateState();
		
		if (SS_Player)
		{
			if(CustomInputMode)
			{
				SS_Player->SetCustomInputMode(CustomInputMode);
			}	
		}

		if (SS_World)
		{
			if(ParallelGameplaySystem)
			{
				SS_World->ActivateGameplaySystem(ParallelGameplaySystem, this);
				
				TArray<FGameplayTag> _tags;
				BlockedSystemTags.GetGameplayTagArray(_tags);
				SS_World->ExtraBlockedSystemTags.Append(_tags);
			}	
		}
		
		if(OpenSound)
		{
			PlaySound(OpenSound);
		}
		else if(DefaultToStyleSounds && !OGF_CFG_STYLE()->Sound_Menu_Open.IsNull())
		{
			PlaySound(OGF_CFG_STYLE()->Sound_Menu_Open.LoadSynchronous());
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
		
		if (WrapperActor)
		{
			WrapperActor->K2_DestroyActor();
		}
		
		TempTags = Tags;
		MenuClosed(TempTags, Flag);
		OnClosed.Broadcast(TempTags, Context, Flag);

		//Handle Subsystem
		UOmegaSubsystem_Player* SubsystemRef = GetOwningLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>();
		SubsystemRef->RemoveMenuFromActiveList(this);
		const bool LastMenu = !SubsystemRef->OpenMenus.IsValidIndex(0);
		SubsystemRef->OnMenuClosed.Broadcast(this, TempTags, LastMenu);

		if(SubsystemRef->FocusMenu && SubsystemRef->FocusMenu==this)
		{
			SubsystemRef->ClearControlWidget();
		}
		
		TArray<FGameplayTag> _tags;
		BlockedSystemTags.GetGameplayTagArray(_tags);
		for (FGameplayTag Tag : _tags)
		{
			if (SS_World->ExtraBlockedSystemTags.Contains(Tag))
			{
				SS_World->ExtraBlockedSystemTags.RemoveSingle(Tag);	
			}
		}

		SetVisibility(ESlateVisibility::HitTestInvisible);

		if(CloseSound)
		{
			PlaySound(CloseSound);
		}
		else if(DefaultToStyleSounds && OGF_CFG_STYLE()->Sound_Menu_Close)
		{
			PlaySound(OGF_CFG_STYLE()->Sound_Menu_Close.LoadSynchronous());
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

AOmegaMenuWrapperActor::AOmegaMenuWrapperActor()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>("Root");
	Combatant=CreateOptionalDefaultSubobject<UCombatantComponent>("Combatant");
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
			GetWorld()->GetSubsystem<UOmegaSubsystem_World>()->ShutdownGameplaySystem(ParallelGameplaySystem, this);
		}
	
		RemoveFromParent();
	}
}

AOmegaMenuWrapperActor* UMenu::GetMenuWrapperActor() const
{
	if (WrapperActor) { return WrapperActor; } return nullptr;
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
