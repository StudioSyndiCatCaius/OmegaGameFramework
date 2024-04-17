UE={

    -- ########################################################################
    -- DEBUG
    -- ########################################################################

    PRINT_S=function (string)end,

    -- ########################################################################
    -- FILE / PATH
    -- ########################################################################

    RUN_FILE=function (file) end,
    RUN_PATH=function(path,recursive)end,
    RUN_FILES_IN_DIR=function (dir) end,
    PLUGIN_GET_DIR=function(dir) return "/" end,

    -- ########################################################################
    -- Actor
    -- ########################################################################
    ACTOR_TELEPORT=function(actor,point) end,
    ACTOR_GET=function(key) end,
    -- ########################################################################
    -- Animation
    -- ########################################################################

    PLAY_ANIMATION=function (actor,animation) end,
    PLAY_SEQUENCE=function (sequence,target) end,
    PLAY_DIALOG=function (dialog) end,

    -- ########################################################################
    -- Omega
    -- ########################################################################

    MENU_OPEN=function (menu,context,flag) end,
    SYSTEM_SET_ACTIVE=function (system,active,context,flag) end,

    -- ########################################################################
    -- Level
    -- ########################################################################

    LEVEL_OPEN=function (level,point) end,
    LEVEL_GET_CURRENT=function () return "level_name" end,

    
    -- ########################################################################
    -- Combat
    -- ########################################################################
    ATTRIBUTE_GET_CURRENT=function (target,attribute) return 0.0 end,
    ATTRIBUTE_GET_MAX=function (target,attribute) return 0.0 end,
    ATTRIBUTE_DAMAGE=function (target,instigator,attribute,amount,context) return 0.0 end,

    EFFECT_CREATE=function (effect,target,instigator,power) end,

    -- ########################################################################
    -- Player
    -- ########################################################################
   PLAYER_GET_PAWN=function () return"" end,
}








