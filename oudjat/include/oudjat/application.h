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

#include "oudjat/export.h"

#include "oudjat/window.h"
#include "oudjat/memory.h"

namespace oudjat
{
	class application
	{
	public:
		using exit_code_t = int;

	public:
		OUDJAT_API application();
		OUDJAT_API virtual ~application();

		OUDJAT_API virtual exit_code_t run();

		OUDJAT_API OUDJAT_GETTER window& get_window() const noexcept;

	protected:
		scope<window> window_;

	private:
		OUDJAT_API virtual void initialize() { }
		OUDJAT_API virtual void shutdown() { }
	};

	application* create_application();
}
