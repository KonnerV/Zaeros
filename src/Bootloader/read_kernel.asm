
kernel_lfd:
    mov bx, KRNL_OFF
    mov dh, 4
    mov dl, 0x80 ; 0x80 hdd, 0x81 hdd2, 0x00 Floppy-Drive
    pusha
    push dx

    xor ax, ax
    mov ds, ax
    int 0x13
    jc .dsk_err

    mov ah, 0x02
    mov al, dh
    mov cl, 10
    mov ch, 0x00
    mov dh, 0x00
    int 0x13
    jc .dsk_err

    pop dx
    cmp al, dh
    jne .dsk_err
    popa
    ret

.dsk_err:
    jmp $
