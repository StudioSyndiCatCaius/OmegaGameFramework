# Animation Function Libraries

Covers: `F_Animation`, `F_Tick`, `F_LevelSequence`, `F_ScriptedAnim`

---

## Animation Functions (`UOmegaAnimationFunctions`)

| Node | Description |
|---|---|
| **Try Get Anim Instance From Object** | Returns an Animation Instance from any object (actor, component). Pass the expected anim class for auto-casting. |
| **Play Emote Animation** | Plays an emote montage on a character. |
| **Stop Emote Animation** | Stops a playing emote montage. |
| **Stop All Montages — Character** | Stops every active montage on a character. Pass a **Blend Out Time**. |

---

## Per-Frame Component Animation (`UOmegaFunctions_Tick`)

These nodes drive smooth component movement and rotation every tick. Call them from your Tick event or a Tick-capable Blueprint.

### Rotation
| Node | Description |
|---|---|
| **Rotate Component — Rotation Relative** | Rotates a component toward a target rotation using input-driven speed. |
| **Rotate Component — Towards Target** | Smoothly rotates a component to face a world position. Toggle which axes (X, Y, Z) to affect. |
| **Rotate Component — To Rotation** | Smoothly rotates a component to match a target rotator. |
| **Rotate Pawn — To Velocity** | Rotates a pawn to face the direction it is moving. |

### Translation
| Node | Description |
|---|---|
| **Move Component — To Mouse** | Moves a component to follow the mouse cursor in world space. Set **Plane Lock** axes to constrain movement. |
| **Move Component — Towards Target** | Smoothly moves a component toward a world position. Toggle which axes to affect. |
| **Move Character — Along Spline** | Moves a character along a spline using input. Pass **Distance Offset** and **Input Scale**. |

### Interpolation
| Node | Description |
|---|---|
| **Interp Scene Component** | Interpolates a component's transform to match another. Toggle location and rotation independently. |
| **Interp Spring Arm** | Interpolates a Spring Arm toward another, including arm length, socket offset, and target offset. |
| **Interp Camera** | Interpolates a Camera Component toward another, including FOV. |
| **Blend Dynamic Cameras** | Blends between a set of cameras by distance from a target location. |

---

## Level Sequence Functions (`UOmegaLevelSequenceFunctions`)

| Node | Description |
|---|---|
| **Does Sequence Have Mark** | Returns true (+ exec) if a Level Sequence contains a named mark/bookmark. |

---

## Scripted Animation (Async)

| Node | Description |
|---|---|
| **Play Scripted Animation** | Play a scripted animation sequence asynchronously on an instigator. Fires **On Finished** when complete. |
