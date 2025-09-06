// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Subsystems/OmegaSubsystem_DynamicCamera.h"
#include "Actor_AutoMenu.generated.h"

class UMenu;


UCLASS()
class OMEGADEMO_API AOmegaAutoMenu : public AOmegaDynamicCamera
{
	GENERATED_BODY()

	UPROPERTY() UMenu* REF_Menu;

	UFUNCTION()
	void Native_OnMenuClosed(FGameplayTagContainer GameplayTags, UObject* Context, FString Flag);

	UFUNCTION() void L_OpenMenu();
	
public:
	AOmegaAutoMenu();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AutoMenu")
	TSubclassOf<UMenu> Menu;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AutoMenu")
	UPrimaryDataAsset* MenuContext;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AutoMenu")
	FGameplayTagContainer MenuTags;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AutoMenu")
	FString MenuFlag;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AutoMenu")
	TSoftObjectPtr<UWorld> LevelOpenOnClose;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AutoMenu")
	TMap<FString,TSoftObjectPtr<UWorld>> LevelOpenOnCloseFlag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AutoMenu")
	FGameplayTag LevelTransitSpawnID;
};
