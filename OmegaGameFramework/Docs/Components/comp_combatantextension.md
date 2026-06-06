# Combatant Extension Component

**Component class:** `UCombatantExtensionComponent`
**Add to:** Any actor that needs to hook into a Combatant Component's damage, attribute, or skill calculations without modifying the combatant itself.

The Combatant Extension Component is a bridge between an actor and a Combatant Component. Once linked, it can feed additional modifiers into that combatant's stat calculations and receive notifications when combat events happen. It's useful for things like a weapon actor that grants a damage bonus while held, or a status effect actor that reduces a stat.

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Is Attribute Modifier** | If enabled, this component contributes attribute modifiers to the linked combatant. Implement the attribute modifier interface in Blueprint to return your modifier values. |
| **Is Damage Modifier** | If enabled, this component can modify damage calculations for the linked combatant. |
| **Is Skill Source** | If enabled, this component can contribute additional skills to the linked combatant's skill pool. |

---

## Linking to a Combatant

| Node | Description |
|---|---|
| **Set Combatant** | Link this extension to a specific Combatant Component. Registers it as a modifier/skill source if those flags are on. |
| **Clear Combatant** | Unlink from the current combatant, removing any contributions. |

**Read only:**

| Property | Description |
|---|---|
| **Combatant Ref** | The Combatant Component this extension is currently linked to. |

---

## Blueprint Events (Override These)

These events are called automatically when the extension is linked and the relevant thing happens on the combatant:

| Event | When it's called |
|---|---|
| **On Combatant Setup** | Called when a combatant is successfully linked via Set Combatant. |
| **On Attribute Damaged** | Called when the linked combatant takes damage. Provides the attribute, final damage, instigator, damage type, and hit result. |
| **On Combatant Notify** | Called when the linked combatant fires a Notify. Provides the notify name and flag string. |
