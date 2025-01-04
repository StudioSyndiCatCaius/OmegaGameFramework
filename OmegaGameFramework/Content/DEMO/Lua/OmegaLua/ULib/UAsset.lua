local aget=function (path, name)
    return [[/OmegaGameFramework]]..path..name..'.'..name
end

UASSET={
    CUSTOM={
        Sequence_FX=function(name) return MAC_PATH_GETASSET('/SyndiAsset_CUSTOM/Sequences/FX/',name) end,
    },

    Icons={
        keys={}
    },

    Attributes={
        HP=aget('/DEMO/Attributes/','HP'),
        MP=aget('/DEMO/Attributes/','MP'),
        PATK=aget('/DEMO/Attributes/','PATK'),
        PDEF=aget('/DEMO/Attributes/','PDEF'),
        MATK=aget('/DEMO/Attributes/','MATK'),
        MDEF=aget('/DEMO/Attributes/','MDEF'),
        SPD=aget('/DEMO/Attributes/','Speed'),
        DEX=aget('/DEMO/Attributes/','Dexterity'),
    },
    DamageTypes={
        physical=aget('/DEMO/DamageType/','DT_x_physical'),

        slash=aget('/DEMO/DamageType/','DT_p_slash'),
        bash=aget('/DEMO/DamageType/','DT_p_bash'),
        pierce=aget('/DEMO/DamageType/','DT_p_pierce'),

        fire=aget('/DEMO/DamageType/','DT_m_Fire'),
        water=aget('/DEMO/DamageType/','DT_m_Water'),
        earth=aget('/DEMO/DamageType/','DT_m_Earth'),
        wind=aget('/DEMO/DamageType/','DT_m_Wind'),

        light=aget('/DEMO/DamageType/','DT_c_Light'),
        dark=aget('/DEMO/DamageType/','DT_c_Dark'),
    },
    TargetFilter={
        FRIENDLY=aget('/DEMO/CombFilter/Collections/','TargetFilter_Allies'),
        HOSTILE=aget('/DEMO/CombFilter/Collections/','TargetFilter_Enemies'),
        SELF=aget('/DEMO/CombFilter/Collections/','TargetFilter_Allies'),
        DEAD=aget('/DEMO/CombFilter/Collections/','TargetFilter_KO'),
    }
    
}


local _addIcon_key_keyboard=function (name)
    UASSET.Icons.keys[name]=MAC_PATH_GETASSET('/OmegaGameFramework/Textures/Kenny/input/pc/','keyboard_'..name)
end

local _addIcon_key_mouse=function (name)
    UASSET.Icons.keys['mouse_'..name]=MAC_PATH_GETASSET('/OmegaGameFramework/Textures/Kenny/input/pc/','mouse_'..name)
end


for index, value in ipairs(
    { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '13', '4', '5', '6' }
) do
    _addIcon_key_keyboard(value)
end

for index, value in ipairs(
    { 'left', 'right', }
) do
    _addIcon_key_mouse(value)
end



