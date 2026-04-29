// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Subsystems/Subsystem_Player.h"
#include "Components/AudioComponent.h"
#include "Widget/Menu.h"
#include "Components/InputComponent.h"
#include "TimerManager.h"
#include "EnhancedInputSubsystems.h"
#include "OmegaSettings.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Interfaces/I_Widget.h"
#include "Widget/HUDLayer.h"
#include "UObject/UObjectGlobals.h"
#include "CommonInputSubsystem.h"
#include "OmegaGameManager.h"
#include "OmegaSettings_Slate.h"
#include "Actors/Actor_DynamicCamera.h"
#include "Blueprint/SlateBlueprintLibrary.h"
#include "Camera/CameraComponent.h"
#include "Functions/F_Player.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/GameModeBase.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Widget/DataWidget.h"


// ================================================================================================================
// Subsystem
// ================================================================================================================


UAudioComponent* UOmegaSubsystem_Player::GetLocalAudioComp()
{
	if (!UiAudioComp && REF_Controller)
	{
		UiAudioComp = Cast<UAudioComponent>(REF_Controller->AddComponentByClass(UAudioComponent::StaticClass(), false, FTransform(), false));
	}
	return UiAudioComp;
}


void UOmegaSubsystem_Player::Initialize(FSubsystemCollectionBase& Colection)
{
	REF_Controller = GetLocalPlayer()->GetPlayerController(GetWorld());
	//ParentPlayerController->OnDestroyed.AddDynamic(this, &UOmegaPlayerSubsystem::CloseAllMenus);
	GetHoverCursor();
}

void UOmegaSubsystem_Player::Deinitialize()
{

	Super::Deinitialize();
}

void UOmegaSubsystem_Player::L_PlayerPawnChanged(APawn* Pawn, APawn* Pawn1)
{
	if (InputTargets.Contains(Pawn1)) { InputTargets.Remove(Pawn1); }
	if (InputTargets.Contains(Pawn)) { InputTargets.Remove(Pawn); }
	if (OGF_CFG()->Input_ReplicateToPlayerPawn)
	{
		L_TryRegisterInputTarget(REF_Controller->K2_GetPawn());
	}
}

void UOmegaSubsystem_Player::PlayerControllerChanged(APlayerController* NewPlayerController)
{
	Super::PlayerControllerChanged(NewPlayerController);
	if(NewPlayerController)
	{
		REF_Controller=NewPlayerController;
		REF_Controller->OnPossessedPawnChanged.AddDynamic(this,&UOmegaSubsystem_Player::L_PlayerPawnChanged);
		REF_Controller->SetTickableWhenPaused(true);
		REF_Controller->InputComponent->SetTickableWhenPaused(true);
		//REF_Controller->InputComponent->KeyBindings.Remove(KeyBind_Start);
		//REF_Controller->InputComponent->KeyBindings.Remove(KeyBind_Stop);
		
		// Binding
		KeyBind_Start=REF_Controller->InputComponent->BindKey(EKeys::AnyKey, IE_Pressed, this, &UOmegaSubsystem_Player::Input_OnKeyStart);
		KeyBind_Stop=REF_Controller->InputComponent->BindKey(EKeys::AnyKey, IE_Released, this, &UOmegaSubsystem_Player::Input_OnKeyEnd);
		KeyBind_Start.bExecuteWhenPaused=true;
		KeyBind_Start.bConsumeInput=false;
		KeyBind_Stop.bExecuteWhenPaused=true;
		KeyBind_Stop.bConsumeInput=false;
		
		if (OGF_CFG()->Input_ReplicateToPlayerController)
		{
			L_TryRegisterInputTarget(REF_Controller);
		}
		if (OGF_CFG()->Input_ReplicateToPlayerPawn)
		{
			L_TryRegisterInputTarget(REF_Controller->K2_GetPawn());
		}
		if (OGF_CFG()->Input_ReplicateToGameMode)
		{
			AGameModeBase* _gm=UGameplayStatics::GetGameMode(REF_Controller);
			L_TryRegisterInputTarget(_gm);
		}

		if (!SS_GI)
		{
			SS_GI=REF_Controller->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSubsystem_GameInstance>();
		}
	}
}

