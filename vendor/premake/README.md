# Premake

Premake is a build configuration tool that allows you to generate project files for various **IDEs** and build systems using simple **Lua** scripts. It simplifies the process of managing complex build configurations across multiple platforms.

For more information, visit the official **Premake** repository:  
https://github.com/premake/premake-core

---

## License

This project is licensed under the **Apache License**, Version 2.0. See the `LICENSE` file in this directory for details.

---

## Installing Premake

This folder contains scripts to automatically download and install the latest version of **Premake** for your platform.

### Prerequisites

Before running the install scripts, please ensure the following:

- **Windows**: You may need to temporarily relax **PowerShell's** execution policy. Run **PowerShell** as **Administrator** and execute:  
  `Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass`

- **Linux**: You may need to install required commands such as `curl`, `tar`, and `grp` using your package manager with `sudo`. For example, on **Debian**/**Ubuntu**:  

  `sudo apt-get update`  
  `sudo apt-get install curl tar grep`

- **macOS**: You should have [Homebrew](https://brew.sh) installed. If not, install it first using:  
  `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`  
    
  Then use it to install required commands if they are missing:  
  `brew install curl tar grep`

---

### Installation Instructions by OS

#### Windows

Run the PowerShell script to download and install **Premake**:

`.\windows-install-premake.ps1`

This script will download the latest **Windows** release, remove any previous versions in the `bin` folder, and extract the new executable.

---

#### Linux and macOS

Make the Unix install script executable and run it:

`chmod +x unix-install-premake.sh`  
`./unix-install-premake.sh`

This script will detect your **OS** (**Linux** or **macOS**), download the latest release for your platform, remove previous **Premake** binaries from `bin`, and extract the new version.

---

## Notes

- Both scripts place the **Premake** executable in the `bin` directory relative to this folder.
- Ensure you have required tools installed (`curl`, `tar`, `grep`, etc.). The **Unix** script expects these tools to be available.
- On **Linux** and **macOS**, you may need to run the script with `sudo` if permissions require it.
- You can add the **Premake** executable to your system's `PATH` for easier access.

---

Feel free to contribute or report issues on the official **Premake** **GitHub** repository.

---
