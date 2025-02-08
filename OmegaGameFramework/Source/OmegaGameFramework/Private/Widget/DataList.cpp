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
#include "Kismet/KismetMathLibrary.h"


UDataListCustomEntry::UDataListCustomEntry(const FObjectInitializer& ObjectInitializer)
{
	if (const UObject* Owner = GetOuter())
	{
		WorldPrivate = Owner->GetWorld();
	}
}

UWorld* UDataListCustomEntry::GetWorld() const
{
	if(WorldPrivate)
    {
    	return WorldPrivate;
    }
    else if(GetGameInstance())
    {
    	return GetGameInstance()->GetWorld();
    }
    return nullptr;
}

UGameInstance* UDataListCustomEntry::GetGameInstance() const
{
	return GameInstanceRef;
}

void UDataList::SetEntryClass(TSubclassOf<UDataWidget> NewClass, bool KeepEntries)
{
	if(NewClass)
	{
		EntryClass = NewClass;
		TArray<UDataWidget*> SavedEntryWidgets;

		ClearList();
		if(KeepEntries)
		{
			for(const auto* OldEntry : SavedEntryWidgets)
			{
				AddAssetToList(OldEntry->ReferencedAsset, "NewEntryClass");
			}
		}
	}
}

void UDataList::Native_WidgetNotify(UDataWidget* Widget, FName Notify)
{
	OnEntryNotifed.Broadcast(Widget,Notify);
}

FLuaValue UDataList::GetListScript(TSubclassOf<ULuaState> State)
{
	return ULuaObjectFunctions::RunLuaScriptContainer(this,List_Script,State);
}

void UDataList::SetNewControl(UUserWidget* NewWidget)
{
	if(NewWidget)
	{
		GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->SetControlWidget(NewWidget);
	}
}

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
	if(!Asset)
	{
		return nullptr;
	}
	//Is Entry Class Valid?
	if (!EntryClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to Add Asset. Invalid Widget Class."));
		return nullptr;
	}
	//check metadata
	for(auto* TempMeta : EntryMetadata)
	{
		if(TempMeta && !TempMeta->CanAddObjectToList(Asset))
		{
			return nullptr;
		}
	}

	//Create Entry Widget
	UDataWidget* TempEntry = CreateWidget<UDataWidget>(this, EntryClass);
	TempEntry->WidgetTags=EntryAutoTags;
	TempEntry->WidgetMetadata=EntryMetadata;
	TempEntry->bCanOverrideSize=bCanOverrideSize;
	TempEntry->OverrideSize=OverrideSize;
	
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
	TempEntry->Script=Entry_Script;
	
	// Bind Delegates
	TempEntry->OnSelected.AddDynamic(this, &UDataList::NativeEntitySelect);
	TempEntry->OnHovered.AddDynamic(this, &UDataList::NativeEntityHover);
	TempEntry->OnHighlight.AddDynamic(this, &UDataList::NativeEntityHighlight);
	TempEntry->OnWidgetNotify.AddDynamic(this, &UDataList::Native_WidgetNotify);

	UHorizontalBoxSlot* HSlotRef;
	UVerticalBoxSlot* VSlotRef;
	UUniformGridSlot* USlotRef;

	//Put In List
	if(ListPanel)
	{
		if(ListFormat)
		{
			ListFormat->AddDataWidget(TempEntry,ListPanel);
		}
		else
		{
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
		}
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
	return AddAssetToList(Native_CreateCustomDataObject(EntryData), Flag);
}

UGeneralDataObject* UDataList::Native_CreateCustomDataObject(FCustomAssetData EntryData)
{
	UGeneralDataObject* TempDataObj = NewObject<UGeneralDataObject>(this, UGeneralDataObject::StaticClass());
	TempDataObj->CustomData = EntryData;
	return TempDataObj;
}

TArray<UDataWidget*> UDataList::GetEntries()
{
	TArray<UDataWidget*> OutEntries;
	for(auto* TempEntry : Entries)
	{
		if(TempEntry && TempEntry->IsRendered())
		{
			OutEntries.Add(TempEntry);
		}
	}
	return OutEntries;
}

TArray<UDataWidget*> UDataList::GetEntries_Impure(TSubclassOf<UDataWidget> Class)
{
	TArray<UDataWidget*> out;
	for (auto* i : GetEntries())
	{
		if(i->GetClass()->IsChildOf(Class) || !Class)
		{
			out.Add(i);
		}
	}
	return out;
}

