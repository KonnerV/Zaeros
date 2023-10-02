#include "vga_write.h"
#include "io.h"
#include "pc_spkr.h"
#include "string.h"

void main(void) {
    clr_scrn();
    char wlcm_msg[21] = "Welcome to KV-OS x86\0";

    beep_at_freq(1000);
    vga_writestr(wlcm_msg, get_colour_code(Black, White), strlen(wlcm_msg));
    for(;;) {}
}
