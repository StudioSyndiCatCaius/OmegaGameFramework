// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaFunctions_Animation.generated.h"

UINTERFACE(MinimalAPI)
class UDataInterface_Animation : public UInterface { GENERATED_BODY() };

class OMEGAGAMEFRAMEWORK_API IDataInterface_Animation
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Omega|Animation")
	UAnimSequence* GetAnimationSequence_FromTag(FGameplayTag Tag);
	UFUNCTION(BlueprintImplementableEvent, Category = "Omega|Animation")
	UAnimMontage* GetAnimationMontage_FromTag(FGameplayTag Tag);

};


UCLASS(Blueprintable,BlueprintType,Const,EditInlineNew,Abstract,CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaAnimationEmoteScript : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent,Category="Emote")
	UAnimMontage* GetEmoteMontage(ACharacter* Character) const;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaAnimationEmote : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="General",DisplayName="Name") FText DisplayName;
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="General",DisplayName="Icon") FSlateBrush DisplayIcon;
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="General",DisplayName="Description",meta=(MultiLine)) FText DisplayDescription;
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="General",DisplayName="Label") FString DisplayLabel;
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="General",DisplayName="Category") FGameplayTag CategoryTag;
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="General",DisplayName="Tags") FGameplayTagContainer GameplayTags;
	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Animation")
	UOmegaAnimationEmoteScript* Script;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaAnimationFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure,Category="Omega|Animation")
	static UAnimSequence* GetObjectAnimation_Sequence_FromTag(UObject* Object, FGameplayTag Tag);
	
	UFUNCTION(BlueprintPure,Category="Omega|Animation")
	static UAnimMontage* GetObjectAnimation_Montage_FromTag(UObject* Object, FGameplayTag Tag);

	UFUNCTION(BlueprintCallable,Category="Omega|Animation")
	static void PlayEmoteAnimation(ACharacter* Character, UOmegaAnimationEmote* Emote);
};