void UOmegaSubsystem_Player::Input_OnKeyStart(FKey Key)
{
	bool _isGamepadKey=Key.IsGamepadKey();
	if (_isGamepadKey!=bUsingGamepad)
	{
		bUsingGamepad=_isGamepadKey;
		OnInputDeviceChanged.Broadcast(IsUsingGamepad());	
	}
	if (!KeysActive.Contains(Key))
	{
		KeysActive.Add(Key);
		Input_OnKeyEvent(0,Key,0,false);
	}
}

void UOmegaSubsystem_Player::Input_OnKeyEnd(FKey Key)
{
	if (KeysActive.Contains(Key))
	{
		KeysActive.Remove(Key);
		Input_OnKeyEvent(1,Key,0,false);
	}
}

void UOmegaSubsystem_Player::Input_OnKeyEvent(uint8 event, FKey key, float dt, bool bAxisKey)
{
	if (REF_Controller && SS_GI)
	{
		FVector _scaleAxis=FVector::One();
		if (bAxisKey)
		{
			// if axis key, record axis scale for apply to base value. If Not axis key OR in deadzone, stop this function
			if (!UOmegaPlayerFunctions::GetKeyAxis(REF_Controller,key,_scaleAxis))
			{
				return;
			}
		}
		if (SS_GI->InputKeyCacheData.Contains(key))
		{
			FOmegaInputKeyCacheData _InputKeyCacheData=SS_GI->InputKeyCacheData[key];
			TArray<FGameplayTag> _actionList;
			_InputKeyCacheData.KeyInputs.GetKeys(_actionList);
			TArray<TWeakObjectPtr<UObject>> _targets=InputTargets;
			
			for (TWeakObjectPtr<UObject> _targetRef : _targets)
			{
				if (UObject* _target=_targetRef.Get())
				{
					for (FGameplayTag _actionTag : _actionList)
					{
						if (!IDataInterface_InputAction::Execute_InputAction_Disabled(_target,REF_Controller,_actionTag))
						{
							FVector _foundAxis=_InputKeyCacheData.KeyInputs[_actionTag].ApplySwizzle(_scaleAxis);
							switch (event)
							{
							case 0:  // INPUT - Start
								IDataInterface_InputAction::Execute_OnInputAction_Begin(_target, REF_Controller,_actionTag,_foundAxis);
							
								if (_actionTag==OGF_CFG()->InputAction_UI_Confirm)
								{
									InputConfirm();
								}
								else if (_actionTag==OGF_CFG()->InputAction_UI_Cancel)
								{
									InputCancel();
								}
							
								break;
							case 1:  // INPUT - End
								IDataInterface_InputAction::Execute_OnInputAction_End(_target, REF_Controller,_actionTag,_foundAxis);
							
								if (_actionTag==OGF_CFG()->InputAction_UI_Navigate)
								{
									f_UiNavCooldown=0.0;
								}
								break;
							case 2:  // INPUT - Tick
								IDataInterface_InputAction::Execute_OnInputAction_Update(_target, REF_Controller,_actionTag,dt,_foundAxis);
							
								if (_actionTag==OGF_CFG()->InputAction_UI_Navigate && f_UiNavCooldown<=0.0)
								{
									f_UiNavCooldown=OGF_CFG()->InputAction_UI_Navigate_Cooldown;
									InputNavigate(FVector2D(_foundAxis));
								}
							
								break;
							default: ;
							}
						}
					}
				}
			}
		}
	}
	
}


void UOmegaSubsystem_Player::L_TryRegisterInputTarget(UObject* target)
{
	if (target && target->GetClass()->ImplementsInterface(UDataInterface_InputAction::StaticClass()))
	{
		InputTargets.Add(target);
	}
}

