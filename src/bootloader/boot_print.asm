; Code for printing text to the screen
printstr:
    ; moving hex 0e into ah. This is required for printing
    mov ah, 0x0e
.printchr:
    lodsb ; get a character from the string stored in si
    cmp al, 0 ; checking if it's a null terminator 
    jz .finish ; if it is then it's the end of the string and we jump to the .finish label
    int 0x10 ; calling BIOS interrupt 0x10 to print the current charcter to the screen
    jmp .printchr ; looping back
.finish:
    cli ; disables interrupts
    hlt ; and stops the CPU
