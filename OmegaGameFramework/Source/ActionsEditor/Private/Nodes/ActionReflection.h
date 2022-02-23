// Copyright Studio Syndicat 2021. All Rights Reserved. 

#pragma once
#include <CoreMinimal.h>
#include <UObject/Class.h>

#include "ActionReflection.generated.h"


USTRUCT()
struct FBaseActionProperty
{
    GENERATED_BODY()

protected:

    UPROPERTY()
    TFieldPath<FProperty> Property;

    UPROPERTY()
    FName Name;

    UPROPERTY()
    FEdGraphPinType Type;

public:

    FBaseActionProperty() {}

    FName GetFName() const { return Name; }
    const FEdGraphPinType& GetType() const { return Type; }
    FProperty* GetProperty() const { return Property.Get(); }

    bool IsValid() const { return Property != nullptr; }

    bool operator==(const FBaseActionProperty& Other) const
    {
        return Name == Other.Name && Type == Other.Type;
    }
    bool operator!=(const FBaseActionProperty& Other) const { return !operator==(Other); }

    friend int32 GetTypeHash(const FBaseActionProperty& Item)
    {
        return GetTypeHash(Item.GetFName());
    }

protected:

    FBaseActionProperty(FProperty* Property)
        : Property(Property)
    {
        RefreshProperty();
    }

private:

    void RefreshProperty();
};


USTRUCT()
struct FDelegateActionProperty : public FBaseActionProperty
{
    GENERATED_BODY()

    FDelegateActionProperty(FMulticastDelegateProperty* Property = nullptr)
        : FBaseActionProperty(Property)
    {}

    FMulticastDelegateProperty* GetDelegate() const
    {
        return CastFieldChecked<FMulticastDelegateProperty>(Property.Get());
    }

    UFunction* GetFunction() const
    {
        return GetDelegate()->SignatureFunction;
    }

    bool HasParams() const
    {
        auto* Function = GetFunction();
        return Function? Function->NumParms > 0 : false;
    }
};


USTRUCT()
struct FVariableActionProperty : public FBaseActionProperty
{
    GENERATED_BODY()

    FVariableActionProperty(FProperty* Property = nullptr)
        : FBaseActionProperty(Property)
    {}
};


USTRUCT()
struct FActionProperties
{
    GENERATED_BODY()

    UPROPERTY()
    TSet<FVariableActionProperty> Variables;

    UPROPERTY()
    TSet<FDelegateActionProperty> SimpleDelegates;

    UPROPERTY()
    TSet<FDelegateActionProperty> ComplexDelegates;


    bool operator==(const FActionProperties& Other) const;
    bool operator!=(const FActionProperties& Other) const { return !operator==(Other); }

private:

    template<typename T>
    bool Equals(const TSet<T>& One, const TSet<T>& Other) const
    {
        for(const T& Value : One)
        {
            const T* const OtherValue = Other.Find(Value);
            if (!OtherValue || *OtherValue != Value)
            {
                // Element not found or not equal
                return false;
            }
        }
        return true;
    }
};


namespace ActionReflection
{
    bool GetVisibleProperties(UClass* Class, FActionProperties& OutProperties);
};
