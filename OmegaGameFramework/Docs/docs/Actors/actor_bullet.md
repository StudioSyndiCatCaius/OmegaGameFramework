# Bullet Actor

**Class:** `AOmegaBulletActor`
**How to create:** Blueprint subclass of `OmegaBulletActor`. Spawn using the **Spawn Bullet** function library node.

A projectile actor for any ranged attack — bullets, arrows, fireballs, missiles. It moves using a Projectile Movement Component, detects impacts via hit or overlap, plays cue effects, and can deal damage through the combatant system.

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Impact on Hit** | Trigger impact when the physics collision fires (e.g. hits a wall). |
| **Impact on Overlap** | Trigger impact when the overlap event fires. |
| **Impact Destroy** | How many impacts before the bullet is destroyed. Set to `1` for standard single-hit projectiles. |
| **Cue on Spawn** | A `AOmegaGameplayCue` class to spawn when the bullet is created (muzzle flash, launch effect). |
| **Cue on Impact** | A `AOmegaGameplayCue` class to spawn on impact (sparks, explosion, hit marker). |
| **Impact Effects** | Scripted effects to run on impact. |

---

## Blueprint Events to Override

| Event | When to override |
|---|---|
| **On Impact** | Called when the bullet hits something. Receives the hit actor and its Combatant Component. Apply damage, play effects, etc. |

---

## Nodes

| Node | Description |
|---|---|
| **Trigger Impact** | Manually trigger the impact logic on a specific actor. |

---

## Spawning Bullets

Use the **Spawn Bullet** node from `UOmegaBulletFunctions`:

| Node | Description |
|---|---|
| **Spawn Bullet** | Spawns a bullet of a given class at a transform, with an optional instigator combatant. Returns the spawned bullet. |

---

## Built-in Components

| Component | Description |
|---|---|
| **Sphere Component** | Collision sphere for overlap and hit detection. |
| **Projectile Component** | Controls movement speed, gravity, and bouncing. |
| **Instigator Combatant** | Reference to the combatant that fired this bullet. |
