#include "idt.h"

#include <stdint.h>
#include <stddef.h>

extern void lidt(uint32_t* idt_pointer);
extern void key_handle(void);

extern void outb(uint16_t p, uint8_t data);

__attribute__((noreturn))
void exception_handler(void) {
    __asm__ volatile("cli;hlt");
    for (;;) {}
}

void write_ent(IDT_ent_t* ids_table, uint16_t num, uint32_t handle, uint8_t t) {
    ids_table[num].off_one = handle & 0xffff;
    ids_table[num].sel = 0x08;
    ids_table[num].zero = 0;
    ids_table[num].type = t;
    ids_table[num].off_two = (handle & 0xffff0000) >> 16;
}

void idt_init(IDT_ent_t* table) {
    uint32_t(* idt_p) = NULL;

    uint32_t kybrd_addr = (uint32_t)key_handle;
    write_ent(table, 0x21, kybrd_addr, IRQ);

    outb(0x20, 0x11);
    outb(0xa0, 0x11);
    outb(0x21, 0x20);
    outb(0xa1, 0x28);
    outb(0x21, 0x00);
    outb(0xa1, 0x00);
    outb(0x21, 0x01);
    outb(0xa1, 0x01);
    outb(0x21, 0xff);
    outb(0xa1, 0xff);

    uint32_t idt_addr = (uint32_t)table;
    idt_p[0] = (sizeof(IDT_ent_t)*256) + ((idt_addr&0xffff) << 16);
    idt_p[1] = idt_addr >> 16;
    lidt(idt_p);
}
