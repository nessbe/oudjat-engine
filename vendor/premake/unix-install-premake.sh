# File:        unix-install-premake.sh
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

#!/usr/bin/env bash
set -e

REPO="premake/premake-core"
API_URL="https://api.github.com/repos/$REPO/releases/latest"
DEST_DIR="bin"
TEMP_FILE="/tmp/premake.tar.gz"

# Detect user platform (Linux or macOS)
PLATFORM=""

if [[ "$(uname)" == "Darwin" ]]; then
	PLATFORM="macosx"
elif [[ "$(uname)" == "Linux" ]]; then
	PLATFORM="linux"

else
	echo "Unsupported platform: $(uname)."
	exit 1
fi

echo "Detected platform: $PLATFORM."

echo "Fetching the latest Premake release for $PLATFORM..."

ASSET_URL=$(curl -s "$API_URL" | grep "browser_download_url" | grep "$PLATFORM.tar.gz" | cut -d '"' -f 4)

if [ -z "$ASSET_URL" ]; then
	echo "No $PLATFORM asset found in the latest release."
	exit 1
fi

# Create destination directory if needed
mkdir -p "$DEST_DIR"

# Remove any existing Premake executable
find "$DEST_DIR" -type f -name "premake*" -exec rm -f {} \;

echo "Downloading Premake from $ASSET_URL..."
curl -L "$ASSET_URL" -o "$TEMP_FILE"

echo "Extracting..."
tar -xzf "$TEMP_FILE" -C "$DEST_DIR"

# Make the Premake binary executable
chmod +x "$DEST_DIR/"premake*

echo "Premake installed successfully to $DEST_DIR!"
