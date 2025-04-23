// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SteamTest : ModuleRules
{
	public SteamTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
        { 
            "Core", 
            "CoreUObject", 
            "Engine", 
            "InputCore", 
            "EnhancedInput", 
            "UMG",
            "OnlineSubsystem",
            "OnlineSubsystemSteam"
        });

        PublicIncludePaths.AddRange(new string[]
        {
            "ProjectR/",
        });
    }
}
