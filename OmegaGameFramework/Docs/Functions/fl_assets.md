# Asset & Object Function Libraries

Covers: `F_Assets`, `F_Object`, `F_ObjectSorter`, `F_ObjectTraits`, `F_NamedLists`, `F_Constants`, `F_DataAsset`

---

## Asset Functions (`UOmegaFunctions_Asset`)

Loading and querying classes and assets from the content registry.

| Node | Description |
|---|---|
| **Get All Child Classes** | Returns all Blueprint/C++ classes that inherit from a given parent. Toggle **Include Descendants** and **Include Parent**. |
| **Get Class by Name** | Returns a UClass by its name string. |
| **Get All Classes in Path** | Returns all classes inside a content path, filtered by a parent class. Toggle **Recursive**. |
| **Get Blueprint Class from Path** | Returns a Blueprint class from a content path string. |
| **Create Object From File** | Creates a UObject from an external file path. |
| **Load Uasset With Mount** | Loads a .uasset from disk using a mount path. |
| **Get Global Tagged Asset** | Returns a data asset registered globally under a specific gameplay tag. Pass a class for auto-casting. |
| **Get Named List Data Asset List** | Returns a list of data assets registered under a named tag list. |
| **Get Global Tagged Class** | Returns a class registered under a gameplay tag. |
| **Get PAL — All Assets** | Returns all Primary Asset Library objects matching a label. |
| **Get PAL Objects — All** | Returns all primary asset objects, optionally filtered by class. |
| **Get PAL Objects — Of ID Range** | Returns assets within a chunk ID range. |

---

## Object Functions (`UOmegaObjectFunctions`)

| Node | Description |
|---|---|
| **Rename Object** | Renames a UObject at runtime. |
| **Duplicate Object** | Duplicates a UObject into a new outer. Pass a class for type casting. |
| **Run Selector — Object** | Evaluates an object selector script and returns the selected UObject. |
| **Run Selector — Data Asset** | Evaluates a data asset selector and returns a `UPrimaryDataAsset`. |
| **Check Condition — Data Asset** | Verifies a data asset passes all conditions. Outputs failure **Reasons** text. |

### Lua Metadata on Objects
| Node | Description |
|---|---|
| **Meta — Get Table** | Returns a Lua table value for an object from its metadata. |
| **Meta — Set/Get Bool / Int / Float** | Read or write typed metadata values by parameter name on an object. |

---

## Object Sorter (`UOmegaObjectSorterFunctions`)

| Node | Description |
|---|---|
| **Sort Object Array** | Sort an array of UObjects using a sorter script asset. Pass an optional context and output class for casting. |

---

## Object Traits (`UOmegaObjectTraitsFunctions`)

Traits are typed extension objects attached to data assets or actors.

| Node | Description |
|---|---|
| **Try Get Object Trait** | Returns a specific trait from an object by class and name. Toggle **Fallback to Default** to return a default instance if not found. |
| **Get Object Traits** | Returns all trait objects on an object. |

---

## Named Lists (`UOmegaFunctions_NamedLists`)

Named lists associate a name string with objects, letting you tag objects with "presets" without modifying the assets themselves.

| Node | Description |
|---|---|
| **Get Object Named List Option** | Returns which named list option a specific object is registered under. |
| **Filter Objects With Named List Value** | From an array, keeps objects that have a specific value in a named list. Filter by class. |

---

## Constants (`UOmegaFunctions_Constants`)

Look up typed constants registered in the Omega settings by name. Useful for avoiding hard references in Blueprints.

| Node | Description |
|---|---|
| **Class — DataAsset** | Returns a data asset class registered under a name. |
| **Class — System** | Returns a Gameplay System class by name. |
| **Class — Menu** | Returns a Menu class by name. |
| **Class — HUD** | Returns a HUD Layer class by name. |
| **Byte / Int / Float / String** | Returns a typed constant by name. |
| **DataAsset / DataAsset List** | Returns a data asset or list of assets by name. |
| **Attribute** | Returns a `UOmegaAttribute` by name. |
| **Equip Slot** | Returns a `UEquipmentSlot` by name. |
