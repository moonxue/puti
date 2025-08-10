// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class BlocksTarget : TargetRules
{
	public BlocksTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		ExtraModuleNames.AddRange( new string[] { "Blocks" } );
	}
}
