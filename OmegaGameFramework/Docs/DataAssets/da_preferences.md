# Game Preference

**Class:** `UGamePreference`
**Create:** Content Browser → Data Asset → `GamePreference`

Defines a single user-facing game setting — volume, difficulty, subtitles on/off, display brightness, etc. Preferences are stored as `FVector` values (up to three numeric axes per preference) and are persisted in the save file.

---

## Properties

| Property | Description |
|---|---|
| **Save to Config** | If enabled, the preference is also written to `OmegaPreferences.ini` on disk, so it persists outside the save system. |
| **Global** | If enabled, the preference is saved to the global save data (survives new game). If disabled, it's per-playthrough. |
| **Preference Script** | An instanced script object that defines the preference's type, valid values, and display logic. |

---

## Preference Script Events

Add a **Preference Script** and override these Blueprint events to fully control the preference's behavior:

| Event | Description |
|---|---|
| **Get Preference Type** | Return the UI type — slider, dropdown, toggle, etc. |
| **On Preference Value Updated** | Called whenever the value changes. Use this to apply the change immediately (e.g. set audio volume). |
| **Get Current Value** | Return the current value as an `FVector`. |
| **Get Default Value** | Return the default value used on first launch. |
| **Get Max Value** | Return the maximum allowed value (for sliders). |
| **Get Value Text** | Format the current value into display text (e.g. `"75%"`). |
| **Get Value String** | Return the current value as a plain string. |
| **Get Value String Options** | Return an array of strings for dropdown-style preferences. |

---

## Accessing Preferences at Runtime

Use the **F_Preferences** Blueprint function library or bind to `OnPreferenceValueUpdated` on the Game Manager Subsystem.

> See [Game Manager Subsystem — Game Preferences](../Subsystems/subsystem_gamemanager.md) for the full preference node reference.
