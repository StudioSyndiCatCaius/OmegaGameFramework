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
}

