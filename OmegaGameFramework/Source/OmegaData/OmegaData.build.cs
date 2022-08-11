using UnrealBuildTool;
 
public class OmegaData : ModuleRules
{
	public OmegaData(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bUseUnity = false;

        PrecompileForTargets = PrecompileTargetsType.Any;
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"DeveloperSettings", 
			"GameplayTags",
			"OmegaGameFramework", 
			"SlateCore", 
			"UMG"
		});
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"AssetRegistry"
		});
		
		PublicIncludePaths.AddRange(new string[] {"OmegaData/Public"});
		PrivateIncludePaths.AddRange(new string[] {"OmegaData/Private"});
	}
}