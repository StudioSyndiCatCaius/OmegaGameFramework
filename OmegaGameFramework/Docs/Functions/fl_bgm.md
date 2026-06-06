# F_BGM — Background Music

**Library class:** `UOmegaFunctions_BGM`

Thin wrappers over the BGM system on the Game Manager Subsystem. These nodes are simpler to call than going through the subsystem directly.

> See [DA_BGM](../DataAssets/da_bgm.md) for how to set up music assets.
> See [Game Manager Subsystem](../Subsystems/subsystem_gamemanager.md) for BGM delegate events.

---

| Node | Description |
|---|---|
| **BGM — Play** | Play a `UOmegaBGM` asset in a named slot tag. Toggle **Fade Previous** to fade out the current track first. |
| **BGM — Stop** | Stop playback. Toggle **Fade** for a smooth fade-out; set **Fade Time** in seconds. |
| **BGM — Pause** | Pause or resume playback. |
| **BGM — Lock** | When locked, all Play calls are ignored until unlocked. |
| **BGM — Get Current** | Returns the BGM asset currently playing in the given slot. |