void UDataList::HoverEntry(int32 Index,bool UseLastIndex)
{
	int32 incoming_index=Index;
	if(UseLastIndex)
	{
		incoming_index=RememberedHoverIndex;
	}
	
	if(GetEntry(incoming_index))
	{
		GetEntry(incoming_index)->Hover();
	}
	else
	{
		GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->SetControlWidget(this);
	}
}

void UDataList::ClearHoveredEntry()
{
	for(auto* i : GetEntries())
	{
		if(i && i->IsHovered())
		{
			i->Unhover();
		}
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

bool UDataList::CycleEntry(int32 Amount,int32& NewEntry)
{
	UDataWidget* TempEntry;
	int32 MaxSize = Entries.Num()-1;
	
	//Return false if amount = 0
	if(Amount==0)
	{
	UE_LOG(LogTemp, Warning, TEXT("Failed to Cycle DataList: Cycle Amount is 0"));
		return false;
	}
	
	if(HoveredEntry)
	{
		TempEntry = HoveredEntry;
	}
	else if(GetEntry(0))
	{
		TempEntry = GetEntry(0);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to Cycle DataList: List Empty"));
		return false;
	}

	int32 Tempindex=GetEntryIndex(TempEntry)+Amount;
	
	if(Tempindex < 0)
	{
		Tempindex = MaxSize;
	}
	else if(Tempindex > MaxSize)
	{
		Tempindex = 0;
	}
	
	//IF valid entry index, cycle
	if (GetEntries().IsValidIndex(Tempindex))
	{
		HoverEntry(Tempindex);
		NewEntry = Tempindex;
		return true;
	}
	UE_LOG(LogTemp, Warning, TEXT("Failed to Cycle DataList: Invalid Entry at index %d"), Tempindex);
	return false;
}

int32 UDataList::GetEntryIndex(UDataWidget* Entry)
{
	if(Entry)
	{
		if(GetEntries().Contains(Entry))
		{
			return GetEntries().Find(Entry);
			//return Entries.IndexOfByKey(Entry);
		}
	}
	return -1;
}

UDataWidget* UDataList::GetEntry(int32 Index)
{
	if(GetEntries().IsValidIndex(Index))
	{
		return GetEntries()[Index];
	}
	return nullptr;
}

void UDataList::WidgetNotify(FName notify)
{
	for(auto* temp_entry: GetEntries())
	{
		if(temp_entry)
		{
			temp_entry->WidgetNotify(notify);
		}
	}
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
			return true;
		}
	}
	return false;
}

UDataWidget* UDataListFormat::OnReceiveInput_Navigation_Implementation(FVector2D Input2D, int32 Input1D, UDataList* List)
{
	int32 TempOutIndex;
	List->CycleEntry(Input1D,TempOutIndex);
	return nullptr;
}

void UDataListFormat::OnWidgetHovered_Implementation(UDataWidget* DataWidget, UPanelWidget* PanelWidget)
{
	
}


UPanelWidget* UDataListFormat::CreateWidget_Implementation(UDataList* OwningList)
{
	return nullptr;
}


void UDataListFormat::AddDataWidget_Implementation(UDataWidget* DataWidget, UPanelWidget* PanelWidget)
{
	if(DataWidget && PanelWidget)
	{
		PanelWidget->AddChild(DataWidget);
	}
}


//---------------------------------------------------------------------------------
/// Input 
//---------------------------------------------------------------------------------
void UDataList::InputNavigate_Implementation(FVector2D Axis)
{
	int32 AxisDirection = 0;

	//----------------- Set input direction -----------------//
		
	// Check for horizontal direction
	if (FMath::Abs(Axis.X) > FMath::Abs(Axis.Y))
	{
		AxisDirection=(Axis.X > 0) ? 1 : -1;
	}
	// Check for vertical direction
	else
	{
		AxisDirection=(Axis.Y > 0) ? 2 : -2;
	}

	//----------------- Try Run cycle -----------------//
	
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
		
		int32 TempOutIndex;
		if(ListFormat)
		{
			if(UDataWidget* new_hover = ListFormat->OnReceiveInput_Navigation(Axis,LocalAxis,this))
			{
				new_hover->Hover();
			}
		}
		else if(CycleEntry(int32(LocalAxis),TempOutIndex))
		{
			return;
		}
	}
	OnInputNavigate.Broadcast(Axis);
	//if failed cycle or not a valid input, try fo to nav overflow widget


	switch (AxisDirection)
	{
	case 1:
		OnNavigationOverflow.Broadcast(FVector2d(1,0));
		break;

	case -1:
		// Do something for Left direction
		OnNavigationOverflow.Broadcast(FVector2d(-1,0));
		break;

	case 2:
		// Do something for Up direction
		OnNavigationOverflow.Broadcast(FVector2d(0,1));
		break;

	case -2:
		// Do something for Down direction
		OnNavigationOverflow.Broadcast(FVector2d(0,-1));
		break;
	default: ;
	}
	
}

