using UnrealBuildTool;
 
public class OmegaMod : ModuleRules
{
	public OmegaMod(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"OmegaGameFramework",
			"Json",
			"OmegaSequence",
			"GameplayTags",
			"SlateCore",
			"OmegaData"});
 
		PublicIncludePaths.AddRange(new string[] {"OmegaMod/Public"});
		PrivateIncludePaths.AddRange(new string[] {"OmegaMod/Private"});
	}
}