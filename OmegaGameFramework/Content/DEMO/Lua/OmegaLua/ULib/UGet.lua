UGET={
    Icon=function (name) return MAC_PATH_GETASSET('/Game/0_Main/Assets/Materials/Icons/',name) end,
    Portrait=function (name) return MAC_PATH_GETASSET('/Game/0_Main/Assets/Materials/UI/Portraits/',name) end,
    BKG=function (name) return MAC_PATH_GETASSET('/Game/0_Main/Assets/Textures/BKG/',name) end,
    Cue=function (name) return MAC_PATH_GETCLASS('/Game/0_Main/Blueprints/Actors/Cues/',name) end, 
    Attribute=function (name) return MAC_PATH_GETASSET('/QuestalotEngine/GameData/Attributes/',name) end,
    DamageType=function (name) return MAC_PATH_GETASSET('/OmegaGameFramework/DEMO/DamageType/',name) end,

    Menu=function(name) return MAC_PATH_GETCLASS('/Game/0_Main/Blueprints/Menus/',name) end,

    IMG=function (name) return MAC_PATH_GETASSET('/Game/0_Main/Assets/textures/',name) end,
    IMG_Portraits=function (name) return MAC_PATH_GETASSET('/Game/0_Main/Assets/textures/portraits/',name) end,
    IMG_Tutorial=function (name) return MAC_PATH_GETASSET('/Game/0_Main/Assets/textures/tutorial/',name) end,
}

