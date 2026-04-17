// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "GameplayTagContainer.h"
#include "InputMappingContext.h"
#include "InputCoreTypes.h"
#include "Blueprint/UserWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "Components/InputComponent.h"
#include "Misc/OmegaUtils_Structs.h"

#include "Subsystem_Player.generated.h"

class UOmegaSubsystem_GameInstance;
class UCameraComponent;
class USpringArmComponent;
class UUserWidget;
class UHUDLayer;
class UDataWidget;
class AOmegaDynamicCamera;
class UAudioComponent;
class UMenu;

// ================================================================================================================
// Input Mode
// ================================================================================================================

UENUM(BlueprintType) 
enum class EInputModeType : uint8
{
	InputModeType_Game          UMETA(DisplayName = "Game"),
	InputModeType_UI			UMETA(DisplayName = "UI"),
	InputModeType_GameUI		UMETA(DisplayName = "Game & UI"),
};

	
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaInputMode : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Input")
	EInputModeType Type;

	UPROPERTY(EditAnywhere, Category="Input")
	TArray<UInputMappingContext*> AddedMappingContexts;
	
	UPROPERTY(EditAnywhere, Category="Input")
	int32 InputPriority;
	
	UPROPERTY(EditAnywhere, Category="Mouse") bool bShowMouseCursor;
	UPROPERTY(EditAnywhere, Category="Mouse") bool bEnabledClickEvents;
	UPROPERTY(EditAnywhere, Category="Mouse") bool bEnableTouchEvents;
	UPROPERTY(EditAnywhere, Category="Mouse") bool bEnableMouseOverEvents;
	UPROPERTY(EditAnywhere, Category="Mouse") bool bEnableTouchOverEvents;
};


// ================================================================================================================
// Subsystem
// ================================================================================================================

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FMenuOpened, UMenu*, Menu, FGameplayTagContainer, Tags, bool, FirstMenu);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FMenuClosed, UMenu*, Menu, FGameplayTagContainer, Tags, bool, LastMenu);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FClearHoveredWidgets);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInputModeChanged, UOmegaInputMode*, NewMode);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInputDeviceChangedDelegate, bool, bIsUsingGamepad);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDataWidgetSubsystemEvent,UDataWidget*, Widget, uint8, Event);

UCLASS(DisplayName="Omega Subsystem: Player")
class OMEGAGAMEFRAMEWORK_API UOmegaSubsystem_Player : public ULocalPlayerSubsystem, public FTickableGameObject
{
	GENERATED_BODY()
	
	UPROPERTY() UOmegaSubsystem_GameInstance* SS_GI;

	virtual void Initialize(FSubsystemCollectionBase& Colection) override;
	virtual void Deinitialize() override;
	UPROPERTY() UDataWidget* HoveredWidget = nullptr;
	UPROPERTY() UOmegaHoverCursor* hover_cursor;
	
	float f_UiNavCooldown;
	TArray<FKey> KeysActive;
	void Input_OnKeyStart(FKey Key);
	void Input_OnKeyEnd(FKey Key);
	// 0=press , 1=release , 2=tick
	void Input_OnKeyEvent(uint8 event,FKey key, float dt, bool bAxisKey);
	
public:
	FInputKeyBinding KeyBind_Start;
	FInputKeyBinding KeyBind_Stop;
	
	UPROPERTY() TMap<FGameplayTag, UDataWidget*> SlottedDataWidgets;
	UPROPERTY() TArray<TWeakObjectPtr<UObject>> InputTargets;
	
	virtual void L_TryRegisterInputTarget(UObject* target);
	
	virtual void Tick(float DeltaTime) override;
	virtual ETickableTickType GetTickableTickType() const override { return ETickableTickType::Always; }
	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT( FMyTickableThing, STATGROUP_Tickables ); }
	virtual bool IsTickableWhenPaused() const { return true; }
	virtual bool IsTickableInEditor() const { return false; }
	
	virtual void PlayerControllerChanged(APlayerController* NewPlayerController) override;
	
	UPROPERTY() APlayerController* REF_Controller;
	
	//0=select | 1=hover | 2=unhover
	UPROPERTY() FDataWidgetSubsystemEvent DataWidgetSubsystemEvent; 
	
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|Menu", meta = (DeterminesOutputType = "MenuClass", AdvancedDisplay = "Context, Flag, AutoFocus, Flag"))
	class UMenu* OpenMenu(class TSubclassOf<UMenu> MenuClass, UObject* Context, FGameplayTagContainer Tags, const FString& Flag, bool AutoFocus=true,FOmegaCommonMeta meta=FOmegaCommonMeta());

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|Menu")
	bool CloseMenu(class TSubclassOf<UMenu> MenuClass, FGameplayTagContainer Tags, UObject* Context, const FString& Flag);

	UFUNCTION(BlueprintPure, Category = "Ω|Widget|Menu", meta=(DeterminesOutputType = "MenuClass"))
	class UMenu* GetMenu(class TSubclassOf<UMenu> MenuClass, bool& bIsValid);

	UFUNCTION()
	void CloseAllMenus(AActor* DestroyedActor);

	//Which Menu is this player current inputing into.
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|Menu")
	void SetControlWidget(UUserWidget* Widget);

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|Menu")
	void ClearControlWidget();

	UFUNCTION()
	void RemoveMenuFromActiveList(UMenu* Menu);

	UPROPERTY()
	TArray<class UMenu*> OpenMenus;

	UPROPERTY(BlueprintReadOnly, Category="Widget", meta=(DisplayName="Control Widget"))
	class UUserWidget* FocusMenu;

	UPROPERTY(BlueprintAssignable) FMenuOpened OnMenuOpened;
	UPROPERTY(BlueprintAssignable) FMenuClosed OnMenuClosed;

	//SOUND
	UPROPERTY()
	bool Local_UiSoundCooldown;

	UPROPERTY()
	FTimerHandle SoundCooldownTimer;

	void PlayUiSound(USoundBase* Sound);
