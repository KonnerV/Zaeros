#include <stdint.h>

#include "./graphics/vga_write.hpp"
#include "./drivers/pc_spkr.hpp"

#ifdef __cplusplus
extern "C" {
#endif
    #include "./libk/string.h"
#ifdef __cplusplus
}
#endif
//#include "./idt/idt.h"
//#include "./drivers/keyboard.h"

//extern void cpuid_c(void);
//extern void outb(uint16_t p, uint8_t data);

//IDT_ent_t id_table[256];

namespace Kernel {
    extern "C" void kernel_main(void) {
	VGA::tty vga;
	Audio_Dev::PC_Spkr::beep_frq(1000);
        char wlcm_msg[] = "Welcome to Zaeros x86\n";
	vga.vga_writestr(wlcm_msg, VGA::tty::get_colour_code(VGA::Black, VGA::White), strlen(wlcm_msg));
        for (;;) {}
    }
}
