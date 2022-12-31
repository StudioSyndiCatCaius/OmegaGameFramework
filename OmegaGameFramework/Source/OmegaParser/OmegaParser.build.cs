using UnrealBuildTool;
 
public class OmegaParser : ModuleRules
{
	public OmegaParser(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "GameplayTags"});
 
		PublicIncludePaths.AddRange(new string[] {"OmegaParser/Public"});
		PrivateIncludePaths.AddRange(new string[] {"OmegaParser/Private"});
	}
}