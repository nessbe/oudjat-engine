// File:        null_sink.h
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

#include "oudjat/io/sinks/file_sink.h"

namespace oudjat
{
	namespace io
	{
		file_sink::file_sink(const std::string& file_path) : file(file_path, std::ios::app) {}

		file_sink::~file_sink()
		{
			if (file.is_open())
			{
				file.close();
			}
		}

		void file_sink::write_raw(const std::string& message)
		{
			if (file.is_open())
			{
				file << message << std::endl;
			}
		}
	}
}
