using UnrealBuildTool;
 
public class OmegaVisual : ModuleRules
{
	public OmegaVisual(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine"});
 
		PublicIncludePaths.AddRange(new string[] {"OmegaVisual/Public"});
		PrivateIncludePaths.AddRange(new string[] {"OmegaVisual/Private"});
	}
}