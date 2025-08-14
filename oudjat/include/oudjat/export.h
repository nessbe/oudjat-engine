// File:        export.h
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

#ifdef _WIN32
	#define EXPORT_ATTRIBUTE __declspec(dllexport)
	#define IMPORT_ATTRIBUTE __declspec(dllimport)
	#define NO_EXPORT_ATTRIBUTE
	#define DEPRECATED_ATTRIBUTE __declspec(deprecated)
#else
	#define EXPORT_ATTRIBUTE __attribute__((visibility("default")))
	#define IMPORT_ATTRIBUTE __attribute__((visibility("default")))
	#define NO_EXPORT_ATTRIBUTE __attribute__((visibility("hidden")))
	#define DEPRECATED_ATTRIBUTE __attribute__((deprecated))
#endif

#ifdef OUDJAT_LINKAGE_STATIC
	#define OUDJAT_API NO_EXPORT_ATTRIBUTE
#elif defined(OUDJAT_LINKAGE_DYNAMIC)
	#ifdef OUDJAT_BUILD_DLL
		#define OUDJAT_API EXPORT_ATTRIBUTE
	#else
		#define OUDJAT_API IMPORT_ATTRIBUTE
	#endif
#else
	#define OUDJAT_API
#endif

#define OUDJAT_NO_API \
	NO_EXPORT_ATTRIBUTE

#define OUDJAT_DEPRECATED \
	DEPRECATED_ATTRIBUTE

#define OUDJAT_DEPRECATED_API \
	OUDJAT_DEPRECATED OUDJAT_API

#define OUDJAT_DEPRECATED_NO_API \
	OUDJAT_DEPRECATED OUDJAT_NO_API
