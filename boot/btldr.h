#ifndef _H_BTLDR_H
#define _H_BTLDR_H

#include <utils/attrib_def.h>

// asmlib
extern void _atr_cdecl btldr_hold();
extern void _atr_cdecl btldr_display_clear();
extern void _atr_cdecl btldr_display_putc(char c);

// clib
extern void btldr_display_puts(char* s);

#endif
