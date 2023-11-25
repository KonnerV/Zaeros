#include "pc_spkr.h"
#include <stdint.h>

extern char inb(uint16_t p);
extern void outb(uint16_t p, uint8_t data);

static void play_snd(uint32_t frq) {
    uint32_t pit_frq = 1193180 / frq;
    outb(0x43, 0xb6);
    outb(0x42, (uint8_t) (pit_frq));
    outb(0x42, (uint8_t) (pit_frq >> 8));

    uint8_t p_snd = inb(0x61);
    (p_snd != (p_snd | 3)) ? outb(0x61, p_snd | 3) : -1;    
}

static void no_snd() {
    outb(0x61, (uint8_t)inb(0x61) & 0xfc);
}

void beep_frq(uint32_t frq) {
    play_snd(frq);
    for(int i=0;i<100000000;i++) {}
    no_snd();
}
