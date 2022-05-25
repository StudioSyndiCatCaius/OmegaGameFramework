using UnrealBuildTool;
 
public class Omega5_GameFeatures : ModuleRules
{
	public Omega5_GameFeatures(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine",
			"InputCore",
			"EnhancedInput",
			"GameplayTags",
			"GameplayTasks",
			"GameFeatures",
			"ModularGameplay"
		});
 
		PublicIncludePaths.AddRange(new string[] {"Omega5_GameFeatures/Public"});
		PrivateIncludePaths.AddRange(new string[] {"Omega5_GameFeatures/Private"});
	}
}