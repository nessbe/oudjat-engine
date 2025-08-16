// File:        command_line.h
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
#include <vector>
#include <optional>

#include "oudjat/export.h"
#include "oudjat/utils.h"

namespace oudjat
{
	class command_line
	{
	public:
		using index_t = std::size_t;

	public:
		OUDJAT_API command_line(int argc, char** argv);
		OUDJAT_API ~command_line() noexcept = default;

		OUDJAT_API OUDJAT_GETTER index_t size() const noexcept;

		OUDJAT_API OUDJAT_GETTER const std::string& get_program_name() const noexcept;

		OUDJAT_API OUDJAT_GETTER bool has_argument(index_t index) const noexcept;
		OUDJAT_API OUDJAT_GETTER std::optional<std::string> get_argument(index_t index) const;

		ITERATOR_WRAPPER(std::string, arguments_);

	private:
		std::string program_name_;
		index_t argument_count_;
		std::vector<std::string> arguments_;
	};
}
