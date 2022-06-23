using UnrealBuildTool;
using System.IO;

public class OmegaWorld : ModuleRules
{
	public OmegaWorld(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "GameplayTags"});
 
		PublicIncludePaths.AddRange(new string[] {Path.Combine(ModuleDirectory,"Public")});
		PrivateIncludePaths.AddRange(new string[] {Path.Combine(ModuleDirectory,"Private")});
	}
}