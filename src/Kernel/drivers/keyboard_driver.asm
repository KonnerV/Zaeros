[bits 32]

global key_handle
extern key_handle_f

key_handle:                 
    call key_handle_f
    iretd
