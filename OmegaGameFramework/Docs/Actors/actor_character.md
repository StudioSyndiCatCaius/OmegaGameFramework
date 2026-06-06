# Character Actor

**Class:** `AOmegaMinimalCharacter`
**How to create:** Blueprint subclass of `OmegaMinimalCharacter`.

The Omega Character is the base class for all humanoid or pawn-style characters in your game — players, NPCs, enemies, companions. It extends UE's standard `ACharacter` with identity, appearance, asset libraries, and AI state tree support.

---

## Built-in Components

| Component | Description |
|---|---|
| **Actor Identity** (`UGameplayActorComponent`) | Attaches an identity data asset, gameplay tags, zone, and subscripts to the character. |
| **State Tree** (`UStateTreeComponent`) | AI/behavior state machine component. |

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Preset** | A character configuration preset applied at BeginPlay. |
| **Appearance Override** | Override the character's appearance asset. |
| **Seed** | An integer seed used for randomizing appearance. |
| **Flags** | Custom bit flags stored on this character. |
| **Library — Animation** | Asset library for animation assets. Lets you retrieve animations by tag without hard references. |
| **Library — Sound** | Asset library for sounds. |
| **Library — Slate** | Asset library for UI brushes and icons. |
| **Named Lists** | Named lists of arbitrary objects attached to this character. |
| **Actor Relatives** | References to related actors (mounts, pets, attachments). |

---

## Nodes

| Node | Description |
|---|---|
| **Set Character Preset** | Apply a character preset asset at runtime. |
| **Set Character Appearance** | Change the character's appearance asset at runtime. |
| **Randomize Seed** | Generate a new random seed for appearance randomization. |
