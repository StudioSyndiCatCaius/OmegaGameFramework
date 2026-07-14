# Player, Input & Platform Function Libraries

Covers: `F_Player`, `F_Preferences`, `F_Platforms`, `F_AI`

---

## Player Functions (`UOmegaPlayerFunctions`)

| Node | Description |
|---|---|
| **Get Omega Player** | Returns the `AOmegaPlayer` pawn for the given local player index. |
| **Get All Omega Players** | Returns all local player pawns. |
| **Mouse Hit For Scene Capture** | Performs a line trace from the player's mouse through a Scene Capture Component's view (for in-world cameras/monitors). |
| **Mouse — Get Normalized Position** | Returns the mouse position normalized to 0–1 screen space. |
| **Offset Screen Position to World** | Converts a screen position to a world-space location with an optional offset. |
| **Get Rotation From 2D Direction** | Calculates a world rotation from two screen-space points, with start and end offsets. |
| **Was Key Just Pressed** | Returns true if a specific key was pressed this frame. |
| **Was Input Action Just Pressed** | Returns true if an Enhanced Input action was triggered this frame. |
| **Keys — Combine Pressed Weights** | Sums the weights of currently pressed keys from a weighted map. Toggle **Clamped** to keep result between 0 and 1. |
| **Get Key Axis** | Returns the axis value of a held key (e.g. analog stick tilt). Applies a deadzone. |
| **Get Keys From Input Action** | Returns all keys currently bound to an Enhanced Input action. |
| **Get First Device Key From Input Action** | Returns the first key bound to an action for a specific device type (gamepad or keyboard). |
| **Get Input Action Config** | Returns the full `FOmegaInputConfig` for an Enhanced Input action. |
| **Set Input Action Target Active** | Enable or disable a specific input action target on a player. |
| **Object Hog Input — Set** | Make a single object the exclusive consumer of input for a player. All other targets are blocked. |
| **Object Hog Input — Clear** | Release input hogging, restoring normal routing. |

---

## Preferences (`UOmegaFunctions_Preferences`)

Simple get/set wrappers for `UGamePreference` data assets. Each preference stores an `FVector` internally but these helpers expose common scalar types.

| Node | Description |
|---|---|
| **Bool — Get / Set** | Read or write a bool preference. |
| **Int — Get / Set** | Read or write an int preference. |
| **Float — Get / Set** | Read or write a float preference. |
| **String — Get / Set** | Read or write a string preference. |
| **Check Bool** | Read a bool preference with branching true/false exec pins. |
| **Check Int** | Compare an int preference to a value with exec branching. |
| **Apply Preset** | Apply a `UOmegaPreferencePreset` data asset, setting multiple preferences at once. |

---

## Platform Functions (`UOmegaPlatformFunctions`)

| Node | Description |
|---|---|
| **Get Current Platform Action Icon** | Returns an `FSlateBrush` icon for the button/key that triggers a given Enhanced Input action on the current device. |
| **Get Current Platform Key Icon** | Returns an `FSlateBrush` icon for a specific input key on the current platform. |
| **Get Key From Name** | Constructs an `FKey` from a name string. |
| **Get Current Platform Asset** | Returns the `UOmegaPlatformAsset` configuration for the current platform. |

---

## AI Functions (`UOmegaAIFunctions`)

| Node | Description |
|---|---|
| **Set State Tree Active** | Activates or deactivates an actor's State Tree component. |
