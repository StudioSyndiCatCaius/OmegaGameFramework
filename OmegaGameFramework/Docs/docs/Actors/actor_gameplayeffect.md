# Gameplay Effect Actor

**Class:** `AOmegaGameplayEffect`
**How to create:** Make a Blueprint subclass of `OmegaGameplayEffect`.

A Gameplay Effect is a triggered actor applied to a Combatant — damage-over-time, a stun, a buff, a poison, a burning field. It lives as an actor on the target, applies its effect, and self-destructs based on its lifetime mode.

---

## Lifetime Modes

Set **Effect Lifetime** in the Details panel:

| Mode | Behaviour |
|---|---|
| **Instant** | Triggers immediately on spawn and destroys itself. |
| **Timer** | Runs for a set **Lifetime** duration in seconds, then ends. |
| **On Trigger** | Stays alive until `TriggerEffect` is called manually. |
| **On Destroy** | Stays alive until the actor is otherwise destroyed. |

---

## Blueprint Events to Override

| Event | When to override |
|---|---|
| **Effect Begin Play** | Set up the effect — start particles, apply initial modifiers. Receives the context object and metadata. |
| **Effect Applied** | The effect has triggered. Receives the final damage value. |
| **Effect Can Apply** | Return false to block the effect from being applied. Check conditions here. |
| **Get Damage Type** | Return the `UOmegaDamageType` this effect uses for damage calculations. |
| **On Attribute Damaged** | Called when the effect deals attribute damage. |

---

## Nodes

| Node | Description |
|---|---|
| **Trigger Effect** | Manually fire the effect right now (used with On Trigger lifetime). |

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Effect Lifetime** | How long the effect lives (Instant / Timer / On Trigger / On Destroy). |
| **Lifetime** | Duration in seconds (only used with Timer mode). |
| **Effect Category** | A Gameplay Tag categorizing this effect. |
| **Effect Tags** | Tags identifying this effect — used for `HasEffectWithTags` queries and removal. |
| **Remove Effects on Applied** | Effects with these tags are removed from the target when this effect triggers. |
| **Block Effects** | Effects with these tags cannot be applied while this is active. |

---

## Read-Only Properties

| Property | Description |
|---|---|
| **Combatant Instigator** | The Combatant Component that created this effect. |
| **Targeted Combatant** | The Combatant Component this effect is running on. |
| **Effect Context** | The context object passed at creation. |

---

## Events

| Event | Fires when... |
|---|---|
| `OnEffectTriggered` | The effect fires its main trigger |
