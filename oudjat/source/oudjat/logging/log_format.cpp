// File:        log_format.cpp
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

#include "oudjat/logging/log_format.h"

namespace oudjat
{
	namespace logging
	{
		log_format::log_format(const std::string& format) : format_(format)
		{
			update();
		}

		const std::string& log_format::get_format() const noexcept
		{
			return format_;
		}

		void log_format::set_format(const std::string& format)
		{
			if (format != format_)
			{
				format_ = format;
				is_dirty_ = true;
			}
		}

		bool log_format::is_dirty() const noexcept
		{
			return is_dirty_;
		}

		void log_format::update()
		{
			clear();

			std::size_t format_size = format_.size();
			std::string literal_group;

			for (std::size_t i = 0; i < format_size; i++)
			{
				char current_char = format_[i];

				if (current_char == '%' && i < format_size - 1)
				{
					if (!literal_group.empty())
					{
						emplace_token<literal_log_format_token>(literal_group);
						literal_group.clear();
					}

					char next_char = format_[++i];
					std::string symbol{current_char, next_char};

					switch (next_char)
					{
					case 'C':
						emplace_token<configuration_log_format_token>(symbol);
						break;

					case 'L':
						emplace_token<level_log_format_token>(symbol);
						break;

					case 'M':
						emplace_token<message_log_format_token>(symbol);
						break;
					}
				}
				else
				{
					literal_group += current_char;
				}
			}

			is_dirty_ = false;
		}

		void log_format::clear()
		{
			tokens_.clear();
			is_dirty_ = true;
		}

		void log_format::format(const log_message& message, std::ostream& out) const
		{
			if (is_dirty())
			{
				return;
			}

			for (const reference<log_format_token>& token : tokens_)
			{
				token->fill(message, out);
			}
		}

		void log_format::push_token(reference<log_format_token> token)
		{
			tokens_.push_back(token);
		}

		log_format_token::log_format_token(const std::string& symbol) : symbol_(symbol) {}

		const std::string& log_format_token::get_symbol() const noexcept
		{
			return symbol_;
		}

		void literal_log_format_token::fill(const log_message& message, std::ostream& out) const
		{
			out << get_symbol();
		}

		void configuration_log_format_token::fill(const log_message& message, std::ostream& out) const
		{
			out << message.configuration;
		}

		void level_log_format_token::fill(const log_message& message, std::ostream& out) const
		{
			out << to_string(message.level);
		}

		void message_log_format_token::fill(const log_message& message, std::ostream& out) const
		{
			out << message.literal;
		}
	}
}