void UDataList::InputPage_Implementation(float Axis)
{
	if(CycleOnInputPage)
	{
		int32 CycleIndexOut;
		CycleEntry(int32(Axis),CycleIndexOut);
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

void UDataList::OnControlSetWidget_Implementation()
{
	if(bRememberIndexOnControlSet)
	{
		HoverEntry(RememberedHoverIndex);
	}
	else
	{
		HoverEntry(0,bRememberIndexOnControlSet);
	}
}

void UDataList::SetListOwner(UObject* NewOwner)
{
	if(NewOwner)
	{
		ListOwner = NewOwner;
		for(UDataWidget* TempEntry: Entries)
		{
			TempEntry->OnNewListOwner(ListOwner);
			TempEntry->Refresh();
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
	}

	//Use custom list format if valid
	if(ListFormat)
	{
		ListPanel = ListFormat->CreateWidget(this);
	}
	else
	{
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
	
	for (UPrimaryDataAsset* TempAsset : DefaultAssets)
	{
		AddAssetToList(TempAsset, DefaultListFlag);
	}
	for(auto* temp_entry : CustomEntryObjects)
	{
		if(temp_entry)
		{
			AddAssetToList(temp_entry,"");
		}
	}
	for (const FCustomAssetData& TempData : CustomEntries)
	{
		AddedCustomEntryToList(TempData, DefaultListFlag);
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
	
	// Set Source Assets on Linked Select Widgets
	for(auto* TempWig : LinkedSelectedWidgets)
	{
		if(TempWig)
		{
			TempWig->SetSourceAsset(DataWidget->ReferencedAsset);
		}
	}
	
	OnEntrySelected.Broadcast(DataWidget, DataWidget->GetAssetLabel(), DataWidget->ReferencedAsset, Entries.Find(DataWidget));
}

void UDataList::NativeEntityHover(UDataWidget* DataWidget, bool bIsHovered)
{
	if (bIsHovered)
	{
		HoveredEntry = DataWidget;

		// UnhoverAllWidgetsFirst
		for(auto* TempWig : GetEntries())
		{
			if(TempWig && DataWidget!=TempWig)
			{
				TempWig->Unhover();
			}
		}
		
		// Set Source Assets on Linked Hover Widgets
		for(auto* TempWig : LinkedHoverWidgets)
		{
			if(TempWig)
			{
				TempWig->SetSourceAsset(DataWidget->ReferencedAsset);
			}
		}

		if(ListFormat)
		{
			ListFormat->OnWidgetHovered(DataWidget,ListPanel);
		}
		else if(Format==EDataListFormat::Format_ScrollBox)
		{
			Cast<UScrollBox>(ListPanel)->ScrollWidgetIntoView(DataWidget);
		}

		//Update linked description box
		if(DescriptionTextBlock)
		{
			FText DumText;
			FText DumDesc;
			IDataInterface_General::Execute_GetGeneralDataText(DataWidget->ReferencedAsset, "DumLabel", this, DumText, DumDesc);
			DescriptionTextBlock->SetText(DumDesc);
		}
		
		if(bAutoSetControlOnHover)
		{
			GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->SetControlWidget(this);
		}
		RememberedHoverIndex = Entries.Find(DataWidget);
		OnEntryHovered.Broadcast(DataWidget, DataWidget->GetAssetLabel(), DataWidget->ReferencedAsset, RememberedHoverIndex);
	}
	else
	{
		FCustomAssetData LocalTempData;
		LocalTempData.Texture = nullptr;
		UGeneralDataObject* TempObject = Native_CreateCustomDataObject(LocalTempData);
		
		// Clear Linked Hover Widgets
		for(auto* TempWig : LinkedHoverWidgets)
		{
			if(TempWig)
			{
				TempWig->SetSourceAsset(TempObject);
			}
		}
		
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
	if(GetEntries().IsValidIndex(Index))
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

void UDataList::RefreshAllEntries()
{
	for(auto* TempEntry : GetEntries())
	{
		if(TempEntry)
		{
			TempEntry->Refresh();
		}
	}
}
