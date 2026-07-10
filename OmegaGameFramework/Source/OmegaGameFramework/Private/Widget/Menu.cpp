// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/Menu.h"

#include "OmegaSettings_Slate.h"
#include "TimerManager.h"
#include "Components/Component_Combatant.h"
#include "Engine/GameInstance.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Subsystems/Subsystem_Engine.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Subsystems/Subsystem_World.h"
#include "Subsystems/Subsystem_Player.h"
#include "Engine/Engine.h"
#include "Widget/DataList.h"

void UMenu::OpenMenu(FGameplayTagContainer Tags, UObject* Context, APlayerController* PlayerRef, const FString& Flag)
{
	if(Context) { ContextObject=Context;}
	AddToPlayerScreen(SlateLayerIndex);
	
	SetOwningPlayer(PlayerRef);
	if (!bIsOpen)
	{
		//BIND EVENTS

		Reset();
		
		WrapperActor=Cast<AOmegaMenuWrapperActor>(GetWorld()->SpawnActor(AOmegaMenuWrapperActor::StaticClass()));
		if (WrapperChildActor)
		{
			WrapperActor->ChildActor->SetChildActorClass(WrapperChildActor);
		}
		
		TempTags = Tags;
		PrivateInputBlocked = true;
		InputBlock_Remaining = InputBlockDelay;
		if (InputBlockDelay > 0.0f)
		{
			GetWorld()->GetTimerManager().SetTimer(InputBlockTimer, this, &UMenu::InputBlockTimer_End, InputBlockDelay, false);
		}
		else
		{
			InputBlock_Remaining = 0.0f;
		}
		SetIsEnabled(true);
		SetVisibility(VisibilityOnOpen);
		SetSubstate_Index(0);
		OnOpened.Broadcast(Tags, Flag);
		MenuOpened(Tags, Context, Flag);
		
		if (SS_Player)
		{
			SS_Player->OpenMenus.AddUnique(this);
			if(CustomInputMode)
			{
				SS_Player->SetCustomInputMode(CustomInputMode);
			}
			SS_Player->ControlWidget_Register(this,true);
		}

		if (SS_World)
		{
			if(ParallelGameplaySystem)
			{
				SS_World->ActivateGameplaySystem(ParallelGameplaySystem, this);
			}	
			SS_World->GameplayModifier_Register(this,true);
			SS_World->ForceUpdateGameplayState();
		}
		
		if(OpenSound)
		{
			PlaySound(OpenSound);
		}
		else if (UOmegaSlateTheme* _theme=UOmegaWidgetInterface::GetTheme(this))
		{
			PlaySound(_theme->Sound_Menu_Open);
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
	OGF_GLOBALREFRESH();
}

void UMenu::CloseMenu(FGameplayTagContainer Tags, UObject* Context, const FString& Flag)
{
	if (bIsOpen && InputBlock_Remaining <= 0.0f && CanCloseMenu(Tags,Context,Flag))
	{
		GetWorld()->GetTimerManager().ClearTimer(InputBlockTimer);
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
		
		SetVisibility(ESlateVisibility::HitTestInvisible);

		if(CloseSound)
		{
			PlaySound(CloseSound);
		}
		else if (UOmegaSlateTheme* _theme=UOmegaWidgetInterface::GetTheme(this))
		{
			PlaySound(_theme->Sound_Menu_Close);
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
	OGF_GLOBALREFRESH();
}


AOmegaMenuWrapperActor::AOmegaMenuWrapperActor()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>("Root");
	Combatant=CreateOptionalDefaultSubobject<UCombatantComponent>("Combatant");
	ChildActor=CreateOptionalDefaultSubobject<UChildActorComponent>("ChildActor");
}

void UMenu::L_SetSubstate(int32 NewState)
{
	Super::L_SetSubstate(NewState);
	if (SS_Player)
	{
		//refresh top widget
		SS_Player->ControlWidget_GetTop();
	}
	if (bCloseMenuOnSubstateUnderflow && NewState<0)
	{
		CloseMenu(FGameplayTagContainer(),nullptr,"");
	}
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

bool UMenu::InputAction_Disabled_Implementation(APlayerController* Player, FGameplayTag Action)
{
	return IsInputBlocked();
}

void UMenu::NativeDestruct()
{
	if (SS_Player)
	{
		if (SS_Player->OpenMenus.Contains(this))
		{
			SS_Player->OpenMenus.Remove(this);
		}
		SS_Player->ControlWidget_Register(this,false);
	}
	if (SS_World)
	{
		SS_World->GameplayModifier_Register(this,false);
	}
	Super::NativeDestruct();
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

AActor* UMenu::GetMenuWrapperChildActor(TSubclassOf<AActor> Class)
{
	if (WrapperActor)
	{
		if (AActor* out=WrapperActor->ChildActor->GetChildActor())
		{
			if (!Class || out->GetClass()->IsChildOf(Class))
			{
				return out;
			}
		}
	}
	return nullptr;
}

void UMenu::MenuClosed_Implementation(FGameplayTagContainer Tags, const FString& Flag)
{
}

void UMenu::MenuOpened_Implementation(FGameplayTagContainer Tags, UObject* Context, const FString& Flag)
{
	
}

void UMenu::InputBlockTimer_End()
{
	InputBlock_Remaining = 0.0f;
}

bool UMenu::IsInputBlocked() const
{
	return PrivateInputBlocked || bIsClosing || !bIsOpen || InputBlock_Remaining > 0.0;
}

bool UMenu::InputBlocked_Implementation()
{
	return IsInputBlocked();
}

UUserWidget* UMenu::ControlWidget_Get_Implementation(int32& priority)
{
	priority=Priority;
	if (GetSubstateInputWidget().IsValidIndex(Substate))
	{
		if (UUserWidget* gotWidget=GetSubstateInputWidget()[Substate])
		{
			priority=Priority+1;
			return gotWidget;
		}
	}
	return this;
}

TArray<UUserWidget*> UMenu::GetSubstateInputWidget_Implementation()
{
	return TArray<UUserWidget*>();
}

