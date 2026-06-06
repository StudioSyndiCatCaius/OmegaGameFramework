# Clock Component

**Component class:** `UOmegaClockComponent`
**Add to:** Any actor that needs to track real elapsed time in-game (ability cooldowns, timed events, countdowns).

The Clock Component is a simple real-time stopwatch. It counts up from zero, fires an update event at a configurable rate, and can be started or stopped at any time.

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Auto Start** | If enabled, the clock starts counting automatically when the actor begins play. |
| **Update Rate** | How often the clock fires its update event, in seconds. Default is `0.01` (every tick). Increase this for less frequent updates (e.g. `1.0` for once per second). |

---

## Nodes

| Node | Description |
|---|---|
| **Set Clock Playing** | Start or stop the clock. Pass `true` to start, `false` to stop. |
| **Get Time** | Returns the total elapsed time as an `FTimespan`. |
| **Is Clock Playing** | Returns true if the clock is currently counting. |

---

## Events

| Event | Fires when... |
|---|---|
| `OnClockUpdate` | Fires at the configured Update Rate with the current elapsed time |
| `OnClockStateChange` | Fires when the clock starts or stops |
