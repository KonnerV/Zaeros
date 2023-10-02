#include "string.h"

size_t strlen(char* str) {
    uint8_t len = 0;
    while(str[len]) {
        len++;
    }
    return len;
}

void memset(char* dst, char* data) {
    for (int i=0;i<strlen(data);i++)
        dst[i] = data[i];
    return;
}

void memcpy(char* src, char* dst) {
    uint8_t len = strlen(dst);
    for (int i=0;i<strlen(src);i++) {
        dst[len+i] = src[i];
    }
    return;
}
