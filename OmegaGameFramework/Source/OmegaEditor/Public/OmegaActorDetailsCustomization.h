// OmegaActorDetailsCustomization.h
#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"
#include "Types/OmegaActorInstanceMetadata.h"

/**
 * Minimal actor customization that ONLY ADDS the metadata category.
 * Does NOT touch, hide, or modify any default properties like Transform.
 * Fails gracefully if anything goes wrong.
 */
class FOmegaActorDetailsCustomization : public IDetailCustomization
{
public:
    static TSharedRef<IDetailCustomization> MakeInstance();

    virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

private:
    TWeakObjectPtr<AActor> SelectedActor;

    // Setup the metadata UI
    void SetupMetadataCategory(class IDetailLayoutBuilder& DetailBuilder);
    
    // Callbacks for getting/setting metadata
    FOmegaActorInstanceMetadata GetMetadata() const;
    void SetMetadata(const FOmegaActorInstanceMetadata& NewMetadata);

    // Add type separator
    void AddTypeSeparator(class IDetailCategoryBuilder& Category, const FString& TypeName);

    // Create property widgets for each type
    void CreateBoolProperty(class IDetailCategoryBuilder& Category, FName ParamName);
    void CreateIntProperty(class IDetailCategoryBuilder& Category, FName ParamName);
    void CreateFloatProperty(class IDetailCategoryBuilder& Category, FName ParamName);
    void CreateStringProperty(class IDetailCategoryBuilder& Category, FName ParamName);
    void CreateDataAssetProperty(class IDetailCategoryBuilder& Category, FName ParamName);
    void CreateActorProperty(class IDetailCategoryBuilder& Category, FName ParamName);

    // Getters and setters for each type
    TOptional<bool> GetBoolValue(FName ParamName) const;
    void SetBoolValue(bool NewValue, FName ParamName);

    TOptional<int32> GetIntValue(FName ParamName) const;
    void SetIntValue(int32 NewValue, FName ParamName);

    TOptional<float> GetFloatValue(FName ParamName) const;
    void SetFloatValue(float NewValue, FName ParamName);

    FText GetStringValue(FName ParamName) const;
    void SetStringValue(const FText& NewValue, FName ParamName);

    UObject* GetDataAssetValue(FName ParamName) const;
    void SetDataAssetValue(const FAssetData& AssetData, FName ParamName);

    UObject* GetActorValue(FName ParamName) const;
    void SetActorValue(const FAssetData& AssetData, FName ParamName);
};