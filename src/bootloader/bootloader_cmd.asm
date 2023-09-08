
cmd_init:
    mov si, wlmsg
    call printstr
    jmp .cmd_loop
.cmd_loop:
    call keyboard_get
    cmp al, 0xd
    je .cmd_entered
    jmp .cmd_loop

.cmd_entered:
    mov si, cmd_prfx
    call printstr
    jmp .cmd_loop

wlmsg: db "Hello and welcome to the KV-Bootloader cmd-line. This is where you will configure certain kernel options before booting.", 0xa, 0xd, 0
cmd_prfx: db "| >> ", 0