void UOmegaSubsystem_Player::Tick(float DeltaTime)
{
	Tick_DynamicCamera(DeltaTime);
	Tick_Input(DeltaTime);
	if (f_UiNavCooldown>0.0)
	{
		f_UiNavCooldown-=DeltaTime;
	}
	//tick - input
}


void UOmegaSubsystem_Player::CloseAllMenus(AActor* DestroyedActor)
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


UMenu* UOmegaSubsystem_Player::OpenMenu(class TSubclassOf<UMenu> MenuClass, UObject* Context, FGameplayTagContainer Tags, const FString& Flag, bool AutoFocus,FOmegaCommonMeta meta)
{
	if (!REF_Controller) { return nullptr; }
	//CollectGarbage(EObjectFlags::RF_Garbage);
	bool bIsMenuOpen = false;
	TSubclassOf<UMenu> _InClass=GetMutableDefault<UOmegaSettings>()->CorrectClass_Menu(MenuClass);
	if(UMenu* DumMenu = GetMenu(_InClass, bIsMenuOpen))
	{
		DumMenu->RemoveFromParent(); //Remove Residual menu (just in case)
	}

	if (!bIsMenuOpen)	//If menu is already open, don't open it again.
	{
		if (UMenu* LocalMenu = Cast<UMenu>(CreateWidget(GetWorld(), _InClass)))
		{
			//try load tempalte from GAME CORE
			for (auto* TempMenu : OGF_GAME_CORE()->Menu_Config)
			{
				if (TempMenu && TempMenu->GetClass() == LocalMenu->GetClass())
				{
					UEngine::CopyPropertiesForUnrelatedObjects(TempMenu, LocalMenu);
					break;
				}
			}
			
			OpenMenus.Add(LocalMenu);
			LocalMenu->ContextObject=Context;
			LocalMenu->widget_meta=meta;
			LocalMenu->OpenMenu(Tags, Context, REF_Controller, Flag);	//Set Menu Context, Tags, and Player Controller
			bool MultiMenu = OpenMenus.IsValidIndex(1);
			OnMenuOpened.Broadcast(LocalMenu, Tags, MultiMenu);

			if (AutoFocus)
			{
				SetControlWidget(LocalMenu);
			}
			return LocalMenu;
		}
	}
	return nullptr;
}

bool UOmegaSubsystem_Player::CloseMenu(class TSubclassOf<UMenu> MenuClass, FGameplayTagContainer Tags, UObject* Context, const FString& Flag)
{
	bool bLocalIsValid = false;
	TSubclassOf<UMenu> _InClass=GetMutableDefault<UOmegaSettings>()->CorrectClass_Menu(MenuClass);
	
	class UMenu* FoundMenu = GetMenu(_InClass, bLocalIsValid);

	if (bLocalIsValid)
	{
		FoundMenu->CloseMenu(Tags, Context, Flag);
	}

	return bLocalIsValid;
}


UMenu* UOmegaSubsystem_Player::GetMenu(TSubclassOf<UMenu> MenuClass, bool& bIsValid)
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

void UOmegaSubsystem_Player::SetControlWidget(UUserWidget* Widget)
{
	if (Widget && Widget != FocusMenu)
	{
		FocusMenu = Widget;
		if(FocusMenu->GetClass()->ImplementsInterface(UWidgetInterface_Input::StaticClass()))
		{
			IWidgetInterface_Input::Execute_OnControlSetWidget(FocusMenu);
		}
	}
}

void UOmegaSubsystem_Player::ClearControlWidget()
{
	FocusMenu = nullptr;
}

void UOmegaSubsystem_Player::RemoveMenuFromActiveList(UMenu* Menu)
{
	if(!IsValid(Menu))
	{
		return;
	}
	if (OpenMenus.Contains(Menu))
	{
		OpenMenus.Remove(Menu);
	}
}

