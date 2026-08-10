// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Types/Struct_Material.h"
#include "Types/Struct_Message.h"
#include "Blueprint/UserWidget.h"
#include "UI_MessageSpeaker.generated.h"

class UImage;
class UMaterialInterface;
class UTexture2D;
class UOmegaGameplayMessage;
class UOAsset_TransformPreset;
class UPrimaryDataAsset;
/**
 *
 */
UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UUI_MessageSpeaker : public UUserWidget
{
	GENERATED_BODY()
public:
	UUI_MessageSpeaker(const FObjectInitializer& ObjectInitializer);

	UPROPERTY() UOmegaGameplayMessage* _LastMessage;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Speaker") UPrimaryDataAsset* SpeakerInstigator;
	//if received message meta position matches this one, then assign and appear this speaker.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Speaker") bool bAutosetSpeakByPosition=true;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Speaker") UOAsset_TransformPreset* position;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Speaker") FGameplayTag MessageCategoryFilter;

	UPROPERTY(BlueprintReadWrite,Category="Portrait",meta=(BindWidget)) TObjectPtr<UImage> Portrait_Front;
	UPROPERTY(BlueprintReadWrite,Category="Portrait",meta=(BindWidget)) TObjectPtr<UImage> Portrait_Back;
	UPROPERTY(EditAnywhere,Category="Portrait") float ImageCrossfadeDuration=0.3;
	/*
	 * TRUE = On image change, back and front will fade at the same time
	 * FALSE = On image change, push image to back, then fade in front and THEN fade out back
	 */
	UPROPERTY(EditAnywhere,Category="Portrait") bool ParallelFade=false;
	//time to fade the whole widget in/out when Portrait_SetVisible is used
	UPROPERTY(EditAnywhere,Category="Portrait") float VisibilityFadeDuration=0.2;
	UFUNCTION(BlueprintCallable,Category="Portrait") void Portrait_SetVisible(bool bIsVisible);

	UFUNCTION(BlueprintCallable,Category="Portrait") void Portrait_SetImage(FSlateBrush NewImage,FOmegaDynamicMaterialParams params);

	UFUNCTION(BlueprintCallable,Category="Portrait") void Portrait_SetImage_Material(UMaterialInterface* NewImage);

	UFUNCTION(BlueprintCallable,Category="Portrait") void Portrait_SetImage_Texture(UTexture2D* NewImage);

	/*
	 * if different from current, update the speaker, fading out the old one, using their default portrait from the MessagInstigator Intarface config.
	 * A speaker can only occupy one position: any other widget holding this speaker is cleared.
	 * bUseDefaultPortrait=false skips the default portrait crossfade, for callers that set their own portrait right after.
	 */
	UFUNCTION(BlueprintCallable,Category="Speaker",meta=(AdvancedDisplay="bUseDefaultPortrait")) void Speaker_Set(UPrimaryDataAsset* Speaker,bool bMakeVisible,bool bUseDefaultPortrait=true);

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
	UFUNCTION() void L_OnMessageBegin(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta meta);
	UFUNCTION() void L_OnMessageEnd(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta meta);

	//default portrait from the speaker's MessageInstigator interface config
	FSlateBrush L_GetSpeakerDefaultPortrait() const;

	// 0=idle | 1=fading in front | 2=fading out back
	uint8 fade_phase=0;
	float fade_time=0;
	float fade_backStartOpacity=1;
	//target render opacity for the whole widget, driven by Portrait_SetVisible
	float vis_target=1;
};
