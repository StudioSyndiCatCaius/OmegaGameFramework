// OmegaPropertyHidingCustomization.h
#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"
#include "Types/OmegaActorInstanceMetadata.h"

class FOmegaPropertyHidingCustomization : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

private:
	void HidePropertiesAndCategories(IDetailLayoutBuilder& DetailBuilder, UObject* Object);
	
	// Actor metadata functionality - only called if object is an AActor
	void SetupActorMetadataCategory(class IDetailLayoutBuilder& DetailBuilder, AActor* Actor);
	
	FOmegaActorInstanceMetadata GetMetadata(AActor* Actor) const;
	void SetMetadata(AActor* Actor, const FOmegaActorInstanceMetadata& NewMetadata);
	
	void AddTypeSeparator(class IDetailCategoryBuilder& Category, const FString& TypeName);
	
	void CreateBoolProperty(class IDetailCategoryBuilder& Category, FName ParamName, AActor* Actor);
	void CreateIntProperty(class IDetailCategoryBuilder& Category, FName ParamName, AActor* Actor);
	void CreateFloatProperty(class IDetailCategoryBuilder& Category, FName ParamName, AActor* Actor);
	void CreateStringProperty(class IDetailCategoryBuilder& Category, FName ParamName, AActor* Actor);
	void CreateDataAssetProperty(class IDetailCategoryBuilder& Category, FName ParamName, AActor* Actor);
	void CreateActorProperty(class IDetailCategoryBuilder& Category, FName ParamName, AActor* Actor);
	
	TOptional<bool> GetBoolValue(AActor* Actor, FName ParamName) const;
	void SetBoolValue(AActor* Actor, bool NewValue, FName ParamName);
	
	TOptional<int32> GetIntValue(AActor* Actor, FName ParamName) const;
	void SetIntValue(AActor* Actor, int32 NewValue, FName ParamName);
	
	TOptional<float> GetFloatValue(AActor* Actor, FName ParamName) const;
	void SetFloatValue(AActor* Actor, float NewValue, FName ParamName);
	
	FText GetStringValue(AActor* Actor, FName ParamName) const;
	void SetStringValue(AActor* Actor, const FText& NewValue, FName ParamName);
	
	UObject* GetDataAssetValue(AActor* Actor, FName ParamName) const;
	void SetDataAssetValue(AActor* Actor, const FAssetData& AssetData, FName ParamName);
	
	UObject* GetActorValue(AActor* Actor, FName ParamName) const;
	void SetActorValue(AActor* Actor, const FAssetData& AssetData, FName ParamName);
	
	TArray<TWeakObjectPtr<UObject>> SelectedObjects;
};
