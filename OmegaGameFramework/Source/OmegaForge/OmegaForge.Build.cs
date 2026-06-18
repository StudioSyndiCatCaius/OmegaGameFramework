using UnrealBuildTool;

public class OmegaForge : ModuleRules
{
    public OmegaForge(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "StructUtils",
                "OmegaCore",
                "CommonUI",
                "CommonInput",
                "EnhancedInput",
                "LuaMachine",
                "FileSDK",
                "Engine",
                "OmegaCore",
                "OmegaGameFramework",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "Projects",
                "AssetRegistry",
                "GameplayTags",
                "PropertyPath",
                "DeveloperSettings",
                "AudioPlatformConfiguration",
            }
        );
    }
}