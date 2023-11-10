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
    char wlcm_msg[] = "Welcome to Zaeros x86\n";
    vga_writestr(wlcm_msg, get_colour_code(Black, White), strlen(wlcm_msg));
    idt_init(id_table);
    char idt_msg[] = "IDT [OK]\n";
    vga_writestr(idt_msg, get_colour_code(Black, D_Grey), strlen(idt_msg));
    initialise_kybrd_driver();
    char kbd_msg[] = "Keyboard [OK]\n";
    vga_writestr(kbd_msg, get_colour_code(Black, D_Grey), strlen(kbd_msg));

    for (;;) {}
}
