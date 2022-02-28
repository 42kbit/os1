CFLAGS =-nostdinc -nostdlib -Wall -ansi -c -ffreestanding -fno-pie -I $(PWD) -I $(PWD)/libc
C16 =$(CC) $(CFLAGS) -m16
ASMFLAGS =-c
ASM32 =$(ASM) $(ASMFLAGS) --32
LDFLAGS=-shared -fno-threadsafe-statics -m elf_i386 --oformat binary
LDMBR=$(LD) $(LDFLAGS) 

BUILDDIR = build
OBJDIR = $(BUILDDIR)/obj

CSOURCES :=$(shell find ./ -name '*.c')
ASMSOURCES :=$(shell find ./ -name '*.s')
ALLSOURCES :=$(CSOURCES)\
	$(ASMSOURCES)
COBJS :=$(patsubst %.c, %.o, $(CSOURCES))
COBJSNDIR :=$(notdir $(COBJS))
ASMOBJS :=$(patsubst %.s, %.o, $(ASMSOURCES)) 
ASMOBJSNDIR :=$(notdir $(ASMSOURCES)) 
ALLOBJS :=$(COBJS)\
	$(ASMOBJS)
ALLOBJSNDIR :=$(notdir $(ALLOBJS))
ALLDIRS :=$(patsubst %/, %, $(sort $(dir $(ALLOBJS))))

#Place bootsector first in linkage, to not mess up memory addresses
#PR0 = priority 0, obj's that are locatend in the start of binary output file 
PR0 := btsec.o 
ALLOBJSNDIR := $(filter-out $(PR0), $(ALLOBJSNDIR))
ALLOBJSNDIR := $(addprefix $(PR0), $(ALLOBJSNDIR))

MAKEFLAGS += --no-print-directory
VPATH = $(ALLDIRS)
.PHONY: all always
all: always $(BUILDDIR)/os.bin

$(OBJDIR)/%.o: %.c
	$(C16) -o $@ $^

$(OBJDIR)/%.o: %.s
	$(ASM32) -o $@ $^

$(BUILDDIR)/os.bin: $(addprefix $(OBJDIR)/,$(ALLOBJSNDIR))
	$(LDMBR) -Ttext 0x7c00 -o $@ $^

always:
	mkdir -p build
	mkdir -p build/obj
	
clear:
	rm -rf build/*
