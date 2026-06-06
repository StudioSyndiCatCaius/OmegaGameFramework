# Async Flow System (OmegaFlow)

**Module:** `OmegaFlow`
**Source:** `Source/OmegaFlow/Public/`

---

## Overview

OmegaFlow provides coroutine-style Blueprint nodes that suspend execution until a condition is met or an action completes. Each node is a `UBlueprintAsyncActionBase` subclass exposed to Blueprints as a latent async action.

This lets you write sequential gameplay logic in Blueprints without complex state machines:

```
Open Menu → Await Menu Closed → Play Sound → Await Sound → Trigger Next Phase
```

---

## Async Actions

### Ability

| Node | Description |
|------|-------------|
| `AsyncAction_ActivateAbility` | Activates a combatant ability and awaits its completion |
| `AsyncAction_ActivateGambit` | Activates a gambit (AI decision asset) and awaits result |

### Camera

| Node | Description |
|------|-------------|
| `AsyncAction_FadeCamera` | Fades the camera to/from black; completes when fade finishes |
| `AsyncAction_WaitForFadeState` | Suspends until the camera reaches a specific fade state |

### Gameplay Systems

| Node | Description |
|------|-------------|
| `AsyncAction_GameplaySystem` | Activates a `AOmegaGameplaySystem` and awaits its shutdown |

### HiStop

| Node | Description |
|------|-------------|
| `AsyncAction_Hitstop` | Pauses time for a set duration (hit-freeze effect) |

### Interpolation

| Node | Description |
|------|-------------|
| `AsyncAction_LerpCurve` | Ticks a float along a curve over time; outputs each tick value |

### Level Sequence

| Node | Description |
|------|-------------|
| `AsyncAction_LevelSequence` | Plays a Level Sequence and awaits its completion |

### Menus

| Node | Description |
|------|-------------|
| `AsyncAction_Menu` | Opens a `UMenu` and awaits its closure; outputs the menu reference |

### Movement

| Node | Description |
|------|-------------|
| `AsyncAction_MoveComponentBetweenTargets` | Moves a scene component between two target transforms |
| `AsyncAction_MovePawnAlongSpline` | Moves a pawn along a spline actor |

### Messages

| Node | Description |
|------|-------------|
| `AsyncAction_PlayGameplayMessage` | Sends a gameplay message and awaits its end event |

### Sound

| Node | Description |
|------|-------------|
| `AsyncAction_PlaySound` | Plays a sound and awaits its completion |

### Flow Graph

| Node | Description |
|------|-------------|
| `AsyncAction_StartFlowAsset` | Starts a Flow asset graph and awaits completion |

### Global Events / Flags

| Node | Description |
|------|-------------|
| `AsyncAction_WaitForGlobalEvent` | Suspends until a named global event fires |
| `AsyncAction_AwaitGlobalFlag` | Suspends until a named global flag reaches a target state |

---

## Listener Nodes

Listeners are persistent async nodes that repeatedly fire their output pins each time their event occurs (they don't complete and clean themselves up automatically — call `Cancel()` when done).

| Node | Fires When |
|------|-----------|
| `ListenFor_Actor` | A specific actor fires a named event |
| `ListenFor_DataWidget` | A data widget fires a specific event (hover, select, unhover) |
| `ListenFor_GlobalEvent` | A global event fires (name or tag) |
| `ListenFor_Message` | A gameplay message begins or ends |
| `ListenFor_TurnManager` | A turn-based manager fires a turn event |

---

## LocalTicker

`LocalTicker` is a lightweight tick helper that fires its output once per frame. Useful for driving per-frame logic from a Blueprint event graph without setting up a `Tick` override.

---

## Usage Tips

- Chain async actions with their completion pins for sequential logic
- Use `ListenFor_*` nodes in a `BeginPlay` or `Construct` event to set up ongoing listeners
- Cancel listeners explicitly (call the Cancel function on the returned handle) to avoid memory leaks
- Async actions respect the game's time dilation — if you pause the game, most actions pause too (check individual actions for pausing behavior)
