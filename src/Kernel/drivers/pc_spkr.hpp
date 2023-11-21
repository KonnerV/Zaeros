//#pragma once
#ifndef PCSPKR_HPP_
#define PCSPKR_HPP_

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif
extern char inb(uint16_t p);
extern void outb(uint16_t p, uint8_t data);
#ifdef __cplusplus
}
#endif

namespace Audio_Dev {
    class PC_Spkr {
        public:
            static void beep_frq(uint32_t frq);
        private:
            static void play_snd(uint32_t frq);
            static void no_snd(void);
    };
}

#endif
