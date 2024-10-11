--[[
    Supports
]]
D_Supports={}


local x={
    _config={
        save_default={
            points={
                
            }
        },
        ranks={
            {point=50},
            {point=200},
            {point=500},
        }
    }
}

-- PRIVATE 

local getdata_save=function (a,b)
    return _SAV.support[x.Support_Get_Index(a,b)]
end

--[[
    Points
]]

x.POINTS_Add=function (a,b,amount)
    getdata_save(a,b).points=getdata_save(a,b).points+amount
end

x.POINTS_Get=function (a,b)
   return getdata_save(a,b).points 
end

--[[
    Ranks
]]

function x.RANK_GET(a,b)
    local last_rank=0
    for index, value in ipairs(x._config.ranks) do
        if x.POINTS_GET(a,b)>=value.point then
            last_rank=index
        end
    end
    return last_rank
end

--[[
    Lists
]]

x.GetMembers_All=function (a)
    local out={}
    for index, value in ipairs(D_Supports) do
        if SynTable.has_value(value.members,a) then
            local not_me_val=0
            for member_index, member_val in ipairs(value.members) do
                if member_val~= a then
                    not_me_val=member_val
                end
            end
            table.insert(out,not_me_val)
        end
    end
    return out
end

x.GetMembers_Available=function (a)
    return x.GetMembers_All(a)
end

--[[
    Supports
]]

x.Support_Get_Index=function (a,b)
    for index, tbl in ipairs(D_Supports) do
        if SynTable.has_value(tbl.members,a) and SynTable.has_value(tbl.members,b) then
            return index
        end
    end
end


x.Support_Get_Percent=function (index)
    return SynLit.FLOAT(D_Supports[index])
end

x.Support_Get_RankCount=function (index)
    return SynLit.INT(#D_Supports[index].ranks)
end

--- func desc
---@param a string
---@param b string
---@param ranks integer
x.Support_New=function (a,b,ranks)
    if a==b then
        return
    end
    --don't make if already exists
    if (D_Supports[x.Support_Get_Index(a,b)]) then
        return
    end
    local new_dat={
        members={a,b},
        ranks={
        }
    }
    
    for i = 1, ranks, 1 do
      table.insert(new_dat.ranks,{
        dialog={
            {
                line="This is rank "..i.." affinty scene for "..a.." and "..b.."."
            }
        }
    })  
    end
    table.insert(D_Supports,new_dat)
    table.insert(_SAV.support,{
        points=0,
    })
end

G_Support=x

