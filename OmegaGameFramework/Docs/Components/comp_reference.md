# Reference Component

**Component class:** `UOmegaReferenceComponent`
**Add to:** Any actor that needs to be identified or found by a tag and/or numeric ID.

The Reference Component is a lightweight marker component (extends Arrow Component, so it's visible in the editor viewport). It stores a Gameplay Tag and an integer ID on an actor, making it easy to identify and find specific actors or mark points of interest.

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Tag** | A Gameplay Tag identifying this actor or reference point. |
| **ID** | An integer ID for numeric identification (e.g. waypoint 0, waypoint 1, waypoint 2). |

---

## Usage

- Place multiple Reference Components on an actor to mark multiple tagged points (attack sockets, spawn positions, waypoints).
- Use the tag and ID from Blueprint to filter or sort actors by reference type.
- Because it extends Arrow Component, you can read its **World Transform** to get the reference point's location and rotation.

No additional Blueprint nodes — access the **Tag** and **ID** properties directly off the component reference.
