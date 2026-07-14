# Calendar Component

**Component class:** `UOmegaCalendarComponent`
**Add to:** The World Manager actor (already included), or any actor that needs to track in-game time.

The Calendar Component tracks an in-game date using a structured calendar defined by data assets. Time is organized into **periods** (morning, afternoon, night) within **days** within **months** within **years**. Calling `AdvanceTime` moves through periods one at a time, automatically rolling over to the next day, month, or year when needed.

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Calendar Asset** | The `UOAsset_Calendar` data asset that defines the structure (how many months, days per week, period names, etc.). |
| **Use Save Data** | If enabled, calendar state is automatically saved and restored via the save system. |
| **Save Data Name** | The key used to store calendar data in the save file (only when **Use Save Data** is on). |

---

## Advancing Time

| Node | Description |
|---|---|
| **Advance Time** | Move forward one period. Automatically rolls over to the next day/month/year as needed. |
| **Set Time** | Set the full date at once. All parameters (period, day, month, year) are optional — only pass what you want to change. |
| **Set Period** | Jump to a specific period index within the current day. |
| **Set Day** | Jump to a specific day index within the current month. |
| **Set Month** | Jump to a specific month index. |
| **Set Year** | Jump to a specific year index. |

---

## Reading the Current Time

| Node | Description |
|---|---|
| **Get Current Time** | Returns the full current date as a struct. Pass an **Offset** to read a future/past date without changing the current one. |
| **Get Period Number** | Returns the current period index. |
| **Get Period Asset** | Returns the `UOAsset_DayPeriod` asset for the current period (has the name, icon, etc.). |
| **Get Day Number** | Returns the current day index. |
| **Get Day Asset** | Returns the `UOAsset_Day` asset for the current day. |
| **Get Month Number** | Returns the current month index. |
| **Get Month Asset** | Returns the `UOAsset_Month` asset for the current month. |
| **Is Current Time In Between** | Returns true if the current time falls between two given dates. |

**Standalone node (no component needed):**

| Node | Description |
|---|---|
| **Is Calendar Date In Between Time** | Pure function — check if any given date falls between two other dates. |

---

## Events

| Event | Fires when... |
|---|---|
| `OnPeriodChanged` | The time-of-day period changes |
| `OnDayChanged` | The day rolls over |
| `OnWeekChanged` | The week rolls over |
| `OnMonthChanged` | The month rolls over |
| `OnYearChanged` | The year rolls over |
