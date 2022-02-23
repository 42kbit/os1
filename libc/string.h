#ifndef _H_CLIB_STRING_H
#define _H_CLIB_STRING_H

#define NULL (void*)0
typedef unsigned int size_t;

/* memory */
void* memcpy(void* dest, const void* src, size_t n);
void* memmove(void* dest, const void* src, size_t n);
void* memchr(const char* s, char c, size_t n);
int memcmp(const char* s1, const char* s2, size_t n);
void* memset(char*, int z, size_t);


#endif
