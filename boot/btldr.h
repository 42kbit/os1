#ifndef _H_BTLDR_H
#define _H_BTLDR_H

#include <utils/atr_def.h>
#include <utils/int_def.h>
/* asmlib */
extern void _atr_cdecl btldr_hold(void);
extern void _atr_cdecl btldr_display_clear(void);
extern void _atr_cdecl btldr_display_putc(char c);
extern void _atr_cdecl btldr_display_color_set(u8 rgb, u16 x, u16 y);
extern void _atr_cdecl btldr_display_mode_set(u8 mode);
/* clib */
extern void btldr_display_puts(char* s);

#endif
