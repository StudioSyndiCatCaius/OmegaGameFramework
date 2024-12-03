local a={}


local _getSav=function ()
    if _SAV.recipes==nil then
        _SAV.recipes={}
    end
    return _SAV.recipes
end

a.CanCookItem=function (item)
    
end


a.Recipe_IsOwned=function (recipe)
    return SynLit.BOOL(SynTable.has_value(_getSav(),recipe))
end

a.Recipe_SetOwned=function (recipe,owned)
    if owned~=a.Recipe_IsOwned(recipe) then
        if owned then
            table.insert(_getSav(),recipe)
        else
            SynTable.remove_value(_getSav(),recipe)
        end        
    end
end

a.Recipe_GetOwnedList=function ()
    return _getSav()
end


_A.Cooking=a

