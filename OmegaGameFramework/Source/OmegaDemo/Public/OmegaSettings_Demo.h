// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaSettings_Demo.generated.h"

class AOmegaToolActor;
class UMenu;
class AOmegaGameplaySystem;
/**
 * 
 */
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Omega: DEMO"))
class OMEGADEMO_API UOmegaSettings_Demo : public UDeveloperSettings
{
	GENERATED_UCLASS_BODY()

public:
	
	UPROPERTY(EditAnywhere, Config, Category="Systems") TSoftClassPtr<AOmegaGameplaySystem> System_DialogueFlow;
	UPROPERTY(EditAnywhere, Config, Category="Systems") TSoftClassPtr<AOmegaGameplaySystem> System_Encounter;
	
	UPROPERTY(EditAnywhere, Config, Category="Menu") TSoftClassPtr<UMenu> Menu_Confirmation;
	UPROPERTY(EditAnywhere, Config, Category="Menu") TSoftClassPtr<UMenu> Menu_Info;
	UPROPERTY(EditAnywhere, Config, Category="Menu") TSoftClassPtr<UMenu> Menu_Choice;
	UPROPERTY(EditAnywhere, Config, Category="Actors") TSoftClassPtr<AOmegaToolActor> Default_ToolActor;
};

UCLASS()
class OMEGADEMO_API UOmegaFunctions_DEMO : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintPure,Category="Omega DEMO")
	static void GetOmegaDemo_Systems(TSubclassOf<AOmegaGameplaySystem>& DialogFlow,TSubclassOf<AOmegaGameplaySystem>& Encounter);
	UFUNCTION(BlueprintPure,Category="Omega DEMO")
	static void GetOmegaDemo_Menus(TSubclassOf<UMenu>& Confirm,TSubclassOf<UMenu>& Info,TSubclassOf<UMenu>& Choice);
};
