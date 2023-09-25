
kernel_lfd:
    mov bx, KRNL_OFF
    mov dh, 2
    mov dl, 0
    pusha
    push dx

    xor ax, ax
    mov ds, ax
    int 0x13
    jc .dsk_err

    mov ah, 0x02
    mov al, dh
    mov cl, 0x02
    mov ch, 0x00
    ; 0x80 hdd 0x81 hdd2
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
