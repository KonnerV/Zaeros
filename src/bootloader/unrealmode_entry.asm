
init_unreal:
    jmp .save_realstate
.save_realstate:
    ; initialising ax, data-segment, stack-segment registers to 0
    mov ax, 0
    mov ds, ax
    mov ss, ax
    ; Moving the stack-pointer 0x2000 away from the bootloader's starting point
    mov sp, 0x9c00
    ; Disabling interrupts && saving real mode
    cli
    push ds
    ; loading the gdt into the gdt register
    lgdt [gdtinfo]

    ; enabling the protected mode bit and making the jump into protected mode
    mov eax, cr0
    or al, 1
    mov cr0, eax
    jmp 0x8:prot_mode
prot_mode:
    mov bx, 0x10 ; selecting descriptor 2
    mov ds, bx ; moving the descriptor into the data segment register

    and al,0xfe ; re-enabling real mode whilst still having extra memory loaded
    mov cr0, eax
    jmp 0x0:unreal ; now we enter unreal mode
    ; This allows us to use basic BIOS interrupts and have up to approx. 4GiB of memory
    ; around 4 GiB should be suffiecient to get everything working before we launch the kernel.

; some basic gdt information that'd allowed us to use protected mode to jump to unreal mode
gdtinfo:
   dw gdt_end - gdt - 1
   dd gdt
gdt: dd 0,0 ; entry 0 is always unused
codedesc: db 0xff, 0xff, 0, 0, 0, 10011010b, 00000000b, 0
flatdesc: db 0xff, 0xff, 0, 0, 0, 10010010b, 11001111b, 0
gdt_end:

