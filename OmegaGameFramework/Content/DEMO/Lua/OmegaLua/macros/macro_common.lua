



-- creates a new day and corresponding quest.
function MACRO_DAY_NEW(key,day_data,quest_data)
    D_Days[key]=day_data
    D_Quests[key]=quest_data
end


-- Macros for Unreal Engine Related Events
UEMAC={

    --installs default lib, src, and macro
    INSTALL_DEFAULT_SYSTEMS=function ()
        local saucelua=function (input)
            return UE.PLUGIN_GET_DIR("SyndiCat_LuaBPFunctions").."/Lua/"..input.."/"
        end
        
        -- RUN_FILES_FROMPLUGIN Systems
        UE.RUN_FILES_IN_DIR(saucelua("lib"))
        UE.RUN_FILES_IN_DIR(saucelua("src"))
        UE.RUN_FILES_IN_DIR(saucelua("macros"))
    end,


        
    -- ########################################################################
    -- Combat
    -- ########################################################################
    ATTRIBUTE_DAMAGE_PERCENT=function (target,attribute,percent)
        UE.ATTRIBUTE_DAMAGE(target,attribute,UE.ATTRIBUTE_GET_MAX(target,attribute)*percent)
    end,

    ATTRIBUTE_GET_PERCENT=function (target,attribute)
        return UE.ATTRIBUTE_GET_CURRENT(target,attribute) / UE.ATTRIBUTE_GET_MAX(target,attribute)
    end,

    --- func desc
    ---@param target any
    ---@param ability CLASSPATH
    Ability_Get=function (target,ability)
        
    end,

    -- ########################################################################
    -- Player
    -- ########################################################################
   PLAYER_TELEPORT=function (point)
    UE.ACTOR_TELEPORT(UE.PLAYER_GET_PAWN(),UE.ACTOR_GET(point))
   end,
}


UEMAC.Actors={
    Spawn={ 
        Character=function (id,transform,key,meta)
            local dat={}
            if not meta==nil then dat=meta end
            dat.key=key
            dat.id=id
            return UE.ACTOR_SPAWN(UE.GET_CLASS('OmegaCharacter'),transform,dat)
        end,
    }
}


