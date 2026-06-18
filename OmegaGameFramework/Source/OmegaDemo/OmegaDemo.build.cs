using UnrealBuildTool;
 
public class OmegaDemo : ModuleRules
{
	public OmegaDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        
		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"LuaMachine",
			"Engine",
			"GameplayTags",
			"UMG",
			"Slate",
			"SlateCore",
			"CustomizableObject",
			"Json",
			"JsonUtilities",
			"Niagara",
			"JsonBlueprintUtilities",
			"LevelSequence",
			"AssetRegistry",
			"AnimGraphRuntime",
			"OmegaCore",
			"DeveloperSettings",
			"OmegaGameFramework",
			"SequencerScripting",
			"MovieScene",
			"OmegaSequence",
			"Flow",
			"GameplayStateTreeModule",
			"NavigationSystem",
			"AIModule",
		});

		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.Add("UnrealEd");
		}
 
		PublicIncludePaths.AddRange(new string[] {});
		PrivateIncludePaths.AddRange(new string[] {});
	}
}