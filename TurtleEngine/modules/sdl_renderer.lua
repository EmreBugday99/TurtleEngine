project "SDLRenderer"
	filter {}
	location ("../build/" .. _ACTION .. "/modules/%{prj.name}")
	language "C++"
	cppdialect "C++17"

	targetdir ("../build/".. _ACTION .. "/binaries/" .. outputdirectory .. "/modules/%{prj.name}")
	objdir ("../build/" .. _ACTION .. "/intermediate/" .. outputdirectory .. "/modules/%{prj.name}")

	files
	{
		"sdl_renderer/**.h",
		"sdl_renderer/**.hpp",
		"sdl_renderer/**.cpp"
	}

	libdirs {"../dependencies/sdl/lib", "../dependencies/ftl/lib"}
    includedirs
    {
		"../dependencies/sdl/include",
        "../core"
    }

	-- Defines without any filter
	defines "TURTLE_SDL_RENDERER"

	filter "system:windows"
		kind "SharedLib"
		systemversion "latest"
		links {"Core", "SDL2", "SDL2main", "SDL2_image", "SDL2_ttf"}
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