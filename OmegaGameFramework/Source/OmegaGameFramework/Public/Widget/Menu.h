// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "ScreenWidget.h"
#include "Components/WidgetSwitcher.h"
#include "Subsystems/OmegaSubsystem_Message.h"
#include "Interfaces/OmegaInterface_Widget.h"
#include "Misc/GeneralDataObject.h"

#include "Menu.generated.h"

class APlayerController;
class UWidgetAnimation;
class AOmegaGameplaySystem;
class UOmegaInputMode;
class UDataListCustomEntry;


UINTERFACE(MinimalAPI) class UDataInterface_CommonMenu : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_CommonMenu
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Menu")
	TArray<UObject*> GetDataListEntries(UMenu* Menu);
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaCommonMenuDefinition : public UOmegaDataAsset, public IDataInterface_CommonMenu
{
	GENERATED_BODY()
	
public:UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menu")
	TArray<UPrimaryDataAsset*> CustomEntry_Assets;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category = "Menu")
	TArray<UDataListCustomEntry*> CustomEntry_Objects;
	
	virtual TArray<UObject*> GetDataListEntries_Implementation(UMenu* Menu) override;
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOpened, FGameplayTagContainer, Tags, FString, Flag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FClosed, FGameplayTagContainer, Tags, UObject*, Context, FString, Flag);

UCLASS(HideFunctions=(Construct, RemoveFromParent))
class OMEGAGAMEFRAMEWORK_API UMenu : public UOmegaScreenWidget, public IWidgetInterface_Input
{
	GENERATED_BODY()

protected:
	virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;
	//virtual void OnAnimationFinishedPlaying(UUMGSequencePlayer& Player) override;
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
public:
	UFUNCTION(BlueprintImplementableEvent,Category="Menu")
	UDataList* GetDefaultDataList();
	
	UPROPERTY() FGameplayTagContainer TempTags;
	//----------------------------------------------------------------------
	// Menu
	//----------------------------------------------------------------------
	
	//This Gameplay system will be activated when the menu is opened, and shutdown when it is closed.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	FText DisplayName;
	UPROPERTY(EditAnywhere, Category = "Menu")
	TSubclassOf<AOmegaGameplaySystem> ParallelGameplaySystem;

	UFUNCTION()
		void OpenMenu(FGameplayTagContainer Tags, UObject* Context, APlayerController* PlayerRef, const FString& Flag);

	void Native_CompleteOpen();

	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	bool CanCloseMenu(FGameplayTagContainer Tags, UObject* Context, const FString& Flag);
	
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|Menu", meta=(AdvancedDisplay="Context, Tags, Flag"))
		void CloseMenu(FGameplayTagContainer Tags, UObject* Context, const FString& Flag);
private:
	UPROPERTY() bool bIsClosing;
	UPROPERTY() bool bIsPlayingAnimation;
public:
	
	void Native_CompleteClose();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Widget|Menu")
		void MenuOpened(FGameplayTagContainer Tags, UObject* Context, const FString& Flag);

	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Widget|Menu")
		void MenuClosed(FGameplayTagContainer Tags, const FString& Flag);

	//----------------------------------------------------------------------
	// Reset
	//----------------------------------------------------------------------
	UFUNCTION(BlueprintCallable,Category="Menu")
	void Reset() { OnReset(); }
	UFUNCTION(BlueprintImplementableEvent,Category="Menu")
	void OnReset();
	//----------------------------------------------------------------------
	// Input
	//----------------------------------------------------------------------

	UPROPERTY(EditDefaultsOnly, Category="Input")
	UOmegaInputMode* CustomInputMode;

	//Prevents input when menus is opened for a set amount of time
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Input")
	float InputBlockDelay=0.2;
private:
	UPROPERTY() float InputBlock_Remaining;
	UPROPERTY() bool PrivateInputBlocked;
public:
	UFUNCTION() bool IsInputBlocked() const { return PrivateInputBlocked || bIsClosing || !bIsOpen || InputBlock_Remaining > 0.0; }
	
	virtual bool InputBlocked_Implementation() override;
	//----------------------------------------------------------------------
	// ANIMATIONS
	//----------------------------------------------------------------------
	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Animations")
	UWidgetAnimation* GetOpenAnimation();
	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Animations")
	UWidgetAnimation* GetCloseAnimation();
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animations")
	float OpenCloseInterpTime=0.2;
	UPROPERTY() float OpenCloseInterp_Value;
	UPROPERTY() bool isPlayingOpenCloseInterp;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animations")
	bool AutoInterpOpacityOnOpenClose;
	UFUNCTION(BlueprintImplementableEvent,Category="Animations")
	void UpdateOpenCloseInterp(float value);
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animations")
	bool ReverseOpenAnimation;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animations")
	bool ReverseCloseAnimation=true;
	
	UPROPERTY(EditAnywhere, Category = "Animations", AdvancedDisplay)
	ESlateVisibility VisibilityOnOpen = ESlateVisibility::SelfHitTestInvisible;
	UPROPERTY(EditAnywhere, Category = "Animations", AdvancedDisplay)
	ESlateVisibility VisibilityOnClose = ESlateVisibility::Collapsed;

	UPROPERTY()
	FWidgetAnimationDynamicEvent OpenDelegate;
	UPROPERTY()
	FWidgetAnimationDynamicEvent CloseDelegate;

	UPROPERTY(EditAnywhere, Category = "Sound")
	USoundBase* OpenSound;
	UPROPERTY(EditAnywhere, Category = "Sound")
	USoundBase* CloseSound;
	//If no sound is found for a menu sound, default to using sounds from the current OmegaSlateStyle Asset
	UPROPERTY(EditAnywhere, Category = "Sound")
	bool DefaultToStyleSounds=true;
	
	///PROPERTIES//

	UPROPERTY(BlueprintReadOnly, Category = "Omega|Menu")
	bool bIsOpen;

	///DELGATES//
	UPROPERTY(BlueprintAssignable)
		FOpened OnOpened;
	UPROPERTY(BlueprintAssignable)
		FClosed OnClosed;

	UFUNCTION(BlueprintImplementableEvent, DisplayName="On Global Event (Name)")
	void OnGlobalEvent(FName Event, UObject* Context);
	UFUNCTION(BlueprintImplementableEvent, DisplayName="On Global Event (Tag)")
	void OnTaggedGlobalEvent(FGameplayTag Event, UObject* Context);
	UFUNCTION() void Local_BindGlobalEvent();

	UFUNCTION(BlueprintNativeEvent)
	void OnGameplayMessage(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FLuaValue meta);
	UFUNCTION(BlueprintImplementableEvent)
	void OnInputMethodChanged(bool bIsGamepad);

	//----------------------------------------------------------------------
	// State
	//----------------------------------------------------------------------
private:
	UPROPERTY() int32 menu_state;
	void Native_UpdateState();
public:
	UFUNCTION(BlueprintImplementableEvent,Category="Menu|State")
	void OnMenuStateChanged(int32 new_state);

	UFUNCTION(BlueprintImplementableEvent,Category="Menu|State")
	UWidgetSwitcher* GetWidget_WidgetSwitcher_State();
	
	UFUNCTION(BlueprintCallable,Category="Menu|State")
	void SetMenuState(int32 state);

	UFUNCTION(BlueprintCallable,Category="Menu|State")
	int32 GetMenuState() const { return menu_state;};
};
