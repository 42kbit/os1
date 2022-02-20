.code16
.globl _start
_start:
	jmp %cs:btsec_entry

BTLDR_ENTRY_ADDR = 0x7e00 
btsec_entry:
	movw $0x0, %ax
	movw %ax, %es 

	movb $0x2, %ah
	movb $0x10, %al
	// es:bx = disk destenation	
	movw $BTLDR_ENTRY_ADDR, %bx
	
	movb $0x2, %cl
	movb $0x0, %ch
	movb $0x0, %dh
	//dl already points to right disk	
	int $0x13

	movw $0x0, %ax
	movw %ax, %ds	
	movw %ax, %ss
	movw $0x7c00, %ax
	movw %ax, %bp
	movw %ax, %sp	
	
	jmp %es:BTLDR_ENTRY_ADDR

.org 510
.word 0xaa55

.extern btldr_entry
jmp %es:btldr_entry
