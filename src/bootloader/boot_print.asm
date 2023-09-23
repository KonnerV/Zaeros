
printstr:
; Code for printing text to the screen
    ; moving hex 0e into ah. This is required for printing
    mov ah, 0x0e
    jmp .printchr
.printchr:
    lodsb ; get a character from the string stored in si
    cmp al, 0 ; checking if it's a null terminator 
    jz .finish ; if it is then it's the end of the string and we jump to the .finish label
    int 0x10 ; calling BIOS interrupt 0x10 to print the current charcter to the screen
    jmp .printchr ; looping back
.finish:
    ret
