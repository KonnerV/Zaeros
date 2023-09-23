;[org 0x0000]
enable_pmode:
    
    cli
    lgdt [gdtinfo]
    mov eax, cr0
    or al, 1
    mov cr0, eax
    ;[bits 32]
    ;jmp 8h:0x1000
    jmp 8h:pmode

pmode:
    mov ax, 0x10 ; selector 2
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov sp, 0x3000
    mov eax, 0x0b8000
    mov word[ds:eax], 0x0f50
    ;jmp 0x0000:0x1000
    [bits 32]
    ;jmp 0x1000
    jmp $

gdtinfo: 
   dw gdt_end - gdt - 1
   dd gdt
gdt: dd 0,0
codedesc: db 0xff, 0xff, 0, 0, 0, 10011010b, 00000000b, 0
flatdesc: db 0xff, 0xff, 0, 0, 0, 10010010b, 11001111b, 0
gdt_end:
