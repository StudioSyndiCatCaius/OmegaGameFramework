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
			"JsonUtilities",
			"AnimGraphRuntime",
			"OmegaGameFramework",
			"OmegaSequence",
			"OmegaData",
			"Flow"
			
		});
 
		PublicIncludePaths.AddRange(new string[] {"OmegaDemo/Public"});
		PrivateIncludePaths.AddRange(new string[] {"OmegaDemo/Private"});
	}
}