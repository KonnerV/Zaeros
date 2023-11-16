[bits 32]
global lidt
lidt:
    mov edx, [esp + 4]
    lidt [edx]
    sti
    ret
