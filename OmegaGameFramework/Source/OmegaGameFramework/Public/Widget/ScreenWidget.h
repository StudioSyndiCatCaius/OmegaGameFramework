// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/I_Widget.h"
#include "Components/Image.h"
#include "Misc/OmegaUtils_Structs.h"

#include "ScreenWidget.generated.h"

class UDataList;
class UDataWidget;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaScreenWidget : public UUserWidget
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintNativeEvent) void OnGlobalEvent(FName Event, UObject* Context, FOmegaCommonMeta Meta);
	UFUNCTION(BlueprintNativeEvent) void OnTaggedGlobalEvent(FGameplayTag Event, UObject* Context, FOmegaCommonMeta Meta);
	UFUNCTION(BlueprintNativeEvent) void OnGameplayMessage(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta meta);
	UFUNCTION(BlueprintNativeEvent) void OnActorTaggedTargetChanged(AActor* Instigator, FGameplayTag Tag, AActor* Target, bool bRegsitered);
	UFUNCTION(BlueprintNativeEvent) void OnInputMethodChanged(bool bIsGamepad);
	
	virtual void NativeConstruct() override;
	UPROPERTY(BlueprintReadOnly,Category="OMEGA Widget") UObject* ContextObject;
	UPROPERTY(BlueprintReadOnly,Category="OMEGA Widget") FOmegaCommonMeta widget_meta;
	
	UPROPERTY(EditDefaultsOnly, Category = "OMEGA Widget") int32 SlateLayerIndex;
	
	UFUNCTION(BlueprintImplementableEvent,Category="ScreenWidget") UTextBlock* GetWidget_Text_ContextName();
	UFUNCTION(BlueprintImplementableEvent,Category="ScreenWidget") UTextBlock* GetWidget_Text_ContextDescription();
	UFUNCTION(BlueprintImplementableEvent,Category="ScreenWidget") UImage* GetWidget_Image_ContextIcon();

	UFUNCTION(BlueprintImplementableEvent,Category="ScreenWidget") TArray<UDataList*> GetDataLists_LinkedToPlayerPawn();
	UFUNCTION(BlueprintImplementableEvent,Category="ScreenWidget") TArray<UDataWidget*> GetDataWidgets_LinkedToPlayerPawn();
};
