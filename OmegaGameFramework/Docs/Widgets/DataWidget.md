# Widget: DataWidget

**Class:** `UDataWidget`
**Header:** `Source/OmegaGameFramework/Public/Widget/DataWidget.h`

---

## Overview

`UDataWidget` is a reusable widget designed to display a single `UObject` (typically a `UPrimaryDataAsset`). It is the building block for inventory cells, ability icons, list entries, tooltips, and any widget that maps to a data object.

The player subsystem tracks which `UDataWidget` the cursor is currently over, enabling a global hover state.

---

## Usage Pattern

1. Create a Blueprint subclass of `UDataWidget`
2. Override the `OnDataSet(Object)` event to populate your visual elements
3. Use in `UDataList` entries or place manually in a `UMenu`

---

## Core Interface

| Event | Description |
|-------|-------------|
| `OnDataSet(Object)` (BlueprintImplementableEvent) | Called when `SetData` assigns a new object |

| Function | Description |
|----------|-------------|
| `SetData(Object)` | Assign a data object to this widget |
| `GetData()` | Returns the currently assigned object |

---

## Hover State

The widget integrates with `UOmegaSubsystem_Player`:

- When the cursor enters the widget, it calls `SetCurrentHoverWidget(this)` on the player subsystem
- When the cursor leaves, it calls `TryUnhoverWidget(this)`
- Other systems query `GetCurrentHoverWidget()` to find the focused data object

The `DataWidgetSubsystemEvent` on the player subsystem fires for:
- `0` = selected
- `1` = hovered
- `2` = unhovered

---

## Slot Registration

Data widgets can be registered in named slots via `UOmegaSubsystem_Player::SlottedDataWidgets` (`TMap<FGameplayTag, UDataWidget*>`). This lets systems find a specific widget by tag rather than by reference.

---

## IWidgetInterface

`UDataWidget` participates in the `IWidgetInterface_Input` hierarchy, so it receives routed input from the player subsystem's `InputConfirm`, `InputCancel`, `InputNavigate`, etc.
