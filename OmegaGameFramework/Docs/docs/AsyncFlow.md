# Async Flow System (OmegaFlow)

**Module:** `OmegaFlow`

---

## Overview

OmegaFlow provides coroutine-style Blueprint nodes that suspend execution until a condition is met or an action completes. Each is a latent async action node in the Blueprint graph.

This lets you write sequential gameplay logic in Blueprints without complex state machines:

```
Open Menu → Await Menu Closed → Play Sound → Await Sound → Trigger Next Phase
```

---

## Async Actions

### Combat

| Node | Description |
|------|-------------|
| `AsyncAction_ActivateAbility` | Activates a combatant ability and awaits its completion |
| `OmegaCombatantSelectorAsync` | Runs a combatant selector and awaits the chosen target(s) |

### Camera

| Node | Description |
|------|-------------|
| `AsyncAction_FadeCamera` | Fades the camera to/from a color; completes when fade finishes |
| `AsyncAction_WaitForFadeState` | Suspends until the camera reaches a specific fade state |

### Gameplay Systems

| Node | Description |
|------|-------------|
| `AsyncAction_GameplaySystem` | Activates a Gameplay System and awaits its shutdown |

### Hitstop

| Node | Description |
|------|-------------|
| `AsyncAction_Hitstop` | Pauses time for a set duration (hit-freeze effect) |

### Interpolation & Animation

| Node | Description |
|------|-------------|
| `AsyncAction_LerpCurve` | Ticks a float along a curve over time; outputs each tick value |
| `AsyncAction_ScriptedAnimation` | Plays a scripted animation set and awaits completion |

### Level Sequence

| Node | Description |
|------|-------------|
| `AsyncAction_LevelSequence` | Plays a Level Sequence and awaits its completion |

### Menus

| Node | Description |
|------|-------------|
| `AsyncAction_Menu` | Opens a Menu widget and awaits its closure; outputs the menu reference |

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

### Save Files

| Node | Description |
|------|-------------|
| `AsyncAction_SaveGameToPath` | Saves the game to a file path and awaits the result |
| `AsyncAction_LoadOmegaGameFromPath` | Loads a save game object from a path |
| `AsyncAction_LoadAllOmegaGamesInPath` | Loads all save game objects found in a directory |

### Global Events / Flags

| Node | Description |
|------|-------------|
| `AsyncAction_WaitForGlobalEvent` | Suspends until a named global event fires |
| `AsyncAction_WaitForTaggedGlobalEvent` | Suspends until a tagged global event fires |
| `AsyncAction_AwaitGlobalFlag` | Suspends until a named global flag reaches a target state |

### Linear Events

| Node | Description |
|------|-------------|
| `AsyncPlayLinearEvent` / `AsyncPlayLinearEventSequence` | Plays one / a sequence of Linear Event objects and awaits completion |
| `AyncLinearChoice` | Presents a linear choice and awaits the player's selection |

---

## Listener Nodes

Listeners are persistent async nodes that repeatedly fire their output pins each time their event occurs (they don't complete and clean themselves up automatically).

| Node | Fires When |
|------|-----------|
| `ListenFor_ActorInteraction` | An actor interaction is performed |
| `ListenFor_ActorTagEvent` | An actor fires a tag event |
| `ListenFor_ActorTagTarget` | An actor's tagged target changes |
| `ListenFor_DataWidget` | A data widget fires an event (hover, select, unhover) |
| `ListenFor_GameMessage` | A gameplay message begins or ends |
| `ListenFor_GlobalEventNamed` | A named global event fires |
| `ListenFor_GlobalEventTagged` | A tagged global event fires |
| `ListenFor_TurnManager` | A turn-based manager fires a turn event |

---

## LocalTicker

`LocalTicker` is a lightweight tick helper that fires its output once per frame. Useful for driving per-frame logic from a Blueprint event graph without setting up a `Tick` override.

---

## Usage Tips

- Chain async actions with their completion pins for sequential logic
- Use `ListenFor_*` nodes in a `BeginPlay` or `Construct` event to set up ongoing listeners
- Async nodes are owned by the calling object — if it's destroyed, the listener stops
