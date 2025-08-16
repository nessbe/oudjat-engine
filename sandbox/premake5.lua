-- File:        premake5.lua (sandbox)
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

project "sandbox"
	kind "ConsoleApp"

	language "C++"
	cppdialect "C++17"

	targetdir(target_dir .. output_dir .. "%{prj.name}/")
	objdir(obj_dir .. output_dir .. "%{prj.name}/")

	files {
		"source/**.cpp",
	}

	includedirs {
		"%{wks.location}/oudjat/include/",
	}

	defines {
		"OUDJAT_LINKAGE_DYNAMIC",
	}

	links {
		"oudjat",
	}

	dependson {
		"oudjat",
	}

	prebuildcommands {
		"{COPY} " .. target_dir .. output_dir .. "oudjat/oudjat.dll %{cfg.targetdir}"
	}

	filter "action:vs*"
		debugargs {
			"--configuration",
			"%{cfg.buildcfg}",
		}

	filter "configurations:Debug"
		symbols "On"
		optimize "Off"

	filter "configurations:Release"
		optimize "On"
		runtime "Release"

	filter "configurations:Dist"
		optimize "Full"
		runtime "Release"

		staticruntime "On"
