// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/OmegaGameplaySystem.h"
#include "Components/Component_InstancedActor.h"
#include "sys_dialogue.generated.h"

class UInstanceActorComponent;

UCLASS(Abstract)
class OMEGADEMO_API AGameplaySystemBASE_Dialogue : public AOmegaGameplaySystem
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	AGameplaySystemBASE_Dialogue();
	
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="💬Dialogue")
	FGameplayTag MessageTag=FGameplayTag::RequestGameplayTag("Message.Dialog");
	
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category="Components") UAudioComponent* VoiceComponent;
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category="Components") USceneCaptureComponent2D* CaptureComponent;
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category="Components") UInstanceActorComponent* ImagesComponent;
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category="Components") UInstanceActorComponent* SpeakersComponent;

	UFUNCTION(BlueprintCallable, Category="Dialogue") bool Image_SetTexture(UTexture* Texture, int32 ImageIndex);
};


// ---------------------------------------------------------------------------------------------------------------------
// Actor Instances
// ---------------------------------------------------------------------------------------------------------------------

UCLASS()
class AInstanceActor_Image : public AOmegaInstanceActor
{
	GENERATED_BODY()
	
	UPROPERTY() UMaterialInstanceDynamic* DynaMat=nullptr;
	UMaterialInstanceDynamic* L_GetDynaMat();

public:
	
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category="Components") UStaticMeshComponent* Mesh;
	
	UFUNCTION(BlueprintCallable, Category="ImageActor") bool SetImageTexture(UTexture* Texture);
	
};

UCLASS()
class AInstanceActor_Speaker : public AOmegaInstanceActor
{
	GENERATED_BODY()

	UPROPERTY() UMaterialInstanceDynamic* DynaMat=nullptr;
	UMaterialInstanceDynamic* L_GetDynaMat();
	
public:
	
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category="Components") UStaticMeshComponent* Mesh;
};