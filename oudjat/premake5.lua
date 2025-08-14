-- File:        premake5.lua (core)
-- Project:     oudjat-engine
-- Repository:  https://github.com/nessbe/oudjat-engine
--
-- Copyright (c) 2025 nessbe
-- Licensed under the Apache License, Version 2.0 (the "License");
-- you may not use this file except in compliance with the License.
-- You may obtain a copy of the License at:
--
--     https://www.apache.org/licenses/LICENSE-2.0
--
-- Unless required by applicable law or agreed to in writing, software
-- distributed under the License is distributed on an "AS IS" BASIS,
-- WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
-- See the License for the specific language governing permissions and
-- limitations under the License.
--
-- For more details, see the LICENSE file at the root of the project.

project "oudjat"
	kind "SharedLib"

	language "C++"
	cppdialect "C++17"

	targetdir(target_dir .. output_dir .. "%{prj.name}/")
	objdir(obj_dir .. output_dir .. "%{prj.name}/")

	pchheader "oudjatpch.h"
	pchsource "source/oudjatpch.cpp"

	files {
		"include/**.h",
		"source/**.cpp",
	}

	includedirs {
		"include/",
	}

	filter "system:windows"
		systemversion "latest"

	filter "kind:StaticLib"
		defines {
			"OUDJAT_LINKAGE_STATIC",
		}

	filter "kind:SharedLib"
		defines {
			"OUDJAT_LINKAGE_DYNAMIC",
			"OUDJAT_BUILD_DLL",
		}

	filter "configurations:Debug"
		defines {
			"OUDJAT_DEBUG",
		}
		symbols "On"
		runtime "Debug"

	filter "configurations:Release"
		defines {
			"OUDJAT_RELEASE",
		}
		optimize "On"
		runtime "Release"

	filter "configurations:Dist"
		defines {
			"OUDJAT_DIST",
		}
		optimize "Full"
		runtime "Release"

		staticruntime "On"
