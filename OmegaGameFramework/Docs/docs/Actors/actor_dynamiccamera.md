# Dynamic Camera Actor

**Class:** `AOmegaDynamicCamera`
**How to create:** Blueprint subclass of `OmegaDynamicCamera`. Place in the level.

Dynamic Cameras feed into the **Player Subsystem's** camera system. The subsystem manages blending between multiple cameras — you don't need to activate or switch them manually. Just place them in the level and configure their properties; the subsystem's source/master/override system does the rest.

> See [Player Subsystem — Dynamic Camera](../Subsystems/subsystem_player.md) for how the blending system works.

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Priority** | Higher priority cameras are preferred as the active source. |
| **Camera Active** | Whether this camera is currently eligible to be the active source. |
| **Global Binding** | A name to register this camera globally, so other systems can find it by name. |
| **Interp Speed** | Overall blending speed when transitioning to/from this camera. |
| **Interp Speed Location** | Separate blending speed for position only. |
| **Interp Speed Rotation** | Separate blending speed for rotation only. |
| **Set Rotation to Player Control** | If enabled, the camera's rotation follows the player controller's control rotation instead of its own. |

---

## Blueprint Events to Override

| Event | Description |
|---|---|
| **Source Tick** | Called every frame when this camera is the active source. Use it to update camera position/rotation. Receives `DeltaTime`, the source player controller, and the player subsystem. |
| **Dyna Cam Get Components** | Return the Spring Arm and Camera components for the subsystem to use. Override if you have a non-standard component setup. |
| **On Begin as Target Camera** | Called when this camera becomes the active source camera. |
| **On End as Target Camera** | Called when this camera stops being the active source camera. |
| **On Gameplay Message Begin / End** | Called when a gameplay message starts or ends while this camera is active. |

---

## Built-in Components

| Component | Description |
|---|---|
| **Spring Arm** (`USpringArmComponent`) | Camera arm controlling distance and lag. |
| **Camera** (`UCameraComponent`) | The actual camera. |
