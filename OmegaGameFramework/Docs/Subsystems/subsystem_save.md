# Save Subsystem

**How to access:** Get Game Instance → Get Subsystem → `OmegaSaveSubsystem`

Handles all save and load functionality. It keeps two save objects alive at all times and provides everything you need to persist game state, story progress, and settings.

---

## Two Save Objects

Omega always maintains two saves simultaneously:

| Object | Description |
|---|---|
| **Active Save Data** (`UOmegaSaveGame`) | The current playthrough's data. Resets when you start a new game. Use this for character progress, quest state, collected items, etc. |
| **Global Save Data** (`UOmegaSaveGlobal`) | Cross-playthrough data that never resets. Use this for things like total play time, unlocked characters, or meta-progression. |

Most nodes have a **Global** boolean that controls which save object to operate on.

---

## What Gets Saved

Both save objects store the same categories of data:

| Category | What it holds |
|---|---|
| **Story Tags** | A `FGameplayTagContainer` you use to track story progress |
| **Story State** | A single `FGameplayTag` representing the current story state |
| **Playtime** | Automatically tracked total play time (`FTimespan`) |
| **Quest Data** | Quest progress for every `UOmegaQuest` asset |
| **Entities** | Saved entity references |
| **Preferences** | User preference values |
| **Variables** | Named key→value soft parameters |
| **Bit Flags** | Compact boolean storage (up to 255 per key) |
| **JSON Data** | Custom JSON for systems that opt in |

The per-playthrough save (`UOmegaSaveGame`) also stores:
- The last level the player was in
- The player's transform at save time
- Per-actor state and tag data
- BGM overrides

---

## Starting a Game

| Node | Description |
|---|---|
| **Create New Game** | Creates a blank save object. Does not start the game yet. |
| **Start Game** | Makes a save object active and begins the session. Set **New Game** to true when starting fresh. Enable **Load Saved Level** to send the player to the level stored in the save. |

**Typical new game flow:**
1. Call **Create New Game** → get a save object
2. Call **Start Game** with that object, **New Game** = true

**Event:** `OnNewGameStarted` fires after Start Game when New Game is true.

---

## Saving to a Slot

Slots can be a number or a name string — both work the same way.

| Node | Description |
|---|---|
| **Save Active Game (To Slot)** | Save to a numbered slot. Also takes a **Save Category** tag (e.g. `Save.Auto`, `Save.Manual`). Outputs **Success**. |
| **Save Active Game (To Name)** | Save to a named string slot. |
| **Save Global Game** | Save only the global save data. |

---

## Loading a Save

Loading returns the save object but does **not** make it active. Call **Start Game** afterward to use it.

| Node | Description |
|---|---|
| **Load Game Object (From Slot)** | Load a save from a numbered slot. Outputs **Success**. |
| **Load Game Object (From Name)** | Load from a named string slot. |
| **List Saved Games** | Returns an array of save objects found on disk. |
| **Get Save Slot List** | Returns saves within an index range. |
| **Get Save Slot Name** | Converts a slot number to the string name UE uses on disk. |

---

## Playtime

Playtime is tracked automatically while a save is active.

| Node | Description |
|---|---|
| **Get Save Playtime** | Returns the playtime as an `FTimespan`. |
| **Get Save Playtime String** | Returns a formatted string like `"02:34:17"`. Toggle **Include Milliseconds** as needed. |

---

## Story Tags

The main way to track story progress. Add tags when events happen ("boss defeated", "NPC talked to") and query them later.

| Node | Description |
|---|---|
| **Add Save Tags** | Add one or more Gameplay Tags to the save. |
| **Remove Save Tags** | Remove tags from the save. |
| **Get Active Save Tags** | Get all tags currently stored. |
| **Save Tags Match Query** | Test tags against a `FGameplayTagQuery` (supports AND / OR / NOT logic). |
| **Set Save State Tag** | Set a single "current state" tag (separate from the tag container). |
| **Get Save State** | Read the current state tag. |

**Event:** `OnSaveTagsEdited` fires whenever tags are added or removed.

---

## Per-Asset Save Tags

Associate Gameplay Tags with any Data Asset inside the save. Use this to track per-item or per-location state (e.g. a chest being opened, a collectible being picked up).

| Node | Description |
|---|---|
| **DataAsset - Edit SaveTags** | Add or remove tags on a specific data asset within the save. |
| **DataAsset - Has SaveTags?** | Check if a data asset currently has specific tags. |
| **DataAsset - Get w/ SaveTags** | Find all data assets in the save that have matching tags. |

---

## Story States

A Story State (`UOmegaStoryStateAsset`) is a data asset that runs **Script** objects when activated or deactivated. Scripts let you react to the state in Blueprint without manual event binding. They are saved to the save file.

**Create one:** Content Browser → Data Asset → `OmegaStoryStateAsset`, then add Script objects to it.

**Script events to override in Blueprint:**

| Event | When it's called |
|---|---|
| **Can Activate State** | Before activation — return false to block it |
| **On State Begin** | The state was activated |
| **On State End** | The state was deactivated |
| **On Level Change** | A level loads while this state is active |

| Node | Description |
|---|---|
| **Set Story State Active** | Activate or deactivate a story state asset. |
| **Is Story State Active** | Returns true if a state is currently active. |
| **Get Active Story States** | Returns all currently active story states. |
| **Clear All Story States** | Deactivates all story states at once. |

---

## Bit Flags

Compact boolean storage. Each "flag" is a number from 0–254. Multiple flags can be grouped under a name or GUID key so they don't collide with unrelated systems.

| Node | Description |
|---|---|
| **Set/Get Bit Flag** | Read or write a flag by index on the global flag store. |
| **Set/Get Bit Flag (Named)** | Read or write a flag under a named key. |
| **Set/Get Bit Flag (Guid)** | Read or write a flag under a GUID key. |

---

## Visibility on Save State Component

Add the **Visibility On Save** component (`UOmegaSaveStateComponent`) to any actor in your level to automatically show or hide it based on save tags — no Blueprint event binding required.

**Properties on the component:**

| Property | Description |
|---|---|
| **Visible (On Save Query)** | Actor is visible when this tag query matches the save |
| **Hidden (On Save Query)** | Actor is hidden when this query matches |
| **Global Save** | Check this to read from the global save instead of the active save |

---

## Delegates

| Delegate | Fires when... |
|---|---|
| `OnNewGameStarted` | A new game is started |
| `OnSaveStateChanged` | The story state tag changes |
| `OnSaveTagsEdited` | Story tags are added or removed |
