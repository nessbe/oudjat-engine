// File:        application.cpp
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
#include "oudjat/core/application.h"

namespace oudjat
{
	application::application()
		: window_(nullptr)
	{
		initialize();
	}

	application::~application()
	{
		shutdown();
	}

	exit_code application::run(command_line arguments)
	{
		return exit_code::undefined;
	}

	window& application::get_window() const noexcept
	{
		return *window_;
	}

	bool application::is_running() const noexcept
	{
		return is_running_;
	}

	bool application::post_exit_code(exit_code exit_code) noexcept
	{
		if (!exit_code_.has_value())
		{
			exit_code_ = exit_code;
			is_running_ = false;
			return true;
		}
		return false;
	}

	bool application::has_exit_code() const noexcept
	{
		return exit_code_.has_value();
	}

	exit_code application::get_exit_code() const
	{
		if (has_exit_code())
		{
			return exit_code_.value();
		}
		return exit_code::undefined;
	}
}
