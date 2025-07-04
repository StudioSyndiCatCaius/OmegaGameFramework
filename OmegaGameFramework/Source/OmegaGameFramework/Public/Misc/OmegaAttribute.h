// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "GameplayTagContainer.h"
#include "Curves/CurveFloat.h"
#include "Functions/OmegaFunctions_AVContext.h"
#include "OmegaAttribute.generated.h"

class UCombatantComponent;

USTRUCT(BlueprintType)
struct FOmegaAttributeModifier
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	UOmegaAttribute* Attribute = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	float Incrementer = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	float Multiplier = 0;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaAttribute : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface, public IDataInterface_ContextString
{
	GENERATED_BODY()

public:
	virtual FString GetDesc() override;

	//-----------------------------------------------------------------------------------
	// General
	//-----------------------------------------------------------------------------------

	UFUNCTION(BlueprintPure, Category = "Ω|Attributes")
	float GetAttributeValue(int32 Level, int32 AttributeRank, FGameplayTag ValueCategory);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "Name", Category = "General") FText AttributeName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "Description", Category = "General") FText AttributeDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "Label", Category = "General") FString AttributeLabel;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "Icon", Category = "General", DisplayName="Icon") FSlateBrush AttributeSlateIcon;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "Color", Category = "General") FLinearColor AttributeColor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "General") FLinearColor DamageColor;
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly, Category = "General") UOmegaAttributeScript* Script;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "Icon (Texture)", Category = "General", AdvancedDisplay) UTexture2D* AttributeIcon;

	//-----------------------------------------------------------------------------------
	// Values
	//-----------------------------------------------------------------------------------

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Value", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float StartValuePercentage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Value")
	float MaxValue;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Value")
	bool bIsValueStatic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Value")
	TArray<FRuntimeFloatCurve> RankValueCurves;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Value")
	TMap<FGameplayTag, float> ValueCategoryAdjustments;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Value")
	bool bAllowModifiers = true;

	int32 LocalFloor(float Number, int32 Decimals);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Value", AdvancedDisplay)
	int32 MaxDecimals = 2;
	
	//-----------------------------------------------------------------------------------
	// Tags
	//-----------------------------------------------------------------------------------

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tags")
	FGameplayTag AttributeCategory;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tags")
	FGameplayTagContainer AttributeTags;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
	FGameplayTag GetObjectGameplayCategory();
	virtual FGameplayTag GetObjectGameplayCategory_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
	FGameplayTagContainer GetObjectGameplayTags();
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation();

	//-----------------------------------------------------------------------------------
	// Widget
	//-----------------------------------------------------------------------------------
	
	UFUNCTION(BlueprintPure, Category="Attribute")
	FText GetAttributeValueDisplayText(float value);
	
	UPROPERTY(EditAnywhere, Category="Widget")
	TEnumAsByte<ERoundingMode> RoundingMode = ERoundingMode::HalfToEven;
	
	UPROPERTY(EditAnywhere, Category="Widget")
	bool bAlwaysSign;
	UPROPERTY(EditAnywhere, Category="Widget")
	bool bUseGrouping = true;
	
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MinIntegralDigits = 1;
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MaxIntegralDigits = 324;
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MinFractionalDigits;
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MaxFractionalDigits = 0;

	//-----------------------------------------------------------------------------------
	// Sub Attributes
	//-----------------------------------------------------------------------------------

	
//DataInterface
	
	virtual void GetGeneralDataText_Implementation(const FString& Label, const class UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const class UObject* Context, class UTexture2D*& Texture, class UMaterialInterface*& Material, FSlateBrush& Brush) override;
	virtual void GetGeneralAssetColor_Implementation(FLinearColor& Color) override;
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;
	
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Contex")
    	TMap<FGameplayTag,FText> Context_Text;
    
    	virtual FText GetContextAV_Text_Implementation(FGameplayTag ID) override
    	{
    		if(Context_Text.Contains(ID)) {return Context_Text[ID];} return FText();
    	}
};

UCLASS(EditInlineNew, Blueprintable, BlueprintType, Abstract, CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaAttributeScript : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent, Category="Attribute")
	float GetAttributeValue(int32 level,FGameplayTag ValueCategory);

	UFUNCTION(BlueprintImplementableEvent, Category="Attribute")
	FText GetDisplayText(float value);
	
};

// ==================================================================================================================
// Attribute Set
// ==================================================================================================================

UCLASS(BlueprintType, Blueprintable)
class OMEGAGAMEFRAMEWORK_API UOmegaAttributeSet : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	TArray<UOmegaAttributeSet*> InheritedSets;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	TArray<class UOmegaAttribute*> Attributes;

	UPROPERTY()
	FGameplayTag ValueCategory;

	UFUNCTION(BlueprintPure, Category="Attributes")
	TArray<UOmegaAttribute*> GetAllAttributes();
	UFUNCTION(BlueprintPure, Category="Attributes")
	TArray<UOmegaAttribute*> GetMetricAttributes();
	UFUNCTION(BlueprintPure, Category="Attributes")
	TArray<UOmegaAttribute*> GetStaticAttributes();
	
	UFUNCTION()
	TArray<UOmegaAttribute*> Local_GetAtt(bool bStatic);
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDataInterface_AttributeModifier : public UInterface
{
	GENERATED_BODY()
};

class OMEGAGAMEFRAMEWORK_API IDataInterface_AttributeModifier
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Attributes|Modifiers")
	TArray<FOmegaAttributeModifier> GetModifierValues(UCombatantComponent* CombatantComponent);
};

UCLASS(Blueprintable,BlueprintType,EditInlineNew,CollapseCategories,Const,Abstract)
class UOmegaScripted_AttributeModifier : public UObject, public IDataInterface_AttributeModifier
{
	GENERATED_BODY()

public:

	
};


USTRUCT(BlueprintType)
struct FOmegaScripted_AttributeModifiers
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="AttributeModifiers")
	TArray<UOmegaScripted_AttributeModifier*> Modifiers;

	TArray<FOmegaAttributeModifier> GatherModifiers(UCombatantComponent* CombatantComponent) const
	{
		TArray<FOmegaAttributeModifier> out;
		for(auto* i : Modifiers)
		{
			if(i)
			{
				out.Append(IDataInterface_AttributeModifier::Execute_GetModifierValues(i,CombatantComponent));
			}
		}
		return out;
	};
};



// ==================================================================================================================
// Modifier Container
// ==================================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API UAttributeModifierContainer : public UObject, public IDataInterface_AttributeModifier, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;

	UPROPERTY() UOmegaAttribute* Attribute;
	UPROPERTY() float IncValue;
	UPROPERTY() float MultiValue;
	UPROPERTY() FGameplayTag Category;
	UPROPERTY() FGameplayTagContainer Tags;
	

	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;
};
