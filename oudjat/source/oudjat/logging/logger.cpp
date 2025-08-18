// File:        logger.cpp
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

#include "oudjatpch.h"

#include "oudjat/logging/logger.h"

#include <sstream>

namespace oudjat
{
	namespace logging
	{
		logger::logger() : min_level_(log_level::debug)
		{
		}

		logger::logger(log_level level) : min_level_(level)
		{
		}

		log_level logger::get_level() const noexcept
		{
			return min_level_;
		}

		void logger::set_level(log_level level) noexcept
		{
			min_level_ = level;
		}

		bool logger::is_level_valid(log_level level) const noexcept
		{
			return level >= min_level_;
		}

		void logger::log(const std::string& message, log_level level)
		{
			if (!is_level_valid(level))
			{
				return;
			}

			std::string formatted_message = format_message(message, level);

			log_raw(formatted_message);
		}

		std::string logger::format_message(const std::string& message, log_level level) const
		{
			std::ostringstream oss;
			oss << '[' << to_string(level) << "] ";
			oss << message;
			return oss.str();
		}

		void logger::log_raw(const std::string& message)
		{
			out_ << message << std::endl;
		}
	}
}
