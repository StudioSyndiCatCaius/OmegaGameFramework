// Copyright Studio Syndicat 2022. All Rights Reserved.

#include "Functions/F_PropertyBag.h"
#include "UObject/Field.h"              // For CastField
#include "UObject/UnrealType.h"         // For FTextProperty, FProperty, etc.
// ─────────────────────────────────────────────────────────────────────────────
// Internal helpers
// ─────────────────────────────────────────────────────────────────────────────

/** Maps an FProperty type to the matching EPropertyBagPropertyType enum value.
 *  Also fills OutValueTypeObject for Enum/Object/Struct properties.
 *  Returns false if the type is not supported by PropertyBag. */
static bool GetBagTypeFromProperty(const FProperty* Prop,
                                   EPropertyBagPropertyType& OutType,
                                   UObject*& OutValueTypeObject)
{
	OutValueTypeObject = nullptr;

	if (CastField<FBoolProperty>(Prop))   { OutType = EPropertyBagPropertyType::Bool;   return true; }
	if (CastField<FIntProperty>(Prop))    { OutType = EPropertyBagPropertyType::Int32;  return true; }
	if (CastField<FInt64Property>(Prop))  { OutType = EPropertyBagPropertyType::Int64;  return true; }
	if (CastField<FFloatProperty>(Prop))  { OutType = EPropertyBagPropertyType::Float;  return true; }
	if (CastField<FDoubleProperty>(Prop)) { OutType = EPropertyBagPropertyType::Double; return true; }
	if (CastField<FNameProperty>(Prop))   { OutType = EPropertyBagPropertyType::Name;   return true; }
	if (CastField<FStrProperty>(Prop))    { OutType = EPropertyBagPropertyType::String; return true; }
	//if (CastField<FTextProperty>(Prop))   { OutType = EPropertyBagPropertyType::Text;   return true; }

	if (const FByteProperty* ByteProp = CastField<FByteProperty>(Prop))
	{
		if (ByteProp->Enum)
		{
			OutType = EPropertyBagPropertyType::Enum;
			OutValueTypeObject = ByteProp->Enum;
		}
		else
		{
			OutType = EPropertyBagPropertyType::Byte;
		}
		return true;
	}

	if (const FEnumProperty* EnumProp = CastField<FEnumProperty>(Prop))
	{
		OutType = EPropertyBagPropertyType::Enum;
		OutValueTypeObject = EnumProp->GetEnum();
		return true;
	}

	if (const FObjectPropertyBase* ObjProp = CastField<FObjectPropertyBase>(Prop))
	{
		OutType = EPropertyBagPropertyType::Object;
		OutValueTypeObject = ObjProp->PropertyClass;
		return true;
	}

	if (const FStructProperty* StructProp = CastField<FStructProperty>(Prop))
	{
		OutType = EPropertyBagPropertyType::Struct;
		OutValueTypeObject = StructProp->Struct;
		return true;
	}

	return false;
}

/** Ensure the named property exists in the bag with the matching type, then copy
 *  the value from SourcePtr (which belongs to SourceProp) into the bag. */
static void SetBagValueFromProperty(FInstancedPropertyBag& Bag, const FName Name,
                                    FProperty* SourceProp, const void* SourcePtr)
{
	EPropertyBagPropertyType BagType;
	UObject* TypeObject = nullptr;
	if (!GetBagTypeFromProperty(SourceProp, BagType, TypeObject)) { return; }

	// Add the property if it doesn't exist or if the type changed.
	const FPropertyBagPropertyDesc* Desc = Bag.FindPropertyDescByName(Name);
	if (!Desc || Desc->ValueType != BagType || Desc->ValueTypeObject.Get() != TypeObject)
	{
		Bag.AddProperty(Name, BagType, TypeObject);
		Desc = Bag.FindPropertyDescByName(Name);
	}

	if (!Desc || !Desc->CachedProperty) { return; }

	FStructView View = Bag.GetMutableValue();
	if (!View.IsValid() || !View.GetMemory()) { return; }

	void* DestPtr = Desc->CachedProperty->ContainerPtrToValuePtr<void>(View.GetMemory());
	Desc->CachedProperty->CopySingleValue(DestPtr, SourcePtr);
}

