#ifndef IDT_H_
#define IDT_H_

#include <stdint.h>

typedef struct {
    uint16_t off_one;
    uint16_t sel;
    uint8_t zero;
    uint8_t type;
    uint16_t off_two;
} __attribute__((packed)) IDT_ent_t;

#define IRQ 0x8e
#define EXCEP = 0x8f


void exception_handler(void);
void write_ent(IDT_ent_t* ids_table, uint16_t num, uint32_t handle, uint8_t t);
void idt_init(IDT_ent_t* table);
#endif
