# Item Inspector (Menu)

This is how you can create a basic Item Inspector menu (such as you might see in puzzle and survival horror games).

### Item Source / Data Asset
First we need something to contain them item data. You may have your own solution already set up, but for this demo we'll create a data asset with a static mesh.

-

Then just create a few iterative data assets of `DA_Item` giving them whatever static mesh you want.


### Item Display Actor
This will be the actual 3D actor that is rendered in the menu. Create an actor, and call it something like `a_UI_ItemInspect`

Add this component heriarchy:
    * SceneComponent - acting as the root pivot for the item mesh
        * StaticMesh - the actual displayed mesh
    * SpringArm - the camera boom for the view point's sceneCapture
    * SceneCapture2D - the Scene Capture that will be out in-menu view point

Add a function to set the current item (in this case using a reference to `DA_Item`). Setting the Mesh.

-

Add a function for `Input`, which will be a tick-based method for rotating the mesh around the screen.

-


### Menu

Now, time to create the menu itself. Create a new UMenu class and call it something like `Menu_ItemInspect`.

-

You can use the `Menu Actor Wrapper` and set it to the class of our `a_UI_ItemInspect`. Being a menu wrapper actor means it will be destoryed when the menu is closed.



## Added interaction (TBD)

TBD
