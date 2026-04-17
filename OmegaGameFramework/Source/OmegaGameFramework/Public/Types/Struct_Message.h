
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Struct_Bitflag.h"
#include "Interfaces/I_Common.h"
#include "Misc/OmegaUtils_Structs.h"

#include "Struct_Message.generated.h"

class UOmegaSubsystem_World;

USTRUCT(BlueprintType, Atomic)
struct FOmegaGameplayMessageMeta
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category="Message", EditAnywhere) FName key;
	UPROPERTY(BlueprintReadWrite, Category="Message", EditAnywhere) FGameplayTagContainer Tags;
	UPROPERTY(BlueprintReadWrite, Category="Message", EditAnywhere) FSlateBrush Brush;
	UPROPERTY(BlueprintReadWrite, Category="Message", EditAnywhere,DisplayName="Bitflags") FOmegaBitflagsBase Flags;
	//UPROPERTY(BlueprintReadWrite,Instanced,Category="Message", EditAnywhere) TArray<UOmegaObjectTrait*> Traits;
	UPROPERTY(BlueprintReadWrite, Category="Message", EditAnywhere) FOmegaCommonMeta CommonMeta;
	
};



// ===================================================================================================================
// INTERFACES
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


//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOmegaGameplayMessageDelegate,UOmegaGameplayMessage*,Message);

UCLASS(Blueprintable, EditInlineNew, CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayMessage : public UObject, public IDataInterface_General
{
	GENERATED_BODY()

public:
	UPROPERTY() UOmegaSubsystem_World* subsytem_ref;
	
	UPROPERTY() UObject* Temp_Instigator = nullptr;
	UPROPERTY(BlueprintReadWrite,Category="Message")
	FOmegaGameplayMessageMeta meta;
	
	UFUNCTION(BlueprintPure, Category="Omega|Gameplay Message")
	UObject* GetMessageInstigator() const { return Temp_Instigator;};
	
	UPROPERTY() FText Temp_Text;
	UFUNCTION(BlueprintPure, Category="Omega|Gameplay Message")
	FText GetMessageText() const { return Temp_Text;} 
	
	UFUNCTION(BlueprintPure, Category="Omega|Gameplay Message",meta=(WorldContext="WorldContext"))
	FSlateBrush GetMessagePortrait(UObject* WorldContext) const; 
	
	UPROPERTY() FGameplayTag Temp_Tag;
	
	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override { return Temp_Tag; };
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override { return meta.Tags;};
	
	//UFUNCTION(BlueprintCallable,Category="Message") void Send();
	UFUNCTION(BlueprintCallable,Category="Message") bool End();
	
};

