AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
.PHONY: all
all: build/mouse_context_switch.bin
build/mouse_context_switch.o: mouse_context_switch.S
	@mkdir -p build
	$(AS) -mcpu=cortex-m33 -mthumb $< -o $@
build/mouse_context_switch.elf: build/mouse_context_switch.o mouse_context_switch.ld
	$(LD) -T mouse_context_switch.ld $< -o $@
build/mouse_context_switch.bin: build/mouse_context_switch.elf
	$(OBJCOPY) -O binary $< $@
