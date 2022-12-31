using UnrealBuildTool;
 
public class OmegaSignal : ModuleRules
{
	public OmegaSignal(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "GameplayTags"});
 
		PublicIncludePaths.AddRange(new string[] {"OmegaSignal/Public"});
		PrivateIncludePaths.AddRange(new string[] {"OmegaSignal/Private"});
	}
}