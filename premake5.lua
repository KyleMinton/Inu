workspace "Inu"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Inu"
    location "Inu"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        characterset "Unicode"
        buildoptions { "/utf-8" }   -- tells MSVC to compile source as UTF-8

        defines
        {
            "INU_PLATFORM_WINDOWS",
            "INU_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "INU_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "INU_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "INU_DIST"
        optimize "On"

project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"

        language "C++"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Inu/vendor/spdlog/include",
        "Inu/src"
    }

    links 
    {
        "Inu"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        characterset "Unicode"
        buildoptions { "/utf-8" }   -- tells MSVC to compile source as UTF-8

    defines
    {
        "INU_PLATFORM_WINDOWS"
    }

    filter "configurations:Debug"
        defines "INU_DEBUG"
        symbols "On"

    filter "configurations:Dist"
        defines "INU_RELEASE"
        optimize "On"

    filter "configurations:"
        defines "INU_DIST"
        optimize "On"