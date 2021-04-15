
# ZAINAB GHAURI
# CMS ID : 296357
# CAO - ASSIGNMENT 

# Our 64-Bit-OS-Kernel- 
PRINTING STRING OF LETTERS ( NUST ) USING THIS :

The Repository holds all the code neccesary for making an OS.

# Prerequisites
A text editor such as VS Code.
Docker for creating our build-environment.
Qemu for emulating our operating system.
Remember to add Qemu to the path so that you can access it from your command-line. (Windows instructions here)

# For Windows ( in my case )
Enter build environment
1. Windows (PowerShell): docker run --rm -it -v "${pwd}:/root/env" myos-buildenv
2. Linux or MacOS: docker run --rm -it -v "$pwd":/root/env myos-buildenv

# Build for x86 (other architectures may come in the future):

make build-x86_64
To leave the build environment, enter exit.

# Emulate
You can emulate your operating system using Qemu: (Don't forget to add qemu to your path!)

qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso
NOTE: When building your operating system, if changes to your code fail to compile, ensure your QEMU emulator has been closed, as this will block writing to kernel.iso.

# For C and C++ libraries you will need to install
 1.minGW-w64
 2.Link : https://sourceforge.net/projects/mingw-w64/
# The qemu screen will be displayed where the specified string is printed
