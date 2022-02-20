// extern void btldr_hold();
.code16
.globl btldr_hold
btldr_hold:
	pushw %bp
	movw %sp, %bp

hltlabel:
	jmp %cs:hltlabel

	mov %bp, %sp
	popw %bp
	ret
//extern void _atr_cdecl botld_clear_display();
.globl btldr_display_clear
btldr_display_clear:
	pushw %bp
	pushw %ax
	movw %sp, %bp

	movb $0x0, %ah
	movb $0x3, %al
	int $0x10

	movw %bp, %sp
	popw %ax
	popw %bp
	ret
//extern void _atr_cdecl btldr_display_putc(char c);
.globl btldr_display_putc
btldr_display_putc:
	pushw %bp
	movw %sp, %bp

	movb $0x0e, %ah
	movb 6(%bp), %al
	int $0x10 	

	movw %bp, %sp
	popw %bp		
	ret
