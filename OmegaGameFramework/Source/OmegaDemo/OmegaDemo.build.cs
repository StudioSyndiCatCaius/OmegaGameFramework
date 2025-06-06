using UnrealBuildTool;
 
public class OmegaDemo : ModuleRules
{
	public OmegaDemo(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        bUseUnity = false;

        PrecompileForTargets = PrecompileTargetsType.Any;
        
		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"LuaMachine",
			"Engine", 
			"GameplayTags", 
			"UMG",
			"SlateCore",
			"CustomizableObject",
			"JsonUtilities",
			"LevelSequence",
			"AssetRegistry",
			"AnimGraphRuntime",
			"OmegaGameFramework",
			"SequencerScripting",
			"OmegaSequence",
			"OmegaData",
			"OmegaMutable",
			"Flow"
		});
 
		PublicIncludePaths.AddRange(new string[] {"OmegaDemo/Public"});
		PrivateIncludePaths.AddRange(new string[] {"OmegaDemo/Private"});
	}
}