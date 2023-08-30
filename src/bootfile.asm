bits 32

MBALIGN  equ  1 << 0
MEMINFO  equ  1 << 1
MBFLAGS  equ  MBALIGN | MEMINFO
MAGIC    equ  0x1BADB002
CHECKSUM equ -(MAGIC + MBFLAGS)

section .text
    align 4
    dd MAGIC
    dd MBFLAGS
    dd CHECKSUM

global start
extern kernel_main

start:
    cli
    mov esp, stack_loc
    call kernel_main
    hlt

section .bss
resb 8192
stack_loc:

