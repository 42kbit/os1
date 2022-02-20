// extern void btldr_hold();
.code16
.globl btldr_hold
btldr_hold:
	pushw %bp
	movw %sp, %bp

	hlt

	mov %bp, %sp
	popw %bp
	ret
// extern void _cdecl btldr_init_stack();
.globl btldr_init_stack
btldr_init_stack:

	movw $0x7c00, %ax
	movw %ax, %sp
	movw %ax, %bp
	ret

//extern void _atr_cdecl botld_clear_display();
.globl btldr_clear_display
btldr_clear_display:
	pushw %bp
	pushw %ax
	movw %sp, %bp

	movb $0x0, %ah
	movb $0x3, %al
	int $0x10

	movw %bp, %sp
	popw %ax
	popw %bp
