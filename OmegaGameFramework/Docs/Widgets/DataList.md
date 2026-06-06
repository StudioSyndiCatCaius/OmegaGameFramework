# Widget: DataList

**Class:** `UDataList`
**Header:** `Source/OmegaGameFramework/Public/Widget/DataList.h`

---

## Overview

`UDataList` is a scrollable list widget that creates one `UDataWidget` entry per item in a `TArray<UObject*>`. It handles entry creation, population, selection, and navigation input automatically.

`UDataList` is commonly used inside a `UMenu` and returned by `GetDefaultDataList()` to receive automatic menu input routing.

---

## Populating the List

| Function | Description |
|----------|-------------|
| `SetListItems(Objects)` | Replaces the current list with new objects, creating/destroying entry widgets as needed |
| `AddListItem(Object)` | Appends a single item |
| `ClearList()` | Removes all entries |

The list creates one instance of the configured **entry widget class** (a `UDataWidget` subclass) per item, then calls `SetData(Object)` on each entry.

---

## Selection

The list tracks a selected index and the corresponding `UDataWidget`.

| Function | Description |
|----------|-------------|
| `SetSelectedIndex(Index)` | Select by index; clamps to valid range |
| `GetSelectedIndex()` | Returns the current selected index |
| `GetSelectedItem()` | Returns the selected `UObject` |
| `GetSelectedWidget()` | Returns the selected entry widget |

**Delegate:** `OnSelectionChanged(DataList, SelectedObject, SelectedWidget)`

---

## Navigation

Navigation input (from `UOmegaSubsystem_Player::InputNavigate`) moves the selection through the list. The list respects wrap-around settings.

---

## Entry Widget Class

The list requires a `TSubclassOf<UDataWidget>` to know what type of widget to spawn per entry. Set this in the widget Blueprint's details panel or via `SetEntryWidgetClass`.

---

## Filtering and Sorting

Before passing objects to `SetListItems`, use the `F_ObjectSorter` Blueprint library to sort or filter the array.

---

## Integration with DataWidget Hover

When a list entry is hovered, the list forwards the hover to the player subsystem's hover tracking system. The currently hovered list entry is accessible via `GetCurrentHoverWidget()` on the player subsystem.
