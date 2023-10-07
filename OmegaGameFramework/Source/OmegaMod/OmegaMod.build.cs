using UnrealBuildTool;
using System.IO;

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
			"DeveloperSettings",
			"GameplayTags",
			"SlateCore",
			"OmegaData"});
 
		PublicIncludePaths.AddRange(new string[] {Path.Combine(ModuleDirectory,"Public")});
		PrivateIncludePaths.AddRange(new string[] {Path.Combine(ModuleDirectory,"Private")});
	}
}