void UOmegaSubsystem_Player::PlayUiSound(USoundBase* Sound)
{
	
	if (!GetWorld()->GetTimerManager().IsTimerActive(SoundCooldownTimer))
	{
		if (Sound)
		{
			UGameplayStatics::PlaySound2D(GetWorld(), Sound);
			GetWorld()->GetTimerManager().SetTimer(SoundCooldownTimer, [this](){}, 0.1, false);
		}
	}
	
}

////INPUT HANDLING
void UOmegaSubsystem_Player::InputConfirm()												
{
	if (CanInterfaceInput()) {IWidgetInterface_Input::Execute_InputConfirm(FocusMenu);}			//Input Confirm
}
void UOmegaSubsystem_Player::InputCancel()												
{
	if (CanInterfaceInput()) {IWidgetInterface_Input::Execute_InputCancel(FocusMenu);}			//Input Cancel
}
void UOmegaSubsystem_Player::InputNavigate(FVector2D Axis)										
{
	if (CanInterfaceInput()) {IWidgetInterface_Input::Execute_InputNavigate(FocusMenu, Axis);}	//Input Navigate
}
void UOmegaSubsystem_Player::InputPage(float Axis)											
{
	if (CanInterfaceInput()) {IWidgetInterface_Input::Execute_InputPage(FocusMenu, Axis); }		//Input Page
}

void UOmegaSubsystem_Player::InputTag(FGameplayTag Tag)
{
	if (CanInterfaceInput()) {IWidgetInterface_Input::Execute_InputTag(FocusMenu, Tag);}
}

bool UOmegaSubsystem_Player::CanInterfaceInput() const
{
	if(!FocusMenu) { return false; }
	if(!FocusMenu->IsRendered()) { return false; }
	if(IWidgetInterface_Input::Execute_InputBlocked(FocusMenu)) { return false; }
	return true;
}


/// HUDS////
UHUDLayer* UOmegaSubsystem_Player::AddHUDLayer(TSubclassOf<UHUDLayer> LayerClass, UObject* Context, bool bPlayerScreen)
{
	CleanHUDLayers();
	
	TSubclassOf<UHUDLayer> _InClass=GetMutableDefault<UOmegaSettings>()->CorrectClass_HUD(LayerClass);
	if (UHUDLayer* LocalLayer = Cast<UHUDLayer>(CreateWidget(GetWorld(), _InClass)))
	{
		//try load TEMPLATE from GAME CORE
		for (auto* TempMenu : OGF_GAME_CORE()->HUD_Config)
		{
			if (TempMenu && TempMenu->GetClass() == LocalLayer->GetClass())
			{
				UEngine::CopyPropertiesForUnrelatedObjects(TempMenu, LocalLayer);
				break;
			}
		}
		
		ActiveHUDLayers.Add(LocalLayer);
		
		LocalLayer->SetOwningLocalPlayer(GetLocalPlayer());
		LocalLayer->ContextObject=Context;
		if(bPlayerScreen)
		{
			LocalLayer->AddToPlayerScreen(LocalLayer->SlateLayerIndex);
		}
		else
		{
			LocalLayer->AddToViewport(LocalLayer->SlateLayerIndex);
		}
		LocalLayer->LayerAdded(GetLocalPlayer()->GetPlayerController(GetWorld()), Context);
		return LocalLayer;
	}
	return nullptr;
}

bool UOmegaSubsystem_Player::RemoveHUDLayer(class TSubclassOf<UHUDLayer> LayerClass, FString Flag)
{
	CleanHUDLayers();
	
	TSubclassOf<UHUDLayer> _InClass=GetMutableDefault<UOmegaSettings>()->CorrectClass_HUD(LayerClass);
	
	if(UHUDLayer* tem_layer = GetHUDLayerByClass(_InClass))
	{
		tem_layer->RemoveHUDLayer();
		return true;
	}
	return false;
}

TArray<class UHUDLayer*> UOmegaSubsystem_Player::GetHUDLayers()
{
	TArray<UHUDLayer*> TempLayers;
	for (UHUDLayer* TempLayer : ActiveHUDLayers)
	{
		if(TempLayer)
		{
			TempLayers.Add(TempLayer);
		}
	}
	return TempLayers;
}


