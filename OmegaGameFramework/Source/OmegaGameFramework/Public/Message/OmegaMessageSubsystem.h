// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataInterface_General.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EngineUtils.h"
#include "GameplayTagContainer.h"
#include "OmegaMessageSubsystem.generated.h"

USTRUCT(BlueprintType, Atomic)
struct FOmegaGameplayMessageData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Message", instanced, EditAnywhere)
	UOmegaGameplayMessage* Message;

	UPROPERTY()
	FText MessageLog_Text;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGameplayMessage, UOmegaGameplayMessage*, Message, FGameplayTag, MessageCategory);

UCLASS(DisplayName="Omega Subsystem: Message")
class OMEGAGAMEFRAMEWORK_API UOmegaMessageSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	//virtual void Initialize(FSubsystemCollectionBase& Colection) override;

	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay Message")
	void FireGameplayMessage(FOmegaGameplayMessageData Message);

	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay Message")
	void FireCustomGameplayMessage(UObject* Instigator, FText Text, FGameplayTag MessageCategory);
	
	UPROPERTY(BlueprintAssignable)
	FOnGameplayMessage OnGameplayMessage;
	
	UPROPERTY()
	TArray<FOmegaGameplayMessageData> MessageLog;

};

//##################################################################################
/// Gameplay Message Object
//##################################################################################

UCLASS(Blueprintable, EditInlineNew, CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayMessage : public UObject, public IDataInterface_General
{
	GENERATED_BODY()

public:
	
	UPROPERTY()
	UObject* Temp_Instigator = nullptr;
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Omega|Gameplay Message")
	UObject* GetMessageInstigator();

	UPROPERTY()
	FText Temp_Text;
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Omega|Gameplay Message")
	FText GetMessageText();

	UPROPERTY()
	FGameplayTag Temp_Tag;
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Omega|Gameplay Message")
	FGameplayTag GetMessageCategory();

	UPROPERTY()
	FGameplayTagContainer Temp_Tags;
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Omega|Gameplay Message")
	FGameplayTagContainer GetMessageTags();
	
};