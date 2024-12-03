_C={} -- constants


if _D==nil then _D={} end -- Database: 
if _SAV==nil then _SAV={} end  -- Save: data save to the game file.
COMP={} --Create Components

_C.ENGINE={
    UE={
        setup=function ()
            
        end
    },
    GODOT={
        setup=function ()
            
        end
    }
}

_C.COLOR={
    White = "#FFFFFF",
    Silver = "#C0C0C0",
    Gray = "#808080",
    Black = "#000000",
    Red = "#FF0000",
    Maroon = "#800000",
    Yellow = "#FFFF00",
    Olive = "#808000",
    Lime = "#00FF00",
    Green = "#008000",
    Aqua = "#00FFFF",
    Teal = "#008080",
    Blue = "#0000FF",
    Navy = "#000080",
    Fuchsia = "#FF00FF",
    Purple = "#800080",
    Orange = "#FFA500"
}


SYN={
    Math=SynMath,
    File=SynFile,
    Loc=SynLoc,
    Hook=SynHook,
    Table=SynTable,
    String=SynString,
    Parse=SynParse,
}

