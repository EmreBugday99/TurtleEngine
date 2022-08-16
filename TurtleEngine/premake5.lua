workspace "TurtleEngine"
	location ("build/" .. _ACTION)
	startproject "Engine"
	architecture "x64"

	outputdirectory = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	configurations
	{
		"Debug",
		"Release"
	}

include "core.lua"
include "engine.lua"
include "modules/game.lua"
include "modules/sdl_renderer.lua"