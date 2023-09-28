#include <stdint.h>
#include <stddef.h>
#include "vga_write.h"

uint8_t get_colour_code(colour8_t background, colour8_t foreground) {
    return ((uint8_t)background << 4) | (uint8_t)foreground;
}

uint8_t strlen(const char *str) {
    uint8_t i = 0;
    while(str[i] != 0) {
        i++;
    }
    return i;
}

void vga_writec(uint8_t chr, uint8_t colour, uint16_t pos) {
    volatile uint8_t* VGA_buffer = (volatile uint8_t*) 0xb8000;
    VGA_buffer[pos] = chr;
    VGA_buffer[pos+1] = colour;
}

void vga_writestr(char str[], uint8_t colour, uint16_t size) {
    int pos=0;
    for (int i=0;i<size;i++) {
        vga_writec((uint8_t)str[i], get_colour_code(Black, White), pos);
	pos+=2;
    }
}
