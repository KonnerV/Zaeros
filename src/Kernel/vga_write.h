#ifndef VGA_WRITE_H
#define VGA_WRITE_H

#include <stdint.h>
#include <stddef.h>

typedef enum {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    L_Grey = 7,
    D_Grey = 8,
    L_Blue = 9,
    L_Green = 10,
    L_Cyan = 11,
    L_Red = 12,
    Pink = 13,
    Yellow = 14,
    White = 15
} colour8_t;

uint8_t get_colour_code(colour8_t background, colour8_t foreground);
uint8_t strlen(const char *str);
void vga_writec(uint8_t chr, uint8_t colour, uint16_t pos);
void vga_writestr(char str[], uint8_t colour, uint16_t size);

#endif
