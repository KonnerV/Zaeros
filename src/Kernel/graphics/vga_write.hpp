#pragma once
#ifndef VGA_WRITE_HPP_
#define VGA_WRITE_HPP_

#include <cstdint>
#include <cstddef>

namespace VGA {
    typedef enum {
        Black = 0,
        Blue = 1,
        Green = 2,
        Cyan = 3,
        Red = 4,
        Magenta = 5,
        Brown = 6,
        L_Grey = 7,
        D_Grey = 8,
        L_Blue = 9,
        L_Green = 10,
        L_Cyan = 11,
        L_Red = 12,
        Pink = 13,
        Yellow = 14,
        White = 15
    } colour8_t;

    class tty {
        public:
            uint16_t position = 0;
            tty();
            static uint8_t get_colour_code(colour8_t background, colour8_t foreground);
            void vga_writec(uint8_t chr, uint8_t colour, uint16_t pos);
            void vga_writestr(const char* str, uint8_t colour, uint16_t size);
        private:
    };
}

#endif
