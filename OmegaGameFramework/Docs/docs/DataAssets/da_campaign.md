# Campaign

**Class:** `UOAsset_Campaign`
**Create:** Content Browser → Data Asset → `OAsset_Campaign`

Defines a story campaign — a named playthrough configuration that can be passed to `StartGame` on the Save Subsystem. The campaign ties together a primary quest and lifecycle scripts.

---

## Properties

| Property | Description |
|---|---|
| **Primary Quest** | The main `UOmegaQuest` that starts when this campaign begins. |
| **Scripts** | An array of instanced `UOAsset_Campaign_Script` objects that respond to campaign lifecycle events. |

---

## Campaign Script Events

Add a **Campaign Script** instance to the **Scripts** array and override these Blueprint events:

| Event | When it fires |
|---|---|
| **On Campaign Started** | The campaign just started for the first time (new game). |
| **On Campaign Loaded** | A save file for this campaign was loaded. |
| **On Campaign Saved** | The active game was saved while this campaign is running. |

---

## How to Use

1. Create a Campaign data asset.
2. Assign a primary quest.
3. Add script objects to respond to start/load/save events.
4. In Blueprint, call **Start Game** on the Save Subsystem and pass this asset as the **New Campaign** parameter.
