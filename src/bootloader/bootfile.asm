[bits 16]
[org 0x7c00]
boot:
    mov si, string
    call printstr

    call init_unreal
unreal:
    pop ds ; restoring the old data-segment
    sti ; re-enabling BIOS interrupts

    mov eax, 0x0b8000 ; VGA-Buffer address

    ; Prints "UR" to the VGA to show that it has worked.
    mov word [ds:eax], 0x0155
    mov word [ds:eax+0x02], 0x0152

    call cmd_init
    jmp $    

.hlt:
    cli ; clear interrupts
    hlt ; stop the CPU

%include "unrealmode_entry.asm"
%include "boot_print.asm"
%include "bios_keyboard.asm"
%include "bootloader_cmd.asm"
string: db "Hello, KV-Bootloader!", 0xa, 0xd, 0


times 510-($-$$) db 0
; Boot signature
dw 0xaa55
