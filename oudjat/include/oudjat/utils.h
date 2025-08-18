// File:        utils.h
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

#define ITERATOR_WRAPPER(type, member)                                                                                 \
	OUDJAT_API OUDJAT_GETTER std::vector<type>::iterator begin() noexcept                                              \
	{                                                                                                                  \
		return member.begin();                                                                                         \
	}                                                                                                                  \
	OUDJAT_API OUDJAT_GETTER std::vector<type>::iterator end() noexcept                                                \
	{                                                                                                                  \
		return member.end();                                                                                           \
	}                                                                                                                  \
	OUDJAT_API OUDJAT_GETTER std::vector<type>::const_iterator cbegin() const noexcept                                 \
	{                                                                                                                  \
		return member.cbegin();                                                                                        \
	}                                                                                                                  \
	OUDJAT_API OUDJAT_GETTER std::vector<type>::const_iterator cend() const noexcept                                   \
	{                                                                                                                  \
		return member.cend();                                                                                          \
	}                                                                                                                  \
	OUDJAT_API OUDJAT_GETTER std::vector<type>::reverse_iterator rbegin() noexcept                                     \
	{                                                                                                                  \
		return member.rbegin();                                                                                        \
	}                                                                                                                  \
	OUDJAT_API OUDJAT_GETTER std::vector<type>::reverse_iterator rend() noexcept                                       \
	{                                                                                                                  \
		return member.rend();                                                                                          \
	}                                                                                                                  \
	OUDJAT_API OUDJAT_GETTER std::vector<type>::const_reverse_iterator crbegin() const noexcept                        \
	{                                                                                                                  \
		return member.crbegin();                                                                                       \
	}                                                                                                                  \
	OUDJAT_API OUDJAT_GETTER std::vector<type>::const_reverse_iterator crend() const noexcept                          \
	{                                                                                                                  \
		return member.crend();                                                                                         \
	}
