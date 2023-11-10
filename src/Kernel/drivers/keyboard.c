#include "keyboard.h"
#include "../graphics/vga_write.h"
#include "keyboard_layout.h"

#include <stdint.h>

extern unsigned char key_map[128];
extern void key_handle(void);

extern void outb(uint16_t p, uint8_t data);
extern char inb(uint16_t p);

void initialise_kybrd_driver(void) {
    outb(0x21, 0xfd);
}

void key_handle_f(void) {
    outb(0x20, 0x20);
    uint8_t stat = inb(0x64);
    if (stat & 0x01) {
        int8_t key = inb(0x60);
        if(key < 0) {
            return;
	}
        vga_writec(key_map[(uint8_t) key], get_colour_code(Black, Red), position);
        position+=2;
    }
}
