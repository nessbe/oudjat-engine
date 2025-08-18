// File:        logger.h
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

#include <iostream>
#include <ostream>
#include <string>

#include "oudjat/export.h"
#include "oudjat/logging/log_level.h"

namespace oudjat
{
	namespace logging
	{
		class logger
		{
		public:
			OUDJAT_API logger();
			OUDJAT_API logger(log_level level);

			OUDJAT_API ~logger() = default;

			OUDJAT_API OUDJAT_GETTER log_level get_level() const noexcept;
			OUDJAT_API OUDJAT_SETTER void set_level(log_level level) noexcept;

			OUDJAT_API OUDJAT_GETTER bool is_level_valid(log_level level) const noexcept;

			OUDJAT_API void log(const std::string& message, log_level level);

		private:
			std::ostream& out_ = std::cout;
			log_level min_level_;

		private:
			OUDJAT_API std::string format_message(const std::string& message, log_level level) const;

			OUDJAT_API void log_raw(const std::string& message);
		};
	}
}
