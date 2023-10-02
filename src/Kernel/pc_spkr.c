#include <stdint.h>
#include "io.h"
static void play_sound(uint32_t freq) {
    uint32_t pit_freq = 1193180 / freq;
    outb(0x43, 0xb6);
    outb(0x42, (uint8_t) (pit_freq));
    outb(0x42, (uint8_t) (pit_freq >> 8));

    uint8_t p_snd = inb(0x61);
    (p_snd != (p_snd | 3)) ? outb(0x61, p_snd | 3) : -1;    
}

static void nosound() {
    outb(0x61, (uint8_t)inb(0x61) & 0xFC);
}

void beep_at_freq(uint32_t freq) {
    play_sound(freq);
    for(int i=0;i<100000000;i++) {}
    nosound();
}
