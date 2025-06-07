// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "GameplayTagContainer.h"
#include "LuaObject.h"
#include "Interfaces/OmegaInterface_Widget.h"
#include "Types/SlateEnums.h"
#include "Components/SlateWrapperTypes.h"
#include "Blueprint/UserWidget.h"
#include "Widget/DataWidget.h"
#include "Math/Vector2D.h"
#include "Components/CanvasPanel.h"
#include "Misc/GeneralDataObject.h"

#include "DataList.generated.h"

class SConstraintCanvas;
class UPanelWidget;
class UPrimaryDataAsset;
class UDataWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnEntrySelected, UDataWidget*, Entry, FString, Label, UObject*, Asset, int32, Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnEntryHovered, UDataWidget*, Entry, FString, Label, UObject*, Asset, int32, Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnEntryUnhovered, UDataWidget*, Entry, FString, Label, UObject*, Asset, int32, Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FOnEntryHighlighted, UDataWidget*, Entry, FString, Label, UObject*, Asset, int32, Index, bool, IsHighlighted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEntryNotify, UDataWidget*, DataWidget, FName, Notify);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDataListInputCancel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDataListInputPage, float, Axis);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDataListInputNavigate, FVector2D, Axis);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDataListNavigationOverflow, FVector2D, Axis);

UENUM()
enum class EDataListFormat : uint8
{
	Format_Box				UMETA(DisplayName = "Box"),
	Format_ScrollBox		UMETA(DisplayName = "Scroll Box"),
	Format_UniformGrid		UMETA(DisplayName = "Uniform Grid"),
};


UCLASS(BlueprintType, Blueprintable, Abstract, editinlinenew, CollapseCategories,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UDataListCustomEntry : public UPrimaryDataAsset, public IDataInterface_General
{
	GENERATED_BODY()
public:

};

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UDataList : public UUserWidget, public IWidgetInterface_Input
{
	GENERATED_BODY()

public:
	
	//###########################################
	// Class
	//###########################################

	UPROPERTY(EditInstanceOnly, Instanced, Category="List")
	UDataListFormat* ListFormat;
	
	//###########################################
	// Entry
	//###########################################
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "List",AdvancedDisplay)
	EDataListFormat Format;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "List",AdvancedDisplay)
	TEnumAsByte<EOrientation> Orientation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "List",AdvancedDisplay)
	TEnumAsByte<EHorizontalAlignment> EntryHorizontalAlignment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "List",AdvancedDisplay)
	TEnumAsByte<EVerticalAlignment> EntryVerticalAlignment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "List",AdvancedDisplay)
	FSlateChildSize EntrySize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "List")
	bool bAutoSizeList;

	//##### ENTRY CLASS #####//
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Entry")
	TSubclassOf<UDataWidget> EntryClass;
	UPROPERTY(EditAnywhere, Instanced, Category = "Entry")
	TArray<UDataWidgetMetadata*> EntryMetadata;

	UFUNCTION(BlueprintCallable, Category="Entry", meta=(AdvancedDisplay="KeepEntires"))
	void SetEntryClass(TSubclassOf<UDataWidget> NewClass, bool KeepEntries=true);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Entry",DisplayName="Entries (Data Assets)")
	TArray<UPrimaryDataAsset*> DefaultAssets;
	
	UPROPERTY(meta=(DeprecatedProperty))
	bool bUseCustomEntries;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category = "Entry",DisplayName="Entries (Custom)")
	TArray<UDataListCustomEntry*> CustomEntryObjects;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Entry",AdvancedDisplay)
	TArray<FCustomAssetData> CustomEntries;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "List")
	int32 UniformGridMaxValue = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Entry")
	FString EntryLabel;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "List",DisplayName="List Gameplay Tags")
	FGameplayTagContainer ListTags;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Entry")
    TArray<FName> EntryAutoTags;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Entry")
	FString DefaultListFlag;

	UPROPERTY(EditDefaultsOnly, Category="Tooltip")
	TSubclassOf<UDataTooltip> OverrideEntryTooltip;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Entry")
	bool HighlightOnSelect;

	UFUNCTION()
	void Native_WidgetNotify(UDataWidget* Widget, FName Notify);
	
	UPROPERTY(BlueprintAssignable)
	FOnWidgetNotify OnEntryNotifed;

	UFUNCTION(BlueprintCallable, Category="Entry")
	void RefreshAllEntries();

	UPROPERTY(EditAnywhere,Category="EntryOverrides")
	bool bCanOverrideSize;
	UPROPERTY(EditAnywhere,Category="EntryOverrides",meta=(EditCondition="bCanOverrideSize"))
	FVector2D OverrideSize;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Overrides")
	UMaterialInterface* Override_IconMaterial;
	UPROPERTY(EditAnywhere, Category="EntryOverrides")
	UCurveVector* OverrideHoverOffset_Curve;
	UPROPERTY(EditAnywhere, Category="EntryOverrides")
	FVector OverrideHoverOffset_Scale=FVector::One();

