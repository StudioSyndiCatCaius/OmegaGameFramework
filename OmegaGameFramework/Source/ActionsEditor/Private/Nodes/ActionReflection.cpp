// Copyright Studio Syndicat 2021. All Rights Reserved. 

#include "ActionReflection.h"

#include "EdGraphSchema_K2.h"


void FBaseActionProperty::RefreshProperty()
{
	if(Property.Get())
	{
		Name = Property->GetFName();
		const auto* K2Schema = GetDefault<UEdGraphSchema_K2>();
		K2Schema->ConvertPropertyToPinType(Property.Get(), Type);
	}
}


bool ActionReflection::GetVisibleProperties(UClass* Class, FActionProperties& OutProperties)
{
	if(!Class)
	{
		return false;
	}

	OutProperties = {};
	for (TFieldIterator<FProperty> PropertyIt(Class, EFieldIteratorFlags::IncludeSuper); PropertyIt; ++PropertyIt)
	{
		FProperty* Property = *PropertyIt;

		// Delegate properties
		if(auto* DelegateProperty = CastField<FMulticastDelegateProperty>(Property))
		{
			if (DelegateProperty && Property->HasAllPropertyFlags(CPF_BlueprintAssignable))
			{
				FDelegateActionProperty ActionProperty{ DelegateProperty };
				if(ActionProperty.HasParams())
				{
					OutProperties.ComplexDelegates.Add(ActionProperty);
				}
				else
				{
					OutProperties.SimpleDelegates.Add(ActionProperty);
				}
			}
		}
		// Variable properties
		else if (UEdGraphSchema_K2::IsPropertyExposedOnSpawn(Property) &&
			!Property->HasAnyPropertyFlags(CPF_Parm) &&
			!Property->HasAnyPropertyFlags(CPF_DisableEditOnInstance) &&
			 Property->HasAllPropertyFlags(CPF_BlueprintVisible))
		{
			OutProperties.Variables.Add({ Property });
		}
	}
	return true;
}

bool FActionProperties::operator==(const FActionProperties& Other) const
{
	if (Variables.Num() != Other.Variables.Num() ||
		SimpleDelegates.Num() != Other.SimpleDelegates.Num() ||
		ComplexDelegates.Num() != Other.ComplexDelegates.Num())
	{
		return false;
	}

	return Equals<FVariableActionProperty>(Variables, Other.Variables)
		&& Equals<FDelegateActionProperty>(SimpleDelegates, Other.SimpleDelegates)
		&& Equals<FDelegateActionProperty>(ComplexDelegates, Other.ComplexDelegates);
}
