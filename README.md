# ZAEROS - The hobbyist Operating System

## About
Zaeros is a lightweight kernel and bootloader for hobbyists. This Operating-System is no way able to be used as a daily-driver or even for minimal functionality as of yet, though, I'm working to improve the operating system's functionality.
This Operating System is made as a side-project and only intended for learning purposes, however, you can fork and modify the source code; Even feel free to use it yourself!

The bootloader is made with the intention of being robust and allowing for a more customisable experience. I aim to allow the user to tell the bootloader where their kernel location is and even some other features or possibly even just use the bootloade as the minimal functionality required!
This Bootloader customisability may allow for a wide variety of kernels to be used. Feel free to fork and modify the kernel and swap it for your own if that's what you want.

Obviously, this project is a Work-In-Progress and very much within the early stages of development so you can most likely expect drastic changes and updates from myself and even the community if they would like to contibute.

The kernel is currently being made and will mostly likely be uploaded here soon so, please, be prepared.

## Contibuting && Forks
Anyone is allowed to fork the repository and modify the code so long as it fits under the Apache 2.0 licensing, which, tends to give quite a lot of freedom with what you can do with the softwares.
It must be remembered that if you were to make a pull request to the repository it must be fully evaluated and checked by myself or the developer team so you could expect quite long wait times when contributing.

## Support
As of recent, It's recommended that you join my [discord](https://discord.gg/WSx336WCCe) server and ask for support there.

## Docs
Docs will be released when V1.0.0 is released for now you probably have to rely on support from the [discord](https://discord.gg/WSx336WCCe) server if you wish to modify or help develop the OS.

## Installation && Build
As this is quite primitive there is only the "_build.sh_" file that you can use to compile and run the operating system, though, It is worth noting that work is being done to create a more robust and cross-platform solution.
### _Linux_
Compiling for Linux based systems is rather simple:
First, clone the repository from Github.
You could do this using git:
```bash
git clone https://github.com/KonnerV/Zaeros
```
Then, build and run it using the _build.sh_ file:
```bash
./build.sh
```
### _Windows_
At this current point in time a Windows supported build system is incredibly precarious and continues to be a problem even with bash virtualisers. At a later point in time; I'll implement a simple build system in a more cross platform manner, however, Windows is generally poor when it comes to native Operating System development tooling, so, for now you may attempt to virtualise the build script, though, be warned that it may not work.

### _MacOS_
At this moment in time, I haven't had enough time to write a build system to target MacOS, so, If you use MacOS I do encourage you to take a gander at the "build.sh" and try your best to build it, though, As I had said there will be a cross platform build system.

## Running and support
This Operating system current runs in 32-bit protected mode with the A20 Line enabled so mostly all of the memory is available to the kernel.
However, **This Operating System doesn't have support for ARM or RISC-V processors as of yet**, though, this is an issue we're actively working to resolve.

I'm currently unsure if it works on real hardware as due to it's primitive nature it has only been ran on a qemu-i386 and qemu-x86_64 Virtual Machine, however, **In theory it should work on basic x86_64 BIOS CPUs**.

| Platform          | Is supported? |
| :---------------- | ------------: |
| x86               |           Yes |
| ARM               |            No |
| MIPS              |            No |
| PPC               |            No |

| Firmware          | Is supported? |
| :---------------- | ------------: |
| BIOS              |           Yes |
| UEFI              |            No |

### Operating System Goals/Checklist
#### _Bootloader_
 - [ ] UEFI support
 - [ ] Multi-architecture support
 - [x] BIOS support
 - [x] BIOS Boot
 - [x] BIOS Print
 - [x] GDT
 - [x] Loading Kernel from disk
 - [ ] Loading multiple Kernels dynamically
 - [x] A20 line
 - [x] Protected mode
#### _Kernel_
 - [x] VGA drivers
 - [x] PC Speaker
 - [ ] Sound Blaster 16
 - [x] IDT
 - [x] PS2 Keyboard driver
 - [ ] PS2 Mouse driver
 - [ ] Virtual 8086
 - [ ] VESA drivers
 - [ ] ACPI
 - [ ] ATA
 - [ ] ATAPI
