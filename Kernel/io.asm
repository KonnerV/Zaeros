[bits 32]
global outb
global inb

outb:
    mov edx, [esp + 4]    
    mov al, [esp + 4 + 4]  
    out dx, al  
    ret

inb:
    mov edx, [esp + 4]                            
    in al, dx                                      
    ret
