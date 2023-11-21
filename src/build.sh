#!/bin/bash

# Bootloader compilation
nasm ./Bootloader/bootfile.asm -f bin -o bootloader.bin

# Kernel compilation
nasm ./Kernel/kernel_entry.asm -f elf -o kernel_entry.o
nasm -f elf32 ./Kernel/io.asm -o io.o
nasm -f elf32 ./Kernel/idt/idt.asm -o idtasm.o
nasm -f elf32 ./Kernel/drivers/keyboard_driver.asm -o keyboard_asm.o
nasm -f elf32 ./Kernel/cpuidentifier.asm -o cpu.o

g++ -m32 -ffreestanding -fno-pie -fno-stack-protector -c ./Kernel/kernel.cpp -o kernel.o
g++ -m32 -ffreestanding -fno-pie -fno-stack-protector -c ./Kernel/idt/idt.cpp -o idtc.o
g++ -m32 -ffreestanding -fno-pie -fno-stack-protector -c ./Kernel/graphics/vga_write.cpp -o vga_write.o
gcc -m32 -ffreestanding -fno-pie -fno-stack-protector -c ./Kernel/libk/string.c -o string.o
g++ -m32 -ffreestanding -fno-pie -fno-stack-protector -c ./Kernel/drivers/pc_spkr.cpp -o pc_spkr.o
g++ -m32 -ffreestanding -fno-pie -fno-stack-protector -c ./Kernel/drivers/keyboard.cpp -o keyboard.o

ld -m elf_i386 -T linker.ld -o krnl.bin kernel_entry.o pc_spkr.o kernel.o cpu.o vga_write.o string.o io.o idtasm.o idtc.o keyboard_asm.o keyboard.o -z noexecstack

# Merging the Kernel and Bootloader
cat bootloader.bin krnl.bin > os.bin

# Creating an ISO with the appropriate size to hold the OS binary data
#dd if=/dev/zero of=zaeros.iso bs=512 count=22
# Writing the OS binary data into the ISO file
#dd if=./os.bin of=zaeros.iso bs=512 count=22

qemu-system-i386 -hda os.bin -audiodev pa,id=snd0 -machine pcspk-audiodev=snd0
