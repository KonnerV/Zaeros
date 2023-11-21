#include "pc_spkr.hpp"
#include <cstdint>

namespace Audio_Dev {
    void PC_Spkr::play_snd(uint32_t frq) {
        uint32_t pit_freq = 1193180 / frq;
        outb(0x43, 0xb6);
        outb(0x42, (uint8_t) (pit_freq));
        outb(0x42, (uint8_t) (pit_freq >> 8));

        uint8_t p_snd = inb(0x61);
        if (p_snd != (p_snd | 3)) {
            outb(0x61, p_snd | 3); 
        };
    }
    void PC_Spkr::no_snd(void) {
        outb(0x61, (uint8_t)inb(0x61) & 0xfc);
    }
    void PC_Spkr::beep_frq(uint32_t frq) {
        PC_Spkr::play_snd(frq);
        for (int i=0;i<10000000;i++) {}
	PC_Spkr::no_snd();
    }
}
