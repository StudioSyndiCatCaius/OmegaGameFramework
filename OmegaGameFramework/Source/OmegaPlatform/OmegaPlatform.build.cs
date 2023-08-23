using UnrealBuildTool;
using System.IO;

public class OmegaPlatform : ModuleRules
{
	public OmegaPlatform(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"GameplayTags",
			"PropertyPath",
			"InputCore",
			"OmegaGameFramework",
			"EnhancedInput",
			"DeveloperSettings",
			"SlateCore"
		});
 
		PublicIncludePaths.AddRange(new string[] {Path.Combine(ModuleDirectory,"Public")});
		PrivateIncludePaths.AddRange(new string[] {Path.Combine(ModuleDirectory,"Private")});
	}
}