// Copyright Studio Syndicat 2021. All Rights Reserved.

using UnrealBuildTool;

public class OmegaGameFramework : ModuleRules
{
	public OmegaGameFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
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
				"StructUtils",
				"OmegaCore",
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
				"GeometryScriptingCore",
				"PhysicsCore",
				"RenderCore",
				"GeometryCore",
				"GeometryFramework",
				"DynamicMesh",
				"ImageWrapper",
				"MetasoundEngine",
				"UMG",
				"InputCore",
				"PakFile",
				"Niagara",
				"Json",
				//"CustomizableSequencerTracks",
				"JsonUtilities",
				"AudioMixer",
				"JsonBlueprintUtilities",
				"PCG",
				"BinkMediaPlayer",
				"StateTreeModule",
				"GameplayStateTreeModule", "GameplayDebugger",
				"AIModule",
				"NavigationSystem",
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
		
		if (Target.bBuildEditor)
		{
			PublicDependencyModuleNames.Add("BlueprintGraph");
		}

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			
				
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
