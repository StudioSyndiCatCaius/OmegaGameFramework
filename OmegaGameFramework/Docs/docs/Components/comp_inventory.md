# Inventory (Interfaces & Assets)

Omega's inventory system is interface-based rather than a single component. Items are `UPrimaryDataAsset` objects and any object can act as an inventory source by implementing the right interface.

> For per-combatant inventory (adding, removing, and transferring items), see the **Inventory** section in [Combatant Component](comp_combatant.md). The Combatant Component has a full built-in inventory.

---

## IDataInterface_InventorySource

Any object (actor, component, data asset) can implement this interface to expose an inventory.

| Method | Description |
|---|---|
| **Get Inventory** | Returns a `TMap` of data assets to quantities representing the inventory contents. |

---

## IDataInterface_InventoryItem

Implement this on an item data asset to define its collection rules.

| Method | Description |
|---|---|
| **🧪Inventory Item - Get Max Amount** | Returns the maximum number of this item that can be held at once. |
| **🧪Inventory Item - Get Size Per Max** | Returns how much "space" each unit of this item takes. |
| **🧪Inventory Item - Get Trade Requirements** | Returns what assets are required to trade for this item. Pass a **Trade Tag** to support multiple trade types. |

---

## UOmegaCommonInventory (Data Asset)

A simple data asset containing a fixed map of items and quantities. Use it to define loot tables, shop stock, starting inventories, or reward bundles — then implement `IDataInterface_InventorySource` on it or read it directly.

**Property:**

| Property | Description |
|---|---|
| **Inventory** | A `TMap` of `UPrimaryDataAsset` to quantity `int32`. Fill this in the Content Browser. |
