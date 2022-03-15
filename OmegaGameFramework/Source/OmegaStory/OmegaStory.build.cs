using UnrealBuildTool;
 
public class OmegaStory : ModuleRules
{
	public OmegaStory(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "GameplayTags"});
 
		PublicIncludePaths.AddRange(new string[] {"OmegaStory/Public"});
		PrivateIncludePaths.AddRange(new string[] {"OmegaStory/Private"});
	}
}