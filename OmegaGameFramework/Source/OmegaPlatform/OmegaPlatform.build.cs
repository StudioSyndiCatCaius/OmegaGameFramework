using UnrealBuildTool;
 
public class OmegaPlatform : ModuleRules
{
	public OmegaPlatform(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "GameplayTags"});
 
		PublicIncludePaths.AddRange(new string[] {"OmegaPlatform/Public"});
		PrivateIncludePaths.AddRange(new string[] {"OmegaPlatform/Private"});
	}
}