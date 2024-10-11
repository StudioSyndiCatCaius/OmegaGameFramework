_D.Character={}

G_CHAR={

    
    --Requires "name" and "surname" fields.
    ---@param key string
    ---@return string GET_FULLNAME
    GET_FULLNAME=function (key)
        local dat = _D.Character[key]
        return dat.name.." "..dat.surname
    end
}