/** Read the named property from the bag and copy it into DestPtr (which belongs to
 *  DestProp). Returns true only if the property exists and the type matches. */
static bool GetBagValueToProperty(const FInstancedPropertyBag& Bag, const FName Name,
                                  FProperty* DestProp, void* DestPtr)
{
	const FPropertyBagPropertyDesc* Desc = Bag.FindPropertyDescByName(Name);
	if (!Desc || !Desc->CachedProperty) { return false; }

	// Verify the stored type is compatible with the output property.
	EPropertyBagPropertyType ExpectedType;
	UObject* ExpectedTypeObject = nullptr;
	if (!GetBagTypeFromProperty(DestProp, ExpectedType, ExpectedTypeObject)) { return false; }
	if (Desc->ValueType != ExpectedType) { return false; }

	FConstStructView View = Bag.GetValue();
	if (!View.IsValid() || !View.GetMemory()) { return false; }

	const void* SrcPtr = static_cast<const uint8*>(View.GetMemory())
	                     + Desc->CachedProperty->GetOffset_ForInternal();
	DestProp->CopySingleValue(DestPtr, SrcPtr);
	return true;
}

// ─────────────────────────────────────────────────────────────────────────────
// Stub bodies (never called directly – Blueprint always goes through the thunk)
// ─────────────────────────────────────────────────────────────────────────────

void UOmegaFunctions_PropertyBag::SetPropertyBagValue(UPARAM(ref) FOmegaPropertyBagWrapper& Bag,
                                                       FName PropertyName, const int32& Value)
{
	checkf(false, TEXT("SetPropertyBagValue: thunk should always be called instead of this stub"));
}

void UOmegaFunctions_PropertyBag::GetPropertyBagValue(const FOmegaPropertyBagWrapper& Bag,
                                                       FName PropertyName, bool& bValid, int32& Value)
{
	checkf(false, TEXT("GetPropertyBagValue: thunk should always be called instead of this stub"));
}

// ─────────────────────────────────────────────────────────────────────────────
// Custom thunks
// ─────────────────────────────────────────────────────────────────────────────

DEFINE_FUNCTION(UOmegaFunctions_PropertyBag::execSetPropertyBagValue)
{
	// 1. Bag (struct ref)
	P_GET_STRUCT_REF(FOmegaPropertyBagWrapper, Bag);
	// 2. PropertyName
	P_GET_PROPERTY(FNameProperty, PropertyName);
	// 3. Wildcard Value – step the stack to find the actual property/address
	Stack.MostRecentPropertyAddress = nullptr;
	Stack.MostRecentProperty = nullptr;
	Stack.StepCompiledIn<FProperty>(nullptr);
	const void* ValuePtr   = Stack.MostRecentPropertyAddress;
	FProperty*  ValueProp  = Stack.MostRecentProperty;

	P_FINISH;
	P_NATIVE_BEGIN;

	if (ValueProp && ValuePtr)
	{
		SetBagValueFromProperty(Bag.Bag, PropertyName, ValueProp, ValuePtr);
	}

	P_NATIVE_END;
}

DEFINE_FUNCTION(UOmegaFunctions_PropertyBag::execGetPropertyBagValue)
{
	// 1. Bag (struct ref – const in the signature, non-const here but we won't mutate it)
	P_GET_STRUCT_REF(FOmegaPropertyBagWrapper, Bag);
	// 2. PropertyName
	P_GET_PROPERTY(FNameProperty, PropertyName);
	// 3. bValid output
	P_GET_UBOOL_REF(bValid);
	// 4. Wildcard Value output
	Stack.MostRecentPropertyAddress = nullptr;
	Stack.MostRecentProperty = nullptr;
	Stack.StepCompiledIn<FProperty>(nullptr);
	void*      ValuePtr  = Stack.MostRecentPropertyAddress;
	FProperty* ValueProp = Stack.MostRecentProperty;

	P_FINISH;
	P_NATIVE_BEGIN;

	bValid = false;
	if (ValueProp && ValuePtr)
	{
		bValid = GetBagValueToProperty(Bag.Bag, PropertyName, ValueProp, ValuePtr);
	}

	P_NATIVE_END;
}
