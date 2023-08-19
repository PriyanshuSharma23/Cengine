-- Cli/premake5.lua

project "Cli"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++14"

   -- Include directories for Cli project
   includedirs { "src", "../SearchEngineCore/src", "../SearchEngineCore/vendor" }
   files { "src/**.cpp", "src/**.h" }

   -- Link with the SearchEngineCore project
   links { "SearchEngineCore" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
