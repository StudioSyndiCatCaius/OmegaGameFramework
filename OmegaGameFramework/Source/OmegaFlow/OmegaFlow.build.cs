using UnrealBuildTool;
using System.IO;

public class OmegaFlow : ModuleRules
{
	public OmegaFlow(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "GameplayTags", 
			"LuaMachine",
			"OmegaGameFramework", 
			"Flow", 
			"LevelSequence", 
			"SequencerScripting",
			"MovieScene"});
 
		PublicIncludePaths.AddRange(new string[] {Path.Combine(ModuleDirectory,"Public")});
		PrivateIncludePaths.AddRange(new string[] {Path.Combine(ModuleDirectory,"Private")});
	}
}