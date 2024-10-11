--SAVE_GAME.affinity={}

local gen_ranks=function ()
    local out={}
    for i = 1, 10, 1 do
        table.insert(out,{
            ap=i*150
        })
    end
    return out
end

G_Affinity={
    _config={
        ranks=gen_ranks()
    }
}

-- PRIVATE -------------------------------------------------------------------

local get_member=function (m)
    if not (_SAV.affinity[m]) then
        _SAV.affinity[m]={
            ap=0,
            tags={},
        }
    end
    return _SAV.affinity[m]
end

local get_rank_dat=function (rank)
    return G_Affinity._config.ranks[rank]
end

-- PUBLIC -------------------------------------------------------------------

function G_Affinity.Get_Entities()
    
end

--- func desc
---@param member string
---@param ap integer
function G_Affinity.Add_AP(member,ap)
    get_member(member).ap = G_Affinity.Get_AP(member)+ap

end

function G_Affinity.Get_AP(member)
    return get_member(member).ap
end

function G_Affinity.Get_Rank(member)
    local last_index=0
    for index, rank_dat in ipairs(G_Affinity._config.ranks) do
        if G_Affinity.Get_AP(member)>=G_Affinity._config.ranks[index].ap then
            last_index = index
        end
    end
    return last_index
end

function G_Affinity.Get_PercentToNext(member)
    local out=0.0
    local cur = G_Affinity.Get_AP(member)
    local max = get_rank_dat(G_Affinity.Get_Rank(member)+1).ap
    out = cur/max
    return out
end

