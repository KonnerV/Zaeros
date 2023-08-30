#include <stdint.h>

struct vga {
    char *addr; // 0xb8000
    uint16_t max_size; // 4000
};

enum colour {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    GREY = 7,
    LIGHT_GREY = 8,
    LIGHT_BLUE = 9,
    LIGHT_GREEN = 10,
    LIGHT_CYAN = 11,
    LIGHT_RED = 12,
    LIGHT_MAGENTA = 13,
    LIGHT_BROWN = 14,
    WHITE = 15,
};

static inline uint8_t get_colourcode(enum colour background, enum colour foreground) {
    return (background << 4) | foreground;
}

unsigned int strlen(const char* str) {
    unsigned int length=0;
    while (str[length]) {length++;}
    return length;
}

void vga_ent(struct vga vga_struct) {
    vga_struct.addr = (char *)0xb8000;
    vga_struct.max_size = 4000;
    // Clear screen
    for (uint16_t i=0;i<vga_struct.max_size;i+=2) {
        vga_struct.addr[i] = ' ';
        vga_struct.addr[i+1] = 0x07;
    }
}

// TODO: Implement strlen
void vga_write(struct vga vga_struct, const char *str, uint8_t colourcode) {
    vga_struct.addr = (char *)0xb8000;
    unsigned int j=0;
    for (unsigned int i=0;i<strlen(str);i++) {
        vga_struct.addr[j] = str[i];
        vga_struct.addr[j+1] = colourcode;
        j+=2;
    }
}

void kernel_main(void) {
    struct vga vga_to_write;
    vga_ent(vga_to_write);
    vga_write(vga_to_write, "Hello, World!", 0x04);
    return;
}
