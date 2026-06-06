# Widget: Menu

**Class:** `UMenu`
**Parent:** `UOmegaScreenWidget`
**Header:** `Source/OmegaGameFramework/Public/Widget/Menu.h`

---

## Overview

`UMenu` is the base class for all full-screen game menus (main menu, pause menu, inventory, etc.). It is managed by `UOmegaSubsystem_Player` — never add it to the viewport directly; always open it through the player subsystem.

---

## Opening and Closing

```
// Via subsystem (recommended)
UMenu* Menu = PlayerSubsystem->OpenMenu(UMyMenu::StaticClass(), Context, Tags, Flag);
Menu->CloseMenu(Tags, Context, Flag);
```

`CanCloseMenu(Tags, Context, Flag)` is a BlueprintNativeEvent you can override to conditionally block closing (e.g. prevent closing during a save prompt).

---

## Lifecycle Events

| Event | When |
|-------|------|
| `MenuOpened(Tags, Context, Flag)` | Called after open animation completes |
| `MenuClosed(Tags, Context, Flag)` | Called after close animation completes |
| `OnReset()` | Called by `Reset()`, use to restore default widget state |

---

## Open/Close Animations

| Property | Description |
|----------|-------------|
| `GetOpenAnimation()` (BlueprintImplementableEvent) | Return the UMG animation to play on open |
| `GetCloseAnimation()` (BlueprintImplementableEvent) | Return the UMG animation to play on close |
| `ReverseOpenAnimation` | Play open animation in reverse |
| `ReverseCloseAnimation` | Play close animation in reverse (default true) |
| `OpenCloseInterpTime` | Duration of opacity interpolation (default 0.2s) |
| `AutoInterpOpacityOnOpenClose` | Automatically interpolate opacity on open/close |
| `UpdateOpenCloseInterp(value)` | BlueprintImplementableEvent — respond to interp tick (0.0–1.0) |

Visibility automatically changes between `VisibilityOnOpen` (default `SelfHitTestInvisible`) and `VisibilityOnClose` (default `Collapsed`).

---

## Input

| Property | Description |
|----------|-------------|
| `CustomInputMode` | `UOmegaInputMode` data asset to apply while this menu is open |
| `InputBlockDelay` | Seconds to block input after opening (default 0.2) |

Input is blocked while the menu is animating closed (`bIsClosing`) or during the open delay. `InputBlocked()` reflects this.

---

## Parallel Gameplay System

| Property | Description |
|----------|-------------|
| `ParallelGameplaySystem` | A `AOmegaGameplaySystem` class to activate when this menu opens and shut down when it closes |
| `BlockedSystemTags` | Tags that will be blocked while this menu is open |

---

## Sound

| Property | Description |
|----------|-------------|
| `OpenSound` | Sound played on open |
| `CloseSound` | Sound played on close |
| `DefaultToStyleSounds` | Fall back to the OmegaSlateStyle asset sounds if no explicit sound is set |

---

## Wrapper Actor

Each menu can optionally spawn a companion actor into the world.

| Property | Description |
|----------|-------------|
| `WrapperChildActor` | Actor class to spawn as a child of the menu's wrapper |

`GetMenuWrapperActor()` returns the `AOmegaMenuWrapperActor` (which also has a `UCombatantComponent` for combat-menu interactions).

`GetMenuWrapperChildActor(Class)` returns the spawned child actor cast to the given class.

---

## Data List

`GetDefaultDataList()` is a BlueprintImplementableEvent. Return a `UDataList` widget to have the menu automatically route navigation input to it.

---

## Delegates

| Delegate | Description |
|----------|-------------|
| `OnOpened(Tags, Flag)` | Menu finished opening |
| `OnClosed(Tags, Context, Flag)` | Menu finished closing |

---

## IDataInterface_CommonMenu

Any object can implement this interface to supply entries to menus:

```cpp
TArray<UObject*> GetDataListEntries(UMenu* Menu);
```

`UOmegaCommonMenuDefinition` is a data asset that implements this interface, allowing menus to be populated entirely from a data asset without Blueprint code.

---

## IDataInterface_MenuSource

Objects implementing this can provide a menu class by name:

```cpp
TSubclassOf<UMenu> GetMenuClass(FName Name);
```
