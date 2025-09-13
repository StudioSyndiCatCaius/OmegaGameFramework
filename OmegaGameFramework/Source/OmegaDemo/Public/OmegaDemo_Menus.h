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

	virtual UWidgetSwitcher* GetWidget_WidgetSwitcher_State_Implementation() override;

public:
	virtual void NativePreConstruct() override;
	
	//UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Title Menu") FVector2D LogoSize=FVector2D(400,400);

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu",meta=(BindWidget)) UImage* IMG_Logo;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu",meta=(BindWidget)) UDataList* List_RootOptions;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu",meta=(BindWidget)) UWidgetSwitcher* Switcher_SplashState;
	
	
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
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu", meta=(BindWidget))
	UDataList* List_SaveSlots;
	
	virtual void MenuOpened_Implementation(FGameplayTagContainer Tags, UObject* Context, const FString& Flag) override;
	UFUNCTION(BlueprintImplementableEvent,Category="Menu") FString GetSavesPath_ByCategory(int32 save_category);

	UFUNCTION(BlueprintImplementableEvent,Category="Menu") UDataList* GetDataList_SavePaths(int32 save_category);
	
	UFUNCTION(BlueprintImplementableEvent,Category="Menu") UWidgetSwitcher* GetWidget_Switcher_SavePaths();
	
};

UCLASS(Abstract)
class OMEGADEMO_API UMenuBase_Equipment : public UMenu
{
	GENERATED_BODY()


public:

	
};
