UASSET={
    CUSTOM={
        Sequence_FX=function(name) return MAC_PATH_GETASSET('/SyndiAsset_CUSTOM/Sequences/FX/',name) end,
    },

    Icons={
        keys={}
    },
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



