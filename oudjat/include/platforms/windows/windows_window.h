// File:		windows_window.h
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

#include <string>
#include <optional>

#include "oudjat/export.h"
#include "oudjat/utils.h"

#include "oudjat/window.h"
#include "oudjat/exit_code.h"

#ifdef _WIN32

#include <Windows.h>

namespace oudjat
{
	class windows_window : public window
	{
	public:
		using window::window;
		OUDJAT_API virtual ~windows_window() override;

		OUDJAT_API virtual void open() override;
		OUDJAT_API virtual std::optional<exit_code> update() override;
		OUDJAT_API virtual void close() override;

		OUDJAT_API virtual void show() override;
		OUDJAT_API virtual void hide() override;

		OUDJAT_API OUDJAT_GETTER virtual bool is_vsync() const noexcept override;
		OUDJAT_API OUDJAT_GETTER virtual void set_vsync(bool enabled) noexcept override;

		OUDJAT_API OUDJAT_GETTER virtual void* get_native_handle() const noexcept override;

	private:
		const wchar_t* CLASS_NAME = L"oudjat_window";

		static std::size_t window_count_;

		bool is_class_registered_ = false;

		HWND window_handle_;
		HINSTANCE instance_handle_;

	private:
		OUDJAT_API static LRESULT CALLBACK window_procedure(HWND window_handle, UINT message, WPARAM wide_parameter, LPARAM long_parameter);

		OUDJAT_API std::wstring get_wide_title() const;

		OUDJAT_API std::optional<WNDCLASS> register_window_class(const std::wstring& class_name);
		OUDJAT_API bool unregister_window_class(const std::wstring& class_name);
	};
}

#endif
