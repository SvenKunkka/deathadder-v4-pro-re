# Host-only library of reconstructed C modules. No MCU startup/linker/HAL.
CC = clang
AR = ar
CFLAGS = -std=c11 -Wall -Wextra -Werror -pedantic -O2
SOURCES := $(wildcard *.c)
HEADERS := $(wildcard *.h)
OBJECTS := $(patsubst %.c,build/host/%.o,$(SOURCES))

.PHONY: all
all: build/librr_recovered.a

build/host/%.o: %.c $(HEADERS)
	@mkdir -p build/host
	$(CC) $(CFLAGS) -c $< -o $@

build/librr_recovered.a: $(OBJECTS)
	$(AR) rcs $@ $(OBJECTS)
