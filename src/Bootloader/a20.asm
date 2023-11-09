is_A20:
    pusha
    mov ax, 0x2403
    int 0x15
    jb dsk_err
    cmp ah, 0
    jnz dsk_err
    mov ax, 0x2402
    int 0x15
    jb dsk_err
    cmp ah, 0
    jnz dsk_err
    cmp al, 1
    jz A20_on
    mov ax, 0x2401
    int 0x15
    jb dsk_err
    cmp ah, 0
    jnz dsk_err
    popa
    ret
dsk_err:
    jmp $
A20_on:
    mov si, success_a20
    call printstr
    jmp A20_enabled
success_a20: db "Success a20", 0xa, 0xd, 0
