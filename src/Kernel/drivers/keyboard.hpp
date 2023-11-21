#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

#include "../graphics/vga_write.hpp"

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif  
    extern unsigned char key_map[128];
    extern void key_handle(void);
    extern void outb(uint16_t p, uint8_t data);
    extern char inb(uint16_t p);
#ifdef __cplusplus
}
#endif

namespace Device_Driver {
    class PS2_Keyboard {
        public:
            PS2_Keyboard();
            static void key_handle_f(void);
        private:
            static inline VGA::tty PS2_VGA_Interface;
    };
    extern "C" void key_handle_f_wrapper(void);
}

#endif