void UOmegaSubsystem_Player::RemoveAllHudLayers()
{
	CleanHUDLayers();
	for(UHUDLayer* TempLayer : ActiveHUDLayers)
	{
		if(TempLayer)
		{
			TempLayer->RemoveHUDLayer();
		}
	}
	ActiveHUDLayers.Empty();
}

UHUDLayer* UOmegaSubsystem_Player::GetHUDLayerByClass(TSubclassOf<UHUDLayer> LayerClass)
{
	for(auto* TempLayer : GetHUDLayers())
	{
		if(TempLayer->GetClass() == LayerClass && TempLayer->IsVisible())
		{
			return TempLayer;
		}
	}
	return nullptr;
}


void UOmegaSubsystem_Player::CleanHUDLayers()
{
	TArray<UHUDLayer*> LocalLayers;
	for(UHUDLayer* TempLayer : ActiveHUDLayers)
	{
		if(TempLayer)
		{
			LocalLayers.Add(TempLayer);
		}
	}
	ActiveHUDLayers = LocalLayers;
}


void UOmegaSubsystem_Player::SetCurrentHoverWidget(UDataWidget* Widget)
{
	if(HoveredWidget!=Widget)
	{
		if(HoveredWidget)
		{
			HoveredWidget->Native_SetHovered(false);
		}
		HoveredWidget=nullptr;
		if(Widget)
		{
			HoveredWidget=Widget;
			Widget->Native_SetHovered(true);
		}
	}
}

void UOmegaSubsystem_Player::TryUnhoverWidget(UDataWidget* Widget)
{
	if(Widget==HoveredWidget)
	{
		SetCurrentHoverWidget(nullptr);
	}
}

UDataWidget* UOmegaSubsystem_Player::GetCurrentHoverWidget() const
{
	if(HoveredWidget)
	{
		return HoveredWidget;
	}
	return nullptr;
}

UOmegaHoverCursor* UOmegaSubsystem_Player::GetHoverCursor()
{
	if (hover_cursor)
	{
		return hover_cursor;
	}
	if(const TSubclassOf<UOmegaHoverCursor> incoming_class = OGF_CFG_STYLE()->HoverCursorClass.LoadSynchronous())
	{
		hover_cursor = Cast<UOmegaHoverCursor>(CreateWidget(GetWorld(), incoming_class));
		hover_cursor->subsystem_ref=this;
		return hover_cursor;
	}
	return nullptr;
	
}

void UOmegaSubsystem_Player::SetCustomInputMode(UOmegaInputMode* InputMode)
{
	if(!InputMode || !REF_Controller)
	{
		return;
	}

	UEnhancedInputLocalPlayerSubsystem* LocalInputSubsys = REF_Controller->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	
	if(CurrentInputMode)
	{
		for(auto* TempContext : CurrentInputMode->AddedMappingContexts)
		{
			LocalInputSubsys->RemoveMappingContext(TempContext);
		}
	}
	
	//Add New
	REF_Controller->bShowMouseCursor = InputMode->bShowMouseCursor;
	REF_Controller->bEnableClickEvents = InputMode->bEnabledClickEvents;
	REF_Controller->bEnableTouchEvents = InputMode->bEnableTouchOverEvents;
	REF_Controller->bEnableMouseOverEvents = InputMode->bEnableMouseOverEvents;
	REF_Controller->bEnableTouchOverEvents = InputMode->bEnableTouchOverEvents;

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
			UWidgetBlueprintLibrary::SetInputMode_GameOnly(REF_Controller);
			break;
	case EInputModeType::InputModeType_UI:
			UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(REF_Controller);
			break;
	case EInputModeType::InputModeType_GameUI:
			UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(REF_Controller);
			break;
	default: ;
	}
	
	CurrentInputMode = InputMode;
	OnInputModeChanged.Broadcast(InputMode);
}


