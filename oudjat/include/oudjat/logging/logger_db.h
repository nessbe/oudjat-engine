// File:        logger_db.h
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

#include <optional>
#include <string>
#include <unordered_map>

#include "oudjat/export.h"
#include "oudjat/logging/logger.h"
#include "oudjat/memory.h"

namespace oudjat
{
	namespace logging
	{
		class logger_db
		{
		public:
			OUDJAT_API OUDJAT_GETTER static bool has_logger(const std::string& configuration);
			OUDJAT_API OUDJAT_GETTER reference<logger> get_logger(const std::string& configuration);

			OUDJAT_API static bool add_logger(reference<logger> logger);
			OUDJAT_API static bool remove_logger(const std::string& configuration);

			OUDJAT_API static reference<logger> emplace_logger(const std::string& configuration);
			OUDJAT_API static reference<logger> get_or_emplace_logger(const std::string& configuration);

		private:
			static std::unordered_map<std::string, reference<logger>> loggers_;
		};
	}
}
