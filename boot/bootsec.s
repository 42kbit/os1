.code16
.globl _start
_start:
	jmp %cs:btldr_entry

BTLDR_ENTRY_ADDR = 0x1000 
btldr_entry:
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
	
	jmp %es:BTLDR_ENTRY_ADDR

.org 510
.word 0xaa55