void UOmegaSubsystem_Player::Tick_Input(float DeltaTime)
{
	if (REF_Controller)
	{
		for (FKey k : KeysActive)
		{
			Input_OnKeyEvent(2,k,DeltaTime,false);
		}
		for (FKey k : SS_GI->cachedAxisKeys)
		{
			Input_OnKeyEvent(2,k,DeltaTime,true);
		}
	}
}

void UOmegaHoverCursor::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if(!subsystem_ref)
	{
		subsystem_ref = GetOwningPlayer()->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>();
	}
	if(subsystem_ref && subsystem_ref->GetCurrentHoverWidget())
	{
		SetVisibility(subsystem_ref->GetCurrentHoverWidget()->GetVisibility());
		const FVector2D target_pos = USlateBlueprintLibrary::LocalToAbsolute(subsystem_ref->GetCurrentHoverWidget()->GetCachedGeometry(),FVector2d());
		last_pos=UKismetMathLibrary::Vector2DInterpTo(last_pos,target_pos,InDeltaTime,InterpSpeed);
		SetPositionInViewport(last_pos);
		SetRenderOpacity(subsystem_ref->GetCurrentHoverWidget()->GetRenderOpacity());
	}
	else
	{
		SetRenderOpacity(0.0f);
	}
	Super::NativeTick(MyGeometry, InDeltaTime);
}


// ------------------------------------------------------------
// Dynamic Camera
// ------------------------------------------------------------

void UOmegaSubsystem_Player::DynaCam_SnapToCurrent()
{
	if(AOmegaDynamicCamera* cam_source = DynaCam_GetSource())
	{
		if(AOmegaDynamicCamera* cam_master = DynaCam_GetMaster())
		{
			DynaCam_Interp(cam_source,cam_master,0.0);
		}
	}
}


void UOmegaSubsystem_Player::Tick_DynamicCamera(float DeltaTime)
{
	if(GetWorld() && REF_Controller && is_DynamicCamerActive)
	{
		last_delta=DeltaTime;
		if(REF_Controller)
		{
			if(AOmegaDynamicCamera* _newCam = DynaCam_GetSource())
			{
				if (_newCam->L_CanPlayerUse(REF_Controller))
				{
					if(AOmegaDynamicCamera* cam_master = DynaCam_GetMaster())
					{
						//if current SourceCam does not match the one last frame, then call change
						if(l_PreviousCam!=_newCam)
						{
							if(l_PreviousCam)
							{
								l_PreviousCam->OnEndAsTargetCamera(REF_Controller);
							}
							l_PreviousCam=_newCam;
							_newCam->OnBeginAsTargetCamera(REF_Controller);
						}
						DynaCam_Interp(_newCam,cam_master,_newCam->InterpSpeed);
						_newCam->SourceTick(DeltaTime,REF_Controller,this);
					}
				}
			}
		}
	}
}

TSubclassOf<AOmegaDynamicCamera> UOmegaSubsystem_Player::DynaCam_GetDefaultClass()
{
	if (TSubclassOf<AOmegaDynamicCamera> _cl=GetMutableDefault<UOmegaSettings>()->DynamicCameraClass.LoadSynchronous())
	{
		return _cl;
	}
	return AOmegaDynamicCamera::StaticClass();
}

AOmegaDynamicCamera* UOmegaSubsystem_Player::DynaCam_GetMaster()
{
	if(!master_camera)
	{
		master_camera = GetWorld()->SpawnActorDeferred<AOmegaDynamicCamera>(DynaCam_GetDefaultClass(),FTransform());
		master_camera->FinishSpawning(FTransform());
	}
	return master_camera;
}

AOmegaDynamicCamera* UOmegaSubsystem_Player::DynaCam_GetSource()
{
	if(override_camera && override_camera->CameraActive)
	{
		return override_camera;
	}
	AOmegaDynamicCamera* out = nullptr;
	AOmegaDynamicCamera* master = DynaCam_GetMaster();
	TArray<AOmegaDynamicCamera*> _camList = source_cameras;
	for(AOmegaDynamicCamera* temp_cam : _camList)
	{
		if(temp_cam &&
			temp_cam != master &&
			!temp_cam->IsActorBeingDestroyed() &&
			temp_cam->CameraActive)
		{
			if(out)
			{
				if(temp_cam->Priority >= out->Priority)
				{
					out = temp_cam;
				}
			}
			else
			{
				out = temp_cam;
			}
		}
	}
	return out;
}

