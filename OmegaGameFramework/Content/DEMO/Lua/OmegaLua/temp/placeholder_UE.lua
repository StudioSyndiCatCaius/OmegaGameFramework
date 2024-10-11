--Base Types
---@alias ASSETPATH string
---@alias CLASSPATH string
---@alias UOBJECT userdata
---@alias GUID string
---@alias Vector3 table
---@alias Transform3D table
---@alias LinearEvent table

UE={
	-- initialize Omega/Syndicat libraries
	Init=function() end,
    Init_Local=function() end,
    -- ########################################################################
    -- DEBUG
    -- ########################################################################
    GET_ASSET=function(path) end,
    GET_CLASS=function(path) end,
    
    NEW_OBJECT=function(class,params)end,
    PRINT_S=function (string)end,

    -- ########################################################################
    -- Overrite
    -- ########################################################################

    -- override UE params of a Uobject
    ---@param object UOBJECT
    ---@param params table
    WRITE_PARAMS=function(object,params) end,

    --- func desc
    ---@param object UOBJECT
    ---@param property string
    ---@return any
    PGET=function(object,property) return {} end,

    
    ---@param object UOBJECT
    ---@param property string
    ---@param value any
    PSET=function(object,property,value) end,

    -- ########################################################################
    -- FILE / PATH
    -- ########################################################################

    RUN_FILE=function (file) end,
    RUN_PATH=function(path,recursive)end,
    RUN_FILES_IN_DIR=function (dir) end,
    PLUGIN_GET_DIR=function(dir) return "/" end,
    RUN_PLUGIN_FILE=function (plugin,file) end,
    RUN_PLUGIN_PATH=function (plugin,path,recursive) end,
    STRING_FROM_FILE=function(file) end,

    -- ########################################################################
    -- Actor
    -- ########################################################################
    ACTOR_SPAWN=function(class,transform,meta,key,param_override) return {} end,
    ACTOR_DESTROY=function(actor) end,
    ACTOR_TELEPORT=function(actor,point) end,
    ACTOR_GET=function(key) end,
    --Gets a child actor from a class. Can use TAGS to filter.
    ACTOR_GETCHILD=function (actor,class,tags) end,
	
    --Gets a component from an actor class. Can use TAGS to filter.
    COMP_GET=function (actor,class,tags) end,
	
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
    LINEAR_EVENT_START=function (class,meta)
        return {}
    end,
    
    GLOBAL_EVENT=function (event,context)
        
    end,
   
    -- ########################################################################
    -- SAVE
    -- ########################################################################
    SAVE_TAGS_SET=function(tag,state,global) end,

    --- @param slot_name string
    SAVE_GAME=function(slot_name) end,

    ---@param slot_name string
    ---@param LoadLevel boolean
    LOAD_GAME=function(slot_name,LoadLevel) end,

    GET_PATH_TO_PROJECT=function() return [[<ProjectPath>]] end,

    -- ########################################################################
    -- Materials
    -- ########################################################################
    MPC_Set=function(ParameterCollection,Field,Value) end,

    URL_Launch=function(url) end,
    QuitGame=function() end,

}

