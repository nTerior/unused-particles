workspace "unused-particles"
    configurations {"Debug", "Release"}
    architecture "x64"
    startproject "unused-particles"

outputdir = "%{wks.location}/bin/%{cfg.buildcfg}/%{cfg.system}/%{cfg.architecture}/%{prj.name}"
tempdir = "%{wks.location}/bin/intermediate/%{cfg.buildcfg}/%{cfg.system}/%{cfg.architecture}/%{prj.name}"

group "Dependencies"
    include "vendor/"
group ""

include "src/"