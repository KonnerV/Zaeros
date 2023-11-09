#include <stdint.h>

#include "./graphics/vga_write.h"
#include "./libk/string.h"
#include "./drivers/pc_spkr.h"
#include "./idt/idt.h"
#include "./drivers/keyboard.h"

IDT_ent_t id_table[256];

void kernel_main(void) {
    clr_scrn();
    beep_at_freq(1000);
    char wlcm_msg[] = "Welcome to Zaeros x86\0";
    vga_writestr(wlcm_msg, get_colour_code(Black, White), strlen(wlcm_msg));
    idt_init(id_table);
    initialise_kybrd_driver();
    for (;;) {}
}
