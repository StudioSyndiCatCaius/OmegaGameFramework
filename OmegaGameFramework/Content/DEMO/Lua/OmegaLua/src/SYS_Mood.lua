--[[
    Mood system is a singleton state in which a current is currently in.
]]
D_Moods={
    neutral={}
}

G_MOOD={
    _config={
        default_mood='neutral'
    },
}

local get_char=function (name)
    return _SAV.party[name]
end

G_MOOD.SET_MOOD=function (character,mood)
    get_char(character)["mood"]=D_Moods[mood]
    SynHook.Call('MOOD_CHANGED',{character=character,mood=mood})
end

G_MOOD.GET_MOOD=function (character,mood)
    if (get_char(character)["mood"]) then
        return get_char(character)["mood"]
    end
    return D_Moods[G_MOOD._config.default_mood]
end