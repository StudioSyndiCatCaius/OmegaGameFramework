// Copyright Studio Syndicat 2021. All Rights Reserved.

using UnrealBuildTool;

public class OmegaGameFramework : ModuleRules
{
	public OmegaGameFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		bUseUnity = false;

		PrecompileForTargets = PrecompileTargetsType.Any;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				//"Save"
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"OmegaCORE",
				"CommonUI",
				"CommonInput",
				"EnhancedInput",
				"LuaMachine",
				"FileSDK",
				"Engine",
				"SkeletalMerging",
				"DeveloperSettings",
				"ApplicationCore",
				"LevelSequence",
				"MovieScene",
				"ImageWrapper",
				"MetasoundEngine",
				"UMG",
				"InputCore",
				"PakFile",
				"Niagara",
				"Json",
				"JsonUtilities",
				"JsonBlueprintUtilities",
				"PCG",
				"BinkMediaPlayer",
				"StateTreeModule",
				"GameplayStateTreeModule",
			}
			);
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"Projects",
				"AssetRegistry",
				"GameplayTags",
				"PropertyPath",
				"DeveloperSettings",
				"AudioPlatformConfiguration",
			}
			);
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			
				
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
