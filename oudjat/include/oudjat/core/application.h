// File:        application.h
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

#include <optional>

#include "oudjat/export.h"
#include "oudjat/attributes.h"
#include "oudjat/memory.h"

#include "oudjat/core/exit_code.h"
#include "oudjat/core/window.h"
#include "oudjat/core/command_line.h"

namespace oudjat
{
	class application
	{
	public:
		OUDJAT_API application();
		OUDJAT_API virtual ~application();

		OUDJAT_API virtual exit_code run(command_line arguments);

		OUDJAT_API OUDJAT_GETTER window& get_window() const noexcept;
		OUDJAT_API OUDJAT_GETTER bool is_running() const noexcept;

		OUDJAT_API bool post_exit_code(exit_code exit_code) noexcept;

	protected:
		scope<window> window_;

	protected:
		OUDJAT_API OUDJAT_GETTER bool has_exit_code() const noexcept;
		OUDJAT_API OUDJAT_GETTER exit_code get_exit_code() const;

	private:
		bool is_running_ = true;
		std::optional<exit_code> exit_code_ = std::nullopt;

	private:
		OUDJAT_API virtual void initialize() { }
		OUDJAT_API virtual void shutdown() { }
	};

	application* create_application();
}
