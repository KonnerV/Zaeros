#!/bin/bash

# Bootloader compilation
nasm ./Bootloader/bootfile.asm -f bin -o bootloader.bin

# Kernel compilation
nasm ./Kernel/kernel_entry.asm -f elf -o kernel_entry.o
nasm -f elf32 ./Kernel/io.asm -o io.o
nasm -f elf32 ./Kernel/idt/idt.asm -o idtasm.o
nasm -f elf32 ./Kernel/drivers/keyboard_driver.asm -o keyboard_asm.o

gcc -m32 -ffreestanding -fno-pie -fno-stack-protector -c ./Kernel/kernel.c -o kernel.o
gcc -m32 -ffreestanding -fno-pie -fno-stack-protector -c ./Kernel/idt/idt.c -o idtc.o
gcc -m32 -ffreestanding -fno-pie -fno-stack-protector -c ./Kernel/graphics/vga_write.c -o vga_write.o
gcc -m32 -ffreestanding -fno-pie -fno-stack-protector -c ./Kernel/libk/string.c -o string.o
gcc -m32 -ffreestanding -fno-pie -fno-stack-protector -c ./Kernel/drivers/pc_spkr.c -o pc_spkr.o
gcc -m32 -ffreestanding -fno-pie -fno-stack-protector -c ./Kernel/drivers/keyboard.c -o keyboard.o

ld -m elf_i386 -T linker.ld -o krnl.bin kernel_entry.o io.o keyboard_asm.o idtasm.o idtc.o keyboard.o kernel.o vga_write.o string.o pc_spkr.o -z noexecstack

# Creating an ISO with the appropriate size to hold the OS binary data
dd if=/dev/zero of=zaeros.iso bs=512 count=22
# Writing the OS binary data into the ISO file
dd if=./os.bin of=zaeros.iso bs=512 count=22

# Merging the Kernel and Bootloader
cat bootloader.bin krnl.bin > os.bin

qemu-system-i386 -hda zaeros.iso -audiodev pa,id=snd0 -machine pcspk-audiodev=snd0
