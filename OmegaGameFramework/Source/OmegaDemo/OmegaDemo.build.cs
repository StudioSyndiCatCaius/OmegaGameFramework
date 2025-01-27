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
			"JsonUtilities",
			"AssetRegistry",
			"AnimGraphRuntime",
			"OmegaGameFramework",
			"SequencerScripting",
			"OmegaSequence",
			"OmegaData",
			"Flow"
		});
 
		PublicIncludePaths.AddRange(new string[] {"OmegaDemo/Public"});
		PrivateIncludePaths.AddRange(new string[] {"OmegaDemo/Private"});
	}
}