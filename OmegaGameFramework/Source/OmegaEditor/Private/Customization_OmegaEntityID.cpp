// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Customization_OmegaEntityID.h"
#include "DetailWidgetRow.h"
#include "IDetailChildrenBuilder.h"
#include "PropertyCustomizationHelpers.h"
#include "Widgets/Input/SComboButton.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SBox.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Engine/DataAsset.h"

#define ENTITY_TYPE_ASSET 0
#define ENTITY_TYPE_NAME  1
#define ENTITY_TYPE_GUID  3

TSharedRef<IPropertyTypeCustomization> FOmegaEntityIDCustomization::MakeInstance()
{
	return MakeShareable(new FOmegaEntityIDCustomization());
}

void FOmegaEntityIDCustomization::CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	StructHandle = PropertyHandle;

	HeaderRow
	.NameContent()
	[
		PropertyHandle->CreatePropertyNameWidget()
	]
	.ValueContent()
	.MinDesiredWidth(300.f)
	[
		SNew(SHorizontalBox)

		// ── Type selector ──────────────────────────────────────────────────
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(0, 0, 6, 0)
		[
			SNew(SComboButton)
			.OnGetMenuContent(this, &FOmegaEntityIDCustomization::MakeTypePickerMenu)
			.ButtonContent()
			[
				SNew(STextBlock)
				.Text(this, &FOmegaEntityIDCustomization::GetCurrentTypeLabel)
				.Font(IPropertyTypeCustomizationUtils::GetRegularFont())
			]
		]

		// ── Type 0: Data Asset picker ──────────────────────────────────────
		+ SHorizontalBox::Slot()
		.FillWidth(1.f)
		[
			SNew(SBox)
			.Visibility_Lambda([this]()
			{
				return GetCurrentType() == ENTITY_TYPE_ASSET ? EVisibility::Visible : EVisibility::Collapsed;
			})
			[
				SNew(SObjectPropertyEntryBox)
				.AllowedClass(UPrimaryDataAsset::StaticClass())
				.ObjectPath(this, &FOmegaEntityIDCustomization::GetAssetPath)
				.OnObjectChanged(this, &FOmegaEntityIDCustomization::OnAssetChanged)
				.AllowClear(true)
			]
		]

		// ── Type 1: Name text field ────────────────────────────────────────
		+ SHorizontalBox::Slot()
		.FillWidth(1.f)
		[
			SNew(SBox)
			.Visibility_Lambda([this]()
			{
				return GetCurrentType() == ENTITY_TYPE_NAME ? EVisibility::Visible : EVisibility::Collapsed;
			})
			[
				SNew(SEditableTextBox)
				.Text_Lambda([this]() { return FText::FromString(GetEntityString()); })
				.OnTextCommitted_Lambda([this](const FText& Text, ETextCommit::Type) { SetEntityString(Text.ToString()); })
				.Font(IPropertyTypeCustomizationUtils::GetRegularFont())
				.HintText(FText::FromString("Name..."))
			]
		]

		// ── Type 3: GUID — formatted text box + Generate button ───────────
		+ SHorizontalBox::Slot()
		.FillWidth(1.f)
		[
			SNew(SBox)
			.Visibility_Lambda([this]()
			{
				return GetCurrentType() == ENTITY_TYPE_GUID ? EVisibility::Visible : EVisibility::Collapsed;
			})
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.FillWidth(1.f)
				[
					SNew(SEditableTextBox)
					.Text_Lambda([this]()
					{
						// Display as the standard "XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX" form.
						FGuid Parsed;
						const FString Stored = GetEntityString();
						if (FGuid::Parse(Stored, Parsed))
						{
							return FText::FromString(Parsed.ToString(EGuidFormats::DigitsWithHyphens));
						}
						return FText::FromString(Stored);
					})
					.OnTextCommitted_Lambda([this](const FText& Text, ETextCommit::Type)
					{
						// Accept both hyphenated and raw hex forms.
						FGuid Parsed;
						if (FGuid::ParseExact(Text.ToString(), EGuidFormats::DigitsWithHyphens, Parsed) ||
							FGuid::ParseExact(Text.ToString(), EGuidFormats::Digits, Parsed)            ||
							FGuid::Parse(Text.ToString(), Parsed))
						{
							SetEntityString(Parsed.ToString(EGuidFormats::DigitsWithHyphens));
						}
						else
						{
							// Keep whatever was there; don't store an invalid GUID.
						}
					})
					.Font(IPropertyTypeCustomizationUtils::GetRegularFont())
					.HintText(FText::FromString("00000000-0000-0000-0000-000000000000"))
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(4, 0, 0, 0)
				[
					SNew(SButton)
					.Text(FText::FromString("Generate"))
					.ToolTipText(FText::FromString("Create a new random GUID"))
					.OnClicked_Lambda([this]()
					{
						SetEntityString(FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphens));
						return FReply::Handled();
					})
				]
			]
		]
	];
}

void FOmegaEntityIDCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	// All controls live in the header row.
}

// ─────────────────────────────────────────────────────────────────────────────
// Raw struct access
// entity_type and entity_string lack EditAnywhere, so child property handles
// silently reject SetValue. We go through the struct pointer directly and use
// NotifyPreChange / NotifyPostChange so undo/redo still works.
// ─────────────────────────────────────────────────────────────────────────────

FOmegaEntityID* FOmegaEntityIDCustomization::GetStructPtr() const
{
	if (!StructHandle.IsValid()) return nullptr;
	void* RawData = nullptr;
	if (StructHandle->GetValueData(RawData) == FPropertyAccess::Success)
	{
		return static_cast<FOmegaEntityID*>(RawData);
	}
	return nullptr;
}

uint8 FOmegaEntityIDCustomization::GetCurrentType() const
{
	if (const FOmegaEntityID* S = GetStructPtr()) return S->entity_type;
	return 0;
}

void FOmegaEntityIDCustomization::SetCurrentType(uint8 NewType)
{
	FOmegaEntityID* S = GetStructPtr();
	if (!S || !StructHandle.IsValid()) return;

	StructHandle->NotifyPreChange();
	S->entity_type = NewType;
	S->entity_string.Empty();
	StructHandle->NotifyPostChange(EPropertyChangeType::ValueSet);
}

FText FOmegaEntityIDCustomization::GetTypeLabel(uint8 Type) const
{
	switch (Type)
	{
		case ENTITY_TYPE_ASSET: return FText::FromString("Data Asset");
		case ENTITY_TYPE_NAME:  return FText::FromString("Name");
		case ENTITY_TYPE_GUID:  return FText::FromString("GUID");
		default:                return FText::FromString("Unknown");
	}
}

FText FOmegaEntityIDCustomization::GetCurrentTypeLabel() const
{
	return GetTypeLabel(GetCurrentType());
}

FString FOmegaEntityIDCustomization::GetEntityString() const
{
	if (const FOmegaEntityID* S = GetStructPtr()) return S->entity_string;
	return FString();
}

void FOmegaEntityIDCustomization::SetEntityString(const FString& NewValue)
{
	FOmegaEntityID* S = GetStructPtr();
	if (!S || !StructHandle.IsValid()) return;

	StructHandle->NotifyPreChange();
	S->entity_string = NewValue;
	StructHandle->NotifyPostChange(EPropertyChangeType::ValueSet);
}

FString FOmegaEntityIDCustomization::GetAssetPath() const
{
	return GetEntityString();
}

void FOmegaEntityIDCustomization::OnAssetChanged(const FAssetData& AssetData)
{
	SetEntityString(AssetData.IsValid() ? AssetData.GetObjectPathString() : FString());
}

TSharedRef<SWidget> FOmegaEntityIDCustomization::MakeTypePickerMenu()
{
	FMenuBuilder MenuBuilder(true, nullptr);

	const TArray<uint8> Types = { ENTITY_TYPE_ASSET, ENTITY_TYPE_NAME, ENTITY_TYPE_GUID };
	for (uint8 Type : Types)
	{
		MenuBuilder.AddMenuEntry(
			GetTypeLabel(Type),
			FText::GetEmpty(),
			FSlateIcon(),
			FUIAction(
				FExecuteAction::CreateLambda([this, Type]() { SetCurrentType(Type); }),
				FCanExecuteAction(),
				FIsActionChecked::CreateLambda([this, Type]() { return GetCurrentType() == Type; })
			),
			NAME_None,
			EUserInterfaceActionType::RadioButton
		);
	}

	return MenuBuilder.MakeWidget();
}
