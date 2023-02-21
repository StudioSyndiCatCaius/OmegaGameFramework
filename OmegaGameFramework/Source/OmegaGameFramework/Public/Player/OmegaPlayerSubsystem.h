// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "GameplayTagContainer.h"
#include "OmegaInputMode.h"
#include "Widget/Menu.h"
#include "Components/SlateWrapperTypes.h"

#include "OmegaPlayerSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FMenuOpened, UMenu*, Menu, FGameplayTagContainer, Tags, bool, FirstMenu);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FMenuClosed, UMenu*, Menu, FGameplayTagContainer, Tags, bool, LastMenu);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FClearHoveredWidgets);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInputModeChanged, UOmegaInputMode*, NewMode);


class UUserWidget;
class UHUDLayer;
class UDataWidget;

UCLASS(DisplayName="Omega Subsystem: Player")
class OMEGAGAMEFRAMEWORK_API UOmegaPlayerSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

	virtual void Initialize(FSubsystemCollectionBase& Colection) override;

public:
	////////////////////////
	/////////Menus/////////
	//////////////////////
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|Menu", meta = (DeterminesOutputType = "MenuClass", AdvancedDisplay = "Context, Flag, AutoFocus, Flag"))
	class UMenu* OpenMenu(class TSubclassOf<UMenu> MenuClass, UObject* Context, FGameplayTagContainer Tags, const FString& Flag, bool AutoFocus=true);

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

	UPROPERTY(BlueprintAssignable)
	FMenuOpened OnMenuOpened;

	UPROPERTY(BlueprintAssignable)
	FMenuClosed OnMenuClosed;

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


	
	////////////////////////
	/////////HUD/////////
	//////////////////////
	
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|HUD", meta=(AdvancedDisplay = "LayerIndex, Context"))
	UHUDLayer* AddHUDLayer(class TSubclassOf<UHUDLayer> LayerClass, UObject* Context);

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|HUD", meta = (AdvancedDisplay = "Flag"))
	bool RemoveHUDLayer(class TSubclassOf<UHUDLayer> LayerClass, FString Flag);

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

	UFUNCTION()
	APlayerController* Local_GetPlayerController();
	
	UPROPERTY()
	class APlayerController* ParentPlayerController;

	UPROPERTY()
	FClearHoveredWidgets ClearHoveredWidgets;

	///////////////////
	/// DATA WIDGETS ////
	/// /////////

	UPROPERTY()
	UDataWidget* HoveredWidget = nullptr;
	
	///////////////////
	/// Input ////
	/// /////////
	///
	///
	UPROPERTY(BlueprintReadOnly, Category="Input")
	UOmegaInputMode* CurrentInputMode;
	
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|Input")
	void SetCustomInputMode(UOmegaInputMode* InputMode);

	UPROPERTY(BlueprintAssignable)
	FOnInputModeChanged OnInputModeChanged;
};



