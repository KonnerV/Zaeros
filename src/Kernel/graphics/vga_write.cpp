#include <cstdint>
#include <cstddef>
#include "vga_write.hpp"

namespace VGA {
    uint8_t tty::get_colour_code(colour8_t background, colour8_t foreground) {
        return ((uint8_t)background<<4|(uint8_t)foreground);
    }
    void tty::vga_writec(uint8_t chr, uint8_t colour, uint16_t pos) {
        volatile char* VGA_buffer = (volatile char*) 0xb8000;
        VGA_buffer[pos] = chr;
        VGA_buffer[pos+1] = colour;
    }
    tty::tty() {
        for(size_t i=0;i<80*25*2;i+=2) {
            vga_writec(' ', get_colour_code(VGA::Black, VGA::White), i);
        }
    }
    void tty::vga_writestr(const char* str, uint8_t colour, uint16_t size) {
        for (size_t i=0;i<size;i++) {
            switch(str[i]) {
                case 0x0a:
                    position+=(((80*2)*((uint16_t)position/(80*2)+1))-position);
                break;
            default:
                vga_writec((uint8_t)str[i], colour, position);
                position+=2;
                break;
            }
        }
    }
    void vga_write_wrapper(void* instance, const char* str, uint8_t colour, uint16_t size) {
        tty* vga_write_instance = static_cast<tty*> (instance);
        vga_write_instance->vga_writestr(str, colour, size);
    }
}
