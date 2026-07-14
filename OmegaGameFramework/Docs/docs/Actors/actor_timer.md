# Timer Actor

**Class:** `AOmegaTimerActor`
**Place in level:** Yes, or spawn at runtime. Use for countdowns, timed events, challenge timers, ability cooldown displays.

A self-contained countdown timer that fires global events when it starts and ends. It can loop, play sounds at configurable thresholds, and send tag events to other actors when time is up.

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Duration** | Total countdown time in seconds. |
| **Auto Play** | If enabled, the timer starts automatically at BeginPlay. |
| **Loop** | If enabled, the timer restarts automatically when it reaches zero. |
| **Event Begin** | A named global event fired when the timer starts. |
| **Event End** | A named global event fired when the timer finishes. |
| **Events on Begin** | Tag events sent to specific actors when the timer starts. |
| **Events on End** | Tag events sent to specific actors when the timer ends. |
| **Play Sound** | Enable sound playback during countdown. |
| **Sound Default** | Sound played continuously or at regular intervals. |
| **Sound at Percent** | Sounds triggered at specific percentages of remaining time (e.g. a warning beep at 20%). |

---

## Nodes

| Node | Description |
|---|---|
| **Play Timer** | Start or restart the countdown from **Duration**. |
| **Stop Timer** | Stop the countdown early without firing the end event. |
| **Is Timer Playing** | Returns true if the timer is currently counting down. |

---

## Read-Only Properties

| Property | Description |
|---|---|
| **Time Remaining** | Seconds left on the countdown. Returns `0` when stopped. |
