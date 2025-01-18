# Installation Guide

Follow the steps below to set up your development environment with the required tools.

---

## 1. Open MSYS2

You can choose one of the following MSYS2 environments:

- **MSYS2 MINGW-W64**
- **MSYS2 MSYS**
- **MSYS2 UCRT64**

---

## 2. Install Compiler and Debugger

To install the required tools (GCC, G++, and GDB), execute the following commands in your MSYS2 terminal:

```bash
# Update the package database and system
pacman -Syu
pacman -Su

# Search for the GCC package
pacman -Ss gcc

# Install GCC and G++ for MINGW-w64
pacman -S mingw-w64-x86_64-gcc

# Search for the GDB package
pacman -Ss gdb

# Install GDB for MINGW-w64
pacman -S mingw-w64-x86_64-gdb

```

## 3. Verify the Installation
After installation, confirm that the compiler and debugger are installed correctly by running the following commands:

gcc --version
g++ --version
gdb --version
You should see the versions of the installed tools if everything is set up correctly.

## 4. Install an IDE
You need an Integrated Development Environment (IDE) to write and compile your code. Below are two recommended IDEs:

Code::Blocks
An open-source IDE with a built-in GCC compiler for Windows.

Visual Studio Code
A lightweight and powerful IDE with support for extensions, including C++ development tools.

IDE Installation Instructions
Code::Blocks:

Download the installer from the link above.
Follow the installation instructions to set up Code::Blocks with the MINGW-w64 toolchain.
Visual Studio Code:

Download the installer from the link above.
Install the C++ extension for Visual Studio Code to enable C++ development features.

## 5. Additional Resources
**MSYS2** Website: https://www.msys2.org/

**Code::Blocks** Website: https://www.codeblocks.org/

**Visual Studio Code** Website: https://code.visualstudio.com/
