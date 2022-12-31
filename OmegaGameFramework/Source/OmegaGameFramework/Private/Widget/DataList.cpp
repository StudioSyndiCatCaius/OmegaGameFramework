// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Widget/DataList.h"
#include "Widget/DataWidget.h"

#include "Components/HorizontalBox.h"
#include "Components/VerticalBox.h"
#include "Components/ScrollBox.h"
#include "Components/UniformGridPanel.h"
#include "Components/PanelWidget.h"

#include "Components/HorizontalBoxSlot.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/UniformGridSlot.h"

#include "Widgets/Layout/Anchors.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/TextBlock.h"
#include "Engine/DataAsset.h"


void UDataList::ClearList()
{
	if (ListPanel)
	{
		ListPanel->ClearChildren();
	}
	Entries.Empty();
	CurrentA = 0;
	CurrentB = 0;

	UE_LOG(LogTemp, Warning, TEXT("ListCleared"));
}

void UDataList::RemoveEntryFromList(int32 Index)
{
	if(Entries.IsValidIndex(Index))		//check is valid index
	{
		Entries[Index]->RemoveFromParent();		//Remove from viewport
		Entries.RemoveAt(Index);				//Remove from array of entries
	}
}

void UDataList::RemoveEntryOfAsset(UObject* Asset, bool All)
{
	bool OneFound = false;
	TArray<UDataWidget*> MarkedRemovals;
	for(UDataWidget* TempEntry : Entries)
	{
		if(TempEntry->ReferencedAsset == Asset && (All || !OneFound))
		{
			OneFound = true;
			MarkedRemovals.Add(TempEntry);
		}
	}

	for(UDataWidget* TempEntry : MarkedRemovals)
	{
		RemoveEntryFromList(GetEntryIndex(TempEntry));
	}
	
} 

// ADD ENTRY BASE
UDataWidget* UDataList::AddAssetToList(UObject* Asset, FString Flag)
{
	//Is Entry Class Valid?
	if (!EntryClass)
	{
		return nullptr;
		UE_LOG(LogTemp, Warning, TEXT("Failed to Add Asset. Invalid Widget Class."));
	}

	//Create Entry Widget
	UDataWidget* TempEntry = CreateWidget<UDataWidget>(this, EntryClass);

	if(OverrideEntryTooltip)
	{
		TempEntry->DefaultTooltipWidget = OverrideEntryTooltip;
	}
	
	// Do not add if hidden
	if(TempEntry->IsEntityHidden(Asset))
	{
		return nullptr;
	}
	
	Entries.Add(TempEntry);
	TempEntry->AssetLabel = EntryLabel;
	TempEntry->ParentList = this;
	if (Asset)
	{
		TempEntry->ReferencedAsset = Asset;
	}
	
	// Bind Delegates
	TempEntry->OnSelected.AddDynamic(this, &UDataList::NativeEntitySelect);
	TempEntry->OnHovered.AddDynamic(this, &UDataList::NativeEntityHover);
	TempEntry->OnHighlight.AddDynamic(this, &UDataList::NativeEntityHighlight);

	UHorizontalBoxSlot* HSlotRef;
	UVerticalBoxSlot* VSlotRef;
	UUniformGridSlot* USlotRef;

	//Put In List
	switch (Format)
	{
	case EDataListFormat::Format_Box:

		switch (Orientation)
		{
		case EOrientation::Orient_Horizontal:
			HSlotRef = Cast<UHorizontalBox>(ListPanel)->AddChildToHorizontalBox(TempEntry);
			HSlotRef->SetHorizontalAlignment(EntryHorizontalAlignment);
			HSlotRef->SetVerticalAlignment(EntryVerticalAlignment);
			HSlotRef->SetSize(EntrySize);

			break;
		case EOrientation::Orient_Vertical:
			VSlotRef = Cast<UVerticalBox>(ListPanel)->AddChildToVerticalBox(TempEntry);
			VSlotRef->SetHorizontalAlignment(EntryHorizontalAlignment);
			VSlotRef->SetVerticalAlignment(EntryVerticalAlignment);
			VSlotRef->SetSize(EntrySize);

			break;
		}

		break;
	case EDataListFormat::Format_ScrollBox:
		Cast<UScrollBox>(ListPanel)->AddChild(TempEntry);
		Cast<UScrollBox>(ListPanel)->SetOrientation(Orientation);

		break;
	case EDataListFormat::Format_UniformGrid:
		int32 InRow = 0;
		int32 InCol = 0;
		switch (Orientation)
		{
		case EOrientation::Orient_Horizontal:
			InRow = CurrentA;
			InCol = CurrentB;
			break;
		case EOrientation::Orient_Vertical:
			InRow = CurrentB;
			InCol = CurrentA;
			break;
		}

		USlotRef = Cast<UUniformGridPanel>(ListPanel)->AddChildToUniformGrid(TempEntry, InRow, InCol);
		USlotRef->SetHorizontalAlignment(EntryHorizontalAlignment);
		USlotRef->SetVerticalAlignment(EntryVerticalAlignment);
		if (CurrentB>=(UniformGridMaxValue - 1))
		{
			CurrentA = CurrentA + 1;
			CurrentB = 0;
		}
		else
		{
			CurrentB = CurrentB + 1;
		}
		break;
	}
	UE_LOG(LogTemp, Warning, TEXT("Added WidgetToList"));
	TempEntry->AddedToDataList(this, Entries.Find(TempEntry), Asset, ListTags, Flag);

	return TempEntry;
}

