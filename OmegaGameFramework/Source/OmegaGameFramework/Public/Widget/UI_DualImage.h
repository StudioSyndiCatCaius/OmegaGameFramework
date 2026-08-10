// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Blueprint/UserWidget.h"
#include "UI_DualImage.generated.h"

class UImage;
class UOmegaSubsystem_Player;
/**
 *
 */
UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaDualImageWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite,Category="Image",meta=(BindWidget)) TObjectPtr<UImage> Image_Front;
	UPROPERTY(BlueprintReadWrite,Category="Image",meta=(BindWidget)) TObjectPtr<UImage> Image_Back;

	UPROPERTY(EditAnywhere,Category="Image",meta=(Categories="IMAGE"))
	FGameplayTag GlobalImageTag;
	UPROPERTY(EditAnywhere,Category="Image") FSlateBrush Image;
	UPROPERTY(EditAnywhere,Category="Image") float ImageCrossfadeDuration=0.3;
	/*
	 * TRUE = On image change, back and front will fade at the same time
	 * FALSE = On image change, push image to back, then fade in front and THEN fade out back
	 */
	UPROPERTY(EditAnywhere,Category="Image") bool ParallelFade=false;

	UFUNCTION(BlueprintCallable,Category="Image") void SetImage(FSlateBrush NewImage);

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
	UFUNCTION() void OnGlobalImageChanged(APlayerController* Player, FGameplayTag Tag, FSlateBrush NewImage);
	UFUNCTION() void OnGlobalImageRemoved(APlayerController* Player, FGameplayTag Tag, FSlateBrush NewImage);

	void Refresh();
	
	UOmegaSubsystem_Player* GetPlayerSubsystem() const;

	// 0=idle | 1=fading in front | 2=fading out back
	uint8 fade_phase=0;
	float fade_time=0;
	float fade_backStartOpacity=1;
};