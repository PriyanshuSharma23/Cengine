project "SearchEngineCore"
    kind "StaticLib"
    language "C++"
    cppdialect "C++14"

    includedirs { "src", "vendor" }
    files {
        "vendor/json/**.hpp", "vendor/rapidxml/**.hpp", "src/**.cpp", "src/**.hpp" 
    }


    filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"

    filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"
