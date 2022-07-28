using UnrealBuildTool;
 
public class OmegaSequence : ModuleRules
{
	public OmegaSequence(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "GameplayTags", "OmegaGameFramework"});
 
		PublicIncludePaths.AddRange(new string[] {"OmegaSequence/Public"});
		PrivateIncludePaths.AddRange(new string[] {"OmegaSequence/Private"});
	}
}