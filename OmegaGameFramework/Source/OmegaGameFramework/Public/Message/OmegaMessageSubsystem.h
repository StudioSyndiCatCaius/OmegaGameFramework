// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataInterface_General.h"
#include "Subsystems/WorldSubsystem.h"
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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameplayMessage, UOmegaGameplayMessage*, Message);

UCLASS(DisplayName="Omega Subsystem: Message")
class OMEGAGAMEFRAMEWORK_API UOmegaMessageSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	//virtual void Initialize(FSubsystemCollectionBase& Colection) override;

	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay Message")
	void FireGameplayMessage(FOmegaGameplayMessageData Message);

	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay Message")
	void FireCustomGameplayMessage(FText Text, FGameplayTag MessageCategory);
	
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
	
};