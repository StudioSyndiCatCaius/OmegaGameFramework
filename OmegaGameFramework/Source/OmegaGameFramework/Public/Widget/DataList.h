// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "GameplayTagContainer.h"
#include "WidgetInterface_Input.h"
#include "Types/SlateEnums.h"
#include "Components/SlateWrapperTypes.h"
#include "Blueprint/UserWidget.h"
#include "Widget/DataWidget.h"
#include "Components/CanvasPanel.h"
#include "Data/GeneralDataObject.h"

#include "DataList.generated.h"

class SConstraintCanvas;
class UPanelWidget;
class UPrimaryDataAsset;
class UDataWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnEntrySelected, UDataWidget*, Entry, FString, Label, UObject*, Asset, int32, Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnEntryHovered, UDataWidget*, Entry, FString, Label, UObject*, Asset, int32, Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnEntryUnhovered, UDataWidget*, Entry, FString, Label, UObject*, Asset, int32, Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FOnEntryHighlighted, UDataWidget*, Entry, FString, Label, UObject*, Asset, int32, Index, bool, IsHighlighted);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDataListInputCancel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDataListInputPage, float, Axis);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDataListInputNavigate, FVector2D, Axis);

UENUM()
enum class EDataListFormat : uint8
{
	Format_Box				UMETA(DisplayName = "Box"),
	Format_ScrollBox		UMETA(DisplayName = "Scroll Box"),
	Format_UniformGrid		UMETA(DisplayName = "Uniform Grid"),
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UDataList : public UUserWidget, public IWidgetInterface_Input
{
	GENERATED_BODY()

public:

	///
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout")
	EDataListFormat Format;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout")
	TEnumAsByte<EOrientation> Orientation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout")
	TEnumAsByte<EHorizontalAlignment> EntryHorizontalAlignment;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout")
	TEnumAsByte<EVerticalAlignment> EntryVerticalAlignment;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout")
	FSlateChildSize EntrySize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout")
	bool bAutoSizeList;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Entry")
	TSubclassOf<UDataWidget> EntryClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Entry")
	TArray<UPrimaryDataAsset*> DefaultAssets;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Entry")
	bool bUseCustomEntries;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Entry")
	TArray<FCustomAssetData> CustomEntries;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Entry")
	int32 UniformGridMaxValue = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Entry")
	FString EntryLabel;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Entry")
	FGameplayTagContainer ListTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Entry")
	FString DefaultListFlag;

	UPROPERTY(EditDefaultsOnly, Category="Tooltip")
	TSubclassOf<UDataTooltip> OverrideEntryTooltip;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Entry")
	bool HighlightOnSelect;
	
	// Read Only
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
	
	UPROPERTY()
	UDataWidget* HoveredEntry;

	UFUNCTION(BlueprintPure, Category = "Ω|Widget|DataList")
	TArray<UDataWidget*> GetEntries();
	
	//Access Entires
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataList")
	void HoverEntry(int32 Index);
	
    UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Ω|Widget|DataList")
    UDataWidget* GetHoveredEntry();

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataList")
	void SelectHoveredEntry();

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataList")
	void SelectEntry(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataList")
	void CycleEntry(int32 Amount);

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Ω|Widget|DataList")
	int32 GetEntryIndex(UDataWidget* Entry);
	
	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Ω|Widget|DataList")
	UDataWidget* GetEntry(int32 Index);
	


	//INPUT
	virtual void InputNavigate_Implementation(FVector2D Axis) override;
	virtual void InputPage_Implementation(float Axis ) override;
	virtual void InputConfirm_Implementation() override;
	virtual void InputCancel_Implementation() override;

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
	UFUNCTION(BlueprintPure, Category = "Ω|Widget|DataList")
	TArray<UDataWidget*> GetEntiresWithTag(FName Tag, bool bInvertGet);

	UFUNCTION(BlueprintPure, Category = "Ω|Widget|DataList")
	bool AnyEntryHasTag(FName Tag);
};