#include <stdint.h>
#include <stddef.h>
#include "vga_write.h"

uint8_t get_colour_code(colour8_t background, colour8_t foreground) {
    return ((uint8_t)background << 4) | (uint8_t)foreground;
}

void clr_scrn(void) {
    for(size_t i=0;i<80*25*2;i+=2) {
        vga_writec(' ', get_colour_code(Black, White), i);
    }
}

void vga_writec(uint8_t chr, uint8_t colour, size_t pos) {
    volatile char* VGA_buffer = (volatile char*) 0xb8000;
    VGA_buffer[pos] = chr;
    VGA_buffer[pos+1] = colour;
}

void vga_writestr(const char* str, uint8_t colour, uint16_t size) {
    for (size_t i=0;i<size;i++) {
        switch(str[i]) {
            case 0x0a:    
                position+=(((80*2)*((uint16_t)position/(80*2)+1))-position);
            break;
            case 0x08:
                position-=2;
                vga_writec(' ', colour, position);
            break;    
            default:
                vga_writec(str[i], colour, position);
                position+=2;
            break;
        }
    }
}

