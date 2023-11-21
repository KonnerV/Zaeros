#ifndef IDT_HPP_
#define IDT_HPP_

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif
    extern void lidt(uint32_t* idt_pointer);
    extern void key_handle(void);
    extern void outb(uint16_t p, uint8_t data);
#ifdef __cplusplus
}
#endif

typedef struct {
    uint16_t off_one;
    uint16_t sel;
    uint8_t zero;
    uint8_t type;
    uint16_t off_two;
} __attribute__((packed)) IDT_ent_t;

#define IRQ 0x8e
#define EXCEP = 0x8f

namespace CPU {
    #ifdef __cplusplus
    extern "C" {
    #endif
    void exception_handler(void); 
    class interrupt_descriptor_table {
        public:
            static void write_ent(IDT_ent_t* interrupt_table, uint16_t num, uint32_t handle, uint8_t t);
            static void idt_init(IDT_ent_t* table);
        private:
    };
    #ifdef __cplusplus
    }
    #endif
}
#endif
