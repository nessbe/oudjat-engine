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

	virtual oudjat::application::exit_code_t run(oudjat::command_line arguments) override
	{
		std::cout << "Running Sandbox application..." << std::endl;
		std::cout << "Running " << arguments.get_program_name() << " with arguments: ";

		for (const std::string& argument : arguments)
		{
			std::cout << argument << ' ';
		}
		std::cout << std::endl;

		std::cout << "Press the enter key to exit." << std::endl;
		std::cin.get();

		std::cout << "Exiting Sandbox application..." << std::endl;

		return static_cast<oudjat::application::exit_code_t>(0);
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
