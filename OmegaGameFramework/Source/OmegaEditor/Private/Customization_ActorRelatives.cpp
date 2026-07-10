// Customization_ActorRelatives.cpp

#include "Customization_ActorRelatives.h"
#include "OmegaGameManager.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "IDetailChildrenBuilder.h"
#include "PropertyCustomizationHelpers.h"
#include "Widgets/Text/STextBlock.h"
#include "ScopedTransaction.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
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
			.Text(LOCTEXT("ActorRelativesHeader", "🔵Actor Relatives"))
			.Font(IDetailLayoutBuilder::GetDetailFont())
		];
}

void FCustomization_ActorRelatives::CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	StructPropertyHandle = PropertyHandle;

	MapPropertyHandle = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FOmegaActorRelatives, RelativeActors));
	AssetMapPropertyHandle = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FOmegaActorRelatives, RelativeAssets));
	if (!MapPropertyHandle.IsValid())
	{
		return;
	}

	TArray<UObject*> OuterObjects;
	StructPropertyHandle->GetOuterObjects(OuterObjects);

	UObject* OwnerObject = GetOwnerActor();

	if (!OwnerObject && OuterObjects.Num() > 0)
	{
		OwnerObject = OuterObjects[0];
	}
	if (!OwnerObject)
	{
		ChildBuilder.AddCustomRow(LOCTEXT("NoOwner", "No Owner"))
			.WholeRowContent()
			[
				SNew(STextBlock)
				.Text(LOCTEXT("NoOwnerActor", "Could not determine owner object"))
			];
		return;
	}

	FOmegaBitmaskEditorData editData;

	if (OGF_CFG()->ClassBitflagData.Contains(OwnerObject->GetClass()))
	{
		editData = OGF_CFG()->ClassBitflagData[OwnerObject->GetClass()];
	}

	TArray<FName> AvailableKeys = editData.Relative_Actors;
	TArray<FName> AvailableAssetKeys = editData.Relative_Assets;

	void* StructData = nullptr;
	StructPropertyHandle->GetValueData(StructData);
	if (FOmegaActorRelatives* _struct = static_cast<FOmegaActorRelatives*>(StructData))
	{
		if (_struct->override_keys)
		{
			AvailableKeys = _struct->override_keyList;
		}
	}

	if (AvailableKeys.Num() == 0 && AvailableAssetKeys.Num() == 0)
	{
		ChildBuilder.AddCustomRow(LOCTEXT("NoKeys", "No Keys"))
			.WholeRowContent()
			[
				SNew(STextBlock)
				.Text(LOCTEXT("NoKeysAvailable", "No relationship keys available"))
			];
		return;
	}

	CleanupNullEntries();

	for (const FName& Key : AvailableKeys)
	{
		GenerateKeyRow(ChildBuilder, Key);
	}

	for (const FName& Key : AvailableAssetKeys)
	{
		GenerateAssetKeyRow(ChildBuilder, Key);
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
	return OGF_GAME_CORE()->ActorRealtives_GetKeys(OwnerActor);
}

TArray<FName> FCustomization_ActorRelatives::GetAvailableAssetKeys(AActor* OwnerActor) const
{
	if (!OwnerActor)
	{
		return TArray<FName>();
	}
	return OGF_GAME_CORE()->AssetRealtives_GetKeys(OwnerActor);
}

// ---- Helpers: always access raw data through StructPropertyHandle so that
//      AccessRawData returns FOmegaActorRelatives* (the struct base), not a
//      pointer to one of its member maps. Using a child map handle's
//      AccessRawData returns a pointer to the map field itself, so casting
//      that to FOmegaActorRelatives* and then accessing a member at a
//      non-zero offset corrupts adjacent memory.

