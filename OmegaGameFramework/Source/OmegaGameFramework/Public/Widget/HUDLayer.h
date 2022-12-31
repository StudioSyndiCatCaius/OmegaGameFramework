// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"

#include "HUDLayer.generated.h"

class UOmegaPlayerSubsystem;

/**
 * 
 */
UCLASS(HideFunctions = (Construct, Destruct))
class OMEGAGAMEFRAMEWORK_API UHUDLayer : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	
	UFUNCTION(BlueprintImplementableEvent, Category = "HUD")
	void LayerAdded(class APlayerController* OwningPlayer, UObject* Context);

	//UFUNCTION(BlueprintImplementableEvent)
	//void LayerRemoved();

	UPROPERTY(EditDefaultsOnly, Category = "HUD Layer")
	FGameplayTagContainer HUDTags;
	
	UPROPERTY(EditDefaultsOnly, Category = "HUD Layer")
	int32 SlateLayerIndex;
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnGlobalEvent(FName Event, UObject* Context);
	
	UFUNCTION()
	void Local_BindGlobalEvent();
	
};
