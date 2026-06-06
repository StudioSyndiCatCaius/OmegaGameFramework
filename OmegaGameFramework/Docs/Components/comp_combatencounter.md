# Combat Encounter Component

**Component class:** `UOmegaCombatEncounter_Component`
**Add to:** Any actor that manages a combat encounter — typically a game mode actor or a world manager.

The Combat Encounter Component manages the lifecycle of a combat encounter: spawning battler characters, assigning them to stages, playing intro sequences, starting BGM, and coordinating the turn flow. It works alongside the Turn-Based Manager Component but handles the higher-level setup of who's fighting and where.

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Default Encounter Class** | The encounter instance class to spawn when starting a new encounter. |
| **Battler Character Class** | The character class spawned for each combatant in the encounter. Must implement the Encounter Battler interface. |
| **Extra Battler Abilities** | Ability classes automatically granted to every spawned battler. |
| **Default Sequence Intro** | A Level Sequence to play as the encounter intro cinematic (if the encounter data doesn't specify its own). |
| **Default BGM** | Background music to play during the encounter (if the encounter data doesn't override it). |

---

## Starting and Ending

| Node | Description |
|---|---|
| **Start Encounter** | Begin a new encounter with a specific encounter class and stage. |
| **Start Encounter From Source** | Begin an encounter from a data asset that implements the encounter source interface (e.g. an enemy group asset). |
| **End Encounter** | Close the current encounter. |

---

## Stages

Stages represent phases or arenas within an encounter (e.g. different battle backgrounds, waves of enemies).

| Node | Description |
|---|---|
| **Get All Stages** | Returns all available encounter stages. |
| **Get Stage from ID** | Returns a specific stage by its Gameplay Tag ID. |
| **Get Current Stage** | Returns the stage that is currently active. |

---

## Battlers

| Node | Description |
|---|---|
| **Spawn Battler** | Manually spawn a battler character from a data asset. Specify their faction, transform, which stage transform point to use, and collision handling method. |
| **Get Current Encounter** | Returns the current active encounter instance. |
| **Get Encounter Sequence Intro** | Returns the intro Level Sequence for the current encounter. |
| **Get Encounter BGM** | Returns the BGM asset for the current encounter. |

---

## Events

| Event | Fires when... |
|---|---|
| `OnEncounterSpawned` | A battler character is spawned into the encounter |
