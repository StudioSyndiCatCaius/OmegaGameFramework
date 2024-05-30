UE={

    -- ########################################################################
    -- DEBUG
    -- ########################################################################
    GET_ASSET=function(path)end,
    NEW_OBJECT=function(class,meta)end,
    PRINT_S=function (string)end,

    -- ########################################################################
    -- FILE / PATH
    -- ########################################################################

    RUN_FILE=function (file) end,
    RUN_PATH=function(path,recursive)end,
    RUN_FILES_IN_DIR=function (dir) end,
    PLUGIN_GET_DIR=function(dir) return "/" end,
    RUN_PLUGIN_FILE=function (plugin,file) end,
    RUN_PLUGIN_PATH=function (plugin,path,recursive) end,

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
    SYSTEM_ACTIVATE=function (system,context,flag) end,

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

    EFFECT_CREATE=function (effect,target,instigator,context,power) end,

    -- ########################################################################
    -- Player
    -- ########################################################################
   PLAYER_GET_PAWN=function () return"" end,

   
    -- ########################################################################
    -- Linear Events
    -- ########################################################################
    LIN_EVENT_START=function (class,meta)
        return {}
    end,
    
    GLOBAL_EVENT=function (event,context)
        
    end,
   
    -- ########################################################################
    -- SAVE
    -- ########################################################################
    SAVE_TAGS_SET=function(tag,state,global) end,
}









