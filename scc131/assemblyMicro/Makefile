ARM_PREFIX=arm-none-eabi-

CC=$(ARM_PREFIX)gcc
LD=$(ARM_PREFIX)ld
OBJCOPY=$(ARM_PREFIX)objcopy

OPENOCD=openocd

SRCS= main.S 
OBJS= main.o

CFLAGS=-Wno-expansion-to-defined -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -fno-exceptions -fno-unwind-tables -ffunction-sections -fdata-sections -Wall -Wextra -Wno-unused-parameter -fwrapv -fno-rtti -fno-threadsafe-statics -fno-exceptions -fno-unwind-tables -Wl,--gc-sections -Wl,--sort-common -Wl,--sort-section=alignment -Wno-array-bounds -g3
LDFLAGS=-nostdlib -T lib/link.ld --print-memory-usage

TARGET=MICROBIT.hex

all: $(TARGET)

$(TARGET): $(OBJS)
	"$(LD)" $(LDFLAGS) $^ -o $@

%.o: %.c
	"$(CC)" $(CFLAGS) -o $@ -c $<

%.o: %.S
	"$(CC)" $(CFLAGS) -o $@ -c $<

.PHONY: upload
upload: $(TARGET)
	"$(OPENOCD)"  -f interface/cmsis-dap.cfg -f target/nrf52.cfg -c "program MICROBIT.hex verify reset"

clean:
	rm $(TARGET) MICROBIT.bin $(OBJS) >/dev/null 2>/dev/null || true
