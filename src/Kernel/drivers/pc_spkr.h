#ifndef PCSPKR_H_
#define PCSPKR_H_

#include <stdint.h>

static void play_sound(uint32_t freq);
static void nosound();
void beep_at_freq(uint32_t freq);

#endif
