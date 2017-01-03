CC := arm-none-eabi-gcc
CFLAGS := $(CFLAGS) -mcpu=cortex-m0 -D STM32F031K4U6 -mthumb -g2 -O0 -L . -T ./link.ld -nostdlib -ggdb -lgcc -Wall -Wextra
SRC := main.c startup.c
OUTPUT := main.elf

all: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUTPUT)

clean:
	rm -rf $(OUTPUT)

burn: $(OUTPUT)
	openocd -f openocd-swd.cfg -c "program $(OUTPUT); shutdown"

reset:
	openocd -f openocd-swd.cfg -c "reset halt; shutdown"

# svf @ https://github.com/bharrisau/busblaster
confdebugger:
	openocd -f board/dp_busblaster_v3.cfg -c "adapter_khz 1000; init; svf system.svf; shutdown"