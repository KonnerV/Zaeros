#include <stdint.h>

#include "./graphics/vga_write.hpp"
#include "./drivers/pc_spkr.hpp"

#ifdef __cplusplus
extern "C" {
#endif
    #include "./libk/string.h"
    extern void cpuid_c(void);
#ifdef __cplusplus
}
#endif
#include "./idt/idt.hpp"
#include "./drivers/keyboard.hpp"

IDT_ent_t id_table[256];

namespace Kernel {
    extern "C" void kernel_main(void) {
	VGA::tty vga;
	Audio_Dev::PC_Spkr::beep_frq(1000);
        const char wlcm_msg[] = "Welcome to Zaeros x86\n";
        CPU::interrupt_descriptor_table::idt_init(id_table);
        vga_write_wrapper(&vga, wlcm_msg, VGA::tty::get_colour_code(VGA::Black, VGA::White), strlen(wlcm_msg));
        Device_Driver::PS2_Keyboard keyboard;
        for (;;) {}
    }
}