TArray<UDataWidget*> UDataList::AddAssetsToList(TArray<UObject*> Assets, FString Flag, bool ClearListFirst)
{
	if (ClearListFirst)
	{
		ClearList();
	}

	TArray<UDataWidget*> LocalEntryList;
	for (UObject* TempAsset : Assets)
	{
		UE_LOG(LogTemp, Warning, TEXT("Attempted to add Widget To List"));
		UDataWidget* LocalEntry = AddAssetToList(TempAsset, Flag);
		LocalEntryList.Add(LocalEntry);
	}
	return LocalEntryList;
}

UDataWidget* UDataList::AddedCustomEntryToList(FCustomAssetData EntryData, FString Flag)
{
	UGeneralDataObject* TempDataObj = NewObject<UGeneralDataObject>(this, UGeneralDataObject::StaticClass());
	TempDataObj->CustomData = EntryData;
	return AddAssetToList(TempDataObj, Flag);
}

TArray<UDataWidget*> UDataList::GetEntries()
{
	TArray<UDataWidget*> OutEntries;
	for(auto* TempEntry : Entries)
	{
		if(TempEntry)
		{
			OutEntries.Add(TempEntry);
		}
	}
	return OutEntries;
}

void UDataList::HoverEntry(int32 Index)
{
	if(GetEntry(Index))
	{
		GetEntry(Index)->Hover();
	}
}

UDataWidget* UDataList::GetHoveredEntry()
{
	if(HoveredEntry)
	{
		return HoveredEntry;
	}
	return nullptr;
}

void UDataList::SelectHoveredEntry()
{
	if(HoveredEntry)
	{
		HoveredEntry->Select();
	}
}

void UDataList::SelectEntry(int32 Index)
{
	HoverEntry(Index);
	SelectHoveredEntry();
}

void UDataList::CycleEntry(int32 Amount)
{
	UDataWidget* TempEntry;
	int32 MaxSize = Entries.Num();
	if(HoveredEntry)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hovered Valid"));
		TempEntry = HoveredEntry;
	}
	else if(GetEntry(0))
	{
		UE_LOG(LogTemp, Warning, TEXT("Go to Default"));
		TempEntry = GetEntry(0);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("FAILED"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("EntrySize"));
	int Tempindex = GetEntryIndex(TempEntry)+Amount;

	if(Tempindex < 0)
	{
		Tempindex = MaxSize;
	}
	else if(Tempindex > MaxSize)
	{
		Tempindex = 0;
	}
	HoverEntry(Tempindex);
}

