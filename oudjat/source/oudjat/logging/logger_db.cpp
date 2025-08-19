// File:        logger_db.cpp
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

#include "oudjat/logging/logger_db.h"

#include <functional>

#include "oudjat/utils.h"

namespace oudjat
{
	namespace logging
	{
		bool logger_db::has_logger(const std::string& configuration)
		{
			return loggers_.find(configuration) != loggers_.end();
		}

		reference<logger> logger_db::get_logger(const std::string& configuration)
		{
			auto it = loggers_.find(configuration);
			return it != loggers_.end() ? it->second : nullptr;
		}

		bool logger_db::add_logger(reference<logger> logger)
		{
			if (!logger)
			{
				return false;
			}
			return loggers_.emplace(logger->get_configuration(), std::move(logger)).second;
		}

		bool logger_db::remove_logger(const std::string& configuration)
		{
			return loggers_.erase(configuration) > 0;
		}

		reference<logger> logger_db::emplace_logger(const std::string& configuration)
		{
			auto [it, inserted] =
				loggers_.try_emplace(configuration, std::make_shared<logger>(configuration));
			return inserted ? it->second : nullptr;
		}

		reference<logger> logger_db::get_or_emplace_logger(const std::string& configuration)
		{
			reference<logger> logger = emplace_logger(configuration);
			return logger ? logger : loggers_[configuration];
		}

		std::unordered_map<std::string, reference<logger>> logger_db::loggers_;
	}
}
