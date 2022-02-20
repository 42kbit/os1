#include <boot/btldr.h>

extern void btldr_display_puts(char* s){
	while ( *s ){
		btldr_display_putc( *s );
		++s;
	} 
	return;
}
