# Quest System

---

## Overview

The quest system tracks objectives and progress through `UOmegaQuest` data assets and their runtime `AOmegaQuestInstance` counterparts. Quest data is persisted in the active save file.

---

## Key Classes

| Class | Type | Description |
|-------|------|-------------|
| `UOmegaQuest` | Data Asset | Quest definition (static data) |
| `AOmegaQuestInstance` | Actor | Runtime quest state in the world |
| `UOmegaQuestTypeScript` | UObject (instanced) | Blueprint-extensible quest behavior |
| `FOmegaQuestData` | Struct | Serializable quest progress data |
| `EOmegaQuestStatus` | Enum | `Inactive`, `Active`, `Complete`, `Failed` |

---

## Quest Data Asset (`UOmegaQuest`)

Create via **Content Browser → Miscellaneous → Data Asset → OmegaQuest**.

Key properties:
- Display name and description (via `IDataInterface_General`)
- `UOmegaQuestTypeScript` instances — behavior scripts for custom quest logic
- Replayability flag — whether the quest can be started again after completion

---

## Quest Type Scripts (`UOmegaQuestTypeScript`)

Instanced objects on the quest data asset. Override these BlueprintNativeEvents:

| Event | Description |
|-------|-------------|
| `CanStartQuest(WorldManager, Quest)` | Guard condition — return false to block start |
| `OnQuestStarted(Instance, Quest)` | Called when quest becomes active |
| `OnQuestUpdated(Instance, Quest)` | Called when quest state changes |
| `OnQuestEnded(Instance, Quest, bSuccess)` | Called when quest completes or fails |

---

## Starting a Quest

Quests are started through `AOmegaWorldManager`:

```
WorldManager->Quest_Start(Quest, bResumeFromSave)
```

- Returns `AOmegaQuestInstance*` if successful
- Returns null if `Quest_CanStart` returns false (e.g. quest already active or scripts block it)
- `bResumeFromSave` — pass true when loading a save to restore existing progress

---

## Quest Status

| Function | Description |
|----------|-------------|
| `Quest_GetStatus(Quest)` | Returns `EOmegaQuestStatus` |
| `Quest_IsComplete(Quest)` | Returns true if status is `Complete` |
| `Quest_GetActive()` | Returns all active quest data assets |
| `Quest_GetInstance(Quest)` | Returns the runtime instance for a quest |
| `Quest_Stop(Quest, bFailed)` | Ends a quest (complete or failed) |

---

## Persistence

Quest progress is stored in `UOmegaSaveBase::quest_data` as `TMap<UOmegaQuest*, FOmegaQuestData>`. When `StartGame` loads a save, active quests are resumed automatically.

---

## Delegates (`UOmegaSubsystem_World`)

| Delegate | Signature | Description |
|----------|-----------|-------------|
| `OnQuest_Start` | `(AOmegaQuestInstance*, UOmegaQuest*)` | Quest became active |
| `OnQuest_End` | `(AOmegaQuestInstance*, UOmegaQuest*)` | Quest ended |
| `OnQuest_Updated` | `(AOmegaQuestInstance*, UOmegaQuest*)` | Quest state changed |

---

## Async Integration

Use `ListenFor_GlobalEvent` (see `AsyncFlow.md`) to await quest milestones fired via `FireGlobalEvent`, or bind directly to the quest delegates from a Gameplay System.
