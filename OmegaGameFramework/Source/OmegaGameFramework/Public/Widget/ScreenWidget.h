// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/I_StandardInput.h"
#include "Interfaces/I_Widget.h"
#include "Misc/OmegaUtils_Structs.h"

#include "ScreenWidget.generated.h"

class UOmegaSubsystem_Player;
class UOmegaSubsystem_World;
class UOmegaSubsystem_GameInstance;
class UImage;

class UDataList;
class UDataWidget;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaScreenWidget : public UUserWidget, public IDataInterface_InputAction
{
	GENERATED_BODY()

public:
	
	UPROPERTY() UOmegaSubsystem_GameInstance* SS_GI;
	UPROPERTY() UOmegaSubsystem_World* SS_World;
	UPROPERTY() UOmegaSubsystem_Player* SS_Player;
	
	UFUNCTION(BlueprintNativeEvent) void OnGlobalEvent(FName Event, UObject* Context, FOmegaCommonMeta Meta);
	UFUNCTION(BlueprintNativeEvent) void OnTaggedGlobalEvent(FGameplayTag Event, UObject* Context, FOmegaCommonMeta Meta);
	UFUNCTION(BlueprintNativeEvent) void OnGameplayMessage(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta meta);
	UFUNCTION(BlueprintNativeEvent) void OnGameplayMessageEnd(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta meta);
	UFUNCTION(BlueprintNativeEvent) void OnActorTaggedTargetChanged(AActor* Instigator, FGameplayTag Tag, AActor* Target, bool bRegsitered);
	UFUNCTION(BlueprintNativeEvent) void OnInputMethodChanged(bool bIsGamepad);
	
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	UPROPERTY(BlueprintReadOnly,Category="OMEGA Widget") UObject* ContextObject;
	UPROPERTY(BlueprintReadOnly,Category="OMEGA Widget") FOmegaCommonMeta widget_meta;
	
	//----------------------------------------------------------------------
	// State
	//----------------------------------------------------------------------

	UPROPERTY(EditDefaultsOnly, Category = "OMEGA Widget") int32 SlateLayerIndex;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,Category="♎Omega|Misc") TArray<FName> Substates;
	UPROPERTY(BlueprintReadOnly,Category="OMEGA Widget") int32 Substate=-1;
	
	UFUNCTION() TArray<FName> L_Substates() const { return Substates; }
	
	UFUNCTION(BlueprintCallable,Category="System State",DisplayName="Set Widget State (Name)") void SetSubstate_Name(UPARAM(meta=(GetOptions="L_Substates")) FName State);
	UFUNCTION(BlueprintCallable,Category="System State",DisplayName="Set Widget State (index)") void SetSubstate_Index(int32 State);
	UFUNCTION(BlueprintPure,Category="System State",DisplayName="Get Widget State (index)") int32 GetSubstate_Index() const { return Substate; };
	UFUNCTION(BlueprintPure,Category="System State",DisplayName="Get Widget State (Name from index)") FName GetSubstate_NameFromIndex(int32 index) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="System State") void OnSubstateChange(int32 NewState,FName NewState_N,int32 OldState,FName OldState_N);
	
	//----------------------------------------------------------------------
	// Input
	//----------------------------------------------------------------------

	
	virtual bool InputAction_Disabled_Implementation(APlayerController* Player, FGameplayTag Action) override
	{
		return !IsRendered();
	};

	UFUNCTION(BlueprintImplementableEvent,Category="ScreenWidget") UTextBlock* GetWidget_Text_ContextName();
	UFUNCTION(BlueprintImplementableEvent,Category="ScreenWidget") UTextBlock* GetWidget_Text_ContextDescription();
	UFUNCTION(BlueprintImplementableEvent,Category="ScreenWidget") UImage* GetWidget_Image_ContextIcon();

	UFUNCTION(BlueprintImplementableEvent,Category="ScreenWidget") TArray<UDataList*> GetDataLists_LinkedToPlayerPawn();
	UFUNCTION(BlueprintImplementableEvent,Category="ScreenWidget") TArray<UDataWidget*> GetDataWidgets_LinkedToPlayerPawn();
};
