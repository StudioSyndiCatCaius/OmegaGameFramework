// Copyright Studio Syndicat 2021. All Rights Reserved.

using UnrealBuildTool;

public class OmegaGameFramework : ModuleRules
{
	public OmegaGameFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		//bEnforceIWYU = true;
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
				// ... add other public dependencies that you statically link with here ...
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
				// ... add private dependencies that you statically link with here ...	
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
