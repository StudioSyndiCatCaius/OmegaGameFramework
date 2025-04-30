// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/Menu.h"
#include "OmegaDemo_Menus.generated.h"

UCLASS(Abstract)
class OMEGADEMO_API UMenu_Title : public UMenu
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent,Category="Menu") UImage* GetWidget_Image_Logo();
	UFUNCTION(BlueprintImplementableEvent,Category="Menu") UTextBlock* GetWidget_Text_Legal();

};
