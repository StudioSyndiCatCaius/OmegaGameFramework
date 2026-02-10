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
			"SlateCore",
			"CustomizableObject",
			"Json",
			"JsonUtilities",
			"LevelSequence",
			"AssetRegistry",
			"AnimGraphRuntime",
			"OmegaGameFramework",
			"SequencerScripting",
			"MovieScene",
			"OmegaSequence",
			"OmegaData",
			"OmegaMutable",
			"Flow",
			"GameplayStateTreeModule",
			"OmegaCore"
		});
 
		PublicIncludePaths.AddRange(new string[] {});
		PrivateIncludePaths.AddRange(new string[] {});
	}
}