// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "UserWidget_ActorDisplay.generated.h"



UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UActorUIDisplay_Widget : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY() AActor* REF_Actor = nullptr;
	void _destroyRefActor();

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UPROPERTY(EditAnywhere,Category="ActorRender")
	TSubclassOf<AActor> ActorClass;
	
	UFUNCTION(BlueprintImplementableEvent,Category="ActorRender")
	UImage* GetWidget_RenderImage() const;
	
};
