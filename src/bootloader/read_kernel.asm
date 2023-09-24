load_kernel:
    xor ax, ax
    mov ds, ax

    cli
    mov ss, ax
    mov sp, 0x7c00
    sti

    xor ax, ax
    int 0x13
    jc dsk_err

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
    jc dsk_err
    cmp al, 1
    jne dsk_err

    mov si, dsk_ok
    call printstr

    call is_A20
    call enable_pmode
dsk_err:
    mov si, err_msg
    call printstr
is_A20:
    pusha
    mov ax, 2403h
    int 0x15
    jb dsk_err
    cmp ah, 0
    jnz dsk_err
    mov ax, 2402h
    int 0x15
    jb dsk_err
    cmp ah, 0
    jnz dsk_err
    cmp al, 1
    jz A20_on
    mov ax, 2401h
    int 0x15
    jb dsk_err
    cmp ah, 0
    jnz dsk_err
    popa
    ret
A20_on:
    call enable_pmode
    mov word[ds:eax], 0x0f51
    jmp $
dsk_ok: db "Disk [Works]", 0xa, 0xd, 0
err_msg: db "Error reading 0x1000 from disk", 0xa, 0xd, 0
