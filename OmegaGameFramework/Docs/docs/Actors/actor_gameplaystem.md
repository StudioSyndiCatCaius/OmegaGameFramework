# Gameplay System Actor

**Class:** `AOmegaGameplaySystem`
**How to create:** Blueprint subclass of `OmegaGameplaySystem`. Never placed in a level — always activated through code or the World Subsystem.

A Gameplay System represents a discrete **mode** your game can be in. When active, it owns HUD layers, manages input, runs logic, and can block other systems. When shut down, it cleans everything up. Think: pause menu, turn-based combat phase, cutscene mode, item shop.

---

## Lifecycle

1. `ActivateGameplaySystem` is called on the World Subsystem.
2. The system spawns as a transient actor and `SystemActivated` fires.
3. The system runs, handling events and ticking.
4. `Shutdown` is called (by you or another system). `OnBeginShutdown` fires first.
5. Call `CompleteShutdown` from inside `OnBeginShutdown` to finish (or let the default complete it).
6. `SystemShutdown` fires and the actor is destroyed.

---

## Blueprint Events to Override

| Event | When to override |
|---|---|
| **System Activated** | Set up state, open menus, play music, add HUD layers. |
| **System Shutdown** | Clean up after shutdown is complete. |
| **On Begin Shutdown** | Pre-shutdown — play closing animations, then call `Complete Shutdown`. |
| **On Substate Change** | React to substate transitions (e.g. switching from `Setup` to `PlayerTurn`). |
| **On Actor Registered to Group** | An actor was added to or removed from a tag group. |
| **On Actor Identity Registered** | An actor with an identity component registered or unregistered. |
| **On Actor Tag Event** | An actor fired a tag event. |
| **On Actor Interaction** | An actor interaction was performed. |
| **On Gameplay Message** | A gameplay message was sent or ended. |
| **On Global Event / On Tagged Global Event** | A global event fired while this system is active. |
| **On New Game Started** | A new game was started while this system is active. |
| **Get Added HUD Layers** | Return additional HUD layer classes to add when this system activates (supplements the Details panel list). |

---

## Nodes

| Node | Description |
|---|---|
| **Shutdown** | Begin shutting down this system. Pass an optional context and flag. |
| **Complete Shutdown** | Call from inside `On Begin Shutdown` to signal that shutdown is ready to complete. |
| **Restart** | Shut down and immediately re-activate the system. |
| **Output Notify** | Broadcast a notification from this system (received by `OnSystemNotify`). |
| **Set Substate (Name / Index)** | Transition the system to a named or indexed substate. |
| **Get Substate Index** | Returns the current substate index. |
| **Get System Owning Player** | Returns the player controller associated with this system. |
| **Get System Owning Player — Pawn / Character / Combatant** | Convenience casts of the owning player. |

---

## Details Panel Properties

### Tags
| Property | Description |
|---|---|
| **System Tags** | Tags identifying this system. Other systems use these to block it. |
| **Block System Tags** | Any active system with tags in this list is shut down when this system starts. While this is active, those tags remain blocked. |
| **Blocked On System Tags** | This system will not activate if any running system has these tags. |
| **Global Events On Activate** | Tag-based global events fired automatically when this system activates. |
| **Global Events On Shutdown** | Tag-based global events fired automatically when this system shuts down. |

### Player
| Property | Description |
|---|---|
| **Player Input Mode** | An `UOmegaInputMode` data asset applied to the player when this system activates. |
| **Added Player Widgets** | HUD layer classes added to the player's screen when this system is active, removed on shutdown. |
| **Add Player Input Mapping** | Enhanced Input mapping contexts added while this system is active. |
| **Widgets on Player Screen** | If true, added widgets go on the player's screen. If false, they go in world space. |

### Substates
| Property | Description |
|---|---|
| **Substates** | Named states this system can be in (e.g. `Setup`, `PlayerTurn`, `EnemyTurn`, `Results`). |

---

## Read-Only Properties

| Property | Description |
|---|---|
| **Context Object** | The `UObject` passed in when this system was activated. |
| **Activation Flag** | The `FString` flag passed at activation. |
| **System Meta** | The `FOmegaCommonMeta` metadata passed at activation. |

---

## Events

| Event | Fires when... |
|---|---|
| `OnSystemNotify` | `OutputNotify` is called on this system |
| `OnSystemShutdown` | The system finishes shutting down |
