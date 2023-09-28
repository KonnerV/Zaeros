#include "vga_write.h"

void main(void) {
    char string[13] = "Hello, World!";
    vga_writestr(string, get_colour_code(Black, White), sizeof(string));
    for(;;) {}
}