int32 UDataList::GetEntryIndex(UDataWidget* Entry)
{
	if(Entry)
	{
		if(Entries.Contains(Entry))
		{
			return Entries.Find(Entry);
			//return Entries.IndexOfByKey(Entry);
		}
	}
	return -1;
}

UDataWidget* UDataList::GetEntry(int32 Index)
{
	if(Entries.IsValidIndex(Index))
	{
		return Entries[Index];
	}
	return nullptr;
}

TArray<UDataWidget*> UDataList::GetEntiresWithTag(FName Tag, bool bInvertGet)
{
	TArray<UDataWidget*> OutWidgets;
	for(auto* TempEntry : Entries)
	{
		if(TempEntry)
		{
			if(TempEntry->DataWidgetHasTag(Tag) != bInvertGet)
			{
				OutWidgets.Add(TempEntry);
			}
		}
	}
	
	return OutWidgets;
}

bool UDataList::AnyEntryHasTag(FName Tag)
{
	for(auto TempEntry : GetEntries())
	{
		if(TempEntry->DataWidgetHasTag(Tag))
		{
			return false;
		}
	}
	return false;
}


//////////////////////
///Input////////
////////////////////
void UDataList::InputNavigate_Implementation(FVector2D Axis)
{
	if(CycleOnInputNavigate)
	{
		float LocalAxis;
		if(Orientation==EOrientation::Orient_Vertical)
		{
			LocalAxis = Axis.Y*-1;
		}
		else
		{
			LocalAxis = Axis.X;
		}
		CycleEntry(int32(LocalAxis));
	}
	
	OnInputNavigate.Broadcast(Axis);
}

void UDataList::InputPage_Implementation(float Axis)
{
	if(CycleOnInputPage)
	{
		CycleEntry(int32(Axis));
	}
	OnInputPage.Broadcast(Axis);
}

void UDataList::InputConfirm_Implementation()
{
	if(HoveredEntry->IsValidLowLevel())
	{
		HoveredEntry->Select();
	}
}

void UDataList::InputCancel_Implementation()
{
	OnInputCancel.Broadcast();
}

void UDataList::SetListOwner(UObject* NewOwner)
{
	if(NewOwner)
	{
		ListOwner = NewOwner;
		for(UDataWidget* TempEntry: Entries)
		{
			TempEntry->OnNewListOwner(ListOwner);
		}
	}
}

void UDataList::NativePreConstruct()
{
	Super::NativePreConstruct();
	RebuildList();
	ListOwner=GetParent();
}

////////////////////////
/////Native Rebuild List///
//////////////////////////

