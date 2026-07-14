# Turn-Based Manager Component

**Component class:** `UTurnBasedManagerComponent`
**Add to:** Any actor that drives a turn-based combat system — typically a Gameplay System actor.

The Turn-Based Manager Component handles the full turn loop: maintaining a list of registered combatants, building a turn order, advancing through turns, activating abilities for the active member, and firing events at the start and end of each turn.

A related component, **UTurnTrackerComponent**, tracks how many turns have elapsed on individual combatants (useful for timed effects).

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Turn Ability** | The ability class that runs when a combatant's turn starts. This is what actually executes a turn (e.g. an ability that opens the action menu). |
| **Auto Advance Turn** | If enabled, the next turn starts automatically when the Turn Ability completes. |
| **Repeat Turn on Ability Cancel** | If the Turn Ability is cancelled, repeat the same combatant's turn instead of advancing. |
| **Generate Turn Order if Empty** | If the turn order runs out, automatically regenerate it from registered combatants. |
| **Next Turn Tags** | Gameplay Tag events fired on the active combatant when their turn begins. |
| **Repeated Turn Tags** | Gameplay Tag events fired when a combatant's turn repeats (cancelled ability). |
| **Tag Events on Turn Begin** | Events sent to the current turn member at turn start. |
| **Tag Events on Turn End** | Events sent to the current turn member at turn end. |
| **Tag Events on Turn Begin (Global)** | A global event fired via the Game Manager when any turn starts. |
| **Tag Events on Turn End (Global)** | A global event fired via the Game Manager when any turn ends. |

---

## Registering Combatants

Combatants must be registered before they can take turns.

| Node | Description |
|---|---|
| **Register Combatant** | Add a combatant to the registered pool. |
| **Unregister Combatant** | Remove a combatant from the pool. |
| **Clear Registered Combatants** | Remove all registered combatants. Pass a **Flag** and **Tags** to filter which ones to remove. |
| **Get Registered Combatants** | Returns all registered combatants. |

---

## Turn Order

| Node | Description |
|---|---|
| **Generate Turn Order** | Build the turn order list from currently registered combatants. The **Query — Combatant Acts First** delegate controls sort order. |
| **Add to Turn Order** | Add a specific combatant to the existing turn order. |
| **Remove from Turn Order** | Remove a specific combatant from the turn order. |
| **Remove Faction from Turn Order** | Remove all combatants of a given faction from the turn order. |
| **Clear Turn Order** | Empty the turn order without clearing registered combatants. |
| **Get Turn Order** | Returns the current ordered list of combatants. |
| **Get Turn Member at Index** | Returns the combatant at a specific position in the turn order. |

---

## Advancing Turns

| Node | Description |
|---|---|
| **Next Turn** | Move to the next combatant in the order and start their turn. Toggle **Generate if Empty** to auto-rebuild when the order runs out. |
| **Get Active Turn Member** | Returns the combatant whose turn is currently active. |

---

## Firing Events on Combatants

| Node | Description |
|---|---|
| **Fire Events on Combatants** | Send Gameplay Tag events to the currently active turn member. |
| **Fire Events on Faction** | Send Gameplay Tag events to all registered combatants of a specific faction. |
| **Set Turn Ability Class** | Change the Turn Ability class at runtime. |

---

## Events

| Event | Fires when... |
|---|---|
| `OnTurnStart` | A combatant's turn begins |
| `OnTurnEnd` | A combatant's turn ends |
| `OnAddedToTurnOrder` | A combatant is added to the order (provides the index) |
| `OnRemovedFromTurnOrder` | A combatant is removed from the order |
| `OnTurnOrderGenerated` | A new turn order is built |
| `OnTurnFail` | A turn action fails (provides a reason string) |

---

## Turn Tracker Component

**Component class:** `UTurnTrackerComponent`

Add this to individual combatant actors to count how many turns have elapsed. Useful for tracking the duration of status effects.

### Details Panel Properties

| Property | Description |
|---|---|
| **Elapse on Turn Start** | Count a turn when this combatant's turn starts. |
| **Elapse on Turn End** | Count a turn when this combatant's turn ends. |
| **Elapse Increment Value** | How much to add to the count each time it elapses. Default is `1`. |

### Nodes

| Node | Description |
|---|---|
| **Link to Turn Manager** | Connect this tracker to a Turn-Based Manager Component and a specific combatant. |
| **Set Source** | Set the source object that determines the starting turn count. Toggle **Init Turns** to initialize immediately. |
| **Init Turns** | Initialize the turn count from the source, optionally adding to the current value. |
| **Set Turns Elapsed** | Set the turn count directly. Toggle **Added** to add to the current value instead. |
| **Get Turns Elapsed** | Returns the current turn count. |

### Event

| Event | Fires when... |
|---|---|
| `OnTurnValueChanged` | The turn count changes |
