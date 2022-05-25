using UnrealBuildTool;
 
public class OmegaFlow : ModuleRules
{
	public OmegaFlow(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "GameplayTags", "OmegaGameFramework"});
 
		PublicIncludePaths.AddRange(new string[] {"OmegaFlow/Public"});
		PrivateIncludePaths.AddRange(new string[] {"OmegaFlow/Private"});
	}
}