private:
	UFUNCTION()
	void SetNewControl(UUserWidget* NewWidget);
public:
	//###########################################
	// Entires - Read Only
	//###########################################
	UPROPERTY()
	TArray<UDataWidget*> Entries;

	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* ParentPanel;

	//Clears all ENTRIES from the list
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataList")
	void ClearList();

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataList")
	void RemoveEntryFromList(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataList")
	void RemoveEntryOfAsset(UObject* Asset, bool All);

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataList", meta=(AdvancedDisplay="Flag"))
	class UDataWidget* AddAssetToList(UObject* Asset, FString Flag);

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataList", meta=(AdvancedDisplay="Flag"))
	TArray<UDataWidget*> AddAssetsToList(TArray<UObject*> Assets, FString Flag, bool ClearListFirst=true);

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataList", meta=(AdvancedDisplay="Flag"))
	UDataWidget* AddedCustomEntryToList(FCustomAssetData EntryData, FString Flag);

	UFUNCTION()
	UGeneralDataObject* Native_CreateCustomDataObject(FCustomAssetData EntryData);
	
	UFUNCTION(BlueprintPure, Category = "Ω|Widget|DataList", DisplayName="Get Entries (Pure)")
	TArray<UDataWidget*> GetEntries();
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataList", DisplayName="Get Entries",meta=(DeterminesOutputType="Class"))
	TArray<UDataWidget*> GetEntries_Impure(TSubclassOf<UDataWidget> Class);
	
	UPROPERTY()
	UDataWidget* HoveredEntry;
	
	//Access Entires
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataList")
	void HoverEntry(int32 Index,bool UseLastIndex=false);

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataList")
	void ClearHoveredEntry();

private:
	UPROPERTY()
	int32 remembered_hover_index;
public:
	
    UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Ω|Widget|DataList")
    UDataWidget* GetHoveredEntry();

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataList")
	void SelectHoveredEntry();

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataList")
	void SelectEntry(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataList")
	bool CycleEntry(int32 Amount, int32& NewEntry);

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Ω|Widget|DataList")
	int32 GetEntryIndex(UDataWidget* Entry);
	
	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Ω|Widget|DataList")
	UDataWidget* GetEntry(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataList")
	void WidgetNotify(FName notify);
	
	//###########################################
	// Linked Widgets
	//###########################################

	// Widget the player's control will change to when input navigation in this direct goes over the max.
	UPROPERTY(BlueprintAssignable)
	FOnDataListNavigationOverflow OnNavigationOverflow;

	UPROPERTY(EditInstanceOnly, Category="Linked Widgets")
	TArray<UDataWidget*> LinkedSelectedWidgets;
	
	UPROPERTY(EditInstanceOnly, Category="Linked Widgets")
	TArray<UDataWidget*> LinkedHoverWidgets;

	//INPUT
	virtual void InputNavigate_Implementation(FVector2D Axis) override;
	virtual void InputPage_Implementation(float Axis ) override;
	virtual void InputConfirm_Implementation() override;
	virtual void InputCancel_Implementation() override;
	virtual void OnControlSetWidget_Implementation() override;

	//Automatically sets control to this list upon hovering an entry.
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Input")
	bool bAutoSetControlOnHover=true;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Input")
	bool bRememberIndexOnControlSet=true;

	UPROPERTY()
	int32 RememberedHoverIndex;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Input")
	bool CycleOnInputNavigate=true;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Input")
	bool CycleOnInputPage=false;

	//Owner
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataList")
	void SetListOwner(UObject* NewOwner);

	UPROPERTY(BlueprintReadOnly, Category="DataList")
	UObject* ListOwner;

	//DESCRIPTION
	UPROPERTY(EditInstanceOnly, Category="DataList")
	UTextBlock* DescriptionTextBlock;
	
protected:

	//virtual UClass* GetSlotClass() const override;
	virtual void NativePreConstruct() override;

	UFUNCTION()
	void RebuildList();

	UFUNCTION()
	class UPanelWidget* BuildList(TSubclassOf<UPanelWidget> Class);

	UPROPERTY()
	class UPanelWidget* ListPanel;

	UPROPERTY()
	int32 CurrentA;
	UPROPERTY()
	int32 CurrentB;

	UFUNCTION()
	void NativeEntitySelect(UDataWidget* DataWidget);

	UFUNCTION()
	void NativeEntityHover(UDataWidget* DataWidget, bool bIsHovered);

	UFUNCTION()
	void NativeEntityHighlight(UDataWidget* DataWidget, bool bIsHighlighted);

	//#####################################################
	// HIGHLIGHT
	//#####################################################

	UFUNCTION(BlueprintCallable, Category="DataWidget|Entity")
	void SetEntryHighlighted(int32 Index, bool bHighlighted);

	UFUNCTION(BlueprintCallable, Category="DataWidget|Entity")
	void SetAllEntriesHighlighted(bool bHighlighted);
	
	//Delegate Props

	UPROPERTY(BlueprintAssignable)
	FOnEntrySelected OnEntrySelected;
	UPROPERTY(BlueprintAssignable)
	FOnEntryHovered OnEntryHovered;
	UPROPERTY(BlueprintAssignable)
	FOnEntryUnhovered OnEntryUnhovered;
	UPROPERTY(BlueprintAssignable)
	FOnEntryHighlighted OnEntryHighlighted;

	UPROPERTY(BlueprintAssignable)
	FOnDataListInputCancel OnInputCancel;
	UPROPERTY(BlueprintAssignable)
	FOnDataListInputNavigate OnInputNavigate;
	UPROPERTY(BlueprintAssignable)
	FOnDataListInputPage OnInputPage;

	//---------------------------------------------------------------------------------------------//
	//	Tags
	//---------------------------------------------------------------------------------------------//
	UFUNCTION(BlueprintPure, Category = "Ω|Widget|DataList", DisplayName="Get Entries With Tag")
	TArray<UDataWidget*> GetEntiresWithTag(FName Tag, bool bInvertGet);

	UFUNCTION(BlueprintPure, Category = "Ω|Widget|DataList")
	bool AnyEntryHasTag(FName Tag);
};


UCLASS(EditInlineNew, Blueprintable,BlueprintType,CollapseCategories,Abstract)
class OMEGAGAMEFRAMEWORK_API UDataListFormat : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent,Category="DataList")
	void AddDataWidget(UDataWidget* DataWidget, UPanelWidget* PanelWidget);

	UFUNCTION(BlueprintNativeEvent,Category="DataList")
	UPanelWidget* CreateWidget(UDataList* OwningList);

	UFUNCTION(BlueprintNativeEvent,Category="DataList")
	void OnWidgetHovered(UDataWidget* DataWidget, UPanelWidget* PanelWidget);
	
	UFUNCTION(BlueprintNativeEvent,Category="DataList")
	UDataWidget* OnReceiveInput_Navigation(FVector2D Input2D, int32 Input1D, UDataList* List);
	
};