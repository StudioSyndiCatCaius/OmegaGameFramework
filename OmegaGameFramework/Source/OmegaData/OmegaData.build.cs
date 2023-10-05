using UnrealBuildTool;
using System.IO;

public class OmegaData : ModuleRules
{
	public OmegaData(ReadOnlyTargetRules Target) : base(Target)
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
			"Slate",
			"SlateCore", 
			"UMG",
			"FileSDK",
			"GameplayTasks",
			"GameFeatures",
			"ModularGameplay"
		});
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"AssetRegistry"
		});
		
		PublicIncludePaths.AddRange(new string[] {Path.Combine(ModuleDirectory,"Public")});
		PrivateIncludePaths.AddRange(new string[] {Path.Combine(ModuleDirectory,"Private")});
	}
}