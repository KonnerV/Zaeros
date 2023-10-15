[bits 16]
[org 0x7c00]

KRNL_OFF equ 0x1000

boot:
    mov dl, 0
    mov bp, 0x2000
    mov sp, bp

    mov si, bt_ok
    call printstr

    call kernel_lfd
    mov si, lfd_ok
    call printstr
    
    call is_A20

A20_enabled:
    mov si, pm_ent
    call printstr
    call enter_pmode 

[bits 32]
enter_kernel:
    call KRNL_OFF
    jmp $

[bits 16]
bt_ok: db "Bootloader init", 0xa, 0xd, 0
lfd_ok: db "Kernel loaded from disk", 0xa, 0xd, 0
pm_ent: db "Entering 32 bit protected mode...", 0xa, 0xd, 0
%include "read_kernel.asm"
%include "gdt.asm"
%include "a20.asm"
%include "enter_prot_mode.asm"
%include "biosprint.asm"
times 510 - ($-$$) db 0
dw 0xaa55
