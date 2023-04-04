// Copyright Studio Syndicat 2023. All Rights Reserved.

using UnrealBuildTool;

public class FileSDK : ModuleRules 
{
  public FileSDK(ReadOnlyTargetRules Target) : base(Target) 
  {
    bUseUnity = false;

    PrecompileForTargets = PrecompileTargetsType.Any;
    PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

    PublicIncludePaths.AddRange(
      new string[] {
      }
      );


    PrivateIncludePaths.AddRange(
      new string[] {
      }
      );


    PublicDependencyModuleNames.AddRange(
      new string[]
      {
        "Core",
      }
      );


    PrivateDependencyModuleNames.AddRange(
      new string[]
      {
        "CoreUObject",
        "Engine",
        "Slate",
        "SlateCore",
      }
      );


    DynamicallyLoadedModuleNames.AddRange(
      new string[]
      {
      }
      );
  }
}
