// File:        log_level.h
// Project:     oudjat-engine
// Repository:  https://github.com/nessbe/oudjat-engine
//
// Copyright (c) 2025 nessbe
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// For more details, see the LICENSE file at the root of the project.

#pragma once

#include <string>

namespace oudjat
{
	namespace logging
	{
		enum class log_level
		{
			debug = 0,
			trace = 1,
			info = 2,
			warning = 3,
			error = 4,
			critical = 5,
		};

		inline std::string to_string(log_level level)
		{
			switch (level)
			{
			case log_level::debug:
				return "DEBUG";

			case log_level::trace:
				return "TRACE";

			case log_level::info:
				return "INFO";

			case log_level::warning:
				return "WARNING";

			case log_level::error:
				return "ERROR";

			case log_level::critical:
				return "CRITICAL";

			default:
				return "UNKNOWN";
			}
		}
	}
}
