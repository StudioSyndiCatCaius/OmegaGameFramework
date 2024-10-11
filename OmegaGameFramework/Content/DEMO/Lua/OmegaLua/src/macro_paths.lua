

function MAC_PATH_GETASSET(path, asset)
    return path..asset.."."..asset
end

function MAC_PATH_GETCLASS(path, asset)
    return path..asset.."."..asset.."_C"
end


--- Gets a character skin path from the main foler.
---@return string MAC_PATH_SKIN_ROOT
---@param name string
function MAC_PATH_SKIN_ROOT(name)
    local out = MAC_PATH_GETCLASS(UPATHS.skins_character,name)
    return out
end

function MAC_PATH_SKIN_NHANCE_ENEMY(name)
    local out = MAC_PATH_GETCLASS("/SyndiAsset_Nhance/_BP/skin_enemy/",name)
    return out
end


function MAC_PATH_MOVIE(movie)
    return MAC_PATH_GETASSET('/Game/Movies/',movie)
end

function MAC_PATH_MENU(menu)
    return MAC_PATH_GETCLASS('/Game/0_Main/Blueprints/Menus/',menu)
end
function MAC_PATH_SYSTEM(system)
    return MAC_PATH_GETCLASS('/Game/0_Main/Blueprints/Systems/',system)
end

local get_class