AActor* FCustomization_ActorRelatives::GetActorForKey(FName Key) const
{
	if (!StructPropertyHandle.IsValid())
	{
		return nullptr;
	}

	TArray<void*> RawData;
	StructPropertyHandle->AccessRawData(RawData);

	for (void* Data : RawData)
	{
		if (FOmegaActorRelatives* S = static_cast<FOmegaActorRelatives*>(Data))
		{
			if (TSoftObjectPtr<AActor>* Found = S->RelativeActors.Find(Key))
			{
				return Found->Get();
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

	TArray<void*> RawData;
	StructPropertyHandle->AccessRawData(RawData);

	for (void* Data : RawData)
	{
		if (FOmegaActorRelatives* S = static_cast<FOmegaActorRelatives*>(Data))
		{
			if (Actor && Actor->IsValidLowLevel())
			{
				S->RelativeActors.Add(Key, TSoftObjectPtr<AActor>(Actor));
			}
			else
			{
				S->RelativeActors.Remove(Key);
			}
		}
	}

	MapPropertyHandle->NotifyPostChange(EPropertyChangeType::ValueSet);
	MapPropertyHandle->NotifyFinishedChangingProperties();
}

UPrimaryDataAsset* FCustomization_ActorRelatives::GetAssetForKey(FName Key) const
{
	if (!StructPropertyHandle.IsValid())
	{
		return nullptr;
	}

	TArray<void*> RawData;
	StructPropertyHandle->AccessRawData(RawData);

	for (void* Data : RawData)
	{
		if (FOmegaActorRelatives* S = static_cast<FOmegaActorRelatives*>(Data))
		{
			if (TSoftObjectPtr<UPrimaryDataAsset>* Found = S->RelativeAssets.Find(Key))
			{
				return Found->Get();
			}
		}
	}
	return nullptr;
}

void FCustomization_ActorRelatives::SetAssetForKey(FName Key, UPrimaryDataAsset* Asset)
{
	if (!AssetMapPropertyHandle.IsValid())
	{
		return;
	}

	FScopedTransaction Transaction(LOCTEXT("SetRelativeAsset", "Set Relative Asset"));
	AssetMapPropertyHandle->NotifyPreChange();

	TArray<void*> RawData;
	StructPropertyHandle->AccessRawData(RawData);

	for (void* Data : RawData)
	{
		if (FOmegaActorRelatives* S = static_cast<FOmegaActorRelatives*>(Data))
		{
			if (Asset && Asset->IsValidLowLevel())
			{
				S->RelativeAssets.Add(Key, TSoftObjectPtr<UPrimaryDataAsset>(Asset));
			}
			else
			{
				S->RelativeAssets.Remove(Key);
			}
		}
	}

	AssetMapPropertyHandle->NotifyPostChange(EPropertyChangeType::ValueSet);
	AssetMapPropertyHandle->NotifyFinishedChangingProperties();
}

void FCustomization_ActorRelatives::CleanupNullEntries()
{
	if (!StructPropertyHandle.IsValid())
	{
		return;
	}

	TArray<void*> RawData;
	StructPropertyHandle->AccessRawData(RawData);

	bool bActorChanges = false;
	bool bAssetChanges = false;

	for (void* Data : RawData)
	{
		if (FOmegaActorRelatives* S = static_cast<FOmegaActorRelatives*>(Data))
		{
			TArray<FName> ToRemove;
			for (const auto& Pair : S->RelativeActors)
			{
				if (Pair.Value.IsNull() || !Pair.Value.Get())
				{
					ToRemove.Add(Pair.Key);
				}
			}
			for (const FName& Key : ToRemove)
			{
				S->RelativeActors.Remove(Key);
				bActorChanges = true;
			}

			ToRemove.Reset();
			for (const auto& Pair : S->RelativeAssets)
			{
				if (Pair.Value.IsNull() || !Pair.Value.Get())
				{
					ToRemove.Add(Pair.Key);
				}
			}
			for (const FName& Key : ToRemove)
			{
				S->RelativeAssets.Remove(Key);
				bAssetChanges = true;
			}
		}
	}

	if (bActorChanges && MapPropertyHandle.IsValid())
	{
		MapPropertyHandle->NotifyPostChange(EPropertyChangeType::ValueSet);
	}
	if (bAssetChanges && AssetMapPropertyHandle.IsValid())
	{
		AssetMapPropertyHandle->NotifyPostChange(EPropertyChangeType::ValueSet);
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

void FCustomization_ActorRelatives::GenerateAssetKeyRow(IDetailChildrenBuilder& ChildBuilder, FName Key)
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
			.AllowedClass(UPrimaryDataAsset::StaticClass())
			.ObjectPath(this, &FCustomization_ActorRelatives::GetAssetObjectPathForKey, Key)
			.OnObjectChanged(this, &FCustomization_ActorRelatives::OnAssetChangedForKey, Key)
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

FString FCustomization_ActorRelatives::GetAssetObjectPathForKey(FName Key) const
{
	UPrimaryDataAsset* Asset = GetAssetForKey(Key);
	return Asset ? Asset->GetPathName() : FString();
}

void FCustomization_ActorRelatives::OnObjectChangedForKey(const FAssetData& AssetData, FName Key)
{
	AActor* NewActor = Cast<AActor>(AssetData.GetAsset());
	SetActorForKey(Key, NewActor);
}

void FCustomization_ActorRelatives::OnAssetChangedForKey(const FAssetData& AssetData, FName Key)
{
	UPrimaryDataAsset* NewAsset = Cast<UPrimaryDataAsset>(AssetData.GetAsset());
	SetAssetForKey(Key, NewAsset);
}

#undef LOCTEXT_NAMESPACE
