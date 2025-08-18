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
#include "oudjat/attributes.h"

#include "oudjat/core/exit_code.h"

namespace oudjat
{
	class window
	{
	public:
		using dimension_t = unsigned int;

	public:
		OUDJAT_API window(dimension_t width, dimension_t height, const std::string& title);
		OUDJAT_API virtual ~window() { }

		OUDJAT_API virtual void open() = 0;
		OUDJAT_API virtual std::optional<exit_code> update() = 0;
		OUDJAT_API virtual void close() = 0;

		OUDJAT_API virtual void show();
		OUDJAT_API virtual void hide();

		OUDJAT_API OUDJAT_GETTER virtual bool is_visible() const noexcept;
		OUDJAT_API OUDJAT_SETTER virtual void set_visible(bool visible);

		OUDJAT_API OUDJAT_GETTER dimension_t get_width() const noexcept;
		OUDJAT_API OUDJAT_SETTER virtual void set_width(dimension_t width);

		OUDJAT_API OUDJAT_GETTER dimension_t get_height() const noexcept;
		OUDJAT_API OUDJAT_SETTER virtual void set_height(dimension_t height);

		OUDJAT_API OUDJAT_GETTER const std::string& get_title() const noexcept;
		OUDJAT_API OUDJAT_SETTER virtual void set_title(const std::string& title);

		OUDJAT_API OUDJAT_GETTER virtual bool is_vsync() const noexcept;
		OUDJAT_API OUDJAT_SETTER virtual void set_vsync(bool enabled) noexcept;

		OUDJAT_API OUDJAT_GETTER virtual void* get_native_handle() const = 0;

	protected:
		dimension_t width_, height_;
		std::string title_;
		bool is_vsync_ = false;
		bool is_visible_ = true;
	};
}
