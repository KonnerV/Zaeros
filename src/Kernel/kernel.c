#include "vga_write.h"
#include "io.h"
#include "pc_spkr.h"
#include "string.h"

void panic() {
    char panic_msg[] = "Error! Panic resulted in halt.\0";
    vga_writestr(panic_msg, get_colour_code(Black, Red), strlen(panic_msg));
    for (;;) {beep_at_freq(500);}
}

__attribute__((noreturn))
void exception_handler(void);
void exception_handler() {
    __asm__ volatile("cli;hlt");
}

typedef struct {
    uint16_t offone;
    uint16_t sel;
    uint8_t zero;
    uint8_t type;
    uint16_t offtwo;
} __attribute__((packed)) IDT_ent;

IDT_ent interrupt_descriptor_table[256];

void write_ent(uint16_t num, uint32_t handle) {
    interrupt_descriptor_table[num].offone = (uint16_t)((handle)&0xffff);
    interrupt_descriptor_table[num].sel = 0x08;
    interrupt_descriptor_table[num].zero = 0x00;
    interrupt_descriptor_table[num].type = 0x8e;
    interrupt_descriptor_table[num].offtwo = (uint16_t)(((handle)>>16)&0xffff);
}

void wmemloc(uint8_t* loc, char data[]) {
    for(int i=0;i<strlen(data);i++)
        *loc++ = data[i]; 
}

void kernel_main(void) {
    clr_scrn();
    char wlcm_msg[] = "Welcome to Zaeros x86\0";

    beep_at_freq(1000);
    vga_writestr(wlcm_msg, get_colour_code(Black, White), strlen(wlcm_msg));
    for(;;) {}
}
