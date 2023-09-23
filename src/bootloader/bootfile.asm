[bits 16]
[org 0x7c00]
boot:
    mov si, bl_ok
    call printstr
    
    jmp load_kernel

    jmp $

.hlt:
    cli ; clear interrupts
    hlt ; stop the CPU

%include "boot_print.asm"
%include "read_kernel.asm"
bl_ok: db "KV-Boot [Works]", 0xa, 0xd, 0
times 510-($-$$) db 0
; Boot signature
dw 0xaa55
