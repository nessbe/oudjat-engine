:: File:        format.bat
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
setlocal enabledelayedexpansion

set "ROOT_DIR=.."

:: Check if clang-format is installed
clang-format --version >nul 2>&1
if errorlevel 1 (
    echo clang-format not found. Please install it or add it to the PATH.
    pause
    exit /b 1
)

cd /d "%ROOT_DIR%"

:: Get start time
for /f "tokens=1-4 delims=:., " %%a in ("%TIME%") do (
    set "HH=%%a"
    set "MM=%%b"
    set "SS=%%c"
    if "%%d"=="" (
        set "MS=0"
    ) else (
        set "MS=%%d"
    )
)
:: Remove leading spaces if any
set /a HH=1%HH%-100
set /a MM=1%MM%-100
set /a SS=1%SS%-100
set /a MS=1%MS%-100

set /a START_TOTAL_MS=(HH*3600 + MM*60 + SS)*1000 + MS*10

:: Initialize formatted file counter
set /a FORMATTED_FILE_COUNT=0

:: Format only *.cpp and *.h files recursively
for /r %%f in (*) do (
    set "ext=%%~xf"
    set "ext=!ext:~1!"
    if /i "!ext!"=="cpp" (
        echo Formatting %%f...
        clang-format -i "%%f"
        set /a FORMATTED_FILE_COUNT+=1
    ) else if /i "!ext!"=="h" (
        echo Formatting %%f...
        clang-format -i "%%f"
        set /a FORMATTED_FILE_COUNT+=1
    )
)

:: Get end time
for /f "tokens=1-4 delims=:., " %%a in ("%TIME%") do (
    set "HH=%%a"
    set "MM=%%b"
    set "SS=%%c"
    if "%%d"=="" (
        set "MS=0"
    ) else (
        set "MS=%%d"
    )
)
:: Remove leading spaces if any
set /a HH=1%HH%-100
set /a MM=1%MM%-100
set /a SS=1%SS%-100
set /a MS=1%MS%-100

set /a END_TOTAL_MS=(HH*3600 + MM*60 + SS)*1000 + MS*10

:: Calculate elapsed time in milliseconds
set /a ELAPSED_MS=END_TOTAL_MS-START_TOTAL_MS
if %ELAPSED_MS% LSS 0 set /a ELAPSED_MS+=24*3600*1000

set /a ELAPSED_S=ELAPSED_MS/1000
set /a ELAPSED_MS=ELAPSED_MS%%1000

echo.
echo Formatted %FORMATTED_FILE_COUNT% file(s) in %ELAPSED_S%.%ELAPSED_MS% second(s).

pause
