#include <boot/btldr.h>
#include <string.h>
char* string = "hello, world";

void btldr_entry(){
	btldr_display_clear();
	btldr_display_mode_set(0x3);
	char* string2 = "HELLO!";
	memcpy(string, string2, 5);
	btldr_display_puts(string);
	btldr_hold();
}
