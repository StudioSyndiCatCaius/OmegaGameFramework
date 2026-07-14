# Calendar Data Assets

These assets define the structure of the in-game calendar. Together they build a hierarchy: **Periods** within **Days** within **Weeks** within **Months** within a full **Calendar**.

> See [Calendar Component](../Components/comp_calendar.md) for the component that uses these assets at runtime.

---

## Calendar

**Class:** `UOAsset_Calendar`
**Create:** Content Browser → Data Asset → `OAsset_Calendar`

The master calendar asset assigned to the Calendar Component. It defines the full time structure for a world.

### Properties

| Property | Description |
|---|---|
| **Day Periods** | Array of `UOAsset_DayPeriod` assets defining the time-of-day slots (e.g. Dawn, Morning, Afternoon, Dusk, Night). |
| **Weekdays** | Array of `UOAsset_Weekday` assets defining the days of the week. |
| **Months** | Array of `UOAsset_Month` assets defining the months of the year. |

### Blueprint Nodes (on the asset)

| Node | Description |
|---|---|
| **Get Month from Index** | Returns the `UOAsset_Month` at the given index. |
| **Get Weekday from Day Index** | Returns the `UOAsset_Weekday` for a day number, with optional offset wrapping. |

---

## Day Period

**Class:** `UOAsset_DayPeriod`
**Create:** Content Browser → Data Asset → `OAsset_DayPeriod`

A single named time-of-day slot. Create as many as your game needs (e.g. just Day/Night, or a detailed Morning/Noon/Afternoon/Evening/Night/Late Night split).

Implements `IDataInterface_General` — add a **Name**, **Description**, and **Icon** directly on the asset.

---

## Weekday

**Class:** `UOAsset_Weekday`
**Create:** Content Browser → Data Asset → `OAsset_Weekday`

A named day of the week. Implements `IDataInterface_General` for display name and icon.

---

## Day

**Class:** `UOAsset_Day`
**Create:** Content Browser → Data Asset → `OAsset_Day`

Represents a specific calendar day. Can be extended to carry day-specific events or data. Implements `IDataInterface_General`.

---

## Month

**Class:** `UOAsset_Month`
**Create:** Content Browser → Data Asset → `OAsset_Month`

Defines a month including how many days it has and any special named days within it.

### Properties

| Property | Description |
|---|---|
| **Number of Days** | How many days this month contains. |
| **Custom Days** | Map of day-number → `UOAsset_Day` for special/named days (holidays, festivals). |

### Blueprint Nodes (on the asset)

| Node | Description |
|---|---|
| **Get Day** | Returns the `UOAsset_Day` for a given day number. Returns null if that day isn't a named day. |

---

## Week

**Class:** `UOAsset_Week`
**Create:** Content Browser → Data Asset → `OAsset_Week`

A week definition for calendar systems. Typically configured inside the Calendar asset rather than used standalone.

---

## Setting Up a Calendar

1. Create `Day Period` assets for your time-of-day slots.
2. Create `Weekday` assets for each day of the week.
3. Create `Month` assets for each month, setting **Number of Days** and any special days.
4. Create a `Calendar` asset and assign all the above.
5. Assign the Calendar asset to a `Calendar Component` in your level.
