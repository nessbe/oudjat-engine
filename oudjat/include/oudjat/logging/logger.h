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
#include <vector>

#include "oudjat/attributes.h"
#include "oudjat/export.h"
#include "oudjat/io/sinks.h"
#include "oudjat/logging/log_level.h"
#include "oudjat/logging/log_message.h"
#include "oudjat/memory.h"

using namespace oudjat::io;

namespace oudjat
{
	namespace logging
	{
		class logger
		{
		public:
			OUDJAT_API logger(const std::string& configuration);
			OUDJAT_API logger(const std::string& configuration, log_level level);

			OUDJAT_API ~logger() = default;

			OUDJAT_API void push_sink(reference<sink> sink);

			template <typename T, typename... VarArgs> reference<T> emplace_sink(VarArgs&&... arguments)
			{
				reference<T> sink = make_referenced<T>(std::forward<VarArgs>(arguments)...);
				sinks_.push_back(sink);
				return sink;
			}

			OUDJAT_API OUDJAT_GETTER const std::string& get_configuration() const noexcept;

			OUDJAT_API OUDJAT_GETTER log_level get_level() const noexcept;
			OUDJAT_API OUDJAT_SETTER void set_level(log_level level) noexcept;

			OUDJAT_API OUDJAT_GETTER bool is_level_valid(log_level level) const noexcept;

			OUDJAT_API const std::string& get_message_format() const noexcept;
			OUDJAT_API void set_message_format(const std::string& format) noexcept;

			OUDJAT_API void log(const log_message& message);

			OUDJAT_API OUDJAT_INLINE void log_debug(const std::string& message);
			OUDJAT_API OUDJAT_INLINE void log_trace(const std::string& message);
			OUDJAT_API OUDJAT_INLINE void log_info(const std::string& message);
			OUDJAT_API OUDJAT_INLINE void log_warning(const std::string& message);
			OUDJAT_API OUDJAT_INLINE void log_error(const std::string& message);
			OUDJAT_API OUDJAT_INLINE void log_critical(const std::string& message);

		private:
			std::vector<reference<sink>> sinks_;

			std::string configuration_;
			log_level min_level_;

			// %C: Configuration
			// %L: Level
			// %M: Message
			std::string message_format_ = "[%C] [%L] %M";

		private:
			OUDJAT_API std::string format_message(const log_message& message) const;

			OUDJAT_API void log_raw(const std::string& message);
		};
	}
}
