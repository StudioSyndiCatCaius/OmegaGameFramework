// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/Menu.h"
#include "OmegaDemo_Menus.generated.h"

class UOmegaSaveSubsystem;
class UOmegaSaveGame;

UCLASS(Abstract)
class OMEGADEMO_API UMenuBase_Title : public UMenu
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent,Category="Menu") UImage* GetWidget_Image_Logo();
	UFUNCTION(BlueprintImplementableEvent,Category="Menu") UTextBlock* GetWidget_Text_Legal();

};


UCLASS(Abstract)
class OMEGADEMO_API UMenuBase_SaveLoad : public UMenu
{
	GENERATED_BODY()
	
	bool b_isloadMenu=false;

	void L_SetSavePathCategory(int32 cat);
	TArray<UOmegaSaveGame*> L_GetSaveList(int32 cat);

	UPROPERTY() UOmegaSaveSubsystem* l_subsys;

	UFUNCTION() void L_OnSelectSlot(UDataWidget* dw, FString lbl, UObject* asset, int32 ind);

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MENU") int32 SaveCount=20;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MENU") bool RetainSaveCountSize=false;
	
	virtual void MenuOpened_Implementation(FGameplayTagContainer Tags, UObject* Context, const FString& Flag) override;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Menu") FString GetSavesPath_ByCategory(int32 save_category);
	
	UFUNCTION(BlueprintImplementableEvent,Category="Menu") UDataList* GetDataList_SaveSlots();
	UFUNCTION(BlueprintImplementableEvent,Category="Menu") UDataList* GetDataList_SavePaths(int32 save_category);
	
	UFUNCTION(BlueprintImplementableEvent,Category="Menu") UWidgetSwitcher* GetWidget_Switcher_SavePaths();


};
