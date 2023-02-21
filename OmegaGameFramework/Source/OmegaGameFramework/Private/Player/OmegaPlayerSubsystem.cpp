// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Player/OmegaPlayerSubsystem.h"

#include "EnhancedInputSubsystems.h"
#include "OmegaSettings.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Widget/WidgetInterface_Input.h"
#include "Widget/HUDLayer.h"

void UOmegaPlayerSubsystem::Initialize(FSubsystemCollectionBase& Colection)
{
	ParentPlayerController = GetLocalPlayer()->GetPlayerController(GetWorld());
	//ParentPlayerController->OnDestroyed.AddDynamic(this, &UOmegaPlayerSubsystem::CloseAllMenus);
}

void UOmegaPlayerSubsystem::CloseAllMenus(AActor* DestroyedActor)
{
	for (UMenu* TempMenu : OpenMenus)
	{
		if(TempMenu)
		{
			const FGameplayTagContainer NoTags;
			TempMenu->CloseMenu(NoTags, this, TEXT("CloseAll"));		///Remove Menu
		}
	}
}

UMenu* UOmegaPlayerSubsystem::OpenMenu(class TSubclassOf<UMenu> MenuClass, UObject* Context, FGameplayTagContainer Tags, const FString& Flag, bool AutoFocus)
{
	//CollectGarbage(EObjectFlags::RF_Garbage);
	bool bIsMenuOpen = false;
	UMenu* DumMenu = GetMenu(MenuClass, bIsMenuOpen);

	if (!bIsMenuOpen)	//If menu is already open, don't open it again.
	{
        if(DumMenu)
        {
            DumMenu->RemoveFromParent(); //Remove Residual menu (just in case)
        }
        
		class UMenu* LocalMenu = Cast<UMenu>(CreateWidget(GetWorld(), MenuClass));	//Create a new Menu Widget

		if (LocalMenu != nullptr)
		{
			OpenMenus.Add(LocalMenu);
			LocalMenu->OpenMenu(Tags, Context, ParentPlayerController, Flag);	//Set Menu Context, Tags, and Player Controller
			bool MultiMenu = OpenMenus.IsValidIndex(1);
			OnMenuOpened.Broadcast(LocalMenu, Tags, MultiMenu);

			if (AutoFocus)
			{
				SetControlWidget(LocalMenu);
			}
			return LocalMenu;
		}
		else
		{
			return nullptr;
		}
	}
	else
	{
		return nullptr;
	}
}

bool UOmegaPlayerSubsystem::CloseMenu(class TSubclassOf<UMenu> MenuClass, FGameplayTagContainer Tags, UObject* Context, const FString& Flag)
{
	bool bLocalIsValid = false;
	class UMenu* FoundMenu = GetMenu(MenuClass, bLocalIsValid);

	if (bLocalIsValid)
	{
		FoundMenu->CloseMenu(Tags, Context, Flag);
	}

	return bLocalIsValid;
}


UMenu* UOmegaPlayerSubsystem::GetMenu(TSubclassOf<UMenu> MenuClass, bool& bIsValid)
{
	bool bIsMenuFound = false;
	class UMenu* OutMenu = nullptr;

	for (class UMenu* TempMenu : OpenMenus)
	{
		if (!bIsMenuFound&&TempMenu)				//Check if menu already found or if menu reference is invalid
		{
			if (TempMenu->GetClass() == MenuClass)
			{
				OutMenu = TempMenu;
				bIsMenuFound = TempMenu->IsInViewport();		//If Menu is not in viewport, ignore in and create a new one.
			}
		}
	}

	bIsValid = bIsMenuFound;

	if (bIsMenuFound)
	{return OutMenu;}
	else
	{return nullptr;}
}

void UOmegaPlayerSubsystem::SetControlWidget(UUserWidget* Widget)
{
	if (Widget)
	{
		FocusMenu = Widget;
	}
}

void UOmegaPlayerSubsystem::ClearControlWidget()
{
	FocusMenu = nullptr;
}

