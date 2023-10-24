# Trace
This training aims to teach hardware registry and AVR simulation.

## Setup
* Flash the firmware on your DVID [download](./registry.hex)

```bash
avrdude -v -pm328 -cusbasp -u -U flash:w:registry.hex -F
```

* Install simavr tool
```bash
sudo apt install freeglut3-dev libglfw3-dev libgl1-mesa-dev libglu1-mesa-dev avr-libc gcc-avr libelf-dev

git clone https://github.com/buserror/simavr
cd simavr
make
sudo make install release=1
```

## Instruction
Something is written on eeprom. You need to explore the firmware to discovery what. You can try to run the firmware on the DVID or try an alternative way.
