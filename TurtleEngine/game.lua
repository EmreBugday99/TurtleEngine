project "Game"
	filter {}
	location ("build/" .. _ACTION .. "/game")
	language "C++"
	cppdialect "C++17"

	targetdir ("build/".. _ACTION .. "/binaries/" .. outputdirectory .. "/%{prj.name}")
	objdir ("build/" .. _ACTION .. "/intermediate/" .. outputdirectory .. "/%{prj.name}")

	files
	{
		"game/**.h",
		"game/**.hpp",
		"game/**.cpp"
	}

    includedirs
    {
        "core"
    }

	-- Defines without any filter
	defines "TURTLE_GAME"

	filter "system:windows"
		kind "SharedLib"
		systemversion "latest"
		links {"Core"}
		defines "TURTLE_OS_WINDOWS"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		defines "TURTLE_DEBUG"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
		defines "TURTLE_RELEASE"

	filter "kind:SharedLib"
		defines "TURTLE_LIBRARY_SHARED"

	filter "kind:StaticLib"
		defines "TURTLE_LIBRARY_STATIC"