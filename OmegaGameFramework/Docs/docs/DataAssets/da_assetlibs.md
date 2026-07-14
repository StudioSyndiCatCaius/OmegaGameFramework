# Asset Library Data Assets

Asset Libraries are lookup tables for assets (animations, sounds, UI brushes). Rather than storing direct asset references everywhere, you store them in a library and retrieve them by name or Gameplay Tag at runtime. This makes it easy to swap out an entire character's assets just by swapping their library.

All three library types support a **Fallback** library — if the requested asset isn't found in this library, the fallback is checked instead. This makes inheritance easy (a specific character library falls back to a default library).

---

## Animation Library

**Class:** `UOmegaAssetLibrary_Animation`
**Create:** Content Browser → Data Asset → `OmegaAssetLibrary_Animation`

Stores animation sequences, montages, level sequences, and blend spaces, all retrievable by name or Gameplay Tag.

### Properties

| Property | Description |
|---|---|
| **Fallback** | Another Animation Library to check if an asset isn't found here. |
| **Anims Named** | Map of `FName` → `UAnimSequence`. |
| **Anims Named Lists** | Map of `FName` → `TArray<UAnimSequence>`. |
| **Montages Named** | Map of `FName` → `UAnimMontage`. |
| **Montages Named List** | Map of `FName` → `TArray<UAnimMontage>`. |
| **Level Sequences Named** | Map of `FName` → `ULevelSequence`. |
| **Level Sequences Named List** | Map of `FName` → `TArray<ULevelSequence>`. |
| **Blend Space Named** | Map of `FName` → `UBlendSpace`. |
| **Aim Blend Space Named** | Map of `FName` → `UAimOffsetBlendSpace`. |
| **Anim Sequences** (tagged) | Map of `FGameplayTag` → `UAnimSequence`. |
| **Montages** (tagged) | Map of `FGameplayTag` → `UAnimMontage`. |
| **Level Sequences** (tagged) | Map of `FGameplayTag` → `ULevelSequence`. |
| **Blend Spaces** (tagged) | Map of `FGameplayTag` → `UBlendSpace`. |

### Blueprint Nodes (on the asset)

| Node | Description |
|---|---|
| **Get Animation Named** | Returns an animation by name. Toggle **Random from List** to pick randomly from a named list. |
| **Get Montage Named** | Returns a montage by name. Toggle **Random from List** for list variant. |
| **Get Level Sequence Named** | Returns a level sequence by name. |
| **Get Blend Space Named** | Returns a blend space by name. |
| **Get Aim Offset Named** | Returns an aim offset blend space by name. |
| **Get Animation Named List** | Returns the full array for a named animation list. |
| **Get Montage Named List** | Returns the full array for a named montage list. |
| **Get Level Sequence Named List** | Returns the full array for a named level sequence list. |

---

## Sound Library

**Class:** `UOmegaAssetLibrary_Sound`
**Create:** Content Browser → Data Asset → `OmegaAssetLibrary_Sound`

Stores sound assets retrievable by name or Gameplay Tag.

### Properties

| Property | Description |
|---|---|
| **Fallback** | Another Sound Library to check if a sound isn't found here. |
| **Voice ID** | Identifier for localized voice selection. If blank, uses the asset's label. |
| **Default Sound** | The sound returned when no other match is found. |
| **Sounds Named** | Map of `FName` → `USoundBase`. |
| **Sounds Tagged** | Map of `FGameplayTag` → `USoundBase`. |

### Blueprint Nodes (on the asset)

| Node | Description |
|---|---|
| **Get Sound Named** | Returns a sound by name. Falls back to the fallback library if not found. |

---

## Slate Brush Library

**Class:** `UOmegaAssetLibrary_SlateBrush`
**Create:** Content Browser → Data Asset → `OmegaAssetLibrary_SlateBrush`

Stores UI brush assets (icons, portraits, textures) retrievable by name or Gameplay Tag.

### Properties

| Property | Description |
|---|---|
| **Fallback** | Another Slate Brush Library to check if a brush isn't found here. |
| **Fallback to Icon** | If enabled and no brush is found, falls back to a default icon. |
| **Default Brush** | The brush returned when no other match is found. |
| **Brushes Named** | Map of `FName` → `FSlateBrush`. |
| **Brushes Tagged** | Map of `FGameplayTag` → `FSlateBrush`. |

### Blueprint Nodes (on the asset)

| Node | Description |
|---|---|
| **Get Brush Named** | Returns a slate brush by name. |

---

## Usage Pattern

The typical setup for a character:
1. Create one Animation Library, one Sound Library, and one Slate Brush Library for the character.
2. Fill them with the character's assets.
3. Assign them to the character's `UOAsset_Appearance` asset.
4. At runtime, retrieve assets by calling **Get Montage Named** etc. on the library reference, or via the character's Appearance component.
