#include <string.h>
void* memcpy(void* dest, const void* src, size_t n){
	size_t i = 0;
	char* ds = (char*)dest;
	char* sr = (char*)src;
	while ( i < n ){
		*(ds++) = *(sr++);
		++i;
	}
	return dest;
}

void* memchr(const char* s, char c, size_t n){
	size_t i = 0;
	while ( i < n ){ 
		if ( s[i] == c )
			return (char*)s + i;
		++i;
	}
	return NULL;
}

int memcmp(const char* s1, const char* s2, size_t n){
	size_t i = 0;
	while ( i < n ) {
		if( s1 [i] != s2 [i] ){
			return s1[i] > s2[i]? 1 : -1;
		}
		++i;	
	}
	return 0;
}

void* memset(char* dst, int z, size_t s){
	size_t i = 0;
	while ( i < s )
	{
		dst[i] = z;
		++i;
	}
	return dst;	
}

void* memmove(void* dest, const void* src, size_t n){
	char* tmpsrc[n];	
	memcpy(tmpsrc, src, n);
	memcpy(dest, tmpsrc, n); 
	return dest;
}

size_t strlen(const char* s){
	size_t res = 0;
	while ( *(s+res) ) { ++res; } 
	return res;
}

char* strcat(char* dst, const char* src){
	size_t srclen = strlen(src); /* also zero term index */
	strncat(dst, src, srclen);
	return dst;
}

char* strncat(char* dst, const char* src, size_t n){
	size_t dstlen = strlen(dst);
	size_t i = 0;
	while ( i < n ) {
		*(dst + dstlen + i) = *(src + i);
		++i;
	} 
	*(dst + dstlen + n) = '\0';
	return dst;
}

char* strchr(const char* s, int c){
	size_t slen = strlen(s);	
	return (char*)memchr(s, c, slen);
}

char* strrchr(const char* s, int c){
	size_t slen = strlen(s);
	char cur;
	size_t i = 0;
	while( (cur = *(s+slen-1-i)) ) {
		if (cur == c)
			return (char*)s+slen-1-i;
		++i;
	}
	return NULL;
}

#ifndef MATH_MAX
#define MATH_MAX(a,b) (a > b? a : b)
#define MATH_MIN(a,b) (a < b? a : b)
#endif

int strcmp(const char* s1, const char* s2){
	size_t max = MATH_MAX(strlen(s1), strlen(s2));  
	return memcmp(s1, s2, max);
}

int strncmp(const char* s1, const char* s2 , size_t c){
	return memcmp(s1, s2, c);	
}

int strcoll(const char* s1, const char* s2){ /* placeholder, should be reimplemented */
	return strcmp(s1, s2);
}

char* strcpy(char* dst, char* src){
	return memcpy(dst, src, strlen(src) + 1);
}

char* strncpy(char* dst, char* src, size_t n){
	dst[n] = '\0';
	return memcpy(dst, src, n);
}

/* cannot be implemented yet */
char* strerror(int);

size_t strspn(const char* s, const char* accept){
	size_t result = 0;
	size_t i = 0;

	size_t alen = strlen(accept);
	size_t slen = strlen(s);
	while ( i < slen ) {
		size_t j = 0;
		while ( j < alen ){
			if ( accept[j] == s[i] ){
				++result;
				break;
			}
			else if ( j == (alen - 1))
				return i;
			++j;
		} 
		++i;
	}
	return result;
}

size_t strcspn(const char* s, const char* reject){
	size_t i = 0;

	size_t rlen = strlen(reject);
	size_t slen = strlen(s);
	while ( i < slen ) {
		size_t j = 0;
		while ( j < rlen ){
			if ( reject[j] == s[i] ){
				return i;
			}
			else if ( j == (rlen - 1)){
				break;	
			}
			++j;
		} 
		++i;
	}
	return i;
}

char* strpbrk(const char* s, const char* accept){
	size_t i = 0;
	size_t slen = strlen(s);
	size_t alen = strlen(accept);
	while ( i < slen ) {
		size_t j = 0;
		while ( j < alen ){
			/* also can use memchr, but it will be slower due to call */
			if( s[i] == accept[j] )
				return (char*)s + i;
			++j;
		}
		++i;
	}
	return NULL;
}

char* strstr(const char* s1, const char* substr){
	size_t i = 0;
	size_t slen = strlen(s1);
	size_t sslen = strlen(substr);
	while ( i < slen ){
		size_t j = 0;
		while ( j < sslen ){
			if(s1[i+j] != substr[j])
				break;
			if(j == (sslen - 1))
				return (char*)s1 + i;
			++j;
		}
		++i;
	}
	return NULL;
}

#ifndef __STRTOK_BUFFER_SIZE_
#define __STRTOK_BUFFER_SIZE_ 0xFF
#endif
static char __strtok_buf[__STRTOK_BUFFER_SIZE_];
static char __strtok_ret[__STRTOK_BUFFER_SIZE_];
/* kinda fucked up but works */
char* strtok(char* s1, const char* toks){
	if ( !s1 ){
		s1 = __strtok_buf;
	}
	else{
		memcpy(__strtok_buf, s1, strlen(s1) * sizeof(char));
	}
	size_t slen = strlen(s1);
	size_t tlen = strlen(toks);
	size_t i = 0;
	size_t j = 0;
	size_t cm = 0; /* chars missed */
	/* counting cm */
	while ( cm < slen ) {
		j = 0;
		while ( j < tlen ){
			if ( s1[cm] == toks[j] ){	
				break;	
			}
			if ( j == (tlen - 1) ){
				goto loop_end;
			}
			++j;
		}  	
		++cm;
	}
	loop_end:
	i = cm;
	while ( i < slen ) {
		j = 0;
		while ( j < tlen ) {
			if ( s1[i] == toks[j] ) {
				memcpy(__strtok_ret, s1+cm, (i+1-cm) * sizeof(char));	
				__strtok_ret[i-cm] = '\0';
				memcpy(__strtok_buf, s1+i+1, (slen-i+1) * sizeof(char));
				return __strtok_ret;
			}
			++j;
		}
		++i;
	} 
	if ( strlen(__strtok_buf) > 0 ){
		memcpy(__strtok_ret, s1, (i) * sizeof(char));	
		__strtok_ret[i] = '\0';
		memset(__strtok_buf, 0, 2 * sizeof(char));
		return __strtok_ret;
	}
	return NULL;
}

size_t strxfrm(char* dest, const char* src, size_t n){
	strncpy(dest, src, n);		
	return strlen(dest);
}
