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
/* string */
char* strcat(char* dst, const char* src);
char* strncat(char* dst, const char* src, size_t n);
char* strchr(const char* s, int c);
char* strrchr(const char* s, int c);
int strcmp(const char*, const char*);
int strncmp(const char*, const char*, size_t);
int strcoll(const char*, const char*);
char* strcpy(char* dst, char* src);
char* strncpy(char* dst, char* src, size_t n);
char* strerror(int);
size_t strlen(const char*);
size_t strspn(const char* s, const char* accept);
size_t strcspn(const char* s, const char* reject);
char* strpbrk(const char* s, const char* accept);
char* strstr(const char* s1, const char* substr);
char* strtok(char*, const char*);
size_t strxfrm(char* dest, const char* src, size_t n); 

#endif
