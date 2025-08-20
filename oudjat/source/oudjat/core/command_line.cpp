// File:        command_line.cpp
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

#include "oudjat/core/command_line.h"

#include <sstream>

namespace oudjat
{
	command_line::command_line(int argc, char** argv)
	{
		if (argc > 0)
		{
			program_name_ = argv[0];
		}

		for (command_line::index_t i = 1; i < argc; i++)
		{
			arguments_.emplace_back(argv[i]);
		}

		argument_count_ = static_cast<command_line::index_t>(arguments_.size());
	}

	std::string command_line::to_string() const
	{
		std::ostringstream oss;

		for (command_line::index_t i = 0; i < arguments_.size(); i++)
		{
			const std::string& argument = arguments_[i];
			oss << argument;

			if (i < arguments_.size() - 1)
			{
				oss << ' ';
			}
		}

		return oss.str();
	}

	command_line::index_t command_line::size() const noexcept
	{
		return argument_count_;
	}

	const std::string& command_line::get_program_name() const noexcept
	{
		return program_name_;
	}

	bool command_line::has_argument(command_line::index_t index) const noexcept
	{
		return index < size();
	}

	std::optional<std::string> command_line::get_argument(command_line::index_t index) const
	{
		if (has_argument(index))
		{
			return std::string(arguments_[index]);
		}
		return std::nullopt;
	}
}
