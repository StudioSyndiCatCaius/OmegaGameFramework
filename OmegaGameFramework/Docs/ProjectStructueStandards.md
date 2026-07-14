# Project Structue Standards

These are some of the standards used at *Studio SyndiCat* when developing games in Unreal Engine.

_________
### Folder Structure

* Game/Content
    * ***0_Main*** (Main game content folder. Everything goes in here to avoid confusiton with marketplace assets. Named "0_" to ensure always on top)
        * ***Assets***
            * Audio
            * Materials
                * Layers
                * LayerBlends
                * Functions
                * Instances
            * Textures
                * Surface (tilable surface textures)
                * Masks (BW texture masks)
                * RGB (RGB texture masks)
                * UI
                * Icons
            * PCG
            * Niagara
            * Meshes
            * SkeletalMeshes
                * characters
                * creatures
                * objects
        * ***Blueprints***
            * Actors
                * Skins
                * Cameras
                * Cues
                * Effects
            * Systems
            * HUD
            * Menus
            * Widgets
        * ***Data*** - (Primarily for DataAssets, but intended for the many iterations of game data.)
            * GamePreferences
            * Skills
            * Factions
            * Characters
            * Quests
            * *[etc...]*
        * ***Maps***
            * Locations/Levels (All the specific location/level maps.)
            * Test (Testing maps for various features. Not intended for final release)

_________
### Asset Naming

| Type | Name | Example |
| - | - | - |
| Texture (Surface) | T_S_[object]_[type] | T_S_Grass1_ColorMap |
| Texture (Object) | T_O_[object]_[type] | T_O_Character1_ColorMap |
| Texture (Icon) | T_ico_[object] | T_ico_Sword1 |
| Texture (UI) | T_UI_[object] | T_UI_HudElement |
| Material (Surface) | M_S_[object] |  |
| Material (Object) | M_O_[object] |  |
| Material (Decal) | M_D_[object] |  |
| Material (UI Element) | M_UI_[object] |  |
| Sound Wave (UI) | wav_ui_[name] | wav_ui_Confirm |
| Sound Wave (Oneshot sound effect) | wav_sfx_[name] | wav_sfx_explosion1 |
| Sound Wave (Looping ambiance) | wav_amb_[name] | wav_amb_rain1 |
| Sound Wave (voice Clip) | wav_vo_[speaker]_[context] | wav_vo_Adam_Shout1  |
| Sound Cue | sCue_[Sound - 'wav_'] | sCue_sfx_explosion  |
| Actor | a_[object] |  |
| Actor Component | ac_[object] |  |
| Gamepaly System | sys_[object] |  |
| HUD layer | HUD_[object] |  |
| Menu | Menu_[object] |  |
| Data Widget | DW_[object] |  |
| PCG (Full Level) | PCG_World_[object] | PCG_World_Grassland  |
| PCG (Volume Based) | PCG_V_[object] | PCG_V_Forrest |