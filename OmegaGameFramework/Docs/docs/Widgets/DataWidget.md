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
2. Override the `OnSourceAssetChanged(Asset)` event to populate your visual elements
3. Use in `UDataList` entries or place manually in a `UMenu`

---

## Core Interface

| Event | Description |
|-------|-------------|
| `OnSourceAssetChanged(Asset)` | Called when a new source object is assigned |
| `OnRefreshed(SourceAsset, ListOwner)` | Called when the widget refreshes — re-read display data here |
| `OnHoverStateChange(Hovered)` / `OnHoverUpdate(Value)` | React to hover begin/end and the blended hover value |
| `OnHighlightStateChange(Highlight)` | React to highlight changes |

| Function | Description |
|----------|-------------|
| `SetSourceAsset(Asset)` | Assign a data object to this widget |
| `Refresh()` | Force the widget to re-read its source and fire `OnRefreshed` |
| `WidgetNotify(Notify)` | Broadcast a named notify (fires the `OnWidgetNotify` delegate) |

Display info (name, description, icon) is read from the source object via the General data interface, so most data assets work out of the box.

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
