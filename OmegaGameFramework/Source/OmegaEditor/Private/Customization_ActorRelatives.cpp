// Customization_ActorRelatives.cpp

#include "Customization_ActorRelatives.h"
#include "OmegaGameCore.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "IDetailChildrenBuilder.h"
#include "PropertyCustomizationHelpers.h"
#include "Widgets/Text/STextBlock.h"
#include "ScopedTransaction.h"
#include "GameFramework/Actor.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Types/Struct_ActorRelatives.h"

#define LOCTEXT_NAMESPACE "ActorRelativesCustomization"

TSharedRef<IPropertyTypeCustomization> FCustomization_ActorRelatives::MakeInstance()
{
	return MakeShareable(new FCustomization_ActorRelatives());
}

void FCustomization_ActorRelatives::CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	StructPropertyHandle = PropertyHandle;

	HeaderRow
		.NameContent()
		[
			PropertyHandle->CreatePropertyNameWidget()
		]
		.ValueContent()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("ActorRelativesHeader", "Actor Relatives"))
			.Font(IDetailLayoutBuilder::GetDetailFont())
		];
}

void FCustomization_ActorRelatives::CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	StructPropertyHandle = PropertyHandle;
	
	// Get the RelativeActors map property
	MapPropertyHandle = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FOmegaActorRelatives, RelativeActors));
	if (!MapPropertyHandle.IsValid())
	{
		return;
	}

	// Get the owner actor
	AActor* OwnerActor = GetOwnerActor();
	if (!OwnerActor)
	{
		ChildBuilder.AddCustomRow(LOCTEXT("NoOwner", "No Owner"))
			.WholeRowContent()
			[
				SNew(STextBlock)
				.Text(LOCTEXT("NoOwnerActor", "Could not determine owner actor"))
			];
		return;
	}

	// Get all available keys from OmegaGameCore
	TArray<FName> AvailableKeys = GetAvailableKeys(OwnerActor);

	if (AvailableKeys.Num() == 0)
	{
		ChildBuilder.AddCustomRow(LOCTEXT("NoKeys", "No Keys"))
			.WholeRowContent()
			[
				SNew(STextBlock)
				.Text(LOCTEXT("NoKeysAvailable", "No relationship keys available"))
			];
		return;
	}

	// Clean up any null entries in the map first
	CleanupNullEntries();

	// Generate a row for each available key
	for (const FName& Key : AvailableKeys)
	{
		GenerateKeyRow(ChildBuilder, Key);
	}
}

AActor* FCustomization_ActorRelatives::GetOwnerActor() const
{
	if (!StructPropertyHandle.IsValid())
	{
		return nullptr;
	}

	TArray<UObject*> OuterObjects;
	StructPropertyHandle->GetOuterObjects(OuterObjects);

	for (UObject* Outer : OuterObjects)
	{
		if (AActor* Actor = Cast<AActor>(Outer))
		{
			return Actor;
		}
		if (UActorComponent* Component = Cast<UActorComponent>(Outer))
		{
			return Component->GetOwner();
		}
	}
	return nullptr;
}

TArray<FName> FCustomization_ActorRelatives::GetAvailableKeys(AActor* OwnerActor) const
{
	if (!OwnerActor)
	{
		return TArray<FName>();
	}

	// Use the OGF_GAME_CORE() macro to get the game core
	return OGF_GAME_CORE()->ActorRealtives_GetKeys(OwnerActor);
}

AActor* FCustomization_ActorRelatives::GetActorForKey(FName Key) const
{
	if (!MapPropertyHandle.IsValid())
	{
		return nullptr;
	}

	// Access the raw map data
	TArray<void*> RawData;
	MapPropertyHandle->AccessRawData(RawData);

	for (void* Data : RawData)
	{
		if (FOmegaActorRelatives* ActorRelatives = static_cast<FOmegaActorRelatives*>(Data))
		{
			if (TSoftObjectPtr<AActor>* FoundActor = ActorRelatives->RelativeActors.Find(Key))
			{
				return FoundActor->Get();
			}
		}
	}

	return nullptr;
}

