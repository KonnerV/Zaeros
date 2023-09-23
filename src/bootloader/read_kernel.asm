load_kernel:
    xor ax, ax
    mov ds, ax

    cli
    mov ss, ax
    mov sp, 0x7c00
    sti


    xor ax, ax
    int 0x13
    jc .dsk_err

    mov ax, 0x1000
    xor bx, bx
    mov es, bx
    mov bx, 0x1000

    mov ah, 0x02 ;2
    mov al, 0x01
    mov cl, 0x01
    mov ch, 0
    mov dh, 0
    int 0x13
    jc .dsk_err
    cmp al, 1
    jne .dsk_err

    mov si, dsk_ok
    call printstr
    call enable_pmode
    call 0x1000 ;8h:0x1000
    ret
    ;jmp enable_pmode

.dsk_err:
    mov si, err_msg
    call printstr
dsk_ok: db "Disk [Works]", 0xa, 0xd, 0
err_msg: db "Error reading 0x1000 from disk", 0xa, 0xd, 0