bool UOmegaSubsystem_Player::DynaCam_IsValidSource(AActor* Actor)
{
	if (Actor && Actor->GetClass()->ImplementsInterface(UActorInterface_DynamicCameraSource::StaticClass()))
	{
		return true;
	}
	return false;
}

void UOmegaSubsystem_Player::DynaCam_Register(AOmegaDynamicCamera* Camera, bool IsActive)
{
	if(Camera)
	{
		if(IsActive)
		{
			source_cameras.AddUnique(Camera);
		}
		else
		{
			source_cameras.Remove(Camera);
		}
	}
}

void UOmegaSubsystem_Player::DynaCam_SetActive(bool IsActive)
{
	is_DynamicCamerActive = IsActive;
	APlayerController* LocalController = GetLocalPlayer()->GetPlayerController(GetWorld());
	if(is_DynamicCamerActive)
	{
		LocalController->SetViewTarget(DynaCam_GetMaster());
	}
	else
	{
		LocalController->SetViewTarget(LocalController->K2_GetPawn());
	}
}

void UOmegaSubsystem_Player::DynaCam_Interp(AOmegaDynamicCamera* cam_source, AOmegaDynamicCamera* cam_master,
	float speed)
{
	if(cam_source && cam_master)
	{
		const FVector loc_master = DynaCam_GetMaster()->GetActorLocation();
		cam_master->SetActorLocation(UKismetMathLibrary::VInterpTo(loc_master,cam_source->GetActorLocation(),last_delta,speed));
		cam_master->SetActorRotation(UKismetMathLibrary::RInterpTo(cam_master->GetActorRotation(),cam_source->GetActorRotation(),last_delta,speed));
		cam_master->comp_camera->SetFieldOfView(UKismetMathLibrary::FInterpTo(cam_master->comp_camera->FieldOfView,cam_source->comp_camera->FieldOfView,last_delta,speed));

		cam_master->comp_spring->TargetArmLength=UKismetMathLibrary::FInterpTo(cam_master->comp_spring->TargetArmLength,cam_source->comp_spring->TargetArmLength,last_delta,speed);
		cam_master->comp_spring->SetRelativeLocation(UKismetMathLibrary::VInterpTo(cam_master->comp_spring->GetRelativeLocation(),cam_source->comp_spring->GetRelativeLocation(),last_delta,speed));
		cam_master->comp_spring->SetRelativeRotation(UKismetMathLibrary::RInterpTo(cam_master->comp_spring->GetRelativeRotation(),cam_source->comp_spring->GetRelativeRotation(),last_delta,speed));
		cam_master->comp_spring->SocketOffset=UKismetMathLibrary::VInterpTo(cam_master->comp_spring->SocketOffset,cam_source->comp_spring->SocketOffset,last_delta,speed);
		cam_master->comp_spring->TargetOffset=UKismetMathLibrary::VInterpTo(cam_master->comp_spring->TargetOffset,cam_source->comp_spring->TargetOffset,last_delta,speed);
		cam_master->comp_spring->bDoCollisionTest=cam_source->comp_spring->bDoCollisionTest;
	}
}

void UOmegaSubsystem_Player::DynaCam_SetOverride(AOmegaDynamicCamera* Camera, bool bSnapTo)
{
	if(Camera)
	{
		Camera->CameraActive=true;
		override_camera=Camera;
		if(bSnapTo)
		{
			DynaCam_SnapToCurrent();
		}
	}
	else
	{
		override_camera=nullptr;
	}
}

void UOmegaSubsystem_Player::DynaCam_ClearOverride()
{
	override_camera=nullptr;
}
