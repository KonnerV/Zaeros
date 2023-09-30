#include "vga_write.h"

void main(void) {
    clr_scrn();
    char str[20] = "Welcome to KV-OS x86";
    vga_writestr(str, get_colour_code(Black, White), sizeof(str));
    for(;;) {}
}
