# Save & Entity Function Libraries

Covers: `F_Save`, `F_SaveAsync`, `F_Entity`

---

## Save Functions (`UOmegaSaveFunctions`)

> See [Save Subsystem](../Subsystems/subsystem_save.md) for the full save system reference. These are convenience nodes.

### Accessing the Active Save
| Node | Description |
|---|---|
| **Get Save — Game** | Returns the current `UOmegaSaveGame` (active per-playthrough save). Pass a subclass to auto-cast. |
| **Get Save — Global** | Returns the `UOmegaSaveGlobal` (persistent cross-playthrough save). Pass a subclass to auto-cast. |

### Starting Games
| Node | Description |
|---|---|
| **Create Game** | Creates a blank new save game object. |
| **Start Game** | Sets a save as the active save and begins the session. Toggle **Load Save Level** to send the player to the stored level. |

### Saving & Loading
| Node | Description |
|---|---|
| **Custom — Save Game** | Save any `USaveGame` object to a custom directory and file name. Returns success. |
| **Custom — Load Game** | Load any `USaveGame` from a custom path + file name. |
| **Custom — Load Game All in Path** | Load every save file found in a directory. Returns an array. |

### Tag-based Save Parameters
Quick integer and boolean values stored by Gameplay Tag on the active save, without needing a full custom save object.

| Node | Description |
|---|---|
| **Set Save Param Tag — Int** | Store an integer under a Gameplay Tag key. Toggle **Global** for global save. |
| **Set Save Param Tag — Bool** | Store a boolean under a Gameplay Tag key. |
| **Get Save Param Tag — Int** | Read an integer by tag. |
| **Get Save Param Tag — Bool** | Read a boolean by tag. |
| **Check Save Param Tag — Bool** | Read a boolean with a branching exec output (true/false pins). |
| **Check Save Param Tag — Int** | Compare a saved integer to a value with exec branching. |

### Path Helpers
| Node | Description |
|---|---|
| **Get Save Directory Path** | Returns the absolute path to the save game folder. |
| **Make Save File Path — Name** | Constructs a full file path from a directory and file name. |
| **Make Save File Path — Slot** | Constructs a full file path from a directory and slot number. |

---

## Async Save / Load (`F_SaveAsync`)

These are async Blueprint nodes — they complete on a separate thread and fire delegate pins when done.

| Node | Description |
|---|---|
| **Save Omega Game to Path** | Saves a `UOmegaSaveGame` to a custom file path asynchronously. Fires **On Saved** when complete. |
| **Load Omega Game From Path** | Loads a `UOmegaSaveGame` from a file path asynchronously. Fires **On Loaded** with the save object. |
| **Load All Omega Games in Path** | Loads all saves found in a directory asynchronously. Toggle **Recursive** to search subfolders. Fires **On Loaded** with an array. |

---

## Entity Functions (`UOmegaFunctions_Entity`)

Entities are individual persistent objects tracked in the save file by an ID. The ID can be a Data Asset, a Name, or a GUID.

### ID Conversions
| Node | Description |
|---|---|
| **Conv — DataAsset to Entity ID** | Creates an entity ID from a primary data asset. |
| **Conv — Name to Entity ID** | Creates an entity ID from a name string. |
| **Conv — GUID to Entity ID** | Creates an entity ID from a GUID. |
| **Conv — Entity ID to DataAsset / Name / GUID** | Convert an entity ID back to its original type. |

### Saving & Loading
| Node | Description |
|---|---|
| **Set Entity by ID** | Save an `FOmegaEntity` struct under an ID in the save. **Target** selects active or global save. |
| **Get Entity by ID** | Load an `FOmegaEntity` struct by ID. |

### Transform
| Node | Description |
|---|---|
| **Get Transform** | Returns the saved world transform for an entity. |
| **Set Transform** | Saves a world transform for an entity. |

### Integer Parameters
| Node | Description |
|---|---|
| **Get Save Entity Param** | Returns a named integer parameter on an entity. |
| **Set Save Entity Param** | Sets a named integer parameter. Toggle **Added** to add to the current value. |
| **Add Save Entity Param** | Adds a value to an existing integer parameter. |

### String Parameters
| Node | Description |
|---|---|
| **Get Save Entity Param String** | Returns a named string parameter on an entity. |
| **Set Save Entity Param String** | Sets a named string parameter. |

### Tags
| Node | Description |
|---|---|
| **Set Save Entity Tags** | Add or remove gameplay tags on an entity. |
| **Get Save Entity Tags** | Returns all gameplay tags on an entity. |
| **Save Entity Has Tags** | Returns true if an entity has the given tag. |
| **Save Entity Check Tag** | Checks for a tag with an exec branch. Toggle **Add if False** to add the tag if not present. |
