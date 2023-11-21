#include "keyboard.hpp"
#include "../graphics/vga_write.hpp"
extern "C" {
    #include "keyboard_layout.h"
}

#include <cstdint>

namespace Device_Driver {
    PS2_Keyboard::PS2_Keyboard() {
        outb(0x21, 0xfd);
    }
    void PS2_Keyboard::key_handle_f(void) {
        outb(0x20, 0x20);
        uint8_t stat = inb(0x64);
        if (stat & 0x01) {
            int8_t key = inb(0x60);
            if(key < 0) {
                return;
	    }
	    PS2_VGA_Interface.vga_writec(key_map[(uint8_t) key], VGA::tty::get_colour_code(VGA::Black, VGA::Red), VGA::tty::position);
	    VGA::tty::position+=2;
        }
    }
    extern "C" void key_handle_f_wrapper(void) {
        PS2_Keyboard::key_handle_f();
    }
}
