using UnrealBuildTool;
using System.IO;

public class OmegaAnim : ModuleRules
{
	public OmegaAnim(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bUseUnity = false;

        PrecompileForTargets = PrecompileTargetsType.Any;
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"DeveloperSettings", 
			"GameplayTags",
			"OmegaGameFramework", 
			"SlateCore", 
			"UMG"
		});
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"AssetRegistry"
		});
		
		PublicIncludePaths.AddRange(new string[] {Path.Combine(ModuleDirectory,"Public")});
		PrivateIncludePaths.AddRange(new string[] {Path.Combine(ModuleDirectory,"Private")});
	}
}