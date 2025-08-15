// File:        window.h
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

#include "oudjat/export.h"
#include "oudjat/utils.h"

namespace oudjat
{
	class window
	{
	public:
		using dimension_t = unsigned int;

	public:
		OUDJAT_API window(dimension_t p_width, dimension_t p_height, const std::string& p_title);
		OUDJAT_API virtual ~window() = 0;

		OUDJAT_API OUDJAT_GETTER virtual bool is_vsync() const noexcept;
		OUDJAT_API virtual void set_vsync(bool p_enabled) noexcept;

		OUDJAT_API OUDJAT_GETTER virtual void* get_native_handle() const = 0;

	private:
		dimension_t width, height;
		std::string title;
		bool vsync_enabled = false;
	};
}
