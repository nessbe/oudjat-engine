:: File:        generate-projects.bat
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

:: Change the current directory to the folder containing Premake
cd /d "%~dp0../vendor/premake/bin"

:: Search a file called premake*.exe inside the Premake bin folder
set PREMAKE_EXE=

for %%f in (premake*.exe) do (
	set PREMAKE_EXE=%%f
	goto :found
)

echo No Premake executable found in %cd%.
exit /b 1

:found
echo Found Premake executable: %cd%\%PREMAKE_EXE%.

set PREMAKE_PATH=%cd%\%PREMAKE_EXE%

cd ..\..\..

echo Executing Premake for Visual Studio 2022...

:: Execute Premake for Visual Studio 2022
call %PREMAKE_PATH% vs2022

endlocal
