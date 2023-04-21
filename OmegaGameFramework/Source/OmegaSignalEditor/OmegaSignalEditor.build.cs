using UnrealBuildTool;
using System.IO;

public class OmegaSignalEditor : ModuleRules
{
	public OmegaSignalEditor(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"GameplayTags", 
			"BlueprintGraph", 
			"UnrealEd",
			"KismetCompiler",
			"AssetRegistry",
			"OmegaSignal"
		});
 
		PublicIncludePaths.AddRange(new string[] {Path.Combine(ModuleDirectory,"Public")});
		PrivateIncludePaths.AddRange(new string[] {Path.Combine(ModuleDirectory,"Private")});
	}
}

