// File:        main.cpp
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

#include <iostream>

#include "oudjat.h"

class sandbox_application : public oudjat::application
{
public:
	sandbox_application()
	{
		initialize();
	}

	virtual ~sandbox_application()
	{
		shutdown();
	}

	virtual oudjat::exit_code run(oudjat::command_line arguments) override
	{
		oudjat::logging::logger logger;
		logger.log("Hello from a logger!", oudjat::logging::log_level::debug);

		std::cout << "Running Sandbox application..." << std::endl;
		std::cout << "Running " << arguments.get_program_name() << " with arguments: ";

		for (const std::string& argument : arguments)
		{
			std::cout << argument << ' ';
		}
		std::cout << std::endl;

		window_ = oudjat::make_scoped<oudjat::windows_window>(360, 180, "My awesome unique window");
		window_->open();

		const std::size_t WINDOW_COUNT = 0;
		std::vector<oudjat::windows_window*> windows;

		for (std::size_t i = 0; i < WINDOW_COUNT; i++)
		{
			const std::string window_name = "My awesome window " + std::to_string(i);
			oudjat::windows_window* window = new oudjat::windows_window(360, 180, window_name);
			windows.push_back(window);
			window->open();
		}

		while (is_running())
		{
			{
				std::optional<oudjat::exit_code> exit_code = window_->update();

				if (exit_code.has_value())
				{
					post_exit_code(exit_code.value());
				}
			}

			for (oudjat::windows_window* window : windows)
			{
				std::optional<oudjat::exit_code> exit_code = window->update();
				if (exit_code.has_value())
				{
					post_exit_code(exit_code.value());
				}
			}
		}

		window_->close();

		for (oudjat::windows_window* window : windows)
		{
			window->close();
			delete window;
		}

		std::cout << "Exiting Sandbox application..." << std::endl;

		if (!has_exit_code())
		{
			post_exit_code(oudjat::exit_code::success);
		}

		return get_exit_code();
	}

	virtual void initialize() override
	{
		std::cout << "Initializing Sandbox application..." << std::endl;
	}

	virtual void shutdown() override
	{
		std::cout << "Shutting down Sandbox application..." << std::endl;
	}
};

oudjat::application* oudjat::create_application()
{
	return new sandbox_application();
}
