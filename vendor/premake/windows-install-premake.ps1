# File:        windows-install-premake.ps1
# Project:     oudjat-engine
# Repository:  https://github.com/nessbe/oudjat-engine
#
# Copyright (c) 2025 nessbe
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at:
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# For more details, see the LICENSE file at the root of the project.

# Force TLS 1.2 for GitHub API communication
[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12

# Download and install automatically the last version of Premake
$repo =  "premake/premake-core"
$apiUrl = "https://api.github.com/repos/$repo/releases/latest"

Write-Host "Fetching the last version of Premake..."
$latest = Invoke-RestMethod -Uri $apiUrl
$asset = $latest.assets | Where-Object { $_.name -match "windows.zip" } | Select-Object -First 1

if (-not $asset) {
	Write-Error "No Windows asset found in the latest release."
	exit 1
}

$destDir = "bin"
$tempFile = Join-Path $env:TEMP "premake.zip"

# Create destination directory if needed
if (-not (Test-Path $destDir)) {
	New-Item -ItemType Directory -Path $destDir | Out-Null
}

# Remove any existing Premake executable
$existing = Get-ChildItem -Path $destDir -Filter "premake*.exe" -File
if ($existing) {
	Write-Host "Removing old premake executable..."
	Remove-Item $existing.FullName -Force
}

Write-Host "Downloading premake from $($asset.browser_download_url)..."
Invoke-WebRequest $asset.browser_download_url -OutFile $tempFile

Write-Host "Extracting..."
Expand-Archive -Path $tempFile -DestinationPath $destDir

Write-Host "Premake sucessfully installed in $destDir!"
