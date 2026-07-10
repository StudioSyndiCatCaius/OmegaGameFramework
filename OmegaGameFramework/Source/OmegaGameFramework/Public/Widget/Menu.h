// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "ScreenWidget.h"
#include "Interfaces/I_GameplayState.h"
#include "Interfaces/I_Widget.h"
#include "Misc/GeneralDataObject.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Menu.generated.h"

class APlayerController;
class UWidgetAnimation;
class AOmegaGameplaySystem;
class UOmegaInputMode;
class UDataListCustomEntry;
class UOmegaGameplayMessage;

UINTERFACE(MinimalAPI, DisplayName="♎Data🔴 - Menu Source") class UDataInterface_MenuSource : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_MenuSource
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent,Category="Omega|HUD")
	TSubclassOf<UMenu> GetMenuClass(FName Name);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaMenuWrapperActor : public AActor
{
	GENERATED_BODY()

public:
	AOmegaMenuWrapperActor();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Menu") UCombatantComponent* Combatant;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Menu") UChildActorComponent* ChildActor;
	
};



DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOpened, FGameplayTagContainer, Tags, FString, Flag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FClosed, FGameplayTagContainer, Tags, UObject*, Context, FString, Flag);

UCLASS(HideFunctions=(Construct, RemoveFromParent),Abstract)
class OMEGAGAMEFRAMEWORK_API UMenu : public UOmegaScreenWidget, public IWidgetInterface_Input, public IDataInterface_GameplayModifier
{
	GENERATED_BODY()

protected:
	virtual void L_SetSubstate(int32 NewState) override;
	
	virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;
	//virtual void OnAnimationFinishedPlaying(UUMGSequencePlayer& Player) override;
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual bool InputAction_Disabled_Implementation(APlayerController* Player, FGameplayTag Action) override;
	virtual void NativeDestruct() override;
public:
	UFUNCTION(BlueprintImplementableEvent,Category="Menu")
	UDataList* GetDefaultDataList();

	UPROPERTY() FGameplayTagContainer TempTags;
	//----------------------------------------------------------------------
	// Menu
	//----------------------------------------------------------------------
	
	//This Gameplay system will be activated when the menu is opened, and shutdown when it is closed.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu") FText DisplayName;
	UPROPERTY(EditAnywhere, Category = "Menu") TSubclassOf<AOmegaGameplaySystem> ParallelGameplaySystem;
	// if valid, this child actor class will be spawned on the Menu's wrapper actor
	UPROPERTY(EditAnywhere, Category = "Menu") TSubclassOf<AActor> WrapperChildActor;
	//If true, this menu being open will NOT be considered for the Gameplay System blocking tags found in `Omega Settings`
	UPROPERTY(EditAnywhere,Category="Menu") bool bExemptFromGlobalSystemBlockingTags;
	//if substate index is set to <0, close the menu
	UPROPERTY(EditAnywhere,Category="Menu") bool bCloseMenuOnSubstateUnderflow=true;
	
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
	
	UFUNCTION(BlueprintNativeEvent, Category = "Ω|Widget|Menu")
		void MenuOpened(FGameplayTagContainer Tags, UObject* Context, const FString& Flag);

	UFUNCTION(BlueprintNativeEvent, Category = "Ω|Widget|Menu")
		void MenuClosed(FGameplayTagContainer Tags, const FString& Flag);

	//----------------------------------------------------------------------
	// Wrapper Actor
	//----------------------------------------------------------------------
	UPROPERTY() AOmegaMenuWrapperActor* WrapperActor;
	UFUNCTION(BlueprintPure,Category="Menu|ActorWrapper") AOmegaMenuWrapperActor* GetMenuWrapperActor() const;
	
	UFUNCTION(BlueprintCallable,Category="Menu|ActorWrapper",meta=(DeterminesOutputType="Class")) AActor* GetMenuWrapperChildActor(TSubclassOf<AActor> Class);
	
	
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

	FTimerHandle InputBlockTimer;
	UFUNCTION() void InputBlockTimer_End();

	UPROPERTY() float InputBlock_Remaining;
	UPROPERTY() bool PrivateInputBlocked;
public:
	UFUNCTION() bool IsInputBlocked() const;
	
	virtual bool InputBlocked_Implementation() override;
	
	UFUNCTION(BlueprintNativeEvent, Category="Input",DisplayName="Substate - Get Input Target Widgets")
	TArray<UUserWidget*> GetSubstateInputWidget();
	
	virtual UUserWidget* ControlWidget_Get_Implementation(int32& priority) override;
	//----------------------------------------------------------------------
	// ANIMATIONS
	//----------------------------------------------------------------------
	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Animations",DisplayName="Get Widget Animation (Open)")
	UWidgetAnimation* GetOpenAnimation();
	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Animations",DisplayName="Get Widget Animation (Close)")
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

	UPROPERTY(BlueprintReadOnly, Category = "Omega|Menu") bool bIsOpen;

	///DELGATES//
	UPROPERTY(BlueprintAssignable, Category="Omega") FOpened OnOpened;
	UPROPERTY(BlueprintAssignable, Category="Omega") FClosed OnClosed;
	
};

