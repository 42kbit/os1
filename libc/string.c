void* memcpy(void* dest, const void* src, size_t n){
	size_t i = 0;
	char* ds = (char*)dest;
	char* sr = (char*)src;
	while ( i < n ){
		*(ds++) = *(sr++);
		++i;
	}
}

void* memmove(void* dest, const void* src, size_t n);
void* memchr(const char* s, char c, size_t n);
int memcmp(const char* s1, const char* s2, size_t n);
void* memset(char*, int z, size_t);


