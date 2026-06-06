# World Subsystem

**How to access:** Get World Subsystem → `OmegaSubsystem_World`

The World subsystem coordinates everything happening inside the current level. It resets each time a new level loads. Use it for activating gameplay modes, finding combatants, handling quests, travelling between levels, and broadcasting messages.

---

## Gameplay Systems

A **Gameplay System** is a Blueprint actor class that represents a mode your game can be in — a combat phase, a cutscene, a pause menu, a mini-game, etc. You activate one when you need it and shut it down when you're done. Only one instance of each class runs at a time.

### Activating and Shutting Down

| Node | Description |
|---|---|
| **Activate Gameplay System** | Starts a Gameplay System. Pass a **Context** object (whatever triggered it) and an optional **Flag** string. Returns the new instance. |
| **Shutdown Gameplay System** | Stops a running system. |

### Querying

| Node | Description |
|---|---|
| **Get Gameplay System** | Gets a specific active system by class. Also outputs a **Is Active** bool. |
| **Get Active Gameplay Systems** | Returns all currently running systems. |
| **Get Active Gameplay Systems With Interface** | Filters active systems by a UInterface they implement. |
| **Get Active Systems With Tags** | Returns systems matching a set of Gameplay Tags. |
| **Is System Tag Blocked** | Returns true if the given tag is currently blocked by a running system. |
| **Is System Tag Active** | Returns true if a system with the given tags is running. |

### Blocking with Tags

Each Gameplay System Blueprint has three tag settings in its Details panel:

| Property | What it does |
|---|---|
| **System Tags** | Tags that identify this system. Used by other systems to block it. |
| **Block System Tags** | While this system is active, any system whose tags appear here is shut down or prevented from starting. |
| **Blocked On System Tags** | This system will refuse to activate while another active system has any of these tags. |

**Event (on World Subsystem):** `OnGameplaySystemActiveStateChange` — fires whenever any system activates or shuts down.

---

## Combatants

Every actor with a **Combatant Component** registers here automatically. You never need to do this manually.

| Node | Description |
|---|---|
| **Get All Combatants** | Returns every Combatant Component currently active in the world. |
| **Run Custom Combatant Filter** | Passes a list of combatants through a `UCombatantFilter` Blueprint subclass to filter them (e.g. allies only, enemies in range). |

| Delegate | Fires when... |
|---|---|
| `OnCombatantRegistered` | A combatant begins play |
| `OnCombatantUnregistered` | A combatant ends play |
| `OnCombatantDamaged` | Any combatant takes damage |

---

## Quests

Quests are defined as `UOmegaQuest` data assets and tracked at runtime via the World Manager. Quest progress is automatically saved to the active save file.

| Delegate | Fires when... |
|---|---|
| `OnQuest_Start` | A quest becomes active |
| `OnQuest_End` | A quest finishes (completed or failed) |
| `OnQuest_Updated` | A quest's state changes mid-run |

> See **Quests.md** for the full quest system documentation.

---

## Zone Transit (Level Travel)

Move the player between levels or between named spawn points (`AOmegaZonePoint` actors) within a level. The system handles the full fade-out → load → spawn → fade-in sequence automatically.

| Delegate | Fires when... |
|---|---|
| `OnZone_PlayerSpawnAtPoint` | The player has arrived at the destination zone point |

---

## Gameplay Messages

Send broadcast text messages — dialogue lines, tutorial hints, notifications — that other systems can listen for. Multiple messages can be active at once.

| Node | Description |
|---|---|
| **Message Send** | Sends a message. Pass the text, a Category Tag, and optional metadata. Returns a message handle. |
| **Message End** | Manually ends a specific active message. |
| **Message Get First of Category** | Returns the first active message of a given category tag. |

| Delegate | Fires when... |
|---|---|
| `OnGameplayMessage_Begin` | A new message starts |
| `OnGameplayMessage_End` | A message ends |

---

## Global Actor Bindings

Store a named reference to an important actor so anything else can find it without a direct Blueprint reference.

| Node | Description |
|---|---|
| **Set Global Actor Binding** | Register an actor under a name. |
| **Clear Global Actor Binding** | Remove a named binding. |
| **Get Global Actor Binding** | Retrieve the actor by name. Returns null if not set. |

---

## Actor Groups

Add actors to groups identified by Gameplay Tags. Useful for selecting "all enemies in the room" or "all destructibles".

| Node | Description |
|---|---|
| **Set Actor Registered to Group** | Add or remove a single actor from a tag group. |
| **Set Actors Registered to Group** | Bulk add or remove a list. |
| **Clear Actor Group** | Remove all actors from a group. |
| **Get Actors in Group** | Get all actors in a group. |
| **Is Actor in Group** | Check if an actor belongs to a group. |

**Event:** `OnActorGroupChange` fires when an actor is added to or removed from a group.

---

## Actor Tagged Targets

Each actor can store named target references using Gameplay Tags as keys (e.g. a `Target.LockedOn` tag pointing to the enemy being aimed at).

| Node | Description |
|---|---|
| **Set Actor Tagged Target** | Assign a tagged target to an actor. Pass null to clear it. |
| **Get Actor Tagged Target** | Get the actor currently assigned under that tag. |

---

## Actor Parameters

Attach named values to any actor without modifying its Blueprint. Supports string, float, int, and bool.

| Nodes | Description |
|---|---|
| **Get/Set Actor Param (String/Float/Int/Bool)** | Read or write a named parameter on any actor. Get nodes take a default value returned when the key isn't set. |

---

## Actor Interaction

Trigger interactions between actors. The target actor needs an **Interactable Interface** (`IActorInterface_Interactable`) to respond.

| Node | Description |
|---|---|
| **Can Interact** | Checks if the target will currently accept an interaction. |
| **Perform Interaction** | Executes the interaction on the target. |

**Event:** `OnActorInteraction` fires whenever an interaction is performed.

---

## World Manager

The subsystem automatically spawns an `AOmegaWorldManager` actor into the level. You usually don't interact with it directly, but it has one notable setting:

| Property | Description |
|---|---|
| **Start With New Game** | If checked on the World Manager in your level, a blank new save game is created when this level starts. Useful for title screen levels. |

Access it via the **Get World Manager** node on the subsystem.
