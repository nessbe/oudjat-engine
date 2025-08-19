// File:		windows_window.cpp
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

#include "platforms/windows/windows_window.h"

#ifdef _WIN32

	#include <conio.h>

namespace oudjat
{
	windows_window::~windows_window()
	{
		close();
	}

	bool windows_window::is_vsync() const noexcept
	{
		return is_vsync_;
	}

	void windows_window::set_vsync(bool enabled) noexcept
	{
		is_vsync_ = enabled;
	}

	void* windows_window::get_native_handle() const noexcept
	{
		return window_handle_;
	}

	void windows_window::open()
	{
		instance_handle_ = GetModuleHandle(nullptr);

		register_window_class(CLASS_NAME);

		DWORD style = WS_OVERLAPPEDWINDOW;

		RECT rect = {0, 0, static_cast<LONG>(width_), static_cast<LONG>(height_)};
		AdjustWindowRect(&rect, style, FALSE);

		std::wstring window_class_name = CLASS_NAME;
		std::wstring window_title = get_wide_title();

		window_handle_ = CreateWindowEx(0,
										window_class_name.c_str(),
										window_title.c_str(),
										style,
										CW_USEDEFAULT,
										CW_USEDEFAULT,
										rect.right - rect.left,
										rect.bottom - rect.top,
										NULL,
										NULL,
										instance_handle_,
										this);

		show();
		UpdateWindow(window_handle_);
	}

	std::optional<exit_code> windows_window::update()
	{
		MSG message = {};

		while (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
			{
				return exit_code::success;
			}

			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		if (_kbhit())
		{
			int c = _getch();
			if (c == '\r')
			{
				return exit_code::success;
			}
		}
		return std::nullopt;
	}

	void windows_window::close()
	{
		if (window_handle_)
		{
			DestroyWindow(window_handle_);
			window_handle_ = nullptr;
		}
	}

	void windows_window::show()
	{
		if (window_handle_)
		{
			ShowWindow(window_handle_, SW_SHOW);
		}

		is_visible_ = true;
	}

	void windows_window::hide()
	{
		if (window_handle_)
		{
			ShowWindow(window_handle_, SW_HIDE);
		}

		is_visible_ = false;
	}

	std::size_t windows_window::window_count_ = 0;

	LRESULT CALLBACK windows_window::window_procedure(HWND window_handle, UINT message, WPARAM wide_parameter,
													  LPARAM long_parameter)
	{
		windows_window* window = nullptr;

		if (message == WM_NCCREATE)
		{
			CREATESTRUCT* create_struct = reinterpret_cast<CREATESTRUCT*>(long_parameter);
			window = static_cast<windows_window*>(create_struct->lpCreateParams);
			SetWindowLongPtr(window_handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));
		}
		else
		{
			window = reinterpret_cast<windows_window*>(GetWindowLongPtr(window_handle, GWLP_USERDATA));
		}

		switch (message)
		{
		case WM_CREATE:
			window_count_++;

			if (window)
			{
				LOG_INFO("Opening " + window->get_title() + " window...");
			}

			break;

		case WM_DESTROY:
			window_count_--;

			if (window)
			{
				LOG_INFO("Closing " + window->get_title() + " window...");
			}

			if (window_count_ <= 0)
			{
				LOG_INFO("No more windows open, quitting...");
				PostQuitMessage(0);
			}
			return 0;
		}

		return DefWindowProc(window_handle, message, wide_parameter, long_parameter);
	}

	std::wstring windows_window::get_wide_title() const
	{
		return std::wstring(title_.begin(), title_.end());
	}

	std::optional<WNDCLASS> windows_window::register_window_class(const std::wstring& class_name)
	{
		if (is_class_registered_)
		{
			return std::nullopt;
		}

		WNDCLASS window_class = {};
		window_class.lpszClassName = class_name.c_str();
		window_class.hInstance = instance_handle_;
		window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
		window_class.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		window_class.lpfnWndProc = window_procedure;

		RegisterClass(&window_class);
		is_class_registered_ = true;

		return window_class;
	}

	bool windows_window::unregister_window_class(const std::wstring& class_name)
	{
		if (!is_class_registered_)
		{
			return false;
		}

		UnregisterClass(class_name.c_str(), instance_handle_);
		is_class_registered_ = false;

		return true;
	}
}

#endif
