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
Windows support at the moment is very precarious so this is provided that you either have WSL or another way of emulating a Linux machine.
Then you follow the same instructions as with the Linux build, though, this may be virtualised under a hypervisor of sorts.
```bash
git clone https://github.com/KonnerV/Zaeros
```
Then, build and run it using the _build.sh_ file:
```bash
./build.sh
```

## Running and support
This Operating system current runs in 32-bit protected mode with the A20 Line enabled so mostly all of the memory is avvailable to the kernel.
However, **This Operating System doesn't have support for ARM or RISC-V processors as of yet**, though, this is an issue we're actively working to resolve.

I'm currently unsure if it works on real hardware as due to it's primitive nature it has only been ran on a qemu-i386 and qemu-x86_64 Virtual Machine, however, **In theory it should work on basic x86_64 BIOS CPUs**.

| Platform          | Is supported? |
| :---------------- | ------------: |
| x86               |           Yes |
| ARM               |            No |
| MIPS              |            No |
| PPC               |            No |
