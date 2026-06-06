--[[
	TYPES:
		0 - Boolean
		1 - Integer
		2 - Float
]]--

--[[
=========================================================================================================
	GAME
=========================================================================================================
]]


local p_game={
	{
		name="Camera Invert X",
		ini_name="r.CameraInvertX",
		type=0,
		default=false,
	},
	{
		name="Camera Invert Y",
		ini_name="r.CameraInvertY",
		type=0,
		default=false,
	},
	{
		name="Camera Sensitivity",
		ini_name="r.CameraSensitivity",
		type=2,
		default=1.0,
		min=0.1,
		max=10.0,
	},

}

local addScalableGfx=function (name,ini_name)
	return {
		name=name,
		ini_name=ini_name,
		type=1,
		default=0,
		GetOptions=function ()
			return {
				{name="Low",value=0,},
				{name="Medium",value=1,},
				{name="High",value=2,},
				{name="Epic",value=3,},
			}
		end,
	}
end

--[[
=========================================================================================================
	GRAPHICS
=========================================================================================================
]]

local p_visual={
	addScalableGfx("Texture Quality","r.TextureQuality"),
	addScalableGfx("Shadow Quality","r.ShadowQuality"),
	addScalableGfx("Effects Quality","r.EffectsQuality"),
	addScalableGfx("Post-Processing Quality","r.PostProcessQuality"),
	addScalableGfx("Foliage Quality","r.FoliageQuality"),
	addScalableGfx("View Distance Quality","r.ViewDistanceQuality"),
	addScalableGfx("Anti-Aliasing Quality","r.AntiAliasingQuality"),
	{
		name="Anti-Aliasing",
		type=1,
		ini_name="r.AntiAliasingMethod",

		GetOptions=function ()
			return {
				{name="None",value=0,},
				{name="FXAA",value=1,},
				{name="TAA",value=2,},
				--{name="MSAA",value=3,},
				{name="TSR",value=4,},
			}
		end,

	},
	{
		name="V-Sync",
		ini_name="r.VSync",
		type=0,
		default=true,
	},
	{
		name="Resolution Scale",
		ini_name="r.ScreenPercentage",
		type=2,
		default=1.0,
		min=0.5,
		max=2.0,
	},
		addScalableGfx("Global Illumination Quality","r.GlobalIlluminationQuality"),
	{
		name="Global Illumunation Method",
		ini_name="r.GlobalIlluminationMethod",
		type=1,
		GetOptions=function ()
			return {
				{name="None",value=0,},
				{name="Lumen",value=1,},
				{name="Screen Space",value=2,},
			}
		end,
	},
	{
		name="RHI",
		ini_name="r.DefaultFeature.RHI",
		type=1,
		GetOptions=function ()
			return {
				{name="Default",value=0,},
				{name="DirectX 11",value=1,},
				{name="DirectX 12",value=2,},
				{name="Vulkan",value=3,},
			}
		end,
	}

}

--[[
=========================================================================================================
	AUDIO
=========================================================================================================
]]

local addVolume=function (name,ini_name)
	return {
		name=name,
		ini_name=ini_name,
		type=2,
		default=0.5,
		min=0.0,
		max=1.0,
	}
end

local p_audio={
	addVolume("Master Volume","r.MasterVolume"),
	addVolume("Music Volume","r.MusicVolume"),
	addVolume("SFX Volume","r.SFXVolume"),
	addVolume("Voice Volume","r.VoiceVolume"),
	
}



local a={

	categories={
		{
			name="Game",
			options=p_game,
		},
		{
			name="Graphics",
			options=p_visual,
		},
		{
			name="Audio",
			options=p_audio,
		},
	}
}

return a