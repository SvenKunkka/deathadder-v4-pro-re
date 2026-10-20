AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
.PHONY: all
all: build/receiver_context_switch.bin
build/receiver_context_switch.o: receiver_context_switch.S
	@mkdir -p build
	$(AS) -mcpu=cortex-m33 -mthumb $< -o $@
build/receiver_context_switch.elf: build/receiver_context_switch.o receiver_context_switch.ld
	$(LD) -T receiver_context_switch.ld $< -o $@
build/receiver_context_switch.bin: build/receiver_context_switch.elf
	$(OBJCOPY) -O binary $< $@
