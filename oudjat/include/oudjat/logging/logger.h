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

namespace oudjat
{
	namespace logging
	{
		class logger
		{
		public:
			OUDJAT_API logger() = default;
			OUDJAT_API ~logger() = default;

			OUDJAT_API void log(const std::string& message);

		private:
			std::ostream& out_ = std::cout;

		private:
			OUDJAT_API void log_raw(const std::string& message);
		};
	}
}
