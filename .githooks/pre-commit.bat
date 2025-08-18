:: File:        pre-commit.bat
:: Project:     oudjat-engine
:: Repository:  https://github.com/nessbe/oudjat-engine
::
:: Copyright (c) 2025 nessbe
:: Licensed under the Apache License, Version 2.0 (the "License");
:: you may not use this file except in compliance with the License.
:: You may obtain a copy of the License at:
::
::     https://www.apache.org/licenses/LICENSE-2.0
::
:: Unless required by applicable law or agreed to in writing, software
:: distributed under the License is distributed on an "AS IS" BASIS,
:: WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
:: See the License for the specific language governing permissions and
:: limitations under the License.
::
:: For more details, see the LICENSE file at the root of the project.

@echo off

:: Pre-commit hook to format C++ files with clang-format before commit

REM Get all staged .cpp and .h files
for /f "delims=" %%f in ('git diff --cached --name-only --diff-filter=ACM ^| findstr /r "\.cpp$ \.h$"') do (
    echo Formatting %%f...
    clang-format -i "%%f"
    git add "%%f"
)

:: Exit successfully
exit 0
