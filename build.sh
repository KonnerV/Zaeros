#!/bin/bash

# Bootloader compilation
nasm bootfile.asm -f bin -o bootloader.bin

# Kernel compilation
nasm kernel_entry.asm -f elf -o kernel_entry.o
gcc -g -m32 -fno-pie -ffreestanding -c kernel.c -o kernel.o
gcc -g -m32 -fno-pie -ffreestanding -c vga_write.c -o vga_write.o
gcc -g -m32 -fno-pie -ffreestanding -c io.c -o io.o
gcc -g -m32 -fno-pie -ffreestanding -c pc_spkr.c -o pc_spkr.o
# Linking the Kernel
ld -m elf_i386 -o krnl.bin -Ttext 0x1000 kernel_entry.o kernel.o io.o pc_spkr.o vga_write.o --oformat binary

# Merging the Kernel and Bootloader
cat bootloader.bin krnl.bin > os.bin

# Emulating it
qemu-system-x86_64 -hda os.bin
