#pragma once
#ifndef PCSPKR_H_
#define PCSPKR_H_

#include <stdint.h>

static void play_snd(uint32_t frq);
static void no_snd();
void beep_frq(uint32_t frq);

#endif
