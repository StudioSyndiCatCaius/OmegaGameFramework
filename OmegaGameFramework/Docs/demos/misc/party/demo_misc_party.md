# Party System

Common to many RPGs, you can create a party system on OGF either with your own Gameplay System OR using OmegaGameMode. We will use the later option for this example.


* Create or Open your `OmegaGameMode` subclass.

### Member DataAsset

* Create a new DataAsset class OR use a built in one like `OmegaCommonCharacter`. This will be the base data asset for a party member.

* Create whatever party members you want.

### Instance Actors

* Party member data will be stored in instances of the `EntityInstances` component. We'll use the built in `OmegaEntityInstance` actor for this, as it will let us use some built in functions easier, but if you want to use your own, you can create an use a child class of this.

* You need to get all data assets of that character/party member class. You can do this by location search OR using `GetAllAssetsOfClass`.

* Create a ActorInstance for each found entity, then check if the current SaveGame has already inited them with a bool. If NOT do so and then apply their initial data.

### Squad Component

* Now the member instance data is set up, but we still need to determine who is in your party at any time. That;s what the Squad Component is for.

* Somewhere, create an array for default/initial party members (we'll do so in GameMode) and set them as the active members in the party.


### HUD

Now that the basic system is setup, let's display these party members in the UI.

* In your main gamepaly HUD, create a DataList for the active party (we'll use a built in Combatnat DataWidget class for now). You can get the party instances a few ways, but lets use the SplitEntityAtConstant function, allowing us to get only thos in or ACTIVE party by spliting at an index (which can be set in `ProjectSettings > Omega: Constants`)

### Fromation Menu

* Let's create a new menu for changing our party formation. We'll need 2 `DataLists` for ACTIVE and RESERVE members.