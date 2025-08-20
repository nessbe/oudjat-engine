// File:        log_format.h
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
#include <ostream>

#include "oudjat/attributes.h"
#include "oudjat/export.h"
#include "oudjat/memory.h"

#include "oudjat/logging/log_level.h"
#include "oudjat/logging/log_message.h"

namespace oudjat
{
	namespace logging
	{
		class log_format_token
		{
		public:
			OUDJAT_API log_format_token(const std::string& symbol);
			OUDJAT_API ~log_format_token() = default;

			virtual void fill(const log_message& message, std::ostream& out) const = 0;

			OUDJAT_API OUDJAT_GETTER const std::string& get_symbol() const noexcept;

		private:
			std::string symbol_;
		};

		class log_format
		{
		public:
			OUDJAT_API explicit log_format(const std::string& format);
			OUDJAT_API ~log_format() = default;

			OUDJAT_API OUDJAT_GETTER const std::string& get_format() const noexcept;
			OUDJAT_API OUDJAT_SETTER void set_format(const std::string& format);

			OUDJAT_API OUDJAT_GETTER bool is_dirty() const noexcept;

			OUDJAT_API void update();
			OUDJAT_API void clear();

			OUDJAT_API void format(const log_message& message, std::ostream& out) const;

		private:
			std::string format_;
			bool is_dirty_ = true;

			std::vector<reference<log_format_token>> tokens_;

		private:
			OUDJAT_API void push_token(reference<log_format_token> token);

			template <typename T, typename... VarArgs> reference<T> emplace_token(VarArgs&&... arguments)
			{
				reference<T> token = make_referenced<T>(std::forward<VarArgs>(arguments)...);
				tokens_.push_back(token);
				return token;
			}
		};
	}
}

#define DEFINE_LOG_FORMAT_TOKEN(class_name)                                                                            \
	class class_name## : public oudjat::logging::log_format_token                                                      \
	{                                                                                                                  \
	public:                                                                                                            \
		using oudjat::logging::log_format_token::log_format_token;                                                     \
		OUDJAT_API ~class_name##() = default;                                                                          \
		virtual void fill(const oudjat::logging::log_message& message, std::ostream& out) const override;              \
	};

namespace oudjat
{
	namespace logging
	{
		DEFINE_LOG_FORMAT_TOKEN(literal_log_format_token);
		DEFINE_LOG_FORMAT_TOKEN(configuration_log_format_token);
		DEFINE_LOG_FORMAT_TOKEN(level_log_format_token);
		DEFINE_LOG_FORMAT_TOKEN(message_log_format_token);
	}
}
