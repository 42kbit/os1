#include <boot/btldr.h>
#include <stdint.h>

char string[15];

void btldr_entry(){
	btldr_display_clear();
	char* msg = "I'm sorry Dave, I'm afraid I can't do that";
	__builtin_memcpy(string, msg, 14);
	string[14] = '\0';
	btldr_display_puts(string);
	btldr_hold();
}
