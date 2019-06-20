Here, you will find some training with DVID board.
Please, don't share flags in public.

Have fun :)

# Trainers

You need to flash the firmware on the board.

- Plug USBasp on the board (hard flash zone)
- Plug in any other extension needed for the training e.g the JDY-18 BLE module

Then, flash with `avrdude`:

`avrdude -c usbasp -p m328p -C pathto/avrdude.conf -U flash:w:pathtofirmware.hex`
