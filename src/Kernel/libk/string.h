#pragma once
#ifndef STRING_H_
#define STRING_H_

#include <stddef.h>
#include <stdint.h>

size_t strlen(char* str);
void memset(char* dst, char* data);
void memcpy(char* src, char* dst);
int8_t memcmp(char* src, char* dst);

#endif
