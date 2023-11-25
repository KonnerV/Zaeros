global cpuid_c

.is_cpuidsupported:
    pushfd
    pushfd
    xor dword [esp], 0x00200000
    popfd
    pushfd
    pop eax
    xor eax, [esp]
    popfd
    and eax, 0x00200000
    ret

.err:
    cli
    jmp $

cpuid_c:
    call .is_cpuidsupported
    jz .err
    mov eax, 0x0
    cpuid
    ret
