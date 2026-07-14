# Text, Localization & Conversion Function Libraries

Covers: `F_Text`, `F_Localization`, `F_Enum`, `F_Conv`

---

## Text Functions (`UOmegaTextFunctions`)

| Node | Description |
|---|---|
| **Apply Gameplay Text Formatting** | Applies tag-based formatting rules to a text value. Pass a **Tag** and **Meta** context. Returns the formatted `FText`. Useful for dynamic text substitution driven by data. |

---

## Localization & Voice (`UOmegaLocalizationFunctions`)

| Node | Description |
|---|---|
| **Get Language — Voice** | Returns the currently set voice language string (e.g. `"en"`, `"ja"`). |
| **Set Language — Voice** | Changes the active voice language. Affects which voice clips are selected from Sound Libraries. |
| **Play Voice Clip** | Plays a voice clip on an instigator actor. Pass a **Random Range** to pick from a range of lines. Toggle **Try Use Instigator Sound Library** to pull from the actor's own library. |
| **Get Voice Line** | Returns the `USoundBase` for a named voice line in the current language. |
| **Get Voice Cue** | Returns the sound for a voice cue by ID and clip name, using the current language. |

---

## Enum Functions (`UOmegaFunctions_Enum`)

| Node | Description |
|---|---|
| **Get Enum Value Description** | Returns the display description text of an enum value. Reads from the `DisplayName` metadata on the enum entry. |

---

## Conversion Functions (`UOmegaFunctions_Conv`)

| Node | Description |
|---|---|
| **Name Array to String Array** | Converts a `TArray<FName>` to a `TArray<FString>`. |
| **String Array to Name Array** | Converts a `TArray<FString>` to a `TArray<FName>`. |

## Bit Punning (`UOmegaFunctions_Punning`)

| Node | Description |
|---|---|
| **Int32 to Float** | Reinterprets an int32's raw bits as a float (bitwise cast, not a numeric conversion). |
| **Float to Int32** | Reinterprets a float's raw bits as an int32. |
