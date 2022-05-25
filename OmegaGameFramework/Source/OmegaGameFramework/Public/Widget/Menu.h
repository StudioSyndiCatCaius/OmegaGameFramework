// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "Widget/WidgetInterface_Input.h"

#include "Menu.generated.h"

class APlayerController;
class UWidgetAnimation;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOpened, FGameplayTagContainer, Tags, FString, Flag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FClosed, FGameplayTagContainer, Tags, FString, Flag);

UCLASS(HideFunctions=(Construct, RemoveFromParent))
class OMEGAGAMEFRAMEWORK_API UMenu : public UUserWidget, public IWidgetInterface_Input
{
	GENERATED_BODY()

protected:
	virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;
	virtual void NativeConstruct() override;
	
public:

	UFUNCTION()
		void OpenMenu(FGameplayTagContainer Tags, UObject* Context, APlayerController* PlayerRef, const FString& Flag);

	void Native_CompleteOpen();
	
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|Menu", meta=(AdvancedDisplay="Tags, Flag"))
		void CloseMenu(FGameplayTagContainer Tags, const FString& Flag);

	void Native_CompleteClose();

	UPROPERTY()
	bool PrivateInputBlocked;

	UPROPERTY()
	FGameplayTagContainer TempTags;
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Widget|Menu")
		void MenuOpened(FGameplayTagContainer Tags, UObject* Context, const FString& Flag);

	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Widget|Menu")
		void MenuClosed(FGameplayTagContainer Tags, const FString& Flag);

	/////////////////////////
	////////ANIMATIONS///////
	////////////////////////
	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Animations")
	UWidgetAnimation* GetOpenAnimation();
	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Animations")
	UWidgetAnimation* GetCloseAnimation();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animations")
	bool ReverseOpenAnimation;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animations")
	bool ReverseCloseAnimation=true;
	
	UPROPERTY(EditDefaultsOnly, Category = "Animations", AdvancedDisplay)
	ESlateVisibility VisibilityOnOpen = ESlateVisibility::SelfHitTestInvisible;
	UPROPERTY(EditDefaultsOnly, Category = "Animations", AdvancedDisplay)
	ESlateVisibility VisibilityOnClose = ESlateVisibility::Collapsed;

	UPROPERTY()
	FWidgetAnimationDynamicEvent OpenDelegate;
	UPROPERTY()
	FWidgetAnimationDynamicEvent CloseDelegate;
	
	//Input
	virtual bool InputBlocked_Implementation() override;

	///PROPERTIES//

	UPROPERTY(BlueprintReadOnly, Category = "Ω|Widget|Menu")
	bool bIsOpen;

	///DELGATES//
	UPROPERTY(BlueprintAssignable)
		FOpened OnOpened;
	UPROPERTY(BlueprintAssignable)
		FClosed OnClosed;
};
