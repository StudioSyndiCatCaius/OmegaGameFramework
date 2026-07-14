# Systems Function Libraries

Covers: `F_Quest`, `F_Message`, `F_Zone`, `F_Level`, `F_GlobalScripting`, `F_Process`

---

## Quest Functions (`UOmegaFunctions_Quest`)

| Node | Description |
|---|---|
| **Quest — Start** | Start a quest and get back the running `AOmegaQuestInstance`. |
| **Quest — End** | End a quest. Toggle **Complete** (true = success, false = fail). Returns true if it was active. |
| **Quest — Get All Active Instances** | Returns all currently running quest instances. |
| **Quest — Check Condition** | Test a quest against a condition object. Returns true/false. |
| **Quest — Filter** | From an array of quest assets, returns those matching a filter. Toggle **NOT** to invert. |

---

## Message Functions (`UOmegaFunctions_Message`)

| Node | Description |
|---|---|
| **Message — Send** | Broadcast a gameplay message with text, category tag, and metadata. Returns the message handle. |
| **Message — Finish** | End the current active message in a given category. Returns true if one was found. |
| **Message — Get Current** | Returns the current active message in a category, or null if none. |

---

## Zone & Level Travel (`UOmegaFunctions_Zone`)

| Node | Description |
|---|---|
| **Transit — To Point** | Travel the player to a specific `AOmegaZonePoint`. Toggle **Skip Fade** for instant travel. |
| **Transit — To Level** | Travel to a level by soft reference, spawning at a tagged zone point. |
| **Transit — To Level Named** | Same as above but uses a level name string. |
| **Actor in Zone** | Returns true if an actor is currently within a given zone. |
| **Filter Actors in Zone** | From an array, keeps only actors inside a zone. |
| **Level — Get Data** | Returns the `UOmegaLevelData` for a specific level soft reference. |
| **Level — Get Data Current** | Returns the level data for the currently loaded level. |
| **Zone — Get Current Loaded** | Returns the currently active `UOmegaZoneData`. |
| **Point — Get First of Zone** | Returns the first `AOmegaZonePoint` found in a zone. |
| **Is Loading** | Returns true if a zone transition is currently in progress. |

---

## Level Functions (`UOmegaLevelFunctions`)

| Node | Description |
|---|---|
| **Set World Paused** | Pause or unpause the entire world. |
| **Get Level Soft Ref From Name** | Converts a level name string to a soft level reference. |
| **Get Persistent World Asset** | Returns the current world as a hard reference. |
| **Get Persistent World Asset Soft** | Returns the current world as a soft reference. |
| **Sublevel — Get All** | Returns all sublevels in the current world. |
| **Sublevel — Set Loaded** | Load or unload a specific sublevel. |
| **Duplicate Current Level as Custom** | Captures the current level layout as a custom level object. |
| **Open Custom Level** | Loads and opens a custom level in a container level. |
| **Save Custom Level to JSON** | Serializes a custom level to a JSON string. |
| **Load Custom Level from JSON** | Deserializes a custom level from a JSON string. |
| **Is Level Instance Reference Valid** | Returns true if a level instance reference is valid and loaded. |

---

## Global Scripting (`UOmegaFunctions_GlobalScripting`)

| Node | Description |
|---|---|
| **Run Global Scripts** | Execute an array of `UOmegaGlobalScript` objects against the current world context. |
| **Run Global Conditions** | Evaluate an array of `UOmegaGlobalCondition` objects. Returns true if all pass. |

---

## Process Management (`UOmegaFunctions_Process`)

Launch and monitor external OS processes from Blueprint.

| Node | Description |
|---|---|
| **Launch External Process** | Launch an .exe or .bat file with command line arguments. Toggle **Launch Detached** and **Launch Hidden**. Returns a **Process Handle** and success bool. |
| **Is Process Running** | Returns true if the process is still active. |
| **Terminate Process** | Kill the process. Toggle **Kill Tree** to also terminate child processes. |
| **Get Process Return Code** | Returns the exit code once the process has ended. |
| **Close Process Handle** | Release the handle resource. Call this when done with a process. |
| **Is Process Handle Valid** | Returns true if the handle is still valid. |
