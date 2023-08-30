workspace "Cengine"
    configurations { "Debug", "Release" }

include "SearchEngineCore/premake5"
include "Cli/premake5"
include "Server/premake5"
