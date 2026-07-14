# Player Actor (Player Controller)

**Class:** `AOmegaPlayer`
**How to create:** Blueprint subclass of `OmegaPlayer`. Set as the Player Controller class in your Game Mode.

The Omega Player is the Player Controller base class. It comes with a built-in Combatant Component, identity, asset squad, and entity instance management. It also manages which Gameplay Systems are active for this player.

---

## Built-in Components

| Component | Description |
|---|---|
| **Combatant** (`UCombatantComponent`) | The player's own combat stats, abilities, and inventory. |
| **Actor ID** (`UGameplayActorComponent`) | Player identity and tags. |
| **Asset Squad** (`UAssetSquadComponent`) | Party/squad data for this player. |
| **Entity Instances** (`UInstanceActorComponent`) | Manages actor instances spawned for this player. |

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Systems Auto** | Gameplay System classes to activate automatically when the player controller is created. |
| **Systems Persistent** | Gameplay Systems that persist and are regularly refreshed. |
| **Persistent System Frequency** | How often (in seconds) persistent systems are refreshed. |

---

## Nodes

| Node | Description |
|---|---|
| **Set System Active** | Activate or deactivate a single Gameplay System for this player. Pass context, flag, and metadata. |
| **Set Systems Active** | Activate or deactivate a list of Gameplay Systems at once. |
| **Is System Active** | Returns true if a specific Gameplay System class is currently active. |
