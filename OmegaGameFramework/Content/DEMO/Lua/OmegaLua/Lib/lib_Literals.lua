local a={}

a.BOOL=function (input)
    if (input) then
        return input
    end
    return false
end

a.INT=function (input)
    if (input) then
        return input
    end
    return 0
end

a.FLOAT=function (input)
    if (input) then
        return input
    end
    return 0.0
end

a.STRING=function (input)
    if (input) then
        return input
    end
    return ''
end

a.TABLE=function (input)
    if (input) then
        return input
    end
    return {}
end

SynLit=a