protected:
	UPROPERTY()
	UAudioComponent* UiAudioComp;
	UAudioComponent* GetLocalAudioComp();
	
public:
	//Menu Input
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|Input")
	void InputConfirm();

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|Input")
	void InputCancel();

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|Input")
	void InputNavigate(FVector2D Axis);

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|Input")
	void InputPage(float Axis);

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|Input")
	void InputTag(FGameplayTag Tag);

	UFUNCTION()
	bool CanInterfaceInput() const;
	
	// -- HUD -- //
	
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|HUD", meta=(AdvancedDisplay = "LayerIndex, Context"))
	UHUDLayer* AddHUDLayer(class TSubclassOf<UHUDLayer> LayerClass, UObject* Context, bool bPlayerScreen=true);

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|HUD", meta = (AdvancedDisplay = "Flag"))
	bool RemoveHUDLayer(class TSubclassOf<UHUDLayer> LayerClass, FString Flag);

	UPROPERTY()
	TArray <class UHUDLayer*> ActiveHUDLayers;

	UFUNCTION(BlueprintPure, Category = "Ω|Widget|HUD")
	TArray <UHUDLayer*> GetHUDLayers();

	UFUNCTION(BlueprintPure, Category = "Ω|Widget|HUD")
	UHUDLayer* GetHUDLayerByClass(TSubclassOf<UHUDLayer> LayerClass);
	
	UFUNCTION(BlueprintPure, Category = "Ω|Widget|HUD")
	TArray <UHUDLayer*> GetHUDLayersWithTags(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|HUD")
	void RemoveHUDLayersWithTags(FGameplayTagContainer Tags);
	
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|HUD")
	void RemoveAllHudLayers();

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|HUD")
	void SetHUDVisibilityWithTags(FGameplayTagContainer Tags, ESlateVisibility Visibility);

	void CleanHUDLayers();


	UPROPERTY()
	FClearHoveredWidgets ClearHoveredWidgets;

	// -- Data Widgets -- //a

	UFUNCTION(BlueprintCallable,Category="Widget")
	void SetCurrentHoverWidget(UDataWidget* Widget);

	UFUNCTION(BlueprintCallable,Category="Widget")
	void TryUnhoverWidget(UDataWidget* Widget);
	
	UFUNCTION(BlueprintPure,Category="Widgets")
	UDataWidget* GetCurrentHoverWidget() const;

	// -----------
	// Hover Cursor

public:
	
	UFUNCTION(BlueprintPure, Category="Omega|HoverCursor")
	UOmegaHoverCursor* GetHoverCursor();
	
	// -- Input -- //
	UPROPERTY(BlueprintReadOnly, Category="Omega|Input")
	UOmegaInputMode* CurrentInputMode;
	
	UFUNCTION(BlueprintCallable, Category="Omega|Input")
	void SetCustomInputMode(UOmegaInputMode* InputMode);

	UPROPERTY(BlueprintAssignable)
	FOnInputModeChanged OnInputModeChanged;

	UPROPERTY(BlueprintAssignable, Category="Omega|Input")
	FInputDeviceChangedDelegate OnInputDeviceChanged;



	UFUNCTION(BlueprintPure, Category="Omega|Input")
	bool IsUsingGamepad() const
	{
		return bUsingGamepad;
	}
private:
	UPROPERTY()
	bool bUsingGamepad;
	
	void Tick_Input(float DeltaTime);
	
	// ================================================================================================================
	// Dynamic Camera
	// ================================================================================================================
public:
	float last_delta;
	float time_SinceLastCheck;
	bool is_DynamicCamerActive;
	
	UPROPERTY() AOmegaDynamicCamera* override_camera;
	UPROPERTY() TArray<AOmegaDynamicCamera*> source_cameras;
	UPROPERTY() AOmegaDynamicCamera* master_camera;
	UPROPERTY() AOmegaDynamicCamera* l_PreviousCam=nullptr;
	
	void Tick_DynamicCamera(float DeltaTime);
	TSubclassOf<AOmegaDynamicCamera> DynaCam_GetDefaultClass();
	AOmegaDynamicCamera* DynaCam_GetMaster();
	AOmegaDynamicCamera* DynaCam_GetSource();
	bool DynaCam_IsValidSource(AActor* Actor);
	void DynaCam_SetActive(bool IsActive);
	void DynaCam_Register(AOmegaDynamicCamera* Camera, bool IsActive);
	bool DynaCam_IsActive() const { return is_DynamicCamerActive;}
	void DynaCam_Interp(AOmegaDynamicCamera* cam_source, AOmegaDynamicCamera* cam_master, float speed);
	void DynaCam_SetOverride(AOmegaDynamicCamera* Camera, bool bSnapTo);
	void DynaCam_ClearOverride();
	void DynaCam_SnapToCurrent();
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaHoverCursor : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UPROPERTY()
	UOmegaSubsystem_Player* subsystem_ref;
	UPROPERTY()
	FVector2D last_pos;

	UPROPERTY(EditAnywhere,Category="Hover Widget")
	float InterpSpeed = 15.0;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};




