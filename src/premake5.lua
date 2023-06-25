project "unused-particles"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir (outputdir)
    objdir (tempdir)

    files {
        "**.cpp",
        "**.h"
    }

    includedirs{
        "%{IncludeDir.imgui}"
    }

    links {
        "imgui"
    }

    filter "configurations:Debug"
		defines "_UNP_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "_UNP_RELEASE"
		runtime "Release"
		optimize "on"