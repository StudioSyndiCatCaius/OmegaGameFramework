UPATH={
    
    Get_Content_Directory=function () return UE.GET_PATH_TO_PROJECT()..[[Content/]] end,
    Get_Mods_Directory=function () return UE.GET_PATH_TO_PROJECT()..[[Mods/]] end,

    
}


UPATH.Get_Mod_File=function (modname,file)
    return UPATH.Get_Mods_Directory()..modname..[[/]]..file
end