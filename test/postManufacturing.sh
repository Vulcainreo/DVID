#!/bin/bash

# Detect USBASP
ls /dev/ttyUSB*

# Change fuse on Atmega
avrdude -v -patmega328p -P/dev/ttyUSB0 -U lfuse:w:0xE2:m -cusbasp

# Flash test firmware
cd testBoard
avrdude -v -patmega328p -cusbasp -u -U flash:w:testBoard.ino.with_bootloader.arduino_standard.hex

read -p "Reboot device and press enter to continue ..."

# Check BLE
# Scan all bluetooth device during 5s and print if DVID is found
hciconfig hci0 down
hciconfig hci up
timeout 5s stdbuf -oL hcitool lescan | grep "DVID-TESTING"

# Check Wifi
ifconfig wlp59s0 down
ifconfig wlp59s0 up

iwlist scan | grep "DVID-TESTING"

read -p "Test ok ? If yes, press enter ..."

# Flash out of factory firmware
cd ../outFactory
avrdude -v -patmega328p -cusbasp -u -U flash:w:outFactory.ino.with_bootloader.arduino_standard.hex
