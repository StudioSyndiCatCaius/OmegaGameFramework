# Asset Squad Component

**Component class:** `UAssetSquadComponent`
**Add to:** Any actor that manages an ordered group of data assets — a party system, a deck of cards, a skill loadout, a formation.

The Asset Squad Component organizes `UPrimaryDataAsset` objects into named squads with optional maximum sizes. Each squad has an ordered list of members, and members can be moved between squads or swapped in position.

---

## Details Panel Properties

| Property | Description |
|---|---|
| **One Squad Per Asset** | If enabled, each asset can only belong to one squad at a time. Adding it to a second squad removes it from the first. |
| **Bind to Save** | If enabled, squad data is automatically saved and loaded via the save system. |
| **Save Binding** | The name key used to store squad data in the save file (only used when **Bind to Save** is on). |

---

## Managing Squads

| Node | Description |
|---|---|
| **Set Member in Squad** | Add or remove a single asset from a specific squad. |
| **Set Members in Squad** | Add or remove a list of assets from a squad at once. |
| **Remove All Members from Squad** | Clear every member from a specific squad. |
| **Remove Member from All Squads** | Remove an asset from every squad it's in. |
| **Swap Squad Members** | Swap the positions of two assets (can be within the same squad or across squads). |
| **Current Squad - Set** | Set the "currently active" squad (useful for party-style systems where one squad is active at a time). |

## Querying Squads

| Node | Description |
|---|---|
| **Get Squad Members** | Returns all assets in a specific squad as an array. |
| **Get Member Squad** | Returns which squad a given asset belongs to. |
| **Get Member Index in First Squad** | Returns the position index of an asset in the first squad it's found in. |
| **Is Member in Squad** | Returns true if an asset is in a given squad. |
| **Can Add Member to Squad** | Returns true if the asset can be added (squad isn't full, member isn't already in it if One Squad Per Asset is on). |
| **Current Squad - Get** | Returns the currently active squad. |
| **Get Squad Data** | Returns the full squad data structure. |
| **Set Squad Data** | Replace the full squad data structure directly. |

---

## Events

| Event | Fires when... |
|---|---|
| `OnSquadMembersChanged` | An asset is added to or removed from any squad |
| `OnAssetSquadMembersSwapped` | Two assets swap positions |
