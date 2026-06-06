# Ability Actor

**Class:** `AOmegaAbility`
**How to create:** Make a Blueprint subclass of `OmegaAbility`.

Abilities are the core unit of gameplay actions — attacks, spells, skills, special moves, AI actions. An ability is activated on a **Combatant Component**, lives as an actor in the world while it runs, then destroys itself when finished or cancelled.

---

## Lifecycle

1. **Granted** — `SetAbilityGranted` on the Combatant Component adds the ability class to its pool.
2. **Activated** — `ExecuteAbility` on the Combatant starts it. The ability actor is spawned and `AbilityActivated` is called.
3. **Running** — `ActivatedTick` fires every frame while active.
4. **Finished** — Call `CompleteAbility` to end successfully, or `CancelAbility` to abort. `AbilityFinished` fires with a **Cancelled** bool.

---

## Blueprint Events to Override

| Event | When to override |
|---|---|
| **Ability Activated** | Set up the ability — play animations, apply effects, start timers. |
| **Ability Finished** | Clean up — stop sounds, remove effects. Receives a **Cancelled** bool. |
| **Activated Tick** | Per-frame logic while the ability runs. Receives **DeltaTime**. |
| **Can Activate** | Return false to block activation under certain conditions. |
| **Utility Check** | AI scoring — return a **Priority** value so the AI knows when to use this ability. |
| **On Combatant Notify** | React to notifies broadcast by the owning combatant. |
| **On Active Target Changed** | Called when the owner's active combat target changes. |
| **On Registered Target** | Called when a target is added to or removed from the owner's target list. |
| **On Substate Change** | Called when the ability transitions between substates. |

---

## Nodes

| Node | Description |
|---|---|
| **Complete Ability** | End the ability successfully. Destroys the actor. |
| **Cancel Ability** | Abort the ability. Destroys the actor. Fires `AbilityFinished` with Cancelled = true. |
| **Set Input Enabled for Owner** | Enable or disable input processing on the owner. |
| **Set Substate (Name / Index)** | Transition to a named or indexed substate. |
| **Get Ability Owner Character** | Returns the owning character actor. |
| **Get Ability Owner Player** | Returns the owning player controller (null if AI). |
| **Get Ability Owner Mesh** | Returns the owner's skeletal mesh. |
| **Get Ability Owner Character Move Component** | Returns the owner's Character Movement Component. |
| **Is Owner Falling** | Returns true if the owner is currently in the air. |
| **Is Ability in Cooldown** | Returns true if still in cooldown. |
| **Get Remaining Cooldown Values** | Returns the remaining cooldown as a normalized (0–1) value and in seconds. |
| **Get Equipment in Owner Slot** | Returns the item equipped in a specific slot on the owner. |

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Ability Tags** | Tags identifying this ability. Used for blocking and filtering. |
| **Cancel Abilities** | Abilities with these tags are cancelled when this ability activates. |
| **Block Abilities** | Abilities with these tags cannot activate while this is running. |
| **Required Owner Tags** | The owner combatant must have all these tags for activation to succeed. |
| **Restricted Owner Tags** | The owner combatant must NOT have any of these tags. |
| **Owner Tags While Active** | Tags granted to the owner combatant while this ability is active, removed on end. |
| **Substates** | Named states this ability can move through (e.g. `Charging`, `Firing`, `Recovering`). |

---

## Events

| Event | Fires when... |
|---|---|
| `OnAbilityFinished` | The ability completes or is cancelled |

---

## Read-Only Properties

| Property | Description |
|---|---|
| **Is Active** | True while the ability is running. |
| **Combatant Owner** | The Combatant Component that owns this ability. |
