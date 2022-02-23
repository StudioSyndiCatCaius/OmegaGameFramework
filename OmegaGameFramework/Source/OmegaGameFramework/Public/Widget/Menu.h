// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "Widget/WidgetInterface_Input.h"

#include "Menu.generated.h"

class APlayerController;
class UWidgetAnimation;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOpened, FGameplayTagContainer, Tags);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FClosed, FGameplayTagContainer, Tags);

UCLASS(HideFunctions=(Construct, RemoveFromParent))
class OMEGAGAMEFRAMEWORK_API UMenu : public UUserWidget, public IWidgetInterface_Input
{
	GENERATED_BODY()

protected:
	virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;
	virtual void NativeConstruct() override;
	
public:

	UFUNCTION()
		void OpenMenu(FGameplayTagContainer Tags, UObject* Context, APlayerController* PlayerRef);

	void Native_CompleteOpen();
	
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|Menu")
		void CloseMenu(FGameplayTagContainer Tags);

	void Native_CompleteClose();

	UPROPERTY()
	bool PrivateInputBlocked;

	UPROPERTY()
	FGameplayTagContainer TempTags;
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Widget|Menu")
		void MenuOpened(FGameplayTagContainer Tags, UObject* Context);

	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Widget|Menu")
		void MenuClosed(FGameplayTagContainer Tags);

	//Anim
	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Animations")
	UWidgetAnimation* GetOpenAnimation();
	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Animations")
	UWidgetAnimation* GetCloseAnimation();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animations")
	bool ReverseOpenAnimation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animations")
	bool ReverseCloseAnimation=true;

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
