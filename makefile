C_FLAGS =-c -ffreestanding -fno-pie -I $(PWD)

CC =gcc
C16 =$(CC) $(C_FLAGS) -m16
ASM_FLAGS =-c
ASM=as
ASM32 =$(ASM) $(ASM_FLAGS) --32
LD_FLAGS=-m elf_i386 --oformat binary
LD=ld $(LD_FLAGS)

BUILD_DIR = build

.PHONY: genbuild

MAKEFLAGS += --no-print-directory

all: makedirbuild $(BUILD_DIR)/os.bin

makedirbuild:
	mkdir -p build
	mkdir -p build/obj

$(BUILD_DIR)/os.bin: $(BUILD_DIR)/obj/btsec.o $(BUILD_DIR)/obj/main.o $(BUILD_DIR)/obj/btldr_asmlib.o $(BUILD_DIR)/obj/btldr_clib.o
	$(LD) -Ttext 0x7c00 -o $@ $^

$(BUILD_DIR)/obj/%.o: boot/%.c
	$(C16) $^ -o $@

$(BUILD_DIR)/obj/%.o: boot/%.s
	$(ASM32) $^ -o $@

clear:
	rm -rf build/*
