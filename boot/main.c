#include <boot/btldr.h>
#include <string.h>

char* string = "There is a flower within my heart - Daisy, Daisy!";
void btldr_entry(){
	btldr_display_clear();
	btldr_display_mode_set(0x3);
	btldr_display_puts(string);
	btldr_hold();
}
