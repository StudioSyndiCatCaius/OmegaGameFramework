// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "ScreenWidget.h"
#include "HUDLayer.generated.h"

class UOmegaSubsystem_Player;




UCLASS(HideFunctions = (Construct, Destruct))
class OMEGAGAMEFRAMEWORK_API UHUDLayer : public UOmegaScreenWidget
{
	GENERATED_BODY()

private:

	UPROPERTY()
	bool bRemoving;

public:

	virtual void NativeConstruct() override;
	
	virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;
	
	UFUNCTION(BlueprintImplementableEvent, Category = "HUD")
	void LayerAdded(class APlayerController* OwningPlayer, UObject* Context);

	//Will run the removal animation, and then clea the HUD Layer once finished.
	UFUNCTION(BlueprintCallable, Category="HUD")
	void RemoveHUDLayer();

	//UFUNCTION(BlueprintImplementableEvent, Category="Omega")
	//void LayerRemoved();
	
	UPROPERTY(EditDefaultsOnly, Category = "HUD Layer") bool AddRemove_OpacityFade;
	UPROPERTY(EditDefaultsOnly, Category = "HUD Layer") float AddRemove_OpacityFadeTime=0.2;

	UPROPERTY(EditDefaultsOnly, Category = "HUD Layer")
	FGameplayTagContainer HUDTags;
	
	UPROPERTY(EditDefaultsOnly, Category = "HUD Layer")
	bool bReverseCloseAnim=true;

	UFUNCTION(BlueprintImplementableEvent, Category="Omega") UWidgetAnimation* GetAppearAnimation();
	UFUNCTION(BlueprintImplementableEvent, Category="Omega") UWidgetAnimation* GetRemovedAnimation();

private:

	UFUNCTION()
	void Local_RemoveAnimFinished();

	// Opacity-fade fallback (used only when no Appear/Removed animation is set)
	void StartOpacityFade(bool bFadeOut);
	void Local_TickOpacityFade();

	UPROPERTY() bool bFadeOutDirection = false;
	UPROPERTY() float FadeStartTime = 0.f;
	FTimerHandle FadeTimerHandle;

};

UINTERFACE(MinimalAPI, DisplayName="♎Data🔴 - HUD Source") class UDataInterface_HUDSource : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_HUDSource
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent,Category="Omega|HUD")
	TSubclassOf<UHUDLayer> GetHUDLayerClass(FName Name);
};