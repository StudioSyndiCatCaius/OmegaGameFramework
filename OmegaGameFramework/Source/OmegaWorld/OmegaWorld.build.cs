using UnrealBuildTool;
 
public class OmegaWorld : ModuleRules
{
	public OmegaWorld(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "GameplayTags"});
 
		PublicIncludePaths.AddRange(new string[] {"OmegaWorld/Public"});
		PrivateIncludePaths.AddRange(new string[] {"OmegaWorld/Private"});
	}
}