void FCustomization_ActorRelatives::SetActorForKey(FName Key, AActor* Actor)
{
	if (!MapPropertyHandle.IsValid())
	{
		return;
	}

	FScopedTransaction Transaction(LOCTEXT("SetRelativeActor", "Set Relative Actor"));
	MapPropertyHandle->NotifyPreChange();

	// Access the raw map data
	TArray<void*> RawData;
	MapPropertyHandle->AccessRawData(RawData);

	for (void* Data : RawData)
	{
		if (FOmegaActorRelatives* ActorRelatives = static_cast<FOmegaActorRelatives*>(Data))
		{
			if (Actor && Actor->IsValidLowLevel())
			{
				// Set the actor as a soft object pointer if it's valid
				ActorRelatives->RelativeActors.Add(Key, TSoftObjectPtr<AActor>(Actor));
			}
			else
			{
				// Remove the entry if actor is null
				ActorRelatives->RelativeActors.Remove(Key);
			}
		}
	}

	MapPropertyHandle->NotifyPostChange(EPropertyChangeType::ValueSet);
	MapPropertyHandle->NotifyFinishedChangingProperties();
}

void FCustomization_ActorRelatives::CleanupNullEntries()
{
	if (!MapPropertyHandle.IsValid())
	{
		return;
	}

	// Access the raw map data
	TArray<void*> RawData;
	MapPropertyHandle->AccessRawData(RawData);

	bool bMadeChanges = false;

	for (void* Data : RawData)
	{
		if (FOmegaActorRelatives* ActorRelatives = static_cast<FOmegaActorRelatives*>(Data))
		{
			TArray<FName> KeysToRemove;

			// Find all null or invalid entries
			for (const auto& Pair : ActorRelatives->RelativeActors)
			{
				// Check if the soft object pointer is null or points to invalid object
				if (Pair.Value.IsNull() || !Pair.Value.Get())
				{
					KeysToRemove.Add(Pair.Key);
				}
			}

			// Remove null entries
			for (const FName& Key : KeysToRemove)
			{
				ActorRelatives->RelativeActors.Remove(Key);
				bMadeChanges = true;
			}
		}
	}

	if (bMadeChanges)
	{
		MapPropertyHandle->NotifyPostChange(EPropertyChangeType::ValueSet);
	}
}

void FCustomization_ActorRelatives::GenerateKeyRow(IDetailChildrenBuilder& ChildBuilder, FName Key)
{
	ChildBuilder.AddCustomRow(FText::FromName(Key))
		.NameContent()
		[
			SNew(STextBlock)
			.Text(FText::FromName(Key))
			.Font(IDetailLayoutBuilder::GetDetailFont())
		]
		.ValueContent()
		[
			SNew(SObjectPropertyEntryBox)
			.AllowedClass(AActor::StaticClass())
			.ObjectPath(this, &FCustomization_ActorRelatives::GetObjectPathForKey, Key)
			.OnObjectChanged(this, &FCustomization_ActorRelatives::OnObjectChangedForKey, Key)
			.AllowClear(true)
			.DisplayUseSelected(true)
			.DisplayBrowse(true)
			.DisplayThumbnail(false)
		];
}

FString FCustomization_ActorRelatives::GetObjectPathForKey(FName Key) const
{
	AActor* Actor = GetActorForKey(Key);
	return Actor ? Actor->GetPathName() : FString();
}

void FCustomization_ActorRelatives::OnObjectChangedForKey(const FAssetData& AssetData, FName Key)
{
	AActor* NewActor = Cast<AActor>(AssetData.GetAsset());
	SetActorForKey(Key, NewActor);
}

#undef LOCTEXT_NAMESPACE