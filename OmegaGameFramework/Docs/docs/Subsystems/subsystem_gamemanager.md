# Game Manager Subsystem

**How to access:** Get Game Instance → Get Subsystem → `OmegaSubsystem_GameInstance`

The Game Manager is the global, always-on subsystem. It starts when your game launches and never resets — not even when you load a new level. Use it for anything that needs to exist across the whole session.

---

## Gameplay Modules

Gameplay Modules are global singleton objects you create to manage a specific system (inventory, dialogue, achievements, etc.). You subclass `UOmegaGameplayModule` in Blueprint, and the subsystem keeps one instance of it alive forever.

| Node | Description |
|---|---|
| **Get Gameplay Module** | Returns the active instance of a module class. Pin the class and it auto-casts the output. |
| **Get Gameplay Modules** | Returns all active module instances as an array. |

---

## Background Music (BGM)

Plays background music using `UOmegaBGM` data assets. Music is organized into **slots** (a Gameplay Tag) so you can have multiple tracks (e.g. battle music, ambient music) and switch between them. Each slot remembers where playback stopped.

Use the **BGM** function library nodes (search "BGM" in the Blueprint palette):

| Node | Description |
|---|---|
| **BGM - Play** | Play a BGM asset in a slot. Toggle **Fade Previous** to fade out the current track first. |
| **BGM - Stop** | Stop music. Enable **Fade** for a smooth stop, with a customizable fade time. |
| **BGM - Pause** | Pause or resume the current track. |
| **BGM - Lock** | While locked, any Play calls are ignored. Useful during cutscenes. |
| **BGM - Get Current** | Returns the currently playing BGM asset and its slot. |

---

## Global Events

A simple event bus. Any Blueprint can fire a global event by name or tag, and any other Blueprint can listen for it — without needing a direct reference to each other.

| Node | Description |
|---|---|
| **Fire Global Event (Name)** | Broadcasts a named `FName` event. Pass a Context object (optional) and Meta for extra info. |
| **Fire Global Event (Tag)** | Same but uses a Gameplay Tag instead. |

**To listen:** Bind to `OnGlobalEvent` or `OnTaggedGlobalEvent` on this subsystem. Or use the **Wait For Global Event** async node (see AsyncFlow docs).

| Event/Delegate | Fires when... |
|---|---|
| `OnGlobalEvent` | Any named event is fired |
| `OnTaggedGlobalEvent` | Any tag-based event is fired |

---

## Machina (Simple State Machine)

Lets any object have a named "state" without you building a state machine from scratch. Set a state on any object (an actor, a component, a data asset) and react to changes.

Use the **Machina** function library nodes:

| Node | Description |
|---|---|
| **Machina - Set State** | Set an object's current state by name |
| **Machina - Get State** | Read an object's current state |
| **Machina - Can Set State?** | Check whether a state change is allowed |
| **Machina - Stop State** | End the object's current state |
| **Run Object Machina State** (async) | Set a state and get Begin/Tick/End pins for it |

---

## Global Variables (Soft Params)

A name → value map stored at the session level. Use it to share simple values globally without creating a custom subsystem.

> Use the **Global Param / Global Vars** function library nodes to get and set values.

The `OnGlobalParamEdit` event fires whenever a value changes, giving you the name, new value, old value, and scope.

---

## Load State

A text string describing what the game is currently doing. Useful for loading screens.

| Node | Description |
|---|---|
| **Set Load State String** | Set the string (e.g. `"Loading World"`, `"Connecting..."`). |

The current string is readable as `LoadStateString` (Blueprint Read Only).

---

## Game Preferences

User settings like volume or difficulty, defined as `UGamePreference` data assets and stored in the save file.

| Event/Delegate | Fires when... |
|---|---|
| `OnPreferenceValueUpdated` | Any preference value is changed |

> Use the **F_Preferences** function library to get and set values.

---

## Delegates

| Delegate | When it fires |
|---|---|
| `OnNewLevel` | A new level is loaded |
| `OnGlobalEvent` | A named global event fires |
| `OnTaggedGlobalEvent` | A tag-based global event fires |
| `OnGlobalParamEdit` | A global parameter changes |
| `OnPreferenceValueUpdated` | A game preference changes |
