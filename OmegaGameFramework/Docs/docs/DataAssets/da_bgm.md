# BGM (Background Music)

**Class:** `UOmegaBGM`
**Create:** Content Browser → Data Asset → `OmegaBGM`

Defines a background music track for the BGM system. Supports standard Sound Wave assets and Metasound assets. Assign to the Game Manager Subsystem's BGM functions to play it.

---

## Properties

| Property | Description |
|---|---|
| **Sound** | The `USoundBase` asset (Sound Wave or MetaSound) to play. |
| **Loop Begin Time** | The point in seconds where the loop begins after the first playthrough. Use this for tracks that have an intro before looping. Set to `0` for an immediate loop. |
| **Loop End Time** | The point in seconds where playback jumps back to **Loop Begin Time**. Set to `-1` to disable looping and let the sound play to its natural end. |
| **BGM Script** | An optional instanced script for dynamic BGM selection by style. |

---

## BGM Script

The **BGM Script** (`UOmegaBGMScript`) lets you override which sound is played depending on a style tag. Override the **Get Sound by Style** Blueprint event to return a different `FSlateBrush` or sound depending on the context.

This is useful for music that has multiple versions — calm, combat, boss — that share the same loop structure.

---

## How to Use

1. Create a BGM data asset and assign a sound to it.
2. Call **BGM Play** on the Game Manager Subsystem, passing the asset and a slot tag.
3. The subsystem handles playback, fading, and slot memory automatically.

> See [Game Manager Subsystem — BGM](../Subsystems/subsystem_gamemanager.md) for the full BGM node reference.
