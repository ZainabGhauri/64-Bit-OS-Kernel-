
# ZAINAB GHAURI
# CMS ID : 296357
# CAO - ASSIGNMENT 

# Our 64-Bit-OS-Kernel- 
 * Task 1 : CREATING YOUR OWN 64-BIT OPERATING SYSTEM
 * Task 2 : PRINTING STRING OF LETTERS ( NUST ) USING THIS 
 * Task 3 : Create a Static website ( HUGO )
-	We are making a 64 bit OS from the scratch . In this we will make x86 compatible os that is multi boot and then we later on expand to other architecture. This OS is primiarly written in a C and C++ programming language but we also used assembly language in some part of our code where we need hardware specific coding. 
The Repository holds all the code neccesary for making an OS.

# Prerequisites
1. A text editor such as VS Code.
2. Docker for creating our build-environment. (( to simplify the building process and it will allow us to create a reproducible build env)
3. Qemu for emulating our operating system.
4. Remember to add Qemu to the path so that you can access it from your command-line. (Windows instructions here)
5. Nasm Grub
6. Mingw64 ( GCC Complier )
7. Hugo
8. Chocalatey ( For windows )

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

#	Output :
In the Last step we made a Make file ,  Make is handy tool for organizing all of our build commands. After we are done with above mentioned steps , we will open the terminal inside the docker container followed by  build x86_64 , after that we can exit the docker container by writing 'exit' on the terminal & using qemu we will emulate the OS And the text will be printed on the screen.  


# Detailed Description For this Assignment :
- the description for this Assignment is attached in a **word file** with this and also the **desciption is given in the website too**.

# For C and C++ libraries you will need to install
 1.minGW-w64
 2.Link : https://sourceforge.net/projects/mingw-w64/
 
#Links for the installations 
> Links:
   1. VS Code :     (https://code.visualstudio.com/download)
   2. Docker :      (https://www.docker.com/products/docker-desktop)
   3. Qemu :        (https://www.qemu.org/download/)
   4. Mingw64       (https://sourceforge.net/projects/mingw-w64/)
   5. Hugo :        (https://gohugo.io/)
   6. Chocalatey :  (https://chocolatey.org/)

# How to add the Path Variable :
  1. Go to * This PC* .
  2. Right Click on the *This PC* icon.
  3. A new Window will open , From there go to the Advanced Settings.
  4. A Dialogue Box will appear , Click on the *Environment Variables* from there.
  5. Now click on path , then select Edit and from there
     add a *path , where is qemu * there.
  6. Click **ok** when done.
