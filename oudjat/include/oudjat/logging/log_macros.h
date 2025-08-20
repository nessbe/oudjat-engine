// File:        log_macros.h
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

#include "oudjat/logging/log_message.h"
#include "oudjat/logging/logger.h"
#include "oudjat/logging/logger_db.h"

#ifndef LOGGING_CONFIGURATION
	#define LOGGING_CONFIGURATION "CORE"
#endif

#define LOG(message, level)                                                                                            \
	oudjat::logging::logger_db::get_or_emplace_logger(LOGGING_CONFIGURATION)                                           \
		->log(oudjat::logging::log_message{message, level, LOGGING_CONFIGURATION, __FILE__, __LINE__, __func__})

#define LOG_DEBUG(message) LOG(message, oudjat::logging::log_level::debug)
#define LOG_TRACE(message) LOG(message, oudjat::logging::log_level::trace)
#define LOG_INFO(message) LOG(message, oudjat::logging::log_level::info)
#define LOG_WARNING(message) LOG(message, oudjat::logging::log_level::warning)
#define LOG_ERROR(message) LOG(message, oudjat::logging::log_level::error)
#define LOG_CRITICAL(message) LOG(message, oudjat::logging::log_level::critical)
