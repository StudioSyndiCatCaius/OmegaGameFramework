// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/Menu.h"

#include "Kismet/KismetSystemLibrary.h"
#include "Player/OmegaPlayerSubsystem.h"

void UMenu::OpenMenu(FGameplayTagContainer Tags, UObject* Context, APlayerController* PlayerRef, const FString& Flag)
{
	
	SetOwningPlayer(PlayerRef);
	if (!bIsOpen)
	{
		bIsOpen = true;
		TempTags = Tags;
		PrivateInputBlocked = true;
		
		SetIsEnabled(true);
		SetVisibility(VisibilityOnOpen);
		
		OnOpened.Broadcast(Tags, Flag);
		AddToPlayerScreen(200);
		MenuOpened(Tags, Context, Flag);
		//ANIMATION
		
		if(GetOpenAnimation())
		{
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

void UMenu::CloseMenu(FGameplayTagContainer Tags, const FString& Flag)
{
	if (bIsOpen)
	{
		bIsOpen = false;
		PrivateInputBlocked = true;
		
		TempTags = Tags;
		MenuClosed(TempTags, Flag);
		OnClosed.Broadcast(TempTags, Flag);

		//Handle Subsystem
		UOmegaPlayerSubsystem* SubsystemRef = GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>();
		SubsystemRef->RemoveMenuFromActiveList(this);
		const bool LastMenu = !SubsystemRef->OpenMenus.IsValidIndex(0);
		SubsystemRef->OnMenuClosed.Broadcast(this, TempTags, LastMenu);

		if(SubsystemRef->FocusMenu && SubsystemRef->FocusMenu==this)
		{
			SubsystemRef->ClearControlWidget();
		}
		
		
		//ANIMATION
		if(GetCloseAnimation())
		{
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
	}
}

void UMenu::OnAnimationFinished_Implementation(const UWidgetAnimation* MovieSceneBlends)
{
	Super::OnAnimationFinished_Implementation(MovieSceneBlends);
	if(MovieSceneBlends==GetOpenAnimation())
	{
		Native_CompleteOpen();
	}
	else if (MovieSceneBlends==GetCloseAnimation())
	{
		Native_CompleteClose();
	}
}

void UMenu::NativeConstruct()
{
	//Try Set Close Anim
	if(GetCloseAnimation())
	{
		CloseDelegate.BindUFunction(this, "Native_CompleteClose");
		BindToAnimationFinished(GetCloseAnimation(), CloseDelegate);
	}
	
	//Try Set Open Anim
	if(GetOpenAnimation())
	{
		OpenDelegate.BindUFunction(this, "Native_CompleteOpen");
		BindToAnimationFinished(GetOpenAnimation(), OpenDelegate);
		
	}
	else
	{
		Native_CompleteOpen();
	}
	
	Super::NativeConstruct();
}

void UMenu::Native_CompleteOpen()
{
	PrivateInputBlocked = false;
}

void UMenu::Native_CompleteClose()
{
	
	PrivateInputBlocked = true;
	SetIsEnabled(false);
	SetVisibility(VisibilityOnClose);
	
	//Prep for deletio
    RemoveFromParent();
}

bool UMenu::InputBlocked_Implementation()
{
	return PrivateInputBlocked;
}
