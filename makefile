CFLAGS =-nostdinc -nostdlib -Wall -ansi -c -ffreestanding -fno-pie -I $(PWD) -I $(PWD)/libc
C16 =$(CC) $(CFLAGS) -m16
ASM_FLAGS =-c
ASM32 =$(ASM) $(ASM_FLAGS) --32
LD_FLAGS=-shared -fno-threadsafe-statics -m elf_i386 --oformat binary
LD=$(LNK) $(LD_FLAGS)

BUILD_DIR = build

CSOURCES :=$(shell find -name '*.c')
ASMSOURCES :=$(shell find -name '*.s')
OBJS :=$(patsubst %.c, %.o, $(CSOURCES))\
	$(patsubst %.s, %.o, $(ASMSOURCES)) 

MAKEFLAGS += --no-print-directory

.PHONY: all
all: makedirbuild $(BUILD_DIR)/os.bin

$(BUILD_DIR)/obj/%.o: $(CSOURCES)
	$(C16) $^ -o $@

$(BUILD_DIR)/obj/%.o: $(ASMSOURCES)
	$(ASM32) $^ -o $@

$(BUILD_DIR)/os.bin: $(OBJS)
	$(LD) -Ttext 0x7c00 -o $@ $^

makedirbuild:
	mkdir -p build
	mkdir -p build/obj

clear:
	rm -rf build/*
