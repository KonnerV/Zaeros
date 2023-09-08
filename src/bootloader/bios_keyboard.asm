keyboard_get:
    call .keystroke
    mov ah, 0x0e
    int 0x10
    ret
.keystroke:
    mov ah, 0x00
    int 0x16
    cmp al, 0xd
    je .handle_newline
    ret
.handle_newline:
    mov ah, 0x0e
    mov si, newl
    call printstr
    mov al, 0xd
    ret

newl: db 0xa, 0xd, 0
