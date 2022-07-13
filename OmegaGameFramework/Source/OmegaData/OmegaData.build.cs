using UnrealBuildTool;
 
public class OmegaData : ModuleRules
{
	public OmegaData(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "GameplayTags", "OmegaGameFramework", "SlateCore", "UMG"});
 
		PublicIncludePaths.AddRange(new string[] {"OmegaData/Public"});
		PrivateIncludePaths.AddRange(new string[] {"OmegaData/Private"});
	}
}