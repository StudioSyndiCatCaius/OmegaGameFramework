# Spawnable Actors

Omega provides two actors for placing spawnable entities in the world: a deterministic spawner and a randomized spawner.

---

## Actor Spawnable

**Class:** `AOmegaActorSpawnable`
**Place in level:** Yes. Use for enemies, NPCs, interactables, or any actor that should respawn.

Manages spawning and despawning a single actor instance. Configure the actor class and spawn settings in the Details panel, then call `Spawnable Spawn` to create it. Calling it again when the actor is already alive respawns it (useful for respawn timers).

### Details Panel Properties

| Property | Description |
|---|---|
| **Config** | The spawn configuration — actor class to spawn, flags, transform offset. |
| **Flag** | A string flag passed to the spawned actor at creation. |
| **ID** | Numeric identifier for this spawner. |

### Nodes

| Node | Description |
|---|---|
| **Spawnable Spawn** | Spawn (or respawn) the actor. Toggle **Force Respawn** to destroy and re-create even if already alive. |
| **Spawnable Destroy** | Destroy the spawned actor without respawning. |
| **Spawnable Is Alive** | Returns true if the spawned actor currently exists. |
| **Update World Label** | Refresh the editor debug label to reflect current config. |

### Built-in Components

| Component | Description |
|---|---|
| **Billboard** | Editor icon showing spawner position. |
| **Text Render** | Editor label showing config info. |
| **Arrow** | Direction indicator for spawn orientation. |

---

## Random Spawnable

**Class:** `AOmega_RandomSpawnable`
**Place in level:** Yes. Use for random encounter spots, random treasure, varied enemy types.

Picks a random actor from a weighted list and spawns it as a child actor. The chosen actor can be seeded from a global parameter for deterministic randomization (useful for saving which random actor was chosen).

### Details Panel Properties

| Property | Description |
|---|---|
| **Spawnable Config** | A weighted list of actor classes to randomly choose from. |
| **Seed Global Param Source** | Name of the global parameter source to use as a random seed. |
| **Seed Global Param Name** | Key within that source to read the seed value from. |
| **Preview** | Editor-only: index to preview in-editor without playing. |

### Built-in Components

| Component | Description |
|---|---|
| **Child Actor Component** | Hosts the randomly selected spawned actor. |
