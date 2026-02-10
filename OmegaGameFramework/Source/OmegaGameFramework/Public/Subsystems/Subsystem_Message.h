// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/I_Common.h"
#include "Interfaces/I_BitFlag.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Functions/F_ObjectTraits.h"
#include "GameplayTagContainer.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Subsystem_Message.generated.h"

class UOAsset_TransformPreset;

USTRUCT(BlueprintType, Atomic)
struct FOmegaGameplayMessageData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category="Message", instanced, EditAnywhere)
	UOmegaGameplayMessage* Message=nullptr;
	
	UPROPERTY()
	FText MessageLog_Text;
};

USTRUCT(BlueprintType, Atomic)
struct FOmegaGameplayMessageMeta
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category="Message", EditAnywhere) FName key;
	UPROPERTY(BlueprintReadWrite, Category="Message", EditAnywhere) FGameplayTagContainer Tags;
	UPROPERTY(BlueprintReadWrite, Category="Message", EditAnywhere) FSlateBrush Brush;
	UPROPERTY(BlueprintReadWrite, Category="Message", EditAnywhere,DisplayName="Bitflags") FOmegaBitflagsBase Flags;
	UPROPERTY(BlueprintReadWrite,Instanced,Category="Message", EditAnywhere) TArray<UOmegaObjectTrait*> Traits;
	UPROPERTY(BlueprintReadWrite, Category="Message", EditAnywhere) FOmegaCommonMeta CommonMeta;
	
};

// ===================================================================================================================
// Instigator
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UDataInterface_MessageInstigator : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_MessageInstigator
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Gameplay|Message")
	FSlateBrush GetMessageBrush(UOmegaGameplayMessage* Message);
};

UINTERFACE(MinimalAPI) class UDataInterface_MessageContext : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_MessageContext
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Gameplay|Message")
	UOAsset_TransformPreset* GetMessage_TransformPreset();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Gameplay|Message")
	USoundBase* GetMessage_SoundClip();
};



DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnGameplayMessage, UOmegaGameplayMessage*, Message, FGameplayTag, MessageCategory, FOmegaGameplayMessageMeta, meta);

UCLASS(DisplayName="Omega Subsystem: Message")
class OMEGAGAMEFRAMEWORK_API UOmegaMessageSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay Message")
	void FireGameplayMessage(FOmegaGameplayMessageData Message);

	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay Message",meta=(AdvancedDisplay="Tags,meta, Brush,Context"))
	FOmegaGameplayMessageData FireCustomGameplayMessage(UObject* Instigator, FText Text, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta meta);
	
	UPROPERTY(BlueprintAssignable) FOnGameplayMessage OnGameplayMessage;
	
	UPROPERTY()
	TArray<FOmegaGameplayMessageData> MessageLog;

};

//##################################################################################
/// Gameplay Message Object
//##################################################################################

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaMessageTrait : public UOmegaObjectTrait
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent,Category="Message")
	bool OnMessageFired(UOmegaMessageSubsystem* subsystem, UOmegaGameplayMessage* message) const;
};



UCLASS(Blueprintable, EditInlineNew, CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayMessage : public UObject, public IDataInterface_General, public IGameplayTagsInterface, public IDataInterface_Traits
{
	GENERATED_BODY()

public:
	
	UPROPERTY() UObject* Temp_Instigator = nullptr;
	UPROPERTY(BlueprintReadWrite,Category="Message")
	FOmegaGameplayMessageMeta meta;
	virtual TArray<UOmegaObjectTrait*> GetTraits_Implementation() override { return meta.Traits;};
	
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Omega|Gameplay Message")
	UObject* GetMessageInstigator();

	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay Message",meta=(DeterminesOutputType="Class",ExpandBoolAsExecs="result"))
	UObject* TryGetMessageInstigator(TSubclassOf<UObject> Class, bool& result);
	
	UPROPERTY() FText Temp_Text;
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Omega|Gameplay Message")
	FText GetMessageText();
	
	UPROPERTY() FGameplayTag Temp_Tag;
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Omega|Gameplay Message")
	FGameplayTag GetMessageCategory();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Omega|Gameplay Message")
	FGameplayTagContainer GetMessageTags();
	
};