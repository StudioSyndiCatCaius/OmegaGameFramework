// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EngineUtils.h"
#include "GameplayTagContainer.h"
#include "LuaInterface.h"
#include "OmegaSubsystem_Message.generated.h"

USTRUCT(BlueprintType, Atomic)
struct FOmegaGameplayMessageData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category="Message", instanced, EditAnywhere)
	UOmegaGameplayMessage* Message;

	UPROPERTY()
	FText MessageLog_Text;
};

// ===================================================================================================================
// Instigator
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UDataInterface_MessageInstigator : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_MessageInstigator
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Combatant")
	FSlateBrush GetMessageBrush(UOmegaGameplayMessage* Message);
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnGameplayMessage, UOmegaGameplayMessage*, Message, FGameplayTag, MessageCategory, FLuaValue, meta);

UCLASS(DisplayName="Omega Subsystem: Message")
class OMEGAGAMEFRAMEWORK_API UOmegaMessageSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay Message")
	void FireGameplayMessage(FOmegaGameplayMessageData Message);

	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay Message",meta=(AdvancedDisplay="meta, Brush"))
	void FireCustomGameplayMessage(UObject* Instigator, FText Text, FGameplayTag MessageCategory, FGameplayTagContainer Tags, FSlateBrush Brush, FLuaValue meta);
	
	UPROPERTY(BlueprintAssignable)
	FOnGameplayMessage OnGameplayMessage;
	
	UPROPERTY()
	TArray<FOmegaGameplayMessageData> MessageLog;

};

//##################################################################################
/// Gameplay Message Object
//##################################################################################

UCLASS(Blueprintable, EditInlineNew, CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayMessage : public UObject, public IDataInterface_General, public IGameplayTagsInterface, public ILuaInterface
{
	GENERATED_BODY()

public:
	
	UPROPERTY() UObject* Temp_Instigator = nullptr;
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Omega|Gameplay Message")
	UObject* GetMessageInstigator();

	UPROPERTY() FText Temp_Text;
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Omega|Gameplay Message")
	FText GetMessageText();

	UPROPERTY() FSlateBrush Temp_Brush;
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Omega|Gameplay Message")
	FSlateBrush GetMessageBrush();
	
	UPROPERTY() FGameplayTag Temp_Tag;
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Omega|Gameplay Message")
	FGameplayTag GetMessageCategory();

	UPROPERTY() FGameplayTagContainer Temp_Tags;
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Omega|Gameplay Message")
	FGameplayTagContainer GetMessageTags();

	UPROPERTY() FLuaValue lua_val;
	UPROPERTY() FLuaValue lua_key;
	virtual FLuaValue GetValue_Implementation(const FString& Field) override;
	virtual FLuaValue GetKey_Implementation() override;
	virtual void SetKey_Implementation(FLuaValue Key) override;
	virtual void SetValue_Implementation(FLuaValue Value, const FString& Field) override;
};