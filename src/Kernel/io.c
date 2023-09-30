unsigned char inb(unsigned short p) {
    unsigned char ret_value;
    asm volatile("in %%dx, %%al" : "=a"(ret_value) : "d"(p) : "memory");
    return ret_value;
}

void outb(unsigned char val, unsigned short p) {
    asm volatile("out %%al, %%dx" : : "a"(val), "d"(p) : "memory");
}
