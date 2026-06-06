// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaActors.h"
#include "Components/Component_GameplayActor.h"
#include "DataAssets/DA_Appearance.h"
#include "GameFramework/Character.h"
#include "Types/Struct_ActorRelatives.h"
#include "Actor_Character.generated.h"

class UComponent_DebugText;
class UBoxComponent;
class UStateTreeComponent;
class UAnimInstance;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaCharacterConfig : public UOmegaActorConfig
{
	GENERATED_BODY()
public:
	
};


UINTERFACE(MinimalAPI, DisplayName="♎Data🔴 - 🗿Character",BlueprintType) class UDataInterface_Character : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_Character
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent,Category="♎I|🗿Character",DisplayName="Character - On Construct")
	int32 Character_Construct(AOmegaMinimalCharacter* Actor);
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🗿Character",DisplayName="Character - On BeginPlay")
	int32 Character_BeginPlay(AOmegaMinimalCharacter* Actor);
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🗿Character",DisplayName="Character - On Init")
	int32 Character_Init(AOmegaMinimalCharacter* Actor);

};



UCLASS(HideCategories=("Skeletal Mesh, Physics"))
class OMEGAGAMEFRAMEWORK_API AOmegaMinimalCharacter : public AOmegaBaseCharacter, public IDataInterface_Traits,	public IDataInterface_AppearanceSource,
																	public IDataInterface_AssetLibraries, public IDataInterface_General, public IActorInterface_Relatives,
																	public IDataInterface_VoiceSource
{
	GENERATED_BODY()
	UPROPERTY() UOAsset_Appearance* cached_appearance;
	virtual void N_OnCharAssetChange(UPrimaryDataAsset* old_asset, UPrimaryDataAsset* new_asset);
	void RebuildAppearance();
	
	void L_Log(FString logString);
	
public:
	virtual TSubclassOf<UAnimInstance> GetContext_AnimClass();
	
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	
	AOmegaMinimalCharacter();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="OmegaCharacter") TScriptInterface<IDataInterface_Character> Preset;
	UFUNCTION(BlueprintCallable,Category="OmegaCharacter") void SetCharacterPreset(TScriptInterface<IDataInterface_Character> _preset);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (ShowOnlyInnerProperties),Category="Gameplay") UGameplayActorComponent* ActorIdentity;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UStateTreeComponent* StateTree;
	UPROPERTY() UComponent_DebugText* DebugText;
	
	UFUNCTION(BlueprintCallable,CallInEditor,Category="OmegaCharacter")
	void RandomizeSeed();


	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="OmegaCharacter") FOmegaClassNamedLists NamedLists;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="OmegaCharacter") FOmegaActorRelatives ActorRelatives;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="OmegaCharacter")
	int32 Seed=-1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="OmegaCharacter")
	FOmegaBitflagsBase Flags;
	
	UFUNCTION(BlueprintCallable, Category="OmegaCharacter") void SetCharacterAppearance(UOAsset_Appearance* Appearance);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="OmegaCharacter")
	TSoftObjectPtr<UOAsset_Appearance> AppearanceOverride;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="OmegaCharacter",AdvancedDisplay)
	UOmegaAssetLibrary_Animation* Library_Animation;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="OmegaCharacter",AdvancedDisplay)
	UOmegaAssetLibrary_Sound* Library_Sound;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="OmegaCharacter",AdvancedDisplay)
	UOmegaAssetLibrary_SlateBrush* Library_Slate;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,AdvancedDisplay, Category="OmegaCharacter")
	UOmegaCharacterConfig* Config;

	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig) override;
	virtual void GetObjectGameplayTags_Implementation(FGameplayTag& OutCategoryTag, FGameplayTagContainer& OutGameplayTags) override;
	virtual void GetMetaConfig_Implementation(FOmegaBitflagsBase& bitflags, FGuid& guid, int32& seed, FOmegaClassNamedLists& named_lists);
	virtual FOmegaActorRelatives ActorRelatives_Get_Implementation() override { return ActorRelatives; };
	virtual UOAsset_Appearance* GetAppearanceAsset_Implementation() override;
	virtual void GetAppearanceLibraries_Implementation(UOmegaAssetLibrary_Animation*& Anim, UOmegaAssetLibrary_Sound*& Sound, UOmegaAssetLibrary_SlateBrush*& Slate) override;
	virtual FString VoiceSource_GetID_Implementation() override;
};


UCLASS()
class AOmegaRagdoll : public AOmegaBaseCharacter
{
	GENERATED_BODY()

public:
	
};