void UDataList::RebuildList()
{
	//Clear Panel
	ClearList();
	
	if (!ParentPanel)
	{
		return;
		UE_LOG(LogTemp, Warning, TEXT("No Valid Parent Panel"));
	}
	UE_LOG(LogTemp, Warning, TEXT("Rebuilding List"));
	//Create Content Panel
	switch (Format)
	{
	case EDataListFormat::Format_Box:

		switch (Orientation)
		{
		case EOrientation::Orient_Horizontal:
			BuildList(UHorizontalBox::StaticClass());
		break;
		case EOrientation::Orient_Vertical:
			BuildList(UVerticalBox::StaticClass());
		break;
		default: ;
		}

		break;
	case EDataListFormat::Format_ScrollBox:
			BuildList(UScrollBox::StaticClass());
			Cast<UScrollBox>(ListPanel)->SetOrientation(Orientation);
		break;
	case EDataListFormat::Format_UniformGrid:
			BuildList(UUniformGridPanel::StaticClass());
		break;
	}

	//Add to Content Panel and Align
	ParentPanel->AddChildToCanvas(ListPanel);
	UCanvasPanelSlot* TempSlot = UWidgetLayoutLibrary::SlotAsCanvasSlot(ListPanel);
	const FAnchors DumAnc = FAnchors(0.0, 0.0, 1.0, 1.0);
	const FVector2D DumVec = FVector2D(0.0);
	TempSlot->SetAnchors(DumAnc);
	TempSlot->SetSize(DumVec);
	TempSlot->SetAutoSize(bAutoSizeList);
	
	///Assets and ENtires
	CurrentA = 0;
	TArray<UObject*> DumObjList;

	ClearList();
	
	if (bUseCustomEntries)
	{
		for (const FCustomAssetData TempData : CustomEntries)
		{
			AddedCustomEntryToList(TempData, DefaultListFlag);
		}
	}
	else
	{
		for (UPrimaryDataAsset* TempAsset : DefaultAssets)
		{
			AddAssetToList(TempAsset, DefaultListFlag);
		}
	}
}

//UClass* UDataList::GetSlotClass() const
//{
	//return UCanvasPanelSlot::StaticClass();
//}

UPanelWidget* UDataList::BuildList(TSubclassOf<UPanelWidget> Class)
{
	ListPanel = NewObject<UPanelWidget>(this, Class);
	
	return ListPanel;
}

void UDataList::NativeEntitySelect(UDataWidget* DataWidget)
{
	if(HighlightOnSelect)
	{
		for(auto* TempEntry : Entries)
		{
			if(TempEntry)
			{
				TempEntry->SetHighlighted(false);
			}
		}
		if(DataWidget)
		{
			DataWidget->SetHighlighted(true);
		}
	}
	OnEntrySelected.Broadcast(DataWidget, DataWidget->GetAssetLabel(), DataWidget->ReferencedAsset, Entries.Find(DataWidget));
}

void UDataList::NativeEntityHover(UDataWidget* DataWidget, bool bIsHovered)
{
	if (bIsHovered)
	{
		HoveredEntry = DataWidget;
		OnEntryHovered.Broadcast(DataWidget, DataWidget->GetAssetLabel(), DataWidget->ReferencedAsset, Entries.Find(DataWidget));
		if(Format==EDataListFormat::Format_ScrollBox)
		{
			Cast<UScrollBox>(ListPanel)->ScrollWidgetIntoView(DataWidget);
		}

		if(DescriptionTextBlock)
		{
			FText DumText;
			FText DumDesc;
			IDataInterface_General::Execute_GetGeneralDataText(DataWidget->ReferencedAsset, "DumLabel", this, DumText, DumDesc);
			DescriptionTextBlock->SetText(DumDesc);
		}
	}
	else
	{
		OnEntryUnhovered.Broadcast(DataWidget, DataWidget->GetAssetLabel(), DataWidget->ReferencedAsset, Entries.Find(DataWidget));
		if(DescriptionTextBlock)
		{
			DescriptionTextBlock->SetText(FText::FromString(""));
		}
	}
}

void UDataList::NativeEntityHighlight(UDataWidget* DataWidget, bool bIsHighlighted)
{
	
	OnEntryHighlighted.Broadcast(DataWidget, DataWidget->GetAssetLabel(), DataWidget->ReferencedAsset, Entries.Find(DataWidget), bIsHighlighted);
}

void UDataList::SetEntryHighlighted(int32 Index, bool bHighlighted)
{
	if(GetEntries()[Index])
	{
		GetEntries()[Index]->SetHighlighted(bHighlighted);
	}
}

void UDataList::SetAllEntriesHighlighted(bool bHighlighted)
{
	for(auto* TempEntry : GetEntries())
	{
		if(TempEntry)
		{
			TempEntry->SetHighlighted(bHighlighted);
		}
	}
}

