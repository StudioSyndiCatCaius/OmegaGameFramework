local example_transform={
    {0,0,0},
    {0,0,0},
    {1,1,1},
}
local example_vector3={x=0,y=0,z=0}
local example_vector2={0,0}

SynMath={
    --Vector 3
    V3={
        Lerp=function (a,b,alpha)
            return {x=0,y=0,z=0}
        end
    },
    --Vector 2
    V2={
        Lerp=function (a,b,alpha)
            return {x=0,y=0,}
        end
    },

    --- func desc
    ---@param value number
    ---@param min number
    ---@param max number
    clamp=function (value, min, max)
        if value < min then return min end
        if value > max then return max end
        return value
      end,

      -- random number. If in range of min, return true
      RngBool=function (chance)
        local val=math.random()
        return SynLit.BOOL(val<=chance)
      end
}

