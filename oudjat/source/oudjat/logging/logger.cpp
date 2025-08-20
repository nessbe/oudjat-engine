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
		logger::logger(const std::string& configuration) : configuration_(configuration), min_level_(log_level::debug)
		{
		}

		logger::logger(const std::string& configuration, log_level level) :
			configuration_(configuration), min_level_(level)
		{
		}

		void logger::push_sink(reference<sink> sink)
		{
			sinks_.push_back(sink);
		}

		const std::string& logger::get_configuration() const noexcept
		{
			return configuration_;
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

		const std::string& logger::get_log_format() const noexcept
		{
			return log_format_.get_format();
		}

		void logger::set_log_format(const std::string& format) noexcept
		{
			log_format_.set_format(format);

			if (log_format_.is_dirty())
			{
				log_format_.update();
			}
		}

		void logger::log(const log_message& message)
		{
			if (!is_level_valid(message.level))
			{
				return;
			}

			std::string formatted_message = format_message(message);

			log_raw(formatted_message);
		}

		void logger::log_debug(const std::string& message)
		{
			log(log_message{message, log_level::debug, configuration_});
		}

		void logger::log_trace(const std::string& message)
		{
			log(log_message{message, log_level::trace, configuration_});
		}

		void logger::log_info(const std::string& message)
		{
			log(log_message{message, log_level::info, configuration_});
		}

		void logger::log_warning(const std::string& message)
		{
			log(log_message{message, log_level::warning, configuration_});
		}

		void logger::log_error(const std::string& message)
		{
			log(log_message{message, log_level::error, configuration_});
		}

		void logger::log_critical(const std::string& message)
		{
			log(log_message{message, log_level::critical, configuration_});
		}

		std::string logger::format_message(const log_message& message) const
		{
			std::ostringstream oss;
			log_format_.format(message, oss);
			return oss.str();
		}

		void logger::log_raw(const std::string& message)
		{
			for (const reference<sink>& sink : sinks_)
			{
				sink->write(message);
			}
		}
	}
}
