// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "I_ActorPreset.generated.h"

class UArrowComponent;
class UTextRenderComponent;
class UBoxComponent;

UINTERFACE(DisplayName="♎Editor💻 - ⚙️Actor Preset")
class OMEGAGAMEFRAMEWORK_API UDataInterface_ActorPreset : public UInterface { GENERATED_BODY() };


class OMEGAGAMEFRAMEWORK_API IDataInterface_ActorPreset
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintNativeEvent,Category="♎I|⚙️ActorPreset",DisplayName="⚙️Actor Preset - Get Config")
	void ActorPreset_GetConfig(TSubclassOf<AActor>& ActorClass, bool& bPreviewActor, bool& bAllowWorldDrop,bool& bPreviewThumbnailFromActor);

	UFUNCTION(BlueprintNativeEvent,Category="♎I|⚙️ActorPreset",DisplayName="⚙️Actor Preset - Preview")
	bool ActorPreset_PreviewConstruct(AActor* Actor);
};

