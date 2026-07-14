# Widget: DataList

**Class:** `UDataList`

---

## Overview

`UDataList` is a list widget that creates one `UDataWidget` entry per source object. It handles entry creation, layout, hover/selection state, and navigation input automatically.

`UDataList` is commonly used inside a `UMenu` and returned by `GetDefaultDataList()` to receive automatic menu input routing.

---

## Setup (Details Panel)

| Property | Description |
|----------|-------------|
| **💜Entry Class** | The `UDataWidget` subclass spawned per entry. |
| **Format** | An instanced format object controlling layout: `DataListFormat_List`, `DataListFormat_ScrollList`, `DataListFormat_UniformGrid`, or `DataListFormat_Radial`. |
| **🔷Entries (Data Assets)** | Data assets added as entries automatically on construct. |
| **🔷Entries (Custom)** | Hand-authored custom entries (name/icon/description) without needing an asset. |
| **Entry Traits** | Instanced trait objects applied to every entry widget. |

---

## Populating the List

| Node | Description |
|----------|-------------|
| **Add Asset to List** | Appends a single object as a new entry; returns the created `UDataWidget`. |
| **Add Assets to List** | Adds an array of objects. Toggle **Clear List First**. |
| **Added Custom Entry to List** | Adds a hand-authored custom entry (no asset needed). |
| **Clear List** | Removes all entries. |
| **Remove Entry From List** | Removes the entry at an index. |
| **Remove Entry of Asset** | Removes the entry (or all entries) showing a given object. |

---

## Hover & Selection

The list tracks a **hovered** entry (navigation focus) and can **select** it (confirm).

| Node | Description |
|----------|-------------|
| **Hover Entry** | Set the hovered entry by index. Toggle **Use Last Index** to restore the previous hover. |
| **Get Hovered Entry** | Returns the currently hovered entry widget. |
| **Clear Hovered Entry** | Clears hover state. |
| **Select Hovered Entry** | Selects (confirms) the hovered entry. |
| **Select Entry** | Selects the entry at an index directly. |
| **Cycle Entry** | Move the hover by an amount (e.g. +1/-1); returns the new index. |
| **Get Entry / Get Entries / Get Entry Index** | Access entry widgets and their indices. |
| **Get Entries With Tag** | Filter entries by gameplay tag. |

---

## Delegates

| Delegate | Fires when... |
|----------|-----------|
| `OnEntrySelected` | An entry is selected/confirmed |
| `OnEntryHovered` / `OnEntryUnhovered` | Hover moves onto / off an entry |
| `OnEntryHighlighted` | An entry's highlight state changes |
| `OnEntryAdded` | A new entry widget is created |
| `OnNavigationOverflow` | Navigation goes past the first/last entry (use for chaining lists) |
| `OnInputNavigate` / `OnInputPage` / `OnInputCancel` | Routed menu input reached this list |

---

## Navigation

Navigation input (from the Player subsystem's `InputNavigate`) moves the hovered entry through the list; `InputConfirm` selects it. The list format controls wrap-around and layout direction.

---

## Filtering and Sorting

Before adding objects, use the `F_ObjectSorter` Blueprint library to sort or filter the array.
