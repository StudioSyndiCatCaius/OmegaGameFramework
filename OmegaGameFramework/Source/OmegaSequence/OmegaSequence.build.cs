using UnrealBuildTool;
using System.IO;

public class OmegaSequence : ModuleRules
{
	public OmegaSequence(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", 
			"CoreUObject", 
			"LuaMachine",
			"Engine", 
			"OmegaData",
			"LuaMachine",
			"GameplayTags", 
			"OmegaGameFramework"});
 
		PublicIncludePaths.AddRange(new string[] {Path.Combine(ModuleDirectory,"Public")});
		PrivateIncludePaths.AddRange(new string[] {Path.Combine(ModuleDirectory,"Private")});
	}
}