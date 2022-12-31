// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/Menu.h"

#include "Kismet/KismetSystemLibrary.h"
#include "Player/OmegaPlayerSubsystem.h"
#include "OmegaGameManager.h"

void UMenu::OpenMenu(FGameplayTagContainer Tags, UObject* Context, APlayerController* PlayerRef, const FString& Flag)
{
	
	SetOwningPlayer(PlayerRef);
	if (!bIsOpen)
	{
		Local_BindGlobalEvent();
		bIsOpen = true;
		TempTags = Tags;
		PrivateInputBlocked = true;
		
		SetIsEnabled(true);
		SetVisibility(VisibilityOnOpen);
		
		OnOpened.Broadcast(Tags, Flag);
		AddToPlayerScreen(200);
		MenuOpened(Tags, Context, Flag);
		//ANIMATION

		if(OpenSound)
		{
			PlaySound(OpenSound);
		}
		
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

		SetVisibility(ESlateVisibility::HitTestInvisible);

		if(CloseSound)
		{
			PlaySound(CloseSound);
		}
		
		//ANIMATION

		bIsClosing = true;
		
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
	
	if(MovieSceneBlends==GetOpenAnimation() && !bIsClosing)
	{
		UE_LOG(LogTemp, Warning, TEXT("Menu CLOSE Complete") );
		Native_CompleteOpen();
	}
	else if (MovieSceneBlends==GetCloseAnimation() && bIsClosing)
	{
		Native_CompleteClose();
	}
	Super::OnAnimationFinished_Implementation(MovieSceneBlends);
}


void UMenu::NativeConstruct()
{
	/*
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
		
	}*/
	
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
	bIsClosing = false;
	SetVisibility(ESlateVisibility::Collapsed);
	UE_LOG(LogTemp, Warning, TEXT("Menu CLOSE Complete") );
    RemoveFromParent();
}

bool UMenu::InputBlocked_Implementation()
{
	return PrivateInputBlocked;
}

void UMenu::Local_BindGlobalEvent()
{
	GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.AddDynamic(this, &UMenu::OnGlobalEvent);
}
