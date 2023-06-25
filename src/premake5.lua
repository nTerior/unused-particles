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
        ".",
        "%{IncludeDir.imgui}",
        "%{IncludeDir.SFML}"
    }

    libdirs {
        "%{LibDir.SFML}"
    }

    links {
        "imgui",
        -- SFML Dependencies
        "opengl32",
        "freetype",
        "winmm",
        "gdi32"
    }

    filter "configurations:Debug"
		defines {
            "_UNP_DEBUG",
            "SFML_STATIC"
        }
		runtime "Debug"
		symbols "on"

        links {
            "sfml-graphics-s-d",
            "sfml-window-s-d",
            "sfml-system-s-d"
        }

	filter "configurations:Release"
        defines {
            "_UNP_RELEASE",
            "SFML_STATIC"
        }
		runtime "Release"
		optimize "on"

        links {
            "sfml-graphics-s",
            "sfml-window-s",
            "sfml-system-s"
        }