void UOmegaPlayerSubsystem::RemoveMenuFromActiveList(UMenu* Menu)
{
	if(!Menu->IsValidLowLevel())
	{
		return;
	}
	if (OpenMenus.Contains(Menu))
	{
		OpenMenus.Remove(Menu);
	}
}

////INPUT HANDLING
void UOmegaPlayerSubsystem::InputConfirm()												
{
	if (CanInterfaceInput()) {IWidgetInterface_Input::Execute_InputConfirm(FocusMenu);}			//Input Confirm
}
void UOmegaPlayerSubsystem::InputCancel()												
{
	if (CanInterfaceInput()) {IWidgetInterface_Input::Execute_InputCancel(FocusMenu);}			//Input Cancel
}
void UOmegaPlayerSubsystem::InputNavigate(FVector2D Axis)										
{
	if (CanInterfaceInput()) {IWidgetInterface_Input::Execute_InputNavigate(FocusMenu, Axis);}	//Input Navigate
}
void UOmegaPlayerSubsystem::InputPage(float Axis)											
{
	if (CanInterfaceInput()) {IWidgetInterface_Input::Execute_InputPage(FocusMenu, Axis); }		//Input Page
}

void UOmegaPlayerSubsystem::InputTag(FGameplayTag Tag)
{
	if (CanInterfaceInput()) {IWidgetInterface_Input::Execute_InputTag(FocusMenu, Tag);}
}

bool UOmegaPlayerSubsystem::CanInterfaceInput() const
{
	if(!FocusMenu->IsValidLowLevel())
	{
		return false;
	}
	if(IWidgetInterface_Input::Execute_InputBlocked(FocusMenu) ||	//Block if Input Blocked
		FocusMenu->GetVisibility()==ESlateVisibility::Collapsed || FocusMenu->GetVisibility()==ESlateVisibility::Hidden)	//Block on Collapsed OR Hidden
	{
		return false;
	}
	return true;
}


/// HUDS////
UHUDLayer* UOmegaPlayerSubsystem::AddHUDLayer(TSubclassOf<UHUDLayer> LayerClass, UObject* Context)
{
	CleanHUDLayers();
	class UHUDLayer* LocalLayer = Cast<UHUDLayer>(CreateWidget(GetWorld(), LayerClass));
	if (LocalLayer != nullptr)
	{
		ActiveHUDLayers.Add(LocalLayer);
		
		LocalLayer->SetOwningLocalPlayer(GetLocalPlayer());
		LocalLayer->LayerAdded(GetLocalPlayer()->GetPlayerController(GetWorld()), Context);
		LocalLayer->AddToPlayerScreen(LocalLayer->SlateLayerIndex);
		return LocalLayer;
	}
	return nullptr;
}

bool UOmegaPlayerSubsystem::RemoveHUDLayer(class TSubclassOf<UHUDLayer> LayerClass, FString Flag)
{
	CleanHUDLayers();
	if(GetHUDLayerByClass(LayerClass))
	{
		GetHUDLayerByClass(LayerClass)->RemoveFromParent();
		return true;
	}
	return false;
}

TArray<class UHUDLayer*> UOmegaPlayerSubsystem::GetHUDLayers()
{
	CleanHUDLayers();
	TArray<UHUDLayer*> TempLayers;
	for (UHUDLayer*  TempLayer: ActiveHUDLayers)
	{
		if(TempLayer)
		{
			TempLayers.Add(TempLayer);
		}
	}

	return TempLayers;
}

TArray<UHUDLayer*> UOmegaPlayerSubsystem::GetHUDLayersWithTags(FGameplayTagContainer Tags)
{
	TArray<UHUDLayer*> LocalLayers = GetHUDLayers();
	TArray<UHUDLayer*> OutLayers;
	for (UHUDLayer* TempLayer : LocalLayers)
	{
		if(!(TempLayer==nullptr))
		{
			FGameplayTagContainer TempTags = TempLayer->HUDTags;
			if (TempTags.HasAnyExact(Tags))
			{
				OutLayers.Add(TempLayer);
			}	
		}
	}
	
	return OutLayers;
}

void UOmegaPlayerSubsystem::RemoveHUDLayersWithTags(FGameplayTagContainer Tags)
{
	CleanHUDLayers();
	for (UHUDLayer* TempLayer : GetHUDLayersWithTags(Tags))
	{
		TempLayer->RemoveFromParent();
	}
}

void UOmegaPlayerSubsystem::RemoveAllHudLayers()
{
	CleanHUDLayers();
	for(UHUDLayer* TempLayer : ActiveHUDLayers)
	{
		TempLayer->RemoveFromParent();
	}
	ActiveHUDLayers.Empty();
}

UHUDLayer* UOmegaPlayerSubsystem::GetHUDLayerByClass(TSubclassOf<UHUDLayer> LayerClass)
{
	for(auto* TempLayer : GetHUDLayers())
	{
		if(TempLayer->GetClass() == LayerClass)
		{
			return TempLayer;
		}
	}
	return nullptr;
}

void UOmegaPlayerSubsystem::SetHUDVisibilityWithTags(FGameplayTagContainer Tags, ESlateVisibility Visibility)
{
	CleanHUDLayers();
	for(UHUDLayer* Layer : GetHUDLayersWithTags(Tags))
	{
		if(Layer != nullptr)
		{
			Layer->SetVisibility(Visibility);
		}
	}
}

void UOmegaPlayerSubsystem::CleanHUDLayers()
{
	TArray<UHUDLayer*> LocalLayers;
	for(UHUDLayer* TempLayer : ActiveHUDLayers)
	{
		if(TempLayer->IsValidLowLevel())
		{
			LocalLayers.Add(TempLayer);
		}
	}
	ActiveHUDLayers = LocalLayers;
}

APlayerController* UOmegaPlayerSubsystem::Local_GetPlayerController()
{
	if(!ParentPlayerController)
	{
		ParentPlayerController = GetLocalPlayer()->GetPlayerController(GetWorld());
	}
	return ParentPlayerController;
}

void UOmegaPlayerSubsystem::SetCustomInputMode(UOmegaInputMode* InputMode)
{
	if(!InputMode)
	{
		return;
	}

	UEnhancedInputLocalPlayerSubsystem* LocalInputSubsys = Local_GetPlayerController()->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	
	if(CurrentInputMode)
	{
		for(auto* TempContext : CurrentInputMode->AddedMappingContexts)
		{
			LocalInputSubsys->RemoveMappingContext(TempContext);
		}
	}
	
	//Add New
	Local_GetPlayerController()->bShowMouseCursor = InputMode->bShowMouseCursor;
	Local_GetPlayerController()->bEnableClickEvents = InputMode->bEnabledClickEvents;
	Local_GetPlayerController()->bEnableTouchEvents = InputMode->bEnableTouchOverEvents;
	Local_GetPlayerController()->bEnableMouseOverEvents = InputMode->bEnableMouseOverEvents;
	Local_GetPlayerController()->bEnableTouchOverEvents = InputMode->bEnableTouchOverEvents;

	for(const auto* TempContext : InputMode->AddedMappingContexts)
	{
		if(TempContext)
		{
			LocalInputSubsys->AddMappingContext(TempContext, InputMode->InputPriority);
		}
		
	}
	
	switch (InputMode->Type)
	{
	case EInputModeType::InputModeType_Game:
			UWidgetBlueprintLibrary::SetInputMode_GameOnly(Local_GetPlayerController());
			break;
	case EInputModeType::InputModeType_UI:
			UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(Local_GetPlayerController());
			break;
	case EInputModeType::InputModeType_GameUI:
			UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(Local_GetPlayerController());
			break;
	default: ;
	}

	CurrentInputMode = InputMode;
	OnInputModeChanged.Broadcast(InputMode);
}
