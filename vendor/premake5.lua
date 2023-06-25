vendor = "%{wks.location}/vendor/"

IncludeDir = {}
IncludeDir["imgui"] = "%{vendor}/imgui"
IncludeDir["SFML"] = "%{vendor}/SFML/include"

LibDir = {}
LibDir["SFML"] = "%{vendor}/SFML/lib"

project "imgui"
    location "imgui"

    kind "StaticLib"
    language "C++"

    targetdir (outputdir)
    objdir (tempdir)

    files {
        "imgui/imconfig.h",
        "imgui/imgui_demo.cpp",
        "imgui/imgui_draw.cpp",
        "imgui/imgui_internal.h",
        "imgui/imgui_tables.cpp",
        "imgui/imgui_widgets.cpp",
        "imgui/imgui.cpp",
        "imgui/imgui.h",
        "imgui/imstb_rectpack.h",
        "imgui/imstb_textedit.h",
        "imgui/imstb_truetype.h",
    }

    filter "system:window"
        systemversion "latest"
        cppdialect "C++17"
        staticruntime "On"
    
    filter "system:linux"
        systemversion "latest"
        cppdialect "C++17"
        staticruntime "On"
    
    filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"