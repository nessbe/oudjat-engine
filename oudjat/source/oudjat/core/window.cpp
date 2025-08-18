// File:        window.cpp
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

#include "oudjat/core/window.h"

namespace oudjat
{
	window::window(window::dimension_t width, window::dimension_t height, const std::string& title) :
		width_(width), height_(height), title_(title), is_vsync_(false)
	{
	}

	void window::show()
	{
		is_visible_ = true;
	}

	void window::hide()
	{
		is_visible_ = false;
	}

	bool window::is_visible() const noexcept
	{
		return is_visible_;
	}

	void window::set_visible(bool visible)
	{
		if (visible)
		{
			show();
		}
		else
		{
			hide();
		}
	}

	window::dimension_t window::get_width() const noexcept
	{
		return width_;
	}

	void window::set_width(window::dimension_t width)
	{
		width_ = width;
	}

	window::dimension_t window::get_height() const noexcept
	{
		return height_;
	}

	void window::set_height(window::dimension_t height)
	{
		height_ = height;
	}

	const std::string& window::get_title() const noexcept
	{
		return title_;
	}

	void window::set_title(const std::string& title)
	{
		title_ = title;
	}

	bool window::is_vsync() const noexcept
	{
		return is_vsync_;
	}

	void window::set_vsync(bool enabled) noexcept
	{
		is_vsync_ = enabled;
	}
}
