# Gameplay Cue Actor

**Class:** `AOmegaGameplayCue`
**How to create:** Make a Blueprint subclass of `OmegaGameplayCue`, or spawn one using the `Play Gameplay Cue` Blueprint function library node.

A Gameplay Cue is a short-lived actor for visual and audio feedback — hit sparks, explosion effects, impact sounds, camera shakes. Cues are fire-and-forget: spawn one, it plays its effects, then optionally destroys itself.

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Attempt Autocomplete** | If enabled, the cue destroys itself automatically once all its particles and sounds have finished. |
| **Niagara Particles** | Array of Niagara particle systems to activate on spawn. |
| **Sounds** | Array of sounds to play on spawn. |
| **Camera Shake** | Camera shake to apply on spawn. |
| **Post Process** | Post-process settings to apply (e.g. a flash). |

---

## Spawning Cues

Rather than placing cues in the level, use the Blueprint function library:

| Node | Description |
|---|---|
| **Play Gameplay Cue** | Spawns a cue at a location. Pass the class, world context, transform, and optionally a hit result. |
| **Play Gameplay Cue from Config** | Spawns a cue from a pre-configured `FOmegaGameplayCueConfig` struct. |

---

## Read-Only Properties

| Property | Description |
|---|---|
| **Hit Data** | The `FHitResult` passed in when the cue was spawned. Useful for orienting effects to a surface normal. |

---

## Built-in Components

| Component | Description |
|---|---|
| **Niagara** | Niagara particle system component. |
| **Audio** | Audio component for playing sounds. |
| **Post Process** | Post-process component for visual effects. |
