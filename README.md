
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

#### Step 1 ( Creates a Docker Image ) :
---
1. A docker image is just like a snapshot of a linux machine with any extra file or software installed onto it. In the first step we create a folder and name it as **buildenv** and in here we will create a **docker file** and this file will describe all the steps we *need to create our build-senv image* 
2. We have added few lines and commands to install some **packages** like the **apt-get command** to install *Nasm* , *Nasm* will allow us to compile the assembly code and the *grub package* to build the final **iso file** ( grub-pc-bin + grub-common) It also set this folder as the starting folder. 
3. Then we open the **Terminal** and build our image. The one thing we should make sure while doing this step is that our docker should be running. For this we should simply write **docker build buildenv –t myosbuildenv**. The name of the folder should be the same we are writting on a terminal.It is just a name of image , i gave it *myosbuildenv*  in my case. For the first time it will take 5 minutes approx .
4.  Now we can open the instance of the image that we called as **Container**. We are in a *virtual linux environment* with all the tools we need. Make sure the docker daemon has access to the drive. 
---

#### Step 2 ( Creating Folder and Respective Files )
   * source folder ( **implementation Folder**)
        1. We create source folder to store all of our source code , I have followed the same name it has in youtube video to avoid errors but one can organize in any way they want. Firstly we create **implementation (impl) folder** , to hold the all the implementation 
        2. Then we created a **x86 file** , this is the *entry point of the Operating System* , We have to integrate it with multi boot 2 , to perform this we created a **boot folder** and inside it we created a **header.asm** file , Inside this assembly file we will add some data which is to be included in the operating system binary.
        3. The boot loader loads first when we turn the computer on , after that the Operating System loads and the duty of a boot loader is to locate the Operating System. We use the multiboot2 Specification that most bootloaders used. In this file we added the header data and its label , and next we add some information about the architecture of our OS.
        4. Now we create a **main.asm** file in a bootloader folder , this assembly file is the *entry point into our Operating System*. Put the desired labels and set the bits ( 32 or 64 bits) in main.asm. The hexa code for word "Ok" is also written in this file that was our task 1 but this will not be used ( the code for 'ok' ) in task 2. In task 2 we will write a **C level programming language code** to print *NUST*. In the end we used the **Hlt** instruction to completely freeze and not run any further.
        5. **For Task 2** For printing a string of characters on the Screen ( Task 2 ) we have to set a Stack , *which will allow us to link in the C code*. We will setup the stack in the **main.asm**. To create stack we followed the same code in the video that we are provided with in the video.Because we haven’t studied these commands yet.We will store the stack address using a var named **stack_top** . In some tasks that we have not studied I copied the code from the github.The concept of **virual addressing** has been carried out here so we will have to create a **page tables** in the main.asm file.
        6. **setting up the page tables** : We have four types of page tables, namely L4, L3, L2, L1, so we will reserve memory for page tables.Using the **Identity Mapping**  physical address to the exact same virtual address so that our instructions are executed that a CPU can read the instructions and treat the address as virtual address.After that we *filled 512 entries of L2* , As each entry takes 2MB so the total will be approx 1GB of physical memory being mapped. Once this is completed *we can return from the subroutine*.After this we will enable the **paging** , for this we will pass the location of that page table to our CPU.The extension for the page table is enabled by **PAE FLAG of cr4**
        6. Then we created a folder named **targets** , in which we made **x86_64** and **linker file (.ld)**. The linker file is *responsible for describing how the Operating System has been linked together*. Then we create an **iso folder** that will contain a group configuration.In that folder we also created boot / grub folder.
        7. After that we created an **interface folder** ( intf) in which we will create a **print.h** file , we will use a **pragma once directive** & will define the printing interface here that we will use in our coding.Various methods for printing is created in this file.Include the libraries like *stdio.h stdnnf.h* etc . Also after that I just copied the color codes from the github file. Then in the **print.c** File , there is a video memory that holds an array of characters , to handle this we created a char struct. The code in these files are not in our lectures so I just copy pasted it.It is basically an implemenation of the **print.h** file.
        8. The **main.c file** , this is the main file whose function **kernel_main** is called for printing the required text or pattern on the screen. (i.e NUST)
        7. In the Last step we made a **Make file** ,  **Make** is handy tool for *organizing all of our build commands*. After we are done with above mentioned steps , we haved open the terminal inside the docker container followed by **build x86_64** , after that some processing has done after it finished we **exit** the docker container by writing exit on the terminal & using **qemu** we will emulate the Operating System by writing **qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso** and the text will be printed on the screen ( NUST using alphabets and special Characters